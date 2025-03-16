void check_analog(){
  low_input = analogRead(26);


  if (low_input > sigMax) {
    sigMax = low_input;
  }
  
  if (low_input < sigMin){
    sigMin = low_input;
  }

  sigMax = sigMax - 1;
  sigMin = sigMin + 1;

  lowpeaktopeak = sigMax - sigMin;
  peaktopeak_raw = sigMax - sigMin; //peaktopeak_raw used in auto gain
  if (lowpeaktopeak < 6) lowpeaktopeak = 0;  // remove low noise
  
  //do a running average of peaktopeak?

  auto_gain();

  // map it to the range of the analog out:
//    peaktopeak1 = map(peaktopeak1, 0, 100, 0, 255);    // change sensorValue (0 to 1023) to outputValue (0 to 255)
//    peaktopeak1 = constrain(peaktopeak1, 0, 255); // needed to keep motor pwm between 0 and 255 due to throttle_min/max
//
//
//  //high freq smoothing
//  if (peaktopeak1 > sm_peaktopeak1){
//    sm_peaktopeak1 = peaktopeak1;
//  }else{
//    sm_peaktopeak1 = sm_peaktopeak1 - 3;
//    if (sm_peaktopeak1 < 5) sm_peaktopeak1 = 0;
//  }
//  if (peaktopeak1 < 5) peaktopeak1 = 0;

  //-------------------------

 
//  if (peaktopeak > mapmax-50) {
//    analogWrite(6, peaktopeak);
//  } else{
//    analogWrite(6, 0);
//  }

  // map it to the range of the analog out:
    lowpeaktopeak = map(lowpeaktopeak, 0, mapmax, 0, 255);    // change sensorValue (0 to 1023) to outputValue (0 to 255)
    lowpeaktopeak = constrain(lowpeaktopeak, 0, 255); // needed to keep motor pwm between 0 and 255 due to throttle_min/max


  //low freq smoothing
  if (lowpeaktopeak > sm_peaktopeak){
    sm_peaktopeak = lowpeaktopeak;
  }else{
    if (millis() - smoothMillis >= 2) {
      smoothMillis = millis();
      sm_peaktopeak = sm_peaktopeak - 2;
      if (sm_peaktopeak < 10) sm_peaktopeak = 0;
    }
  }

//  if (sm_peaktopeak > 1){  //to zero negative values
//    analogWrite(3, sm_peaktopeak);
//  }else{
//    analogWrite(3, 0);
//  }

 

  if (sm_peaktopeak > 230){
     digitalWrite(LED_BUILTIN, HIGH);
  }else{
     digitalWrite(LED_BUILTIN, LOW);
  }

}
