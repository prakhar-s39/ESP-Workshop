#define BLYNK_TEMPLATE_ID "TMPL32dZ8Umop"
#define BLYNK_TEMPLATE_NAME "Sambkeith"
#define BLYNK_AUTH_TOKEN "nPyYOsN3uPT1mXk4qiraRLPg0gYvlC53"
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 //Data pin is connected to D2 on ESP
#define DHTTYPE DHT11 // Name the sensor as an object

char auth[] = "nPyYOsN3uPT1mXk4qiraRLPg0gYvlC53";
char ssid[] = "moto g62 5G_6619";
char pass[] = "11102003";
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
Serial.begin(9600);
Serial.println("DHT Test Successful!");
Blynk.begin(auth, ssid, pass);
Serial.println("Blynk completed successfully");
dht.begin();
}
void loop(){
float h = dht.readHumidity();
float t = dht.readTemperature();
float f = dht.readTemperature(true);
if(isnan(h) || isnan(t) || isnan(f))
{
  Serial.println("code no work :(");
  return; 
}
 Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%");
  Serial.print(" Temperature: ");
  Serial.print(t);
  Serial.print(" C");
  Serial.println();
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  delay(2000);

}