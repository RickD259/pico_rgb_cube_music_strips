void check_button() {
  int reading = digitalRead(button_pin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        //ledmode = ledmode + 1;
        if (musicmode != 8){
          musicmode = 8;
          gain_level = 60; //reset auto gain
        }else{
          musicmode = 0;
        }
        //new_ledmode_flag = HIGH;
      }
    }
  }

  // set the LED:
//  ledState = reading;
//  digitalWrite(13, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

  
}//========================================================================
