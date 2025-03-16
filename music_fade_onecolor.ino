void musicfade_onecolor(int music){
  // no auto color change color fading changer
  uint32_t color;
  

  //convert 32bit to 8 bit colors
  byte endWhite = (color_1 >> 24) & 0xff; 
  byte endRed = (color_1 >> 16) & 0xff;
  byte endGreen = (color_1 >> 8) & 0xff;
  byte endBlue = color_1 & 0xff;

  //map music level to led brightness
  byte white = map(music, 0, 255, 0, endWhite);
  byte red = map(music, 0, 255, 0, endRed);
  byte green = map(music, 0, 255, 0, endGreen);
  byte blue = map(music, 0, 255, 0, endBlue);

  
  //set strip
  for (int pixel = 0; pixel < NUMPIXELS; pixel++) {
    pixels.setPixelColor(pixel, red, green, blue, white);
  }  
  pixels.show(); // Output to strip

    
  
}  //-----------------------------------------------
