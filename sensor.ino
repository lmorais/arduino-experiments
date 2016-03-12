int sensor = 0;
int luminosity = 0;

const int RED = 6;
const int YELLOW = 7;
const int GREEN = 5;

void setup(){
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void power(int value){
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(value, HIGH);
}

void loop(){
  luminosity = analogRead(sensor);
  Serial.print("Luminosidade: ");
  Serial.println(luminosity);
  delay(100);
  if(luminosity < 150){
    power(RED);
  }
  if(luminosity >= 200 && luminosity <= 400 ){
    power(YELLOW);
  }
  if(luminosity > 400){
    power(GREEN);
  }
}
