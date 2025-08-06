
// #define BLYNK_TEMPLATE_ID "TMPL6ZoMOOwRd"
// #define BLYNK_TEMPLATE_NAME "Smart Plant Light"
// #define BLYNK_AUTH_TOKEN "Hi13wruc_olRgH7qxzHtLpZ6mL1J_b40"

// #include <ESP8266WiFi.h>
// #include <BlynkSimpleEsp8266.h>

// // Wi-Fi credentials
// // char ssid[] = "Da54";         
// // char pass[] = "12345678h";   
// char ssid[] = "Meemifti";         
// char pass[] = "A00008888b";  

// // Pins and threshold
// const int ldrPin = A0;
// const int ledPin = D2;
// const int threshold = 600;

// int manualControl = 0; // This changes when you press the Blynk button

// // Read value from phone (manual ON/OFF override)
// BLYNK_WRITE(V1) {
//   manualControl = param.asInt(); // 1 = ON, 0 = AUTO mode
// }

// void setup() {
//   Serial.begin(9600);
//   pinMode(ledPin, OUTPUT);

//   Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
//   Serial.println("Setup done. Connecting to Wi-Fi...");
// }

// void loop() {
//   Blynk.run();

//   int ldrValue = analogRead(ldrPin);

//   Serial.print("LDR Value: ");
//   Serial.print(ldrValue);
//   Serial.print(" | ManualControl: ");
//   Serial.println(manualControl);

//   if (manualControl == 1) {
//     // Force ON
//     digitalWrite(ledPin, HIGH);
//   } else {
//     // Auto mode
//     if (ldrValue < threshold) {
//       digitalWrite(ledPin, HIGH);
//     } else {
//       digitalWrite(ledPin, LOW);
//     }
//   }

//   delay(500);
// }
#define BLYNK_TEMPLATE_ID "TMPL6ZoMOOwRd"
#define BLYNK_TEMPLATE_NAME "Smart Plant Light"
#define BLYNK_AUTH_TOKEN "Hi13wruc_olRgH7qxzHtLpZ6mL1J_b40"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Wi-Fi credentials
// char ssid[] = "Da54";         
// char pass[] = "12345678h";   
char ssid[] = "Meemifti";         
char pass[] = "A00008888b"; 

// Pins and threshold
const int ldrPin = A0;
const int ledPin = D2;
const int threshold = 600;

int manualControl = 0; // 0 = Auto, 1 = Force OFF, 2 = Force ON

// Read value from phone (manual override)
BLYNK_WRITE(V1) {
  manualControl = param.asInt();
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  
  Blynk.run();
  


  int ldrValue = analogRead(ldrPin);
  Blynk.virtualWrite(V2, ldrValue);
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Control Mode: ");
  Serial.println(manualControl);

  if (manualControl == 2) {
    // Manual ON
    digitalWrite(ledPin, HIGH);
  } else if (manualControl == 1) {
    // Manual OFF
    digitalWrite(ledPin, LOW);
  } else {
    // Auto Mode
    if (ldrValue < threshold) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }

  delay(500);
}
