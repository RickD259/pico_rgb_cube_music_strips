void vu_mode_onecolor(int music) {
  uint32_t color = color_1;
  
  for(int pixel = 0; pixel < NUMPIXELS; pixel++) {
  
    
    int pixel_max = map(music, 0, 255, 0, NUMPIXELS); // pwm min, pwm max, pixel min, pixel max)
    pixel_max = constrain(pixel_max, 0, NUMPIXELS);  
    
    //color = GREEN;  
    
    if (pixel > pixel_max){ // set unused pixels to off or w/e
      color = 0x000000;
    }
  
     pixels.setPixelColor(pixel, color); //load into ram
  
  }
  pixels.show();   // Send the updated ram pixel colors to the hardware.
  
}//-----------------------------------------------
