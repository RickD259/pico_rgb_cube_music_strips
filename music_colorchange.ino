void no_fade_ledmode(int music) {
 //solid color changer
  uint32_t color; 



  if (music > 230){
    if (dir == false){
      if (millis() - musicMillis > 300){//add 300ms timer here
        musicMillis = millis();
        dir = true;
        counter++;
        if (counter > 12) counter = 0;
      }
    }
    
  } else  {
    if (music < 200) dir = false; //test   
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

  // update strip
  for(pixel_number = 0; pixel_number < NUMPIXELS; pixel_number++) {

    pixels.setPixelColor(pixel_number, color);  //(r, g, b) 0 to 255 
  
  }
   
  pixels.show();   // Send the updated pixel colors to the hardware.
  
  
}//-----------------------
