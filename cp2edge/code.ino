#include <DHT.h>
#include <LiquidCrystal.h>

//DHT11 pin to 6
#define DHTPIN 6
#define DHTTYPE DHT22 //!!!MUDAR PARA DHT11 NA AULA!!!!

// LCD pins ---->(RS, EN, D4, D5, D6, D7). //
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

DHT dht(DHTPIN, DHTTYPE);

int lightSensor = A0;
int greenLED = 4;
int yellowLED = 3;
int redLED = 2;
int buzzer = 5;

int minLightValue = 0;
int maxLightValue = 1023;

float temperature = 0;
float humidity = 0;

float tempSum = 0;
float humiditySum = 0;
int readingsCount = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  dht.begin();
}

void loop() {
  static unsigned long previousDisplayTime = 0;
  const unsigned long displayInterval = 5000; // Display interval in milliseconds

  unsigned long currentMillis = millis();

  // Accumulate temperature and humidity readings
  tempSum += dht.readTemperature();
  humiditySum += dht.readHumidity();
  readingsCount++;

  if (currentMillis - previousDisplayTime >= displayInterval) {
    lcd.clear();

    // Calculate average temperature and humidity
    float averageTemp = tempSum / readingsCount;
    float averageHumidity = humiditySum / readingsCount;

    // Display temperature information
    if (averageTemp >= 10 && averageTemp <= 15) {  
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp.= OK ");
      lcd.setCursor(0, 1);
      lcd.print("Temp.= ");
      lcd.print(averageTemp, 1);
      lcd.print(" *C");
      delay(5000);
    } else if (averageTemp < 10) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp.= BAIXA ");
      digitalWrite(yellowLED, HIGH);
      digitalWrite(buzzer, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Temp.= ");
      lcd.print(averageTemp, 1);
      lcd.print(" *C");
      delay(5000);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp.= ALTA ");
      digitalWrite(yellowLED, HIGH);
      digitalWrite(buzzer, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Temp.= ");
      lcd.print(averageTemp, 1);
      lcd.print(" *C");
      delay(5000);
    }

    // Display humidity information
    if (averageHumidity >= 50 && averageHumidity <= 70) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Umid.= OK ");
      lcd.setCursor(0, 1);
      lcd.print("Umid.= ");
      lcd.print(averageHumidity, 1);
      lcd.print("%");
      delay(5000);
    } else if (averageHumidity < 50) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Umid.= BAIXA ");
      digitalWrite(redLED, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Umid.= ");
      lcd.print(averageHumidity, 1);
      lcd.print("%");
      delay(5000);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Umid.= ALTA ");
      digitalWrite(redLED, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Umid.= ");
      lcd.print(averageHumidity, 1);
      lcd.print("%");
      delay(5000);
    }

    // Reset variables for next readings
    tempSum = 0;
    humiditySum = 0;
    readingsCount = 0;

    previousDisplayTime = currentMillis; // Reset the display timer
  }



  //Sensor de Luz e LEDS
  
  int lightValue = analogRead(lightSensor);
  Serial.print("Intensidade da Luz: ");
  Serial.println(lightValue);
  
  // Map the lightValue to a range of 0-100
  int mappedLightValue = map(lightValue, minLightValue, maxLightValue, 0, 100);
  
  if (mappedLightValue < 0 || mappedLightValue > 100) {
    // Error: O sensor de luz não está captando corretamente.
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  } else if (mappedLightValue > 30 || mappedLightValue < 65) {
    // Ambiente a meia luz / ativa LED AMARELO
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ambiente a meia");
    lcd.setCursor(0, 1);
    lcd.print("luz");
    delay(3000);
    digitalWrite(buzzer, LOW);
  } else if (mappedLightValue > 65) {
    // Luz muito intensa // ativa LED VERMELHO
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ambiente muito");
    lcd.setCursor(0, 1);
    lcd.print("CLARO");
    delay(3000);
  } else {
    // Penumbra // mantem LED VERDE
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
  } 
  delay(5000);
  
}

// Valores vao provavelmente mudar quando feito no hands On
// Valores da luz intensa e escura talvez se invertam
