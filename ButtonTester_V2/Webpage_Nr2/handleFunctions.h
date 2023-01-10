
//=============================================
//Handle functions executed upon client request
//=============================================
unsigned long BTNCNTRval1 = 0, BTNCNTRval2 = 0, BTNCNTRval3 = 0, BTNCNTRval4 = 0, BTNCNTRval5 = 0, BTNCNTRval6 = 0, BTNCNTRval7 = 0;   
unsigned long FRSTMSSDval1 = 0, FRSTMSSDval2 = 0,FRSTMSSDval3 = 0, FRSTMSSDval4 = 0, FRSTMSSDval5 = 0, FRSTMSSDval6 = 0, FRSTMSSDval7 = 0;    
unsigned long LSTMSSDval1 = 0, LSTMSSDval2 = 0, LSTMSSDval3 = 0, LSTMSSDval4 = 0, LSTMSSDval5 = 0, LSTMSSDval6 = 0, LSTMSSDval7 = 0;
unsigned long BTNMSSDTMSval1 = 0, BTNMSSDTMSval2 = 0, BTNMSSDTMSval3 = 0, BTNMSSDTMSval4 = 0, BTNMSSDTMSval5 = 0, BTNMSSDTMSval6 = 0, BTNMSSDTMSval7 = 0;   
bool prestate = 0, prestate2 = 0, prestate3 = 0, prestate4 = 0, prestate5 = 0, prestate6 = 0, prestate7 = 0;
bool firstmissedtime1 = 0, firstmissedtime2 = 0, firstmissedtime3 = 0, firstmissedtime4 = 0, firstmissedtime5 = 0, firstmissedtime6 = 0, firstmissedtime7 = 0;
unsigned long BTNCNTRval1check = 0, BTNCNTRval1check2 = 0; 
unsigned long OPTCSNSRval = 0;
unsigned long TimesCNTR = 0;
String OPTCSNSRvalString;
String BTNCNTRval1String,LSTMSSDval1String,FRSTMSSDval1String,BTNMSSDTMSval1String;
String BTNCNTRval2String,LSTMSSDval2String,FRSTMSSDval2String,BTNMSSDTMSval2String;
String BTNCNTRval3String,LSTMSSDval3String,FRSTMSSDval3String,BTNMSSDTMSval3String;
String BTNCNTRval4String,LSTMSSDval4String,FRSTMSSDval4String,BTNMSSDTMSval4String;
String BTNCNTRval5String,LSTMSSDval5String,FRSTMSSDval5String,BTNMSSDTMSval5String;
String BTNCNTRval6String,LSTMSSDval6String,FRSTMSSDval6String,BTNMSSDTMSval6String;
String BTNCNTRval7String,LSTMSSDval7String,FRSTMSSDval7String,BTNMSSDTMSval7String;

String dataMessage;

void handleRoot()
{
 server.send(200, "text/html", webpageCode);
}
//---------------------------------------




// Write to the SD card (DON'T MODIFY THIS FUNCTION)
void writeFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if(!file) {
    Serial.println("Failed to open file for writing");
    return;
  }
  if(file.print(message)) {
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
  file.close();
}

// Append data to the SD card (DON'T MODIFY THIS FUNCTION)
void appendFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Appending to file: %s\n", path);
  File file = fs.open(path, FILE_APPEND);
  if(!file) {
    Serial.println("Failed to open file for appending");
    return;
  }
  if(file.print(message)) {
    Serial.println("Message appended");
  } else {
    Serial.println("Append failed");
  }
  file.close();
}

void logSDcardLegend()
{
    dataMessageLegend = String("Nr.p.k.") + "," + String("BTNCNTR1") + "," + String("LSTMSSDval1") + "," + String("FRSTMSSDval1") + "," + String("BTNMSSDTMSval1")
  + "," + String("BTNCNTR2") + "," + String("LSTMSSDval2") + "," + String("FRSTMSSDval2") + "," + String("BTNMSSDTMSval2") + "," 
  + String("BTNCNTR3") + "," + String("LSTMSSDval3") + "," + String("FRSTMSSDval3") + "," + String("BTNMSSDTMSval3") + "," 
  + String("BTNCNTR4") + "," + String("LSTMSSDval4") + "," + String("FRSTMSSDval4") + "," + String("BTNMSSDTMSval4") + "," 
  + String("BTNCNTR5") + "," + String("LSTMSSDval5") + "," + String("FRSTMSSDval5") + "," + String("BTNMSSDTMSval5") + ","
  + String("BTNCNTR6") + "," + String("LSTMSSDval6") + "," + String("FRSTMSSDval6") + "," + String("BTNMSSDTMSval6") + "," 
  + String("BTNCNTR7") + "," + String("LSTMSSDval7") + "," + String("FRSTMSSDval7") + "," + String("BTNMSSDTMSval7") + ","
  + String("OPTCSNSRval") + "," + "\r\n";   
  appendFile(SD, "/data.txt", dataMessageLegend.c_str());
}

void logSDCard() 
{
    dataMessage =   String(TimesCNTR) + "," + BTNCNTRval1String + "," + LSTMSSDval1String + "," + FRSTMSSDval1String + "," + BTNMSSDTMSval1String
  + "," + BTNCNTRval2String + "," + LSTMSSDval2String + "," + FRSTMSSDval2String + "," + BTNMSSDTMSval2String + "," 
  + BTNCNTRval3String + "," + LSTMSSDval3String + "," + FRSTMSSDval3String + "," + BTNMSSDTMSval3String + "," 
  + BTNCNTRval4String + "," + LSTMSSDval4String + "," + FRSTMSSDval4String + "," + BTNMSSDTMSval4String + "," 
  + BTNCNTRval5String + "," + LSTMSSDval5String + "," + FRSTMSSDval5String + "," + BTNMSSDTMSval5String + ","
  + BTNCNTRval6String + "," + LSTMSSDval6String + "," + FRSTMSSDval6String + "," + BTNMSSDTMSval6String + "," 
  + BTNCNTRval7String + "," + LSTMSSDval7String + "," + FRSTMSSDval7String + "," + BTNMSSDTMSval7String + ","
  + OPTCSNSRvalString + "," + "\r\n";   
  appendFile(SD, "/data.txt", dataMessage.c_str());
  TimesCNTR++;
}

void time(uint32_t val)
{  
 uint32_t sec = val / 1000;
 seconds = (sec % 60);
 minutes = ((sec / 60) % 60);
 hours = (((sec / 60) / 60) % 24) ;
 days = (((sec / 60) / 60) / 24);
}

void checkButtons()
{
  //btnState
  uint16_t tmp;
  for(int x = 0; x < BUTTON_COUNT; x++)
  {
    tmp = digitalRead(btnPins[x]);
      if (tmp != lastButtonState[x])
      {
        lastDebounceTime[x] = millis();
      }
  
      if ((millis() - lastDebounceTime[x]) > debounceDelay) 
      {
        if(tmp != btnState[x])
        {
          btnState[x] = tmp;
          if( btnState[x] == 1 )
          {
            btnPressLast[x]++;
          }
        } 
      }
    lastButtonState[x] = tmp;
  }
    
}

//brief
// check if buttons missed any clicks
// add counters to total counters, reset temporary counters
void processButtons(){
  if(btnRefPressTotal == 0){
    return;
  }
  
  for(int x = 0; x < BUTTON_COUNT; x++){
    if(btnPressLast[x] == 0){ // check if missed click
      if(btnMissFirst[x] == 0){
        btnMissLast[x] = btnRefPressTotal; //Set when first time missed
        btnMissFirst[x] = btnRefPressTotal;   // set when first time missed
      }
      btnMissLast[x] = btnRefPressTotal; //Set when last time missed
      lastMissedButton = x; // set global last missed button
      btnMissTotal[x]++;    // set total amount of missed clicks for this button
    }else{
      btnPressTotal[x] += btnPressLast[x]; // add current clicks to total clicks
      btnPressLast[x] = 0;  // reset current clicks
    }
  }
}

void StringConversion()
{
  OPTCSNSRvalString = String(btnRefPressTotal);
  
  BTNCNTRval1String = String(btnPressTotal[0]);
  FRSTMSSDval1String = String(btnMissFirst[0]);
  BTNMSSDTMSval1String = String(btnMissTotal[0]);
  LSTMSSDval1String = String(btnMissLast[0]);
  
  BTNCNTRval2String = String(btnPressTotal[1]);
  FRSTMSSDval2String = String(btnMissFirst[1]);
  BTNMSSDTMSval2String = String(btnMissTotal[1]);
  LSTMSSDval2String = String(btnMissLast[1]);
  
  BTNCNTRval3String = String(btnPressTotal[2]);
  FRSTMSSDval3String = String(btnMissFirst[2]);
  BTNMSSDTMSval3String = String(btnMissTotal[2]);
  LSTMSSDval3String = String(btnMissLast[2]);
  
  BTNCNTRval4String = String(btnPressTotal[3]);
  FRSTMSSDval4String = String(btnMissFirst[3]);
  BTNMSSDTMSval4String = String(btnMissTotal[3]);
  LSTMSSDval4String = String(btnMissLast[3]);
  
  BTNCNTRval5String = String(btnPressTotal[4]);
  FRSTMSSDval5String = String(btnMissFirst[4]);
  BTNMSSDTMSval5String = String(btnMissTotal[4]);
  LSTMSSDval5String = String(btnMissLast[4]);
  
  BTNCNTRval6String = String(btnPressTotal[5]);
  FRSTMSSDval6String = String(btnMissFirst[5]);
  BTNMSSDTMSval6String = String(btnMissTotal[5]);
  LSTMSSDval6String = String(btnMissLast[5]);
  
  BTNCNTRval7String = String(btnPressTotal[6]);
  FRSTMSSDval7String = String(btnMissFirst[6]);
  BTNMSSDTMSval7String = String(btnMissTotal[6]);
  LSTMSSDval7String = String(btnMissLast[6]);
}

void JSONStringSend()
{

  JSONtxt  = "{\"BTNCNTR1\":\"" + BTNCNTRval1String + "\",";
  JSONtxt += "\"FRSTMSSDval1\":\"" + FRSTMSSDval1String + "\",";
  JSONtxt += "\"BTNMSSDTMSval1\":\"" + BTNMSSDTMSval1String + "\",";
  JSONtxt += "\"LSTMSSDval1\":\"" + LSTMSSDval1String + "\",";
  JSONtxt += "\"BTNCNTR2\":\"" + BTNCNTRval2String + "\",";
  JSONtxt += "\"FRSTMSSDval2\":\"" + FRSTMSSDval2String + "\",";
  JSONtxt += "\"BTNMSSDTMSval2\":\"" + BTNMSSDTMSval2String + "\",";
  JSONtxt += "\"LSTMSSDval2\":\"" + LSTMSSDval2String + "\",";
  JSONtxt += "\"BTNCNTR3\":\"" + BTNCNTRval3String + "\",";
  JSONtxt += "\"FRSTMSSDval3\":\"" + FRSTMSSDval3String + "\",";
  JSONtxt += "\"BTNMSSDTMSval3\":\"" + BTNMSSDTMSval3String + "\",";
  JSONtxt += "\"LSTMSSDval3\":\"" + LSTMSSDval3String + "\",";
  JSONtxt += "\"BTNCNTR4\":\"" + BTNCNTRval4String + "\",";
  JSONtxt += "\"FRSTMSSDval4\":\"" + FRSTMSSDval4String + "\",";
  JSONtxt += "\"BTNMSSDTMSval4\":\"" + BTNMSSDTMSval4String + "\",";
  JSONtxt += "\"LSTMSSDval4\":\"" + LSTMSSDval4String + "\",";
  JSONtxt += "\"BTNCNTR5\":\"" + BTNCNTRval5String + "\",";
  JSONtxt += "\"FRSTMSSDval5\":\"" + FRSTMSSDval5String + "\",";
  JSONtxt += "\"BTNMSSDTMSval5\":\"" + BTNMSSDTMSval5String + "\",";
  JSONtxt += "\"LSTMSSDval5\":\"" + LSTMSSDval5String + "\",";
  JSONtxt += "\"BTNCNTR6\":\"" + BTNCNTRval6String + "\",";
  JSONtxt += "\"FRSTMSSDval6\":\"" + FRSTMSSDval6String + "\",";
  JSONtxt += "\"BTNMSSDTMSval6\":\"" + BTNMSSDTMSval6String + "\",";
  JSONtxt += "\"LSTMSSDval6\":\"" + LSTMSSDval6String + "\",";
  JSONtxt += "\"BTNCNTR7\":\"" + BTNCNTRval7String + "\",";
  JSONtxt += "\"FRSTMSSDval7\":\"" + FRSTMSSDval7String + "\",";
  JSONtxt += "\"BTNMSSDTMSval7\":\"" + BTNMSSDTMSval7String + "\",";
  JSONtxt += "\"LSTMSSDval7\":\"" + LSTMSSDval7String + "\",";
  JSONtxt += "\"OPTCSNSRval\":\"" + OPTCSNSRvalString + "\"}";
   
  webSocket.broadcastTXT(JSONtxt);
  
}
