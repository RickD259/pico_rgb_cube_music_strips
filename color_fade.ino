void crossFade() {
  uint32_t startColor;
  uint32_t endColor;

  byte a=3;
  if(counter == 0){
    startColor = RED;
    endColor = GREEN;
  }
  else if(counter == 1){
    startColor = GREEN;
    endColor = BLUE;
  }
  else if(counter == 2){
    startColor = BLUE;
    endColor = WHITE; 
  }
  else if(counter == 3){
    startColor = WHITE;
    endColor = RED; 
  }
      
  byte startWhite = (startColor >> 24) & 0xff;
  byte startRed = (startColor >> 16) & 0xff;
  byte startGreen = (startColor >> 8) & 0xff;
  byte startBlue = startColor & 0xff;

  byte endWhite = (endColor >> 24) & 0xff; 
  byte endRed = (endColor >> 16) & 0xff;
  byte endGreen = (endColor >> 8) & 0xff;
  byte endBlue = endColor & 0xff;

  // for each step in the cross-fade
  if (millis() - previousMillis > tempslowdown){
    previousMillis = millis();
    tempslowdown = 15;
    
    byte white = map(steps, 0, 255, startWhite, endWhite);
    byte red = map(steps, 0, 255, startRed, endRed);
    byte green = map(steps, 0, 255, startGreen, endGreen);
    byte blue = map(steps, 0, 255, startBlue, endBlue);
    
    setAllStrips(red, green, blue, white);

    steps++;
    if (steps >= 255){
      steps = 0;
      counter++;
      tempslowdown = 5000;
      if (counter > a) counter = 0;
    }
    
  }
}


void setAllStrips(byte red, byte green, byte blue, byte white) {
  for (int pixel = 0; pixel < NUMPIXELS; pixel++) {
    pixels.setPixelColor(pixel, red, green, blue, white);
  }  
  pixels.show(); // Output to strip
}
