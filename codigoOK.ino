// Programa : Display LCD 16x2 e modulo I2C
// Autor : Arduino e Cia

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Thermistor.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

uint32_t delayMS;
// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

#define DHTPIN            2 
#define DHTTYPE           DHT22

#define PINODHT 2     // qual pino usaremos para comunicação com DHT
#define TIPODHT DHT22   // qual DHT vamos usar. Nocaso, um DHT22(AM2302/ AM2321)
 
DHT dht(PINODHT, TIPODHT);    // configuraçãoes do DHT
 
// ------------- Inicialização de DHT e Display ---------------------------//
 
void setup() {
  
  lcd.begin(16, 2); // inicializa o LCD Display 
  lcd.setCursor(3, 0);
  lcd.print("Bem Vindo!");
  lcd.setCursor(3, 1);
  lcd.print("Lo.Li.BOX");
  delay(2500);
  lcd.clear();
 
//Inicializa o DHT
  dht.begin();
}
 
// ------------------- Lê e mostra informações -------------------- //
 
void loop() {
  // espere um segundo para as informações aparecerem.
  delay(1000);
 
  // Ler a temperatura ou humidade leva cerca de 250 milisegundos!
  int h = dht.readHumidity();
  // Lê a temperatura em Celsius (padrão)
  int t = dht.readTemperature();
 
  // Checando se qualquer leitura falhou.
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 1);
    lcd.print("Falha ao ler");
    return;
  }
  lcd.setCursor(0, 0);
  lcd.print("Umid: ");
  lcd.setCursor(6, 0);
  lcd.print(h);
  lcd.setCursor(9, 0);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.setCursor(6, 1);
  lcd.print(t);
  lcd.setCursor(9, 1);
  lcd.print("*C");
  delay(8500);
  
  lcd.begin(16, 2); // inicializa o LCD Display
  lcd.setCursor(6, 0);
  lcd.print("Lo.Li");
  lcd.setCursor(7, 1);
  lcd.print("BOX");
  delay(2500);
  lcd.clear();
  }
