/*
 * ESP32 Soil Moisture Sensor (Percentage Display)
 * Reads analog value from sensor and converts it to percentage
 */

#define SOIL_PIN 36  // ADC pin connected to soil moisture sensor (AOUT)
#define DRY_VALUE 3500  // Change this based on your dry soil reading
#define WET_VALUE 1200  // Change this based on your wet soil reading

void setup() {
  Serial.begin(9600);
  analogSetAttenuation(ADC_11db); // Allows full 0–3.3V range for analog read
}

void loop() {
  int sensorValue = analogRead(SOIL_PIN); // Read sensor value

  // Map the sensor value to percentage (100% = wet, 0% = dry)
  int moisturePercent = map(sensorValue, DRY_VALUE, WET_VALUE, 0, 100);

  // Constrain to 0–100 range
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  delay(1000);
}
