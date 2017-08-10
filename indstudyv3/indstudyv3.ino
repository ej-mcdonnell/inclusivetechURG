#define SOFTPWM_OUTPUT_DELAY;
#include<SoftPWM.h>;

SOFTPWM_DEFINE_CHANNEL(0, DDRD, PORTD, PORTD0);  //Arduino pin 0
SOFTPWM_DEFINE_CHANNEL(4, DDRD, PORTD, PORTD4);  //Arduino pin 4
SOFTPWM_DEFINE_CHANNEL(2, DDRD, PORTD, PORTD2);  //Arduino pin 2
SOFTPWM_DEFINE_CHANNEL(3, DDRD, PORTD, PORTD3);  //Arduino pin 3
SOFTPWM_DEFINE_CHANNEL(5, DDRD, PORTD, PORTD5);  //Arduino pin 5
SOFTPWM_DEFINE_CHANNEL(6, DDRD, PORTD, PORTD6);  //Arduino pin 6
SOFTPWM_DEFINE_CHANNEL(7, DDRD, PORTD, PORTD7);  //Arduino pin 7
SOFTPWM_DEFINE_CHANNEL(8, DDRB, PORTB, PORTB0);  //Arduino pin 8
SOFTPWM_DEFINE_CHANNEL(9, DDRB, PORTB, PORTB1);  //Arduino pin 9
SOFTPWM_DEFINE_CHANNEL(10, DDRB, PORTB, PORTB2);  //Arduino pin 10
SOFTPWM_DEFINE_CHANNEL(11, DDRB, PORTB, PORTB3);  //Arduino pin 11


SOFTPWM_DEFINE_OBJECT(256);

char incomingByte;

int TL = 11;
int TC = 10;
int TR = 9;
int ML = 6;
int MC = 5;
int MR = 3;
int BL = 2;
int BC = 4;
int BR = 7;

int pwmVal=150;
int onDelay=250;
int offDelay;

void clearAllMotors()
{
  Palatis::SoftPWM.set(TL, 0);
  Palatis::SoftPWM.set(TC, 0);
  Palatis::SoftPWM.set(TR, 0);
  Palatis::SoftPWM.set(ML, 0);
  Palatis::SoftPWM.set(MC, 0);
  Palatis::SoftPWM.set(MR, 0);
  Palatis::SoftPWM.set(BL, 0);
  Palatis::SoftPWM.set(BC, 0);
  Palatis::SoftPWM.set(BR, 0);
  
}
void strongPulse(int m1, int m2, int m3){


  for (int i = 0; i <2; i++)
  {
    Palatis::SoftPWM.set(m1, 150);
    Palatis::SoftPWM.set(m2, 150);
    Palatis::SoftPWM.set(m3, 150);
    delay(250);
    clearAllMotors();
    delay(250);
  }
  delay(2000);

} 
void vibrateThree(int m1, int m2, int m3){
  Palatis::SoftPWM.set(m1, pwmVal);
  Palatis::SoftPWM.set(m2, pwmVal);
  Palatis::SoftPWM.set(m3, pwmVal);

  delay(onDelay);

  clearAllMotors();
}


void vibrateTwo(int m1, int m2){
  Palatis::SoftPWM.set(m1, pwmVal);
  Palatis::SoftPWM.set(m2, pwmVal);

  delay(onDelay);

  clearAllMotors();
  
}

void vibrateOne(int m1){
   Palatis::SoftPWM.set(m1, pwmVal);
   delay(onDelay);

   Palatis::SoftPWM.set(m1, 0);
}

void vibrateFour(int m1, int m2, int m3, int m4){
  Palatis::SoftPWM.set(m1, pwmVal);
  Palatis::SoftPWM.set(m2, pwmVal);
  Palatis::SoftPWM.set(m3, pwmVal);
  Palatis::SoftPWM.set(m4, pwmVal);
  delay(onDelay);

  clearAllMotors();

  
}

void vibrateAll(){
  Palatis::SoftPWM.set(TL, pwmVal);
  Palatis::SoftPWM.set(TC, pwmVal);
  Palatis::SoftPWM.set(TR, pwmVal);
  Palatis::SoftPWM.set(ML, pwmVal);
  Palatis::SoftPWM.set(MC, pwmVal);
  Palatis::SoftPWM.set(MR, pwmVal);
  Palatis::SoftPWM.set(BL, pwmVal);
  Palatis::SoftPWM.set(BC, pwmVal);
  Palatis::SoftPWM.set(BR, pwmVal);
  delay(onDelay);

  clearAllMotors();
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Palatis::SoftPWM.begin(60);
  
  pinMode(TL, OUTPUT);
  Palatis::SoftPWM.set(TL, 0);
  pinMode(TC, OUTPUT);
  Palatis::SoftPWM.set(TC, 0);
  pinMode(TR, OUTPUT);
  Palatis::SoftPWM.set(TR, 0);
  pinMode(ML, OUTPUT);
  Palatis::SoftPWM.set(ML, 0);
  pinMode(MC, OUTPUT);
  Palatis::SoftPWM.set(MC, 0);
  pinMode(MR, OUTPUT);
  Palatis::SoftPWM.set(MR, 0);
  pinMode(BL, OUTPUT);
  Palatis::SoftPWM.set(BL, 0);
  pinMode(BC, OUTPUT);
  Palatis::SoftPWM.set(BC, 0);
  pinMode(BR, OUTPUT);
  Palatis::SoftPWM.set(BR, 0);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  

  if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte);
        }


   switch(incomingByte){
    case'a': // left
      pwmVal = 150;
      onDelay = 250;
      vibrateThree(TR, MR, BR);
      vibrateThree(TC, MC, BC);
      vibrateThree(TL, ML, BL);
      delay(3000);
      break;
    case 'b': //right
      pwmVal = 150;
      onDelay = 250;
      vibrateThree(TL, ML, BL);
      vibrateThree(TC, MC, BC);
      vibrateThree(TR, MR, BR);
      delay(3000);
      break;
    case 'c': //up
      pwmVal=150;
      onDelay=250;
      vibrateThree(BL, BC, BR);
      vibrateThree(ML, MC, MR);
      vibrateThree(TL, TC, TR);
      delay(3000);
      break;
    case 'd': //down
      pwmVal=150;
      onDelay=250;
      vibrateThree(TL, TC, TR);
      vibrateThree(ML, MC, MR);
      vibrateThree(BL, BC, BR);
      delay(3000);
      break;
    case 'e': //sideways left
      pwmVal = 150;
      onDelay = 250;
      vibrateThree(BL, MC, TR);
      vibrateTwo(ML, TC);
      pwmVal = 225;
      vibrateOne(TL);
      delay(3000);
      break;
    case 'f': //sideways right
      pwmVal = 150;
      onDelay = 250;
      vibrateThree(TL, MC, BR);
      vibrateTwo(TC, MR);
      pwmVal =225;
      vibrateOne(TR);
      delay(3000);
      break;
    case 'g': //forwards -- dpesn't super work
      pwmVal = 150;
      onDelay = 250;
      vibrateThree(BL, MC, BR);
      vibrateThree(ML, TC, MR);
      delay(3000);
      break;
    case 'h': //circle outside, mostly to see how it feels
      pwmVal = 150;
      onDelay = 250;
      vibrateOne(BL);
      vibrateOne(ML);
      vibrateOne(TL);
      vibrateOne(TC);
      vibrateOne(TR);
      vibrateOne(MR);
      vibrateOne(BR);
      vibrateOne(BC);
      break;
    case 'i': //vibrate all
      vibrateAll();
      delay(3000);
      break;
    case 'j': //warning?
      pwmVal=150;
      onDelay = 250;
      vibrateFour(TL, BL, TR, BR);

      delay(3000);
      break;
    case 'k': //sideways right arrow -- doesn't super work
      pwmVal = 150;
      onDelay = 250;
      vibrateThree(BL, MC, TL);
      vibrateThree(BC, ML, TC);

      delay(3000);
      break;
    case 'l': //sideways left arrow - doesn't super work
      vibrateThree(BR, MC, TR);
      vibrateThree(BC, ML, TC);

      delay(3000);
      break;
    case 'm': //speed up/get louder
      pwmVal = 125;
      onDelay = 200;
      vibrateOne(BL);
      pwmVal = 175;
      onDelay = 250;
      vibrateOne(MC);
      pwmVal = 225;
      onDelay = 300;
      vibrateOne(TR);

      delay(3000);
      break;
    case 'n': //slow down/get quieter
      pwmVal = 125;
      onDelay = 200;
      vibrateOne(TL);
      pwmVal = 175;
      onDelay = 250;
      vibrateOne(MC);
      pwmVal = 225;
      onDelay = 300;
      vibrateOne(BR);

      delay(3000);
      break;
    case'o': //vibrate top three motors
      strongPulse(TL, TC, TR);
      break;
    case 'p': //vibrate left three motors
      strongPulse(TL, ML, BL);
      break;
    case 'q':
      strongPulse(TR, MR, BR);
      break;
   
    case 'z': //off
      clearAllMotors();
      break;
   }


}
