//
void check_ir(uint32_t Command){
//if (sCallbackData.Address==ADDR) {
    //digitalWrite(LED_BUILTIN, HIGH);
    
    
    
    if (Command == ON){
      Serial.println("on");
      //load();
      ledmode = 4;
      if (Repeatcount == 6){
        //Repeatcount = 0;
        if (musicmode != 8){
          musicmode = 8;
          gain_level = 60; //reset auto gain
        }else{
          musicmode = 0;
        }
      }
    }
    else if (Command == OFF){
      Serial.println("off");
      //save();
      ledmode = 0;
    }
    else if (Command == FLASH){
      //
      ledmode = 1;
      previousMillis = 0;

      if (Repeatcount == 7){
        if (altmode != 1){
          altmode = 1;
        }else{
          altmode = 0;
        }
      }
    }
    else if (Command == STROBE){
      //color fade
      ledmode = 2;
      previousMillis = 0;

      if (Repeatcount == 7){
        if (altmode != 1){
          altmode = 1;
        }else{
          altmode = 0;
        }
      }
    }
    else if (Command == FADE){
      //COLOR change
      ledmode = 3;
      previousMillis = 0;

      if (Repeatcount == 7){
        if (altmode != 1){
          altmode = 1;
        }else{
          altmode = 0;
        }
      }
    }
    else if (Command == SMOOTH){
      //JUST ON
      ledmode = 4;
      previousMillis = 0;

      if (Repeatcount == 7){
        if (altmode != 1){
          altmode = 1;
        }else{
          altmode = 0;
        }
      }
    }
    else if (Command == UP){
      Serial.println("up");
      if (led_brightness < 255) led_brightness = led_brightness + 10;
      pixels.setBrightness(led_brightness);
    }
    else if (Command == DOWN){
      Serial.println("down");
      if (led_brightness > 5) led_brightness = led_brightness - 10;
      pixels.setBrightness(led_brightness);
    }
    else if (Command == RED0){
      color_pick = 0;
      color_picker();
    }
    else if (Command == RED1){
      color_pick = 1;
      color_picker();
    }
    else if (Command == RED2){
      color_pick = 2;
      color_picker();
    }
    else if (Command == RED3){
      color_pick = 3;
      color_picker();
    }
    else if (Command == RED4){
      color_pick = 4;
      color_picker();
    }
    else if (Command == GREEN0){
      color_pick = 5;
      color_picker();
    }
    else if (Command == GREEN1){
      color_pick = 6;
      color_picker();
    }
    else if (Command == GREEN2){
      color_pick = 7;
      color_picker();
    }
    else if (Command == GREEN3){
      color_pick = 8;
      color_picker();
    }
    else if (Command == GREEN4){
      color_pick = 9;
      color_picker();
    }
    else if (Command == BLUE0){
      color_pick = 10;
      color_picker();
    }
    else if (Command == BLUE1){
      color_pick = 11;
      color_picker();
    }
    else if (Command == BLUE2){
      color_pick = 12;
      color_picker();
    }
    else if (Command == BLUE3){
      color_pick = 13;
      color_picker();
    }
    else if (Command == BLUE4){
      color_pick = 14;
      color_picker();
    }
    else if (Command == WHITE0){
      //color_pick = 15;
      if (Repeatcount == 8){
        //Repeatcount = 0;
        if (color_pick == 15){
          color_pick = 16;
        }
      }else{
        color_pick = 15;
      }
      color_picker();
    }
    else {
      Serial.println("new");
    }
    

//  }
  //digitalWrite(LED_BUILTIN, LOW);
} //-------------------------------
//
//// just on mode
////flash = lightning mode / colors change background
////strobe = 
////fade = fade between colors / 
////smoooth = just on mode? (or music)
