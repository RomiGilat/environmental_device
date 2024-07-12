#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#define ON_Board_LED 2  // On board LED, indicator when connecting to a wifi router

#define SEALEVELPRESSURE_HPA (1015)

Adafruit_BME680 bme; // Create an instance of the sensor

const char* ssid = "UAGuest";
const char* password = "your_PASSWORD"; // there is no p


//----------------------------------------Host & httpsPort
const char* host = "script.google.com";
const int httpsPort = 443;
//----------------------------------------

WiFiClientSecure client; // Create a WiFiClientSecure object

// Google spreadsheet script ID
String GAS_ID = "AKfycbzDB1onq2qAh-8eIxq2DlK_1qxsX5Qz_0hsaFVzKVgbUAU2SNOgEzGVhhzJlj-3nOWT";



void setup() {
  Serial.begin(115200);
  if (!bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }

  pinMode(ON_Board_LED,OUTPUT);     // On board LED port as output
  digitalWrite(ON_Board_LED, HIGH); // Turn off Led on board

  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    //----------------------------------------Make LED flashing when connecting to the wifi router
    digitalWrite(ON_Board_LED, LOW);
    delay(200);
    digitalWrite(ON_Board_LED, HIGH);
    delay(200);
  }
  Serial.println("Connected to WiFi");

  digitalWrite(ON_Board_LED, HIGH); // Turn off the LED when it is connected to the wifi router
  Serial.println("");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  //----------------------------------------

  client.setInsecure();
    
  
}

void loop() {
  // Perform a reading
  if (!bme.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;
  }

  float temperature = bme.temperature;
  float humidity = bme.humidity;
  float pressure = bme.pressure / 100.0;
  //float gas = bme.gas_resistance / 1000.0;

  if (!bme.begin()) {
    Serial.println(F("Could not find a valid BME680 sensor, check wiring!"));
    while (1);
  }


 // String postData = "temperature=" + String(temperature) + "&humidity=" + String(humidity) + "&pressure=" + String(pressure) + "&gas=" + String(gas);

  String Temp = "Temperature : " + String(temperature) + " °C";
  String Humi = "Humidity : " + String(humidity) + " %";
  String Pres = "Pressure : " + String(pressure) + " hPa";
  //String gas = "Gas : " + String(gas) + " co2";
  Serial.println(Temp);
  Serial.println(Humi);
  Serial.println(Pres);
  //Serial.println(gas);
  
  sendData(temperature, humidity, pressure); // Call the sendData subroutine
  delay(5000); 
}

// Subroutine for sending data to Google Sheets
void sendData(float temp, float hum, float pres) {
  Serial.println("==========");
  Serial.print("connecting to ");
  Serial.println(host);
  
  //----------------------------------------Connect to Google host
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  //----------------------------------------

  //----------------------------------------Processing data and sending data
  String string_temperature =  String(temp);
  String string_humidity =  String(hum);
  String string_pres =  String(pres);
  //String string_gas = String(gas);
  String url = "/macros/s/" + GAS_ID + "/exec?temperature=" + string_temperature + "&humidity=" + string_humidity + "&pressure="+ string_pres; // + "&gas=" + String(gas) ;
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");

  Serial.println("request sent");
  //----------------------------------------

  //----------------------------------------Checking whether the data was sent successfully or not
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.print("reply was : ");
  Serial.println(line);
  Serial.println("closing connection");
  Serial.println("==========");
  Serial.println();
  //----------------------------------------
}