void color_picker(){
//Serial.println(color_pick);

    if (color_pick == 0){ //RED
      color_1 = RED;
    }
    else if (color_pick == 1){
      color_1 = ROSE; 
    }
    else if (color_pick == 2){
      color_1 = 0xFF3200;
    }
    else if (color_pick == 3){
      //color_1 = 0xFFB400;
      color_1 = ORANGE;
    }
    else if (color_pick == 4){
      color_1 = YELLOW;
    }
    else if (color_pick == 5){ //GREEN
      color_1 = GREEN;
    }
    else if (color_pick == 6){
      color_1 = CHARTREUSE;
    }
    else if (color_pick == 7){
      color_1 = 0x00FF32;
    }
    else if (color_pick == 8){
      //color_1 = 0x00FFB4;
      color_1 = AQUAMARINE;
    }
    else if (color_pick == 9){
      color_1 = CYAN;
    }
    else if (color_pick == 10){ //BLUE
      color_1 = BLUE;
    }
    else if (color_pick == 11){
      color_1 = AZURE;
    }
    else if (color_pick == 12){
      color_1 = 0x3200FF;
    }
    else if (color_pick == 13){
      //color_1 = 0xB400FF;
      color_1 = VIOLET;
    }
    else if (color_pick == 14){
      color_1 = MAGENTA;
    }
    else if (color_pick == 15){ //WHITE
      color_1 = WHITE;
    }
    else if (color_pick == 16){ //WHITE
      color_1 = WHITEALL;
    }

  //convert 32 bit to byte
//  pwm_red = (color_1 >> 16) & 0xff;
//  pwm_green = (color_1 >> 8) & 0xff;
//  pwm_blue = color_1 & 0xff;

    
}
