#define BLYNK_TEMPLATE_ID "********************************"
#define BLYNK_TEMPLATE_NAME "IoT Energy Meter"
#define BLYNK_PRINT Serial

#include "EmonLib.h"
#include <EEPROM.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Constants for calibration
const float vCalibration1 = 41.5;  // Calibration for Device 1
const float vCalibration2 = 41.5;  // Calibration for Device 2
const float currCalibration1 = 0.15; 
const float currCalibration2 = 0.15;

// Blynk and WiFi credentials
const char auth[] = "2zzjrLLEM825aoPqp1guspsDqLrdV9bq";
const char ssid[] = "vivo 1901";
const char pass[] = "21271006";

// EnergyMonitor instances for 2 devices
EnergyMonitor emon1;
EnergyMonitor emon2;

// Timer for regular updates
BlynkTimer timer;

// Variables for energy calculation
float kWh1 = 0.0, kWh2 = 0.0;
unsigned long lastMillis = millis();

// EEPROM addresses for stored values
const int addrKWh1 = 12;
const int addrKWh2 = 16;

// Flags for detecting device status
bool device1On = false;
bool device2On = false;

// Function prototypes
void sendEnergyDataToBlynk();
void readEnergyDataFromEEPROM();
void saveEnergyDataToEEPROM();

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  // Initialize EEPROM
  EEPROM.begin(32);

  // Read stored energy data
  readEnergyDataFromEEPROM();

  // Setup voltage and current inputs for both devices
  emon1.voltage(35, vCalibration1, 1.7); // Voltage: input pin, calibration, phase_shift
  emon1.current(34, currCalibration1);   // Current: input pin, calibration

  emon2.voltage(33, vCalibration2, 1.7); // Second device voltage sensor
  emon2.current(32, currCalibration2);   // Second device current sensor

  // Timer to send data every 5 seconds
  timer.setInterval(5000L, sendEnergyDataToBlynk);

  delay(1000);
}

void loop()
{
  Blynk.run();
  timer.run();
}

void sendEnergyDataToBlynk()
{
  emon1.calcVI(20, 2000);
  emon2.calcVI(20, 2000);

  unsigned long currentMillis = millis();
  
  kWh1 += emon1.apparentPower * (currentMillis - lastMillis) / 3600000000.0;
  kWh2 += emon2.apparentPower * (currentMillis - lastMillis) / 3600000000.0;
  lastMillis = currentMillis;

  Serial.printf("Device 1 -> Vrms: %.2fV  Irms: %.4fA  Power: %.4fW  kWh: %.5fkWh\n",
                emon1.Vrms, emon1.Irms, emon1.apparentPower, kWh1);

  Serial.printf("Device 2 -> Vrms: %.2fV  Irms: %.4fA  Power: %.4fW  kWh: %.5fkWh\n",
                emon2.Vrms, emon2.Irms, emon2.apparentPower, kWh2);

  saveEnergyDataToEEPROM();

  // Send data to Blynk
  Blynk.virtualWrite(V0, emon1.Vrms);
  Blynk.virtualWrite(V1, emon1.Irms);
  Blynk.virtualWrite(V2, emon1.apparentPower);
  Blynk.virtualWrite(V3, kWh1);

  Blynk.virtualWrite(V4, emon2.Vrms);
  Blynk.virtualWrite(V5, emon2.Irms);
  Blynk.virtualWrite(V6, emon2.apparentPower);
  Blynk.virtualWrite(V7, kWh2);

  // Check if Device 1 is turned ON and send notification
  if (emon1.apparentPower > 1.0 && !device1On)
  {
    Blynk.logEvent("device1_on", "Device 1 is now ON");
    device1On = true;
  }
  else if (emon1.apparentPower <= 1.0)
  {
    device1On = false;
  }

  // Check if Device 2 is turned ON and send notification
  if (emon2.apparentPower > 1.0 && !device2On)
  {
    Blynk.logEvent("device2_on", "Device 2 is now ON");
    device2On = true;
  }
  else if (emon2.apparentPower <= 1.0)
  {
    device2On = false;
  }
}

void readEnergyDataFromEEPROM()
{
  EEPROM.get(addrKWh1, kWh1);
  EEPROM.get(addrKWh2, kWh2);

  if (isnan(kWh1))
  {
    kWh1 = 0.0;
    saveEnergyDataToEEPROM();
  }
  if (isnan(kWh2))
  {
    kWh2 = 0.0;
    saveEnergyDataToEEPROM();
  }
}

void saveEnergyDataToEEPROM()
{
  EEPROM.put(addrKWh1, kWh1);
  EEPROM.put(addrKWh2, kWh2);
  EEPROM.commit();
}
