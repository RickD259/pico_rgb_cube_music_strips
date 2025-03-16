void strobe_mode(int slowdown){
//strobes random colors
  uint32_t color;
  
  if (millis() - previousMillis >= slowdown) {
    previousMillis = millis();

    color = Adafruit_NeoPixel::ColorHSV(random(0,65535), random(240,255));
  
  
    for (int pixel = 0; pixel < NUMPIXELS; pixel++) {
      pixels.setPixelColor(pixel, color);
    }  
    pixels.show(); // Output to strip

  }
  
}//----------------------------------------
