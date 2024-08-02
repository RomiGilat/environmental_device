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
![WhatsApp Image 2024-08-02 at 12 06 58_2e432e32](https://github.com/user-attachments/assets/92f0d9d1-0f62-4486-9241-c4761cfafb49)

This is done on the left hand side under library manager (third icon down)

4.	Use code “envdev.ino” as your base code for the device
5.	This device is made to connect to a university wireless network, but change the SSID and password to auto connect to your wireless network.
6.	For university application, make sure to register the device's MAC address so it could connect to the WiFi properly
   this is done in https://uarizona.service-now.com/sp?id=sc_cat_item&sys_id=61ecd86a1b1970107947edf1604bcb13
   ![image](https://github.com/user-attachments/assets/73b56c6d-d35e-4fd1-a94f-c14b3e856aa0)

**This needs to be completed every 6 months to allow the ESP8266 to it to connect to UAGuest wifi**




On the google sheets end:
1.	Create a google sheet.
2.	In google sheets, go to extensions, then app scripts
![image](https://github.com/user-attachments/assets/ee957fb9-7be5-4a08-a320-68289d0ab729)


3. Drop in code XXX
4.	grab the URL, ~https:/docs.google.com/spreadsheets/d/~ **xxxxxxxxxxxxxxxxxxxxxxxxxxxx** ~/edit?gid=0#gid=0~, and add it to the app script code
  	(X portion which is the sheet ID)
![image](https://github.com/user-attachments/assets/00c14c7d-93a4-43d2-8ded-05a7310086b8)
![image](https://github.com/user-attachments/assets/8d036412-1de7-43d6-858f-71aabcc260d9)

6. Press deploy, then new deployment.
7. Select "Web App" under the setting wheel
8. make sure to allow access for everyone (which allows device to communicate with the google sheets),

![image](https://github.com/user-attachments/assets/211266a7-6d3e-42f5-af01-7a21126fb7f4)

9. copy the deployment ID

![image](https://github.com/user-attachments/assets/07077af5-5420-4f11-bb87-231e2b94f4cf)

10.	From there, use the deployment ID and add it onto the string GAS_ID located on the arduino code (make sure to include the " " ; for it to be a string!)
11.	For the string GAS_ID on arduino code, replace the **“xxxxxxxxxxxxxxxxxxxxxxx”** with the proper link to google sheets deployment
![WhatsApp Image 2024-08-02 at 12 22 33_8c0e9d80](https://github.com/user-attachments/assets/759b48f1-1dc6-4b6b-9762-08321984366f)

12.   upload the file to the ESP8266 (the arrow on top left)
![WhatsApp Image 2024-08-02 at 12 23 50_7fac60d6](https://github.com/user-attachments/assets/5c32df10-2090-4c98-a2d6-c6e173ee36a9)

it should look something like this as its uploading
13.	Label the columns!

You are done!

Here are some fun facts:
1. Even at a collection rate of 5 seconds, a year's worth of data is about ~0.1 GB
2. Data can be collected at up to 10 Hz

