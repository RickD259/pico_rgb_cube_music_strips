// diff fire colors
// new vu bg
//--remote codes--
#define ADDR    0xEF00
#define ON      0x3
#define OFF     0x2
#define UP      0x0
#define DOWN    0x1
#define FLASH   0xB
#define STROBE  0xF
#define FADE    0x13
#define SMOOTH  0x17

#define RED0     0x4
#define GREEN0   0x5
#define BLUE0    0x6
#define WHITE0   0x7

#define RED1      0x8
#define GREEN1    0x9
#define BLUE1     0xA

#define RED2      0xC
#define GREEN2    0xD
#define BLUE2     0xE

#define RED3      0x10
#define GREEN3    0x11
#define BLUE3     0x12

#define RED4      0x14
#define GREEN4    0x15
#define BLUE4     0x16

//------ir stuff----------
#include <Arduino.h>

//Set sensible receive pin for different CPU's
#define IR_INPUT_PIN    22
#define NO_LED_FEEDBACK_CODE // activating saves 14 bytes program space
//#define DEBUG // to see if attachInterrupt is used
//#define TRACE // to see the state of the ISR state machine

//Second: include the code and compile it.
#include "TinyIRReceiver.hpp"

//Helper macro for getting a macro definition as string
#if !defined(STR_HELPER)
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#endif

volatile struct TinyIRReceiverCallbackDataStruct sCallbackData;
//-----end ir stuff----------

//----------------neopixel stuff----------
#include <Adafruit_NeoPixel.h>

#define LED_PIN   17 
#define NUMPIXELS 40 // 40 for mini tower. How many NeoPixels are attached to the Arduino?

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int pixel_number =0 ;
bool dir = false;
byte counter = 0;
int neo_green = 0; //neo pixel stuff
int neo_red = 0; //neo pixel stuff
int neo_blue = 110; //neo pixel stuff

//---------------end neopixel--------------

#define analogInPin1 26
#define analogInPin2 27
#define button_pin   16

const uint32_t RED =        0XFF0000; //PRIMARY
const uint32_t ROSE =       0xFF0064;
const uint32_t MAGENTA =    0XFF00FF; //SECONDARY
const uint32_t VIOLET =     0x6400FF;
const uint32_t BLUE =       0X0000FF; //PRIMARY
const uint32_t AZURE =      0X0064FF;
const uint32_t CYAN =       0X00FFFF; //SECONDARY
const uint32_t AQUAMARINE = 0X00FF64;
const uint32_t GREEN =      0X00FF00; //PRIMARY
const uint32_t CHARTREUSE = 0x64FF00;
const uint32_t YELLOW =     0XFFFF00; //SECONDARY
const uint32_t ORANGE =     0xFF6400;

const uint32_t WHITE =      0XFFFFFF;
const uint32_t WHITERGB =   0X00FFFFFF;
const uint32_t WHITEALL =   0XFFFFFFFF;




//uint32_t color = RED;
uint32_t color_1 = RED;
int color_pick;
int led_brightness = 85;
int ledhue = 5000; 
int ledState = LOW;
int tempslowdown = 2000;
int steps = 0;
//int counter = 0;
int Repeatcount = 0;

//button stuff
//int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
byte ledmode = 4;
byte musicmode = 0;
byte altmode = 0;

unsigned long previousMillis = 0;

unsigned long drainMillis = 0;
unsigned long chargeMillis = 0; 
unsigned long musicMillis = 0; 

//int fht_input[128];

int sigMax = 0;
int sigMin = 1024;
int lowpeaktopeak = 0;
int sm_peaktopeak = 0;
int peaktopeak_raw = 0;
int low_input;
//---
int volume1;
int sigMax1 = 0;
int sigMin1 = 1024;
int peaktopeak1 = 0;
int sm_peaktopeak1 = 0;
int mic_input1;
//---

int mapmax=140;
int gaincounter=0;
int gain_level=60;

//analog input stuff
//unsigned int low_input = 0;        // value read from the pot
unsigned int high_input = 0;        // value read from the pot
unsigned int low_value = 0;        // 
unsigned int high_value = 0;        // 
unsigned int low_smooth_value = 0;
unsigned int low_med_smooth_value = 0;
unsigned int capacitor1 = 0;
unsigned int capacitor2 = 0;

unsigned long smoothMillis = 0;
unsigned long highsmoothMillis = 0;
//-----

unsigned long printMillis = 0;

void setup() {
//  initPCIInterruptForTinyReceiver(); //IR stuff
  pinMode(button_pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  // put your setup code here, to run once:
  //Serial.begin(115200); // use the serial port
  pixels.setBrightness(led_brightness); 


}

void setup1() {
  initPCIInterruptForTinyReceiver(); //IR stuff

}

void loop1() {
  if (sCallbackData.justWritten){
      sCallbackData.justWritten = false;
      Serial.print(F("Address=0x"));
      Serial.print(sCallbackData.Address, HEX);
      Serial.print(F(" Command=0x"));
      Serial.print(sCallbackData.Command, HEX);
      if (sCallbackData.isRepeat){
        Serial.print(F(" Repeat"));
        Repeatcount++;
      } else {
        Repeatcount = 0;
      }
      Serial.println();
      //if (sCallbackData.Address==ADDR) {
        rp2040.fifo.push_nb(sCallbackData.Command);
      //check_ir();  
      //}  
  }
}

void loop() {
  // dual core stuff
  if (rp2040.fifo.available() > 0){
    uint32_t b = rp2040.fifo.pop();
    Serial.print("remote ");
    Serial.println(b);
    check_ir(b);
  }

  
  check_button();

  check_analog();
  

//  if (millis() - printMillis >= 200) {
//    printMillis = millis();
//    
//    Serial.print(low_input);
//    Serial.print("  ");
//    Serial.print(gain_level);
//    Serial.print("  ");
//    Serial.print(sigMax);
//    Serial.print("  ");
//    Serial.print(sigMin);
//    Serial.print("  ");
//    Serial.print(peaktopeak_raw);
//    Serial.print("  ");
//    Serial.print(lowpeaktopeak);
//    Serial.print("  ");
//    Serial.println(sm_peaktopeak);
//  }


  switch (ledmode+musicmode){
    case 0:
    //off
      singlecolor(0X000000);
      break;

    case 1:
      if (altmode == 0){    
        crossFade();
      }else{
        rnd_blink(10);
      }
      break;
      
    case 2:
      if (altmode == 0){    
        strobe_mode(1000);
      }else{
        strobe_mode(100);
      }
      break;

    case 3:
      if (altmode == 0){     
        colorchange(4); 
      }else{
        rnd_blink(20);
      }         
      break;

    case 4:
      if (altmode == 0){     
        singlecolor(color_1); 
      }else{
        Fire(50,200,35);
      }        
      break;
      //--music modes--
    case 8:
    //off
      singlecolor(0X000000); 
      break;
      
    case 9:
      if (altmode == 0){     
        no_fade_ledmode(lowpeaktopeak);   
      }else{
        vu_mode_bg(sm_peaktopeak);
      }   
      break;

    case 10:
      //fade_ledmode(lowpeaktopeak);
      if (altmode == 0){ 
        vu_mode(sm_peaktopeak);
      }else{
        dual_vu_mode(sm_peaktopeak);
      }
      break;
      
    case 11:
      if (altmode == 0){
        musicfade(sm_peaktopeak);
      }else{ 
        dual_vu_mode_bg(sm_peaktopeak);
      } 
      break;
      
    case 12:
      if (altmode == 0){
        musicfade_onecolor(sm_peaktopeak);  
      }else{
        vu_mode_onecolor(sm_peaktopeak);
      }    
      break;

  
  }

//    if (ledmode == 0) singlecolor(0X000000);
//    if (ledmode == 1) crossFade();
//    if (ledmode == 2) strobe_mode(1000);
//    if (ledmode == 3) colorchange(4);    
//    if (ledmode == 4) singlecolor(color_1);
//    //plus 8 for music modes
//    if (ledmode == 9) no_fade_ledmode(sm_peaktopeak);
//    if (ledmode == 10) fade_ledmode(lowpeaktopeak);
//    if (ledmode == 11) fade_ledmode(sm_peaktopeak);
//    if (ledmode == 12) fadeone_ledmode(sm_peaktopeak);
//    //if (ledmode == 13) test_music(sm_peaktopeak);
//    if (ledmode >= 13) ledmode = 0;

} // end void

/*
 * This is the function is called if a complete command was received
 * It runs in an ISR context with interrupts enabled, so functions like delay() etc. are working here
 */
void handleReceivedTinyIRData(uint16_t aAddress, uint8_t aCommand, bool isRepeat){

    sCallbackData.Address = aAddress;
    sCallbackData.Command = aCommand;
    sCallbackData.isRepeat = isRepeat;
    sCallbackData.justWritten = true;

}
