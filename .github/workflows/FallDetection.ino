// 1. Fill these 3 lines from your Blynk Console FIRST
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "Fall Detection"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>

// --- Network Credentials ---
char ssid[] = "Your_WiFi_Name"; 
char pass[] = "Your_WiFi_Password";

// --- Hardware Objects ---
Adafruit_MPU6050 mpu;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change to 0x3F if screen is blank
const int buzzerPin = 18;

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");

  // Initialize MPU6050
  if (!mpu.begin()) {
    lcd.clear();
    lcd.print("MPU6050 Error!");
    while (1) yield();
  }

  // Initialize Blynk
  // We use BLYNK_AUTH_TOKEN directly to avoid "not declared" errors
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  lcd.clear();
  lcd.print("System Ready");
  delay(2000);
}

void loop() {
  Blynk.run();

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Calculate Total Acceleration
  float total_acc = sqrt(pow(a.acceleration.x, 2) + 
                         pow(a.acceleration.y, 2) + 
                         pow(a.acceleration.z, 2));

  // Threshold check (30.0 is a standard starting point for a fall)
  if (total_acc > 30.0) {
    makeAlert();
  } else {
    showStatus();
  }

  delay(150); 
}

void makeAlert() {
  digitalWrite(buzzerPin, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("!! FALL !!");
  lcd.setCursor(0, 1);
  lcd.print("Alert Sent");

  // Send to Blynk App
  Blynk.logEvent("fall_detected", "Emergency: Fall Detected!");
  
  Serial.println("Fall Detected!");
  delay(4000); // Buzzer sounds for 4 seconds
  digitalWrite(buzzerPin, LOW);
}

void showStatus() {
  lcd.setCursor(0, 0);
  lcd.print("Status: Active  ");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring...   ");
}
