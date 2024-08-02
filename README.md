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
2.	connect the deive to comm (in this case its comm4)
![WhatsApp Image 2024-08-02 at 12 06 38_576728f1](https://github.com/user-attachments/assets/e3873494-78b5-410d-878f-b5280c679fea)

3.	Add libraries:
   ```
Wire.h
Adafruit_Sensor.h
Adafruit_BME680.h
ESP8266WiFi.h
ESP8266HTTPClient.h
ESP8266WiFi.h
WiFiClientSecure.h
```
this is done on the left hand side under library manager (third icon down)
![WhatsApp Image 2024-08-02 at 12 06 58_2e432e32](https://github.com/user-attachments/assets/92f0d9d1-0f62-4486-9241-c4761cfafb49)


4.	Use code “envdev.ino” as your base code for the device
5.	This device is made to connect to a university wireless network, but change the SSID and password to auto connect to your wireless network.
6.	For university application, make sure to register the device's MAC address so it could connect to the WiFi properly
   this is done in https://uarizona.service-now.com/sp?id=sc_cat_item&sys_id=61ecd86a1b1970107947edf1604bcb13
   ![image](https://github.com/user-attachments/assets/73b56c6d-d35e-4fd1-a94f-c14b3e856aa0)

**This needs to be completed every 6 months to allow the ESP8266 to it to connect to UAGuest wifi**




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

