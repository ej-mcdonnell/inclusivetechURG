void clearAllMotors(){
  analogWrite(11, 0);
  analogWrite(10, 0);
}
char incomingByte;

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(11,OUTPUT);
        digitalWrite(11, LOW);
        pinMode(10, OUTPUT);
        digitalWrite(10, LOW);
     

}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte);
        }


        switch (incomingByte) {
          case 'a':
            analogWrite(11, 150);
            delay(100);
            analogWrite(11, 0);
            delay(500);
            analogWrite(10, 150);
            delay(100);
            analogWrite(10, 0);
            delay(500);
            break;
         case 'z':
           clearAllMotors();
           break;
         

                
                
          
          
          
          
          
          
          
          }
}
