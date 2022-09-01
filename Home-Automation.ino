#include <ArduinoJson.h>

#include <ESP8266WiFi.h>                                                    // esp8266 library                                             // firebase library
#include <FirebaseESP8266.h>
#define FIREBASE_HOST "homeautomation-109af-default-rtdb.firebaseio.com"      //fire base host key
#define FIREBASE_AUTH "AIzaSyBOFX0OFBNfFUyF8iv80rNLHKSaR6b-DFc"               // fire base web key ,project-setting,General
#define WIFI_SSID "wifi-name"
#define WIFI_PASSWORD "wifi-passoward"
#define USER_EMAIL "user email"
#define USER_PASSWORD "user passoward"
int Relay = 16;
int Relay1 = 5;
// Provide the token generation process info.
#include <addons/TokenHelper.h>

// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

FirebaseConfig config;
FirebaseData fbdo;
FirebaseJson json;
FirebaseAuth auth;
//int a;
bool a;
bool b;
const char* doc;
int c;
void setup() {
  Serial.begin(115200);
  pinMode(Relay, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.println("esp8266 serial initialize");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  Serial.print(WIFI_SSID);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }

  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
    /* Assign the api key (required) */
  config.api_key = FIREBASE_AUTH;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = FIREBASE_HOST;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  //Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  delay(1000);

}
void loop() {
  
a=Firebase.getString(fbdo,"/LIGHTS ON-OFF/STATE");
a=fbdo.to<bool>();
Serial.println(a);
Firebase.getString(fbdo,"/FAN ON-OFF/STATE");
b=fbdo.to<bool>();
Serial.println(b);

if (a==1){
  digitalWrite(Relay, LOW);
  }
 else{
  digitalWrite(Relay,HIGH );
  }
 if (b==1){
  digitalWrite(Relay1, LOW);
  }
 else{
  digitalWrite(Relay1, HIGH);
  }
//c=Firebase.getString(fbdo,"/THRESHOLD VALUE/THRESHOLD");
//Serial.println(String(c));
//delay(1000);  
}
