#include <SoftwareSerial.h>
SoftwareSerial gprs(6, 7);

void setup(){

}

void loop(){
  
}

void connectToGPRS() {
  if(digitalRead(7 != LOW)) {
    Serial.println("Connecting to Vivo..\r");
    gprs.println("AT");
    gprs.println("AT+CIPSHUT");
    gprs.println("AT+CIPMUX=1");
    gprs.println("AT+CSTT=\"zap.vivo.com.br\",\"vivo\",\"vivo\"");
    gprs.println("AT+CIICR");
    gprs.println("AT+CDNSCFG=\"8.8.8.8\",\"8.8.4.4\"");
    gprs.println("AT+CIFSR"); // DEVICE IP SHIELD
  }
}

void postData() {
  Serial.print("POST to API");
  gprs.println("AT+CSQ");
  gprs.println("AT+CGATT?");
  gprs.println("AT+SAPBR=2,1"); //check if we have an IP address
  gprs.println("AT+HTTPPARA=\"CID\",1"); // Set the HTTP session.
  gprs.println("AT+HTTPPARA=\"URL\",\"http://sensor.api.com/v1/data\""); // set api endpoint
  gprs.println("AT+HTTPPARA=\"CONTENT\",\"application/json\""); // set content json
  gprs.println("AT+HTTPDATA=100,5000"); // POST session start
  gprs.println("{\"timestamp\":\"2016-03-11T05:00:47.000Z\",\"temp\":\"55\",\"humidity\":\"49\"}"); // Our JSON payload
  delay(100);
  gprs.println("AT+HTTPACTION=1"); // Do POST to API
  gprs.println("AT+HTTPREAD");// Read API response
  gprs.println("AT+HTTPTERM"); // close http session
}


void writeToSerial(){
  while(gprs.available()!= 0){
    Serial.write(gprs.read());
  }
}