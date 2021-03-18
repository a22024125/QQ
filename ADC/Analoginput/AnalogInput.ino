
int sensorPin = A0; 
int sensorValue = 0;
double T, Temp;
double Q = 301.15;
double lnR;
int16_t R; 
int16_t R0 = 8805; 
int16_t B  = 3950;
int16_t Pullup = 9930;


void setup() {
  Serial.begin(115200);

}


void loop() {
  sensorValue = analogRead(sensorPin);
  int16_t ADCvalue = sensorValue;
   R = (Pullup * ADCvalue) / (4096 -ADCvalue);
  T = 1 / (1/Q + (log(R)-log(R0)) / B );
  Temp = T -273.15;
  printf("ADC:%4d, R=%d, Temp.=%f\n", ADCvalue, R, Temp);
  Serial.println(sensorValue);
}
