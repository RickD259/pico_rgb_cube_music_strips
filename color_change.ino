void colorchange(int slowdown) {

  if (millis() - previousMillis >= slowdown) {
    previousMillis = millis();

    ledhue = ledhue + 5;
    if (ledhue > 65530) ledhue = 0;
  
    //strip.setPixelColor(0, strip.gamma32(strip.ColorHSV(ledhue)));         

    for (int pixel = 0; pixel < NUMPIXELS; pixel++) {
      pixels.setPixelColor(pixel, pixels.ColorHSV(ledhue));
    }  
    pixels.show(); // Output to strip

  }
}



void singlecolor(uint32_t color) {

  if (millis() - previousMillis >= 100) {
    previousMillis = millis();
  
    //strip.setPixelColor(0, strip.gamma32(strip.ColorHSV(ledhue)));         //  Set pixel's color (in RAM)   
    for (int pixel = 0; pixel < NUMPIXELS; pixel++) {
      pixels.setPixelColor(pixel, color);
    }  
    pixels.show(); // Output to strip

  }
}


void rnd_blink(int a) {
  uint32_t color;
  //a = 11;  //8

  
 if (millis() - previousMillis > 200){
    if (pixel_number > NUMPIXELS) {
      pixel_number = 0;      
      pixels.show();   // Send the updated pixel colors to the hardware.
      previousMillis = millis();
      // counter++; //new
    }
  

    ledhue = ledhue + 40;
    if (ledhue > 65530) ledhue = 0;
    color = pixels.ColorHSV(ledhue);


    // if(counter  == 10){
    //   color = BLUE;
    // }
    // else if(counter  == 20){
    //   color = MAGENTA;      
    // }
    // else if(counter  == 30){
    //   color = GREEN;      
    // }
    // else if(counter  == 40){
    //   color = YELLOW;     
    // }
    // else if(counter  == 50){
    //   color = RED;      
    // }
    // else if(counter  == 60){
    //   color = CYAN;      
    // }
    // else if(counter  == 70){
    //   color = WHITE;     
    // }
    // else if(counter  == 80){   
    //   color = VIOLET;
    // }
    // else if(counter  == 90){   
    //   color = AQUAMARINE;
    // }
    // else if(counter  == 100){   
    //   color = ORANGE;
    // }
    // else if(counter  == 120){   
    //   color = ROSE;
    // }
    // else if(counter  == 130){   
    //   color = AZURE;
    // }
    // else if(counter  == 140){   
    //   color = CHARTREUSE;
    // }
    // else if (counter == 150){
    //   counter = 0;
    // }

    //--new 2024--
    if (random(a) == 2){
      //color = color1;  
      pixels.setPixelColor(pixel_number, color);
      pixel_number = pixel_number + 1;
    }else{
      pixel_number = pixel_number + 1;
    }
    //-----
  }


}//-------------------------------------------------