# environmental_device
## environmental device that measures temperature, pressure and humidity

How to implement the environmental device :

Electronics: BME688 and ESP8266

Connect pins: 
```
ESP8266    BME688
V3   ->    Vin
GND  ->    GND
D1   ->    SCK
D2   ->    SDI
```

1.	Download Arduino IDE
2.	Add libraries:
   ```
Wire.h
Adafruit_Sensor.h
Adafruit_BME680.h
ESP8266WiFi.h
ESP8266HTTPClient.h
ESP8266WiFi.h
WiFiClientSecure.h
```
4.	Use code “envdev.ino” as your base code for the device
a.	This device is made to connect to a university wireless network, but change the SSID and password to auto connect to your wireless network.

On the google sheets end:
1.	Go in and edit the file used to connect to the excel sheet
2.	In google sheets, go to extensions, then app scripts
3.	From there, use the “google sheets code” and add it on there
a.	For the google ID, replace the ** “xxxxxxxxxxxxxxxxxxxxxxx” ** with the proper link to google sheets
4.	Label the columns! 
You are done!

