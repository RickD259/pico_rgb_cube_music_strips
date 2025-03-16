void auto_gain() {


  //alt option
  if (peaktopeak_raw > gain_level){
    if (millis() - chargeMillis > 5){
      if (gain_level < 750) gain_level = gain_level + 1;
      chargeMillis = millis();
    }
  }else{
    if (millis() - drainMillis > 1000){  //was 3000
      gain_level = gain_level - 1;
      if (gain_level < 60) gain_level = 60; // minimum level to stay at
      drainMillis = millis();
    }
  }


  mapmax = gain_level;
  
  
}
