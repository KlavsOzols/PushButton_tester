
//============
//Webpage Code
//============
const char webpageCode[] PROGMEM = 
R"=====(
<!DOCTYPE html>
<head>
  <title> ESP32 Web Server </title>
</head>
<html>
<!----------------------------CSS---------------------------->
<style>
  body
  {
    background-color: rgba(128, 128, 128, 0.884)
  }
  h4 
  {
    font-family: arial;
    text-align: center;
    color: white;
  }
  .card
  {
     max-width: 900px;
     min-height: 30px;
     background: rgba(255, 255, 255, 0.521);
     padding: 10px;
     font-weight: bold;
     font: 20px calibri;
     text-align: center;
     box-sizing: border-box;
     color: blue;
     margin:20px;
     box-shadow: 0px 2px 15px 15px rgba(0,0,0,0.75);
  }


</style>

<style type="text/css">
  table          {border:ridge 5px black;}
  table td       {border:inset 1px #000;}
  table tr#ROW1  {     max-width: 900px;
     min-height: 50px;
     background: rgba(255, 255, 255, 0.521);
     padding: 10px;
     font-weight: bold;
     font: 22px calibri;
     text-align: center;
     box-sizing: border-box;
     color: blue;
     margin:20px;}
  </style>



<!----------------------------HTML--------------------------->
<body>
  <div class="card">
    <h1><span style="background-color:light grey">Button Cilck times counter server</span></h1>
  </div>
  
   <table border="1" 
          align="left">
  
        <tr id="ROW1">
            <th> Source </th>
            <th> Total times </th>
            <th> Missed times </th>
            <th> First missed </th>
            <th> Last missed </th>
        </tr>
        <tr id="ROW1">
            <td>Button 1</td>
            <td><h2><span style="color:black" id="btncntrlvalue1">0</span></h2></td>
            <td><h2><span style="color:black" id="BTNMSSDTMSvalue1">0</span></h2></td>
            <td><h2><span style="color:black" id="FRSTMSSDvalue1">0</span></h2></td>
            <td><h2><span style="color:black" id="LSTMSSDvalue1">0</span></h2></td>
        </tr>
        <tr id="ROW1">
            <td>Button 2</td>
            <td><h2><span style="color:black" id="BTNCNTRvalue2">0</span></h2></td>
            <td><h2><span style="color:black" id="BTNMSSDTMSvalue2">0</span></h2></td>
            <td><h2><span style="color:black" id="FRSTMSSDvalue2">0</span></h2></td>
            <td><h2><span style="color:black" id="LSTMSSDvalue2">0</span></h2></td>
        </tr>
        <tr id="ROW1">
            <td>Button 3</td>
            <td><h2><span style="color:black" id="BTNCNTRvalue3">0</span></h2></td>
            <td><h2><span style="color:black" id="BTNMSSDTMSvalue3">0</span></h2></td>
            <td><h2><span style="color:black" id="FRSTMSSDvalue3">0</span></h2></td>
            <td><h2><span style="color:black" id="LSTMSSDvalue3">0</span></h2></td>
        </tr>
        <tr id="ROW1">
            <td>Button 4</td>
            <td><h2><span style="color:black" id="BTNCNTRvalue4">0</span></h2></td>
            <td><h2><span style="color:black" id="BTNMSSDTMSvalue4">0</span></h2></td>
            <td><h2><span style="color:black" id="FRSTMSSDvalue4">0</span></h2></td>
            <td><h2><span style="color:black" id="LSTMSSDvalue4">0</span></h2></td>
        </tr>
        <tr id="ROW1">
            <td>Button 5</td>
            <td><h2><span style="color:black" id="BTNCNTRvalue5">0</span></h2></td>
            <td><h2><span style="color:black" id="BTNMSSDTMSvalue5">0</span></h2></td>
            <td><h2><span style="color:black" id="FRSTMSSDvalue5">0</span></h2></td>
            <td><h2><span style="color:black" id="LSTMSSDvalue5">0</span></h2></td>
        </tr>
        <tr id="ROW1">
            <td>Button 6</td>
            <td><h2><span style="color:black" id="BTNCNTRvalue6">0</span></h2></td>
            <td><h2><span style="color:black" id="BTNMSSDTMSvalue6">0</span></h2></td>
            <td><h2><span style="color:black" id="FRSTMSSDvalue6">0</span></h2></td>
            <td><h2><span style="color:black" id="LSTMSSDvalue6">0</span></h2></td>
        </tr>
        <tr id="ROW1">
            <td>Button 7</td>
            <td><h2><span style="color:black" id="BTNCNTRvalue7">0</span></h2></td>
            <td><h2><span style="color:black" id="BTNMSSDTMSvalue7">0</span></h2></td>
            <td><h2><span style="color:black" id="FRSTMSSDvalue7">0</span></h2></td>
            <td><h2><span style="color:black" id="LSTMSSDvalue7">0</span></h2></td>
        </tr>
        <tr id="ROW1">
            <td>Light Gate</td>
            <td><h2><span style="color:black" id="OPTCSNSRvalue">0</span></h2></td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
        </tr>
    </table>
    
  <h4>
    <button onclick="help()">Help</button><br><br>
    <div id="myDIV"> </div>
  </h4>


</body>
 
  
<!-------------------------JavaScrip------------------------->
<script>
  InitWebSocket()
  function InitWebSocket()
  {
    websock = new WebSocket('ws://'+window.location.hostname+':81/');
    websock.onmessage=function(evt)
    {
       JSONobj = JSON.parse(evt.data);
       document.getElementById('btncntrlvalue1').innerHTML = JSONobj.BTNCNTR1;
       var pot1 = parseInt(JSONobj.BTNCNTR1);
       document.getElementById('LSTMSSDvalue1').innerHTML = JSONobj.LSTMSSDval1;
       var pot2 = parseInt(JSONobj.LSTMSSDval1);
       document.getElementById('FRSTMSSDvalue1').innerHTML = JSONobj.FRSTMSSDval1;
       var pot3 = parseInt(JSONobj.FRSTMSSDval1);
       document.getElementById('BTNMSSDTMSvalue1').innerHTML = JSONobj.BTNMSSDTMSval1;
       var pot4 = parseInt(JSONobj.BTNMSSDTMSval1);
       document.getElementById('BTNCNTRvalue2').innerHTML = JSONobj.BTNCNTR2;
       var pot5 = parseInt(JSONobj.BTNCNTR2);
       document.getElementById('LSTMSSDvalue2').innerHTML = JSONobj.LSTMSSDval2;
       var pot6 = parseInt(JSONobj.LSTMSSDval2);
       document.getElementById('FRSTMSSDvalue2').innerHTML = JSONobj.FRSTMSSDval2;
       var pot7 = parseInt(JSONobj.FRSTMSSDval2);
       document.getElementById('BTNMSSDTMSvalue2').innerHTML = JSONobj.BTNMSSDTMSval2;
       var pot8 = parseInt(JSONobj.BTNMSSDTMSval2);
       document.getElementById('BTNCNTRvalue3').innerHTML = JSONobj.BTNCNTR3;
       var pot9 = parseInt(JSONobj.BTNCNTR3);
       document.getElementById('LSTMSSDvalue3').innerHTML = JSONobj.LSTMSSDval3;
       var pot10 = parseInt(JSONobj.LSTMSSDval3);
       document.getElementById('FRSTMSSDvalue3').innerHTML = JSONobj.FRSTMSSDval3;
       var pot11 = parseInt(JSONobj.FRSTMSSDval3);
       document.getElementById('BTNMSSDTMSvalue3').innerHTML = JSONobj.BTNMSSDTMSval3;
       var pot12 = parseInt(JSONobj.BTNMSSDTMSval3); 
       document.getElementById('BTNCNTRvalue4').innerHTML = JSONobj.BTNCNTR4;
       var pot13 = parseInt(JSONobj.BTNCNTR4);
       document.getElementById('LSTMSSDvalue4').innerHTML = JSONobj.LSTMSSDval4;
       var pot14 = parseInt(JSONobj.LSTMSSDval4);
       document.getElementById('FRSTMSSDvalue4').innerHTML = JSONobj.FRSTMSSDval4;
       var pot15 = parseInt(JSONobj.FRSTMSSDval4);
       document.getElementById('BTNMSSDTMSvalue4').innerHTML = JSONobj.BTNMSSDTMSval4;
       var pot16 = parseInt(JSONobj.BTNMSSDTMSval4);
       document.getElementById('BTNCNTRvalue5').innerHTML = JSONobj.BTNCNTR5;
       var pot17 = parseInt(JSONobj.BTNCNTR5);
       document.getElementById('LSTMSSDvalue5').innerHTML = JSONobj.LSTMSSDval5;
       var pot18 = parseInt(JSONobj.LSTMSSDval5);
       document.getElementById('FRSTMSSDvalue5').innerHTML = JSONobj.FRSTMSSDval5;
       var pot19 = parseInt(JSONobj.FRSTMSSDval5);
       document.getElementById('BTNMSSDTMSvalue5').innerHTML = JSONobj.BTNMSSDTMSval5;
       var pot20 = parseInt(JSONobj.BTNMSSDTMSval5);
       document.getElementById('BTNCNTRvalue6').innerHTML = JSONobj.BTNCNTR6;
       var pot21 = parseInt(JSONobj.BTNCNTR6);
       document.getElementById('LSTMSSDvalue6').innerHTML = JSONobj.LSTMSSDval6;
       var pot22 = parseInt(JSONobj.LSTMSSDval6);
       document.getElementById('FRSTMSSDvalue6').innerHTML = JSONobj.FRSTMSSDval6;
       var pot23 = parseInt(JSONobj.FRSTMSSDval6);
       document.getElementById('BTNMSSDTMSvalue6').innerHTML = JSONobj.BTNMSSDTMSval6;
       var pot24 = parseInt(JSONobj.BTNMSSDTMSval6);
       document.getElementById('BTNCNTRvalue7').innerHTML = JSONobj.BTNCNTR7;
       var pot25 = parseInt(JSONobj.BTNCNTR7);
       document.getElementById('LSTMSSDvalue7').innerHTML = JSONobj.LSTMSSDval7;
       var pot26 = parseInt(JSONobj.LSTMSSDval7);
       document.getElementById('FRSTMSSDvalue7').innerHTML = JSONobj.FRSTMSSDval7;
       var pot27 = parseInt(JSONobj.FRSTMSSDval7);
       document.getElementById('BTNMSSDTMSvalue7').innerHTML = JSONobj.BTNMSSDTMSval7;
       var pot28 = parseInt(JSONobj.BTNMSSDTMSval7);
       document.getElementById('OPTCSNSRvalue').innerHTML = JSONobj.OPTCSNSRval;
       var pot29 = parseInt(JSONobj.OPTCSNSRval);
       
    }
  }
    
    //-------------------------------------------------------
    function help()
    {
      var x = document.getElementById("myDIV");
      var message = " This test program was made by Klavs - Reinis Ozols. Please contact him and bring some chocolate :) ";
      if (x.innerHTML == "") x.innerHTML = message;
      else x.innerHTML = "";
    }
  </script>
</body>
</html>
)=====";
