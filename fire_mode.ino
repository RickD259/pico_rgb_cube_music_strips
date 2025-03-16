void Fire(int Cooling, int Sparking, int SpeedDelay) {
  static byte heat[NUMPIXELS];
  int cooldown;
 
  if (millis() - previousMillis >= SpeedDelay) {
    previousMillis = millis();

    // Step 1.  Cool down every cell a little
    for( int i = 0; i < NUMPIXELS; i++) {
      cooldown = random(0, ((Cooling * 10) / NUMPIXELS) + 2);
    
      if(cooldown>heat[i]) {
        heat[i]=0;
      } else {
        heat[i]=heat[i]-cooldown;
      }
    }
  
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= NUMPIXELS - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
    }
    
    // Step 3.  Randomly ignite new 'sparks' near the bottom
    if( random(255) < Sparking ) {
      int y = random(2);        //number of pixels near the bottom
      heat[y] = heat[y] + random(160,255);
      //heat[y] = random(160,255);
    }

    // Step 4.  Convert heat to LED colors
    for( int j = 0; j < NUMPIXELS; j++) {
      setPixelHeatColor(j, heat[j] );
    }

    showStrip();
    //delay(SpeedDelay);
  }
}

void setPixelHeatColor (int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature/255.0)*191);
 
  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252
  byte halfheatramp = heatramp / 2;
 
  // figure out which third of the spectrum we're in:
  // and figure out the color of the fire
  if (color_pick >= 0 && color_pick <= 2){       //red->yellow->white
    if( t192 > 0x80) {                     // hottest yellow->white
      if (heatramp > 180) heatramp = 180;
      setPixel(Pixel, 255, 255, heatramp);
    } else if( t192 > 0x40 ) {             // middle red->yellow
      setPixel(Pixel, 255, heatramp, 0);
    } else {                               // coolest red
      setPixel(Pixel, heatramp, 0, 0);
    }
  }
  else if (color_pick >= 3 && color_pick <= 4){ //magenta->magenta->white
    if( t192 > 0x80) {                     // hottest magenta->white
      setPixel(Pixel, 255, heatramp, 255);
    } else if( t192 > 0x40 ) {             // middle red->magenta
      setPixel(Pixel, 255, 0, heatramp);
    } else {                               // coolest magenta
      setPixel(Pixel, heatramp, 0, heatramp);
    }  
  }
  else if (color_pick >= 5 && color_pick <= 7){ //green->yellow->white
    if( t192 > 0x80) {                     // hottest yellow->white
      setPixel(Pixel, 255, 255, heatramp);
    } else if( t192 > 0x40 ) {             // middle green->yellow
      setPixel(Pixel, heatramp, 255, 0);
    } else {                               // coolest green
      setPixel(Pixel, 0, heatramp, 0);
    }
  }
  else if (color_pick >= 8 && color_pick <= 9){ //green->cyan->white
    if( t192 > 0x80) {                     // hottest cyan->white
      setPixel(Pixel, heatramp, 255, 255);
    } else if( t192 > 0x40 ) {             // middle green->cyan
      setPixel(Pixel, 0, 255, heatramp);
    } else {                               // coolest green
      setPixel(Pixel, 0, heatramp, halfheatramp);
    }  
  }
  else if (color_pick >= 10 && color_pick <= 12){ //blue->cyan->white
    if( t192 > 0x80) {                     // hottest cyan->white
      setPixel(Pixel, heatramp, 255, 255);
    } else if( t192 > 0x40 ) {             // middle blue->cyan
      setPixel(Pixel, 0, heatramp, 255);
    } else {                               // coolest blue
      setPixel(Pixel, 0, 0, heatramp);
    }  
  }
  else if (color_pick >= 13 && color_pick <= 15){ //blue->magenta->white
    if( t192 > 0x80) {                     // hottest magenta->white
      setPixel(Pixel, 255, heatramp, 255);
    } else if( t192 > 0x40 ) {             // middle blue->magenta
      setPixel(Pixel, heatramp, 0, 255);
    } else {                               // coolest blue
      setPixel(Pixel, halfheatramp, 0, heatramp);
    }  
  }

  // if (color_pick >= 0 && color_pick <= 4){                         // red fire
  //   if( t192 > 0x80) {                     // hottest
  //     if (heatramp > 180) heatramp = 180;
  //     setPixel(Pixel, 255, 255, heatramp);
  //   } else if( t192 > 0x40 ) {             // middle
  //     setPixel(Pixel, 255, heatramp, 0);
  //   } else {                               // coolest
  //     setPixel(Pixel, heatramp, 0, 0);
  //   }
  // }
  // else if (color_pick >= 5 && color_pick <= 9){                    // green fire
  //   if( t192 > 0x80) {                     // hottest
  //     setPixel(Pixel, 255, 255, heatramp);
  //   } else if( t192 > 0x40 ) {             // middle
  //     setPixel(Pixel, heatramp, 255, 0);
  //   } else {                               // coolest
  //     setPixel(Pixel, 0, heatramp, 0);
  //   }
  // }
  // else if (color_pick >= 10 && color_pick <= 15){                    // blue fire
  //   if( t192 > 0x80) {                     // hottest
  //     setPixel(Pixel, heatramp, 255, 255);
  //   } else if( t192 > 0x40 ) {             // middle
  //     setPixel(Pixel, 0, heatramp, 255);
  //   } else {                               // coolest
  //     setPixel(Pixel, 0, 0, heatramp);
  //   }  
  // }
}

void showStrip() {
   pixels.show();
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
   pixels.setPixelColor(Pixel, pixels.Color(red, green, blue));
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUMPIXELS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
