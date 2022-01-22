#include "FirebaseESP8266.h”
#include <ESP8266WiFi.h>


#define FIREBASE_HOST "LINK OF DATABASE WITHOUT HTTps" //Without http:// or https:// schemes
#define FIREBASE_AUTH "AUTH KAY"
#define WIFI_SSID "Galaxy M124C0B"
#define WIFI_PASSWORD "Vansh123"

int led = D4;     // Connect LED to D5

FirebaseData firebaseData;
FirebaseData ledData;

FirebaseJson json;


void setup()
{

  Serial.begin(9600);
  pinMode(led,OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

void sensorUpdate(){
  digitalWrite(led,true);
  int t = digitalRead(led);
  
  if (Firebase.setFloat(firebaseData, "/light_a/light_mon", t))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }

  delay(1000);
}

void sensorUpdate1(){
  
  digitalWrite(led,false);
  int t = digitalRead(led);
  
  if (Firebase.setFloat(firebaseData, "/light_a/light_mon", t))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }

  delay(1000);
  
  
}

void loop() {
  sensorUpdate();
  sensorUpdate1();
  delay(100);
}

