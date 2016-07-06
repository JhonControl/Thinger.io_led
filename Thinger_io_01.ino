/*
*
*
* Modified by PDAControl 
* PDAControl English          http://pdacontrolenglish.blogspot.com.co/   
* Blog PDAControl Español     http://pdacontrol.blogspot.com.co/
* https://www.youtube.com/c/JhonValenciaPDAcontrol/videos    
*/



#include <ESP8266WiFi.h>
#include <ThingerWifi.h>


#define USERNAME "**************"
#define DEVICE_ID "**************"
#define DEVICE_CREDENTIAL "*********"

#define SSID "***********"
#define SSID_PASSWORD "***************"

ThingerWifi thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(2, OUTPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << digitalPin(2);

  // resource output example (i.e. reading a sensor value)
  thing["millis"] >> outputValue(millis());

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}
