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
5.	This device is made to connect to a university wireless network, but change the SSID and password to auto connect to your wireless network.
6.	For university application, make sure to register the device's MAC address so it could connect to the WiFi properly


On the google sheets end:
1.	Go in and edit the file used to connect to the excel sheet
2.	In google sheets, go to extensions, then app scripts
3.	grab the URL, ~https:/docs.google.com/spreadsheets/d/~ **xxxxxxxxxxxxxxxxxxxxxxxxxxxx** ~/edit?gid=0#gid=0~, and add it to the app script code
  	(X portion which is the sheet ID)
5. Press deployment, make sure to allow access for everyone (which allows device to communicate with the google sheets), and copy the deployment ID
6.	From there, use the deplayment ID and add it onto the string GAS_ID located on the arduino code (make sure to include the " " ; for it to be a string!)
7.	For the string GAS_ID on arduino code, replace the **“xxxxxxxxxxxxxxxxxxxxxxx”** with the proper link to google sheets deployment
8.	Label the columns!

You are done!

Here are some fun facts:
1. Even at a collection rate of 5 seconds, a year's worth of data is about ~0.1 GB
2. Data can be collected at up to 10 Hz

