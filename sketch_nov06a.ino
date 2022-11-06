#include <WiFi.h>
#include "FirebaseESP32.h"

#define WIFI_SSID "Dormitorio_Alexis_WIFI"
#define WIFI_PASSWORD "21AlExIs"

#define FIREBASE_HOST "https://esp32-2dapba-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "dQ9FhbkBil4TqNGYJorfcHwggUjpZ770T3COKTlv"

FirebaseData firebaseData;

String nodo = "/Sensores";
bool iterar = true;

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectado al WIFI");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
   }
   Serial.println();

   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
   Firebase.reconnectWiFi(true);
  }

void loop()
{
      while(iterar){
        Firebase.getInt(firebaseData, nodo + "/sensor1");
        Serial.println(firebaseData.intData());
        delay(250);
        Firebase.getString(firebaseData, nodo + "/sensor2");
        Serial.println(firebaseData.stringData());


        Firebase.setInt(firebaseData, nodo + "/sensor1", 512);
        Firebase.setString(firebaseData, nodo + "/sensor2", "on");
        Firebase.setBool(firebaseData, nodo + "/iterar", false); 
        
        iterar = false;
        Firebase.end(firebaseData);
        }
  }










  





















  
