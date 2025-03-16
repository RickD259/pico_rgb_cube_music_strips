//add vu mode where background is not black but is lit up the current color, just dimmer

void vu_mode_bg(int music) {
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

  //convert 24 bit color to byte
  int dim_red = (color >> 16) & 0xff;
  int dim_green = (color >> 8) & 0xff;
  int dim_blue = color & 0xff;

  //dim colors
  dim_blue = dim_blue / 5;
  dim_green = dim_green / 5;
  dim_red = dim_red / 5;

  //convert 24 bit color to byte
  uint32_t dim_color = pixels.Color(dim_red, dim_green, dim_blue);

  for(int pixel = 0; pixel < NUMPIXELS; pixel++) {
  
    
    int pixel_max = map(music, 0, 255, 0, NUMPIXELS); // pwm min, pwm max, pixel min, pixel max)
    pixel_max = constrain(pixel_max, 0, NUMPIXELS);  
     
    
    if (pixel > pixel_max){ // set unused pixels to off or w/e
      color = dim_color;
    }
  
     pixels.setPixelColor(pixel, color); //load into ram
  
  }
  pixels.show();   // Send the updated ram pixel colors to the hardware.
  
}//-----------------------------------------------


void dual_vu_mode_bg(int music) {
  uint32_t color;
  uint32_t main_color;
  
  
  
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
    main_color = BLUE;
  }
  else if(counter  == 1){
    main_color = MAGENTA;      
  }
  else if(counter  == 2){
    main_color = GREEN;      
  }
  else if(counter  == 3){
    main_color = YELLOW;     
  }
  else if(counter  == 4){
    main_color = RED;      
  }
  else if(counter  == 5){
    main_color = CYAN;      
  }
  else if(counter  == 6){
    main_color = WHITE;     
  }
  else if(counter  == 7){   
    main_color = VIOLET;
  }
  else if(counter  == 8){   
    main_color = AQUAMARINE;
  }
  else if(counter  == 9){   
    main_color = ORANGE;
  }
  else if(counter  == 10){   
    main_color = ROSE;
  }
  else if(counter  == 11){   
    main_color = AZURE;
  }
  else if(counter  == 12){   
    main_color = CHARTREUSE;
  }
  
  //convert 24 bit color to byte
  int dim_red = (main_color >> 16) & 0xff;
  int dim_green = (main_color >> 8) & 0xff;
  int dim_blue = main_color & 0xff;

  //dim colors
  dim_blue = dim_blue / 5;
  dim_green = dim_green / 5;
  dim_red = dim_red / 5;

  //convert 24 bit color to byte
  uint32_t dim_color = pixels.Color(dim_red, dim_green, dim_blue);

  for(pixel_number = 0; pixel_number < NUMPIXELS; pixel_number++) {
  
    if (pixel_number >= NUMPIXELS / 2){
      // this one starts at the end of the led string
      int pixel_max = map(music, 0, 235, NUMPIXELS, NUMPIXELS / 2); //(flipped) pwm min, pwm max, pixel min, pixel max)
      pixel_max = constrain(pixel_max, NUMPIXELS / 2, NUMPIXELS);

      if (pixel_number < pixel_max){ // (flipped) set unused pixels to off
        color = dim_color;
      }else{
        color = main_color;
      }
  
  
    } else {
      
      int pixel_max = map(music, 0, 235, 0, NUMPIXELS / 2); // pwm min, pwm max, pixel min, pixel max)
      pixel_max = constrain(pixel_max, 0, NUMPIXELS / 2); 

      if (pixel_number >= pixel_max){ // set unused pixels to off
        color = dim_color;
      }else{
        color = main_color;
      }
    
    }
    
  
    pixels.setPixelColor(pixel_number, color);  
  
    }
  pixels.show();   // Send the updated ram pixel colors to the hardware.
  
}//-----------------------------------


  //convert 24 bit color to byte
//  int dim_red = (color_1 >> 16) & 0xff;
//  int dim_green = (color_1 >> 8) & 0xff;
//  int dim_blue = color_1 & 0xff;

//dim colors

//  if (dim_red >= 20) dim_red = dim_red - 20;
//  if (dim_green >= 20) dim_green = dim_green - 20;
//  if (dim_blue >= 20) dim_blue = dim_blue - 20;

  //convert 24 bit color to byte
//  dim_color = pixels.Color(dim_red, dim_green, dim_blue)