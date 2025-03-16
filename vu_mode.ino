void vu_mode(int music) {
  uint32_t color;

  if (music > 230){
    if (dir == false){
      if (millis() - musicMillis > 300){//good for 198 bpm
        musicMillis = millis();
        dir = true;
        counter++;
        if (counter > 12) counter = 0;
      }
    }
    
  } else  {
    if (music < 180) dir = false; //test
    
  }

    //--colors--
  if(counter  == 0){
    color = BLUE;
  }
  else if(counter  == 1){
    color = MAGENTA;      
  }
  else if(counter  == 2){
    color = GREEN;      
  }
  else if(counter  == 3){
    color = YELLOW;     
  }
  else if(counter  == 4){
    color = RED;      
  }
  else if(counter  == 5){
    color = CYAN;      
  }
  else if(counter  == 6){
    color = WHITE;     
  }
  else if(counter  == 7){   
    color = VIOLET;
  }
  else if(counter  == 8){   
    color = AQUAMARINE;
  }
  else if(counter  == 9){   
    color = ORANGE;
  }
  else if(counter  == 10){   
    color = ROSE;
  }
  else if(counter  == 11){   
    color = AZURE;
  }
  else if(counter  == 12){   
    color = CHARTREUSE;
  }



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


void dual_vu_mode(int music) {
  uint32_t color;
  
  
  if (music > 230){
    if (dir == false){
      if (millis() - musicMillis > 300){//good for 198 bpm
        musicMillis = millis();
        dir = true;
        counter++;
        if (counter > 12) counter = 0;
      }
    }
    
  } else  {
    if (music < 180) dir = false; //test
    
  }

    //--colors--
  if(counter  == 0){
    color = BLUE;
  }
  else if(counter  == 1){
    color = MAGENTA;      
  }
  else if(counter  == 2){
    color = GREEN;      
  }
  else if(counter  == 3){
    color = YELLOW;     
  }
  else if(counter  == 4){
    color = RED;      
  }
  else if(counter  == 5){
    color = CYAN;      
  }
  else if(counter  == 6){
    color = WHITE;     
  }
  else if(counter  == 7){   
    color = VIOLET;
  }
  else if(counter  == 8){   
    color = AQUAMARINE;
  }
  else if(counter  == 9){   
    color = ORANGE;
  }
  else if(counter  == 10){   
    color = ROSE;
  }
  else if(counter  == 11){   
    color = AZURE;
  }
  else if(counter  == 12){   
    color = CHARTREUSE;
  }
  
  for(pixel_number = 0; pixel_number < NUMPIXELS; pixel_number++) {
    if (pixel_number >= NUMPIXELS / 2){
      // this one starts at the end of the led string
      int pixel_max = map(music, 0, 235, NUMPIXELS, NUMPIXELS / 2); //(flipped) pwm min, pwm max, pixel min, pixel max)
      pixel_max = constrain(pixel_max, NUMPIXELS / 2, NUMPIXELS);

      if (pixel_number < pixel_max){ // (flipped) set unused pixels to off
        color = 0x000000;
      }
  
  
    } else {
      
      int pixel_max = map(music, 0, 235, 0, NUMPIXELS / 2); // pwm min, pwm max, pixel min, pixel max)
      pixel_max = constrain(pixel_max, 0, NUMPIXELS / 2); 

      if (pixel_number >= pixel_max){ // set unused pixels to off
        color = 0x000000;
      }
    
    }
    
  
    pixels.setPixelColor(pixel_number, color);  
  
    }
  pixels.show();   // Send the updated ram pixel colors to the hardware.
  
}//-----------------------------------

