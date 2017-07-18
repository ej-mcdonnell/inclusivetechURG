
char incomingByte;   // for incoming serial data
int pwmval;

void pulseToIDspeaker(int motor_number){
  int pwmval;

  for(int i = 0; i <500; i++)
  {
     pwmval = 90*sin(.01*i) +95;
     analogWrite(motor_number, pwmval);
  }
  analogWrite(motor_number, 0);
  delay(2000);
  
}
//
//void pulsetoidspeaker2(int motor_number){
//
//  analogWrite(motor_number, 75);
//  delay(2000);
//  analogWrite(motor_number, 0);
//}

void pulseToRequestSpeaking(int motor_number){
  int pwmval;

  for (int i = 0; i <2; i++)
  {
    analogWrite(motor_number, 150);
    delay(250);
    analogWrite(motor_number, 0);
    delay(250);
  }
  delay(2000);

} 

void clearAllMotors()
{
  analogWrite(11, 0);
  analogWrite(10, 0);
  analogWrite(9, 0);
  analogWrite(6, 0);
  analogWrite(5, 0);
  
}

void slowdown(int motor_number)
{
  for(int i=150; i < 650; i++)
  {
    pwmval= -100*log10(i)+300;
    analogWrite(motor_number, pwmval);
    delay(5);
  }
  analogWrite(motor_number, 0);
  delay(3000);
}

void speedup(int motor_number)
{
  for(int i=150; i < 650; i++)
  {
    pwmval= 100*log10(i)+300;
    analogWrite(motor_number, pwmval);
    delay(5);
  }
  analogWrite(motor_number, 0);
  delay(3000);
}

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(11,OUTPUT);
        digitalWrite(11, LOW);
        pinMode(10, OUTPUT);
        digitalWrite(10, LOW);
        pinMode(9, OUTPUT);
        digitalWrite(9, LOW);
        pinMode(6, OUTPUT);
        digitalWrite(6, LOW);
        pinMode(5, OUTPUT);
        digitalWrite(5, LOW);
        int timer = 0;

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
      //vibrate motor 1
      //corresponds to the person @ posn 1(relative) beginning to speak
      clearAllMotors();
      pulseToIDspeaker(11);
      break; 
    case 'b':
      //vibrate motor 2
      //corresponds to the person @ posn 2(relative) beginning to speak
      clearAllMotors();
      pulseToIDspeaker(10);
      analogWrite(10,0); 
      break;
    case 'c':
      //vibrate motor 3
      ////corresponds to the person @ posn 3(relative) beginning to speak
      pulseToIDspeaker(9);
      analogWrite(9,0);
      break;
    case 'd':
      //vibrate motor 4
      //corresponds to the person @ posn 4(relative) beginning to speak
      clearAllMotors();
      pulseToIDspeaker(6);
      analogWrite(6,0);
      break;

    case 'e':
      //vibrate motor 5
      //corresponds to the person @ posn 5(relative) beginning to speak
      clearAllMotors();
      pulseToIDspeaker(5);
      analogWrite(5, 0);
      break;
   case 'f':
      //vibrate all 5 motors in a wave
      //could serve as a "bad conversation behavior" warning
      clearAllMotors();
      int pwmval;
//      for(int i = 0; i <500; i++)
//      {
//        pwmval = 100*sin(.05 *i) + 110;
//        analogWrite(11, pwmval);
//        analogWrite(10, pwmval);
//        analogWrite(9, pwmval);
//        analogWrite(6, pwmval);
//        analogWrite(5, pwmval);
//      }
      analogWrite(11, 100);
      delay(250);
      analogWrite(11, 0);
      analogWrite(10, 100);
      delay(250);
      analogWrite(10,0);
      analogWrite(9, 100);
      delay(250);
      analogWrite(9, 0);
      analogWrite(6, 100);
      delay(250);
      analogWrite(5, 100);
      delay(250);
      analogWrite(5,0);
      break;
  case 'g':
    //person in posn 1 would like to speak
    clearAllMotors();
    pulseToRequestSpeaking(11);
    break;
  case 'h':
    //person in posn 2 would like to speak
    clearAllMotors();
    pulseToRequestSpeaking(10);
    break;
  case 'i':
    //person in posn 3 would like to speak
    clearAllMotors();
    pulseToRequestSpeaking(9);
    break;
  case 'j':
    //person in posn 4 would like to speak
    pulseToRequestSpeaking(6);
    break;
  case'k':
    //person in posn 5 would like to speak
    clearAllMotors();
    pulseToRequestSpeaking(5);
    break;
  case 'l':
    //vibrate all motors at once
    //conversation warning
    pwmval = 175;
    analogWrite(11, pwmval);
 
    analogWrite(10, pwmval);

    analogWrite(9, pwmval);

    analogWrite(6, pwmval);
   
    analogWrite(5, pwmval);
    delay(250);
    clearAllMotors();
    delay(3000);
    break;
  case 'm':
    clearAllMotors();
    pwmval=175;

    analogWrite(11, pwmval);
    analogWrite(5, pwmval);
    delay(250);
    clearAllMotors();
    analogWrite(10, pwmval);
    analogWrite(6, pwmval);
    delay(250);
    clearAllMotors();
    analogWrite(9, pwmval);
    delay(300);
    
    clearAllMotors();
    delay(2000);
    break;

  case 'n':
    clearAllMotors();
    pwmval=175;

    analogWrite(9, pwmval);
    delay(250);
    analogWrite(9, 0);

    analogWrite(10, pwmval);
    delay(250);
    analogWrite(10, 0);

    analogWrite(11, pwmval);
    delay(250);
    analogWrite(11, 0);

    
    clearAllMotors();
    delay(2000);
    break;

  case 'o':
    clearAllMotors(); 
    pwmval=175;

    analogWrite(9, pwmval);
    delay(250);
    analogWrite(9, 0);

    analogWrite(6, pwmval);
    delay(250);
    analogWrite(6, 0);

    analogWrite(5, pwmval);
    delay(250);
    analogWrite(5, 0);
    
    clearAllMotors();
    delay(2000);
    break;

  case 'p':
    clearAllMotors();
//      for(int i = 0; i <500; i++)
//      {
//        pwmval = 100*sin(.05 *i) + 110;
//        analogWrite(11, pwmval);
//        analogWrite(10, pwmval);
//        analogWrite(9, pwmval);
//        analogWrite(6, pwmval);
//        analogWrite(5, pwmval);
//      }
      analogWrite(11, 100);
      delay(250);
      analogWrite(11, 0);
      analogWrite(10, 100);
      delay(250);
      analogWrite(10,0);
      analogWrite(9, 100);
      delay(250);
      analogWrite(9, 0);
      analogWrite(6, 100);
      delay(250);
      analogWrite(6,0);
      analogWrite(5, 100);
      delay(250);
      analogWrite(5,0);
      
      clearAllMotors();
      delay(2000);
      break;
  case 'q':
    clearAllMotors();
     
//    
      analogWrite(5, 100);
      delay(250);
      analogWrite(5, 0);
      analogWrite(6, 100);
      delay(250);
      analogWrite(6,0);
      analogWrite(9, 100);
      delay(250);
      analogWrite(9, 0);
      analogWrite(10, 100);
      delay(250);
      analogWrite(10,0);
      analogWrite(11, 100);
      delay(250);
      analogWrite(11,0);

      clearAllMotors();
      delay(2000);
      break;
  case 'r':
    clearAllMotors();
    pwmval=175;
    
    analogWrite(9, pwmval);
    delay(300);
    clearAllMotors();

    analogWrite(10, pwmval);
    analogWrite(6, pwmval);
    delay(250);
    clearAllMotors();
    
    analogWrite(11, pwmval);
    analogWrite(5, pwmval);
    delay(250);
    clearAllMotors();
    
    delay(2000);
    break;
  case 's':
    clearAllMotors();
    pwmval=200;

    analogWrite(5, pwmval);
    delay(20);
    analogWrite(5, 0);
    delay(380);
    break;

  case 't':
    slowdown(6);
    break;
  case 'u':
    speedup(6);
    break;
    
  case'z':
    clearAllMotors();
    break;
    
  }
        
        
         

          
}
