void musicfade(int music){
  // color fading changer
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

  //convert 32bit to 8 bit colors
  byte endWhite = (color >> 24) & 0xff; 
  byte endRed = (color >> 16) & 0xff;
  byte endGreen = (color >> 8) & 0xff;
  byte endBlue = color & 0xff;

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
