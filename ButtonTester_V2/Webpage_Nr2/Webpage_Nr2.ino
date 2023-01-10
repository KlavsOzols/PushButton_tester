//========================================================
//ESP32 Web Server: Reading Potentiometer Value using AJAX
//========================================================
#include <WiFi.h>
#include <WebServer.h>
#include <ezButton.h>
#include <WebSocketsServer.h>


#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include <Wire.h>

//---------------------------------------------------

WebServer server(80);

WebSocketsServer webSocket = WebSocketsServer(81);
const char* ssid = "AzeronHQ";
const char* password = "ZDUF5LQs";

String JSONtxt;
String dataMessageLegend;
unsigned long nextUpdate;
int count;

#define BUTTON_COUNT 7

uint8_t btnPins[BUTTON_COUNT] = {D2,D3,D4,D5,D9,D7,D8}; // button checks to press
const uint8_t lightGatePin = A2;  // used for button press reference

uint8_t btnState[BUTTON_COUNT];             // save individual button state
uint32_t btnPressLast[BUTTON_COUNT] = {0};  // save button presses since last reference
uint32_t btnPressTotal[BUTTON_COUNT] = {0}; // save total button presses
uint32_t btnMissTotal[BUTTON_COUNT] = {0};  // total times button missed clicks
uint32_t btnMissFirst[BUTTON_COUNT] = {0}; // save when first missed click happened
uint32_t btnMissLast[BUTTON_COUNT] = {0}; // save when Last missed click happened
uint32_t btnRefPressTotal = 0;                 // total reference button presses for comparing with actual buttons
int8_t lastMissedButton = -1;

uint32_t lightGateCount = 0;
uint16_t lightGateStatus = 0;
bool LightGateChecker = 0;

int buttonState;             // the current reading from the input pin
int lastButtonState[BUTTON_COUNT];   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime[BUTTON_COUNT] = {0};  // the last time the output pin was toggled
unsigned long debounceDelay = 25;    // the debounce time; increase if the output flickers

uint16_t days = 0;  
uint8_t hours = 0;
uint8_t minutes = 0;
uint8_t seconds = 0;

#include "webpage.h"
#include "handleFunctions.h"

void setup()
{
  Serial.begin(115200);
  memset(btnState, 1, 7);  // init all array to 1
  //pinMode(lightGatePin, INPUT);
    for(int x = 0; x < BUTTON_COUNT; x++)
  {
    pinMode(btnPins[x], INPUT_PULLUP);  // pull up all buttons
  }

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  //-------------------------------------------------

  server.on("/", handleRoot);
  server.begin();
  webSocket.begin();
  Serial.println("HTTP server started");

    if(!SD.begin())
    {
        Serial.println("Card Mount Failed");
        return;
    }
    uint8_t cardType = SD.cardType();
    logSDcardLegend();
    nextUpdate = millis() + 60000UL;
}

void loop()
{
  webSocket.loop();
  server.handleClient();
  
  lightGateStatus = analogRead(lightGatePin);
 // Serial.println( lightGateStatus); 
  if(LightGateChecker == 1 ){
    if(lightGateStatus < 1000){
      LightGateChecker = 0;
      processButtons();
      btnRefPressTotal++;
    }
  }else{

    if(lightGateStatus > 3500){
      LightGateChecker = 1;
    }
  }
  checkButtons();
  StringConversion();
  JSONStringSend();
  if (millis() >= nextUpdate)
  {
    logSDCard();
    nextUpdate = millis() + 60000UL;
  }
}
