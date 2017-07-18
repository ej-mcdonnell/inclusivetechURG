

char incomingByte;   // for incoming serial data
int pwmval = 150;
int dtime = 250;
void clearAllMotors()
{
  analogWrite(11, 0);
  analogWrite(10, 0);
  analogWrite(9, 0);
  analogWrite(6, 0);
  analogWrite(5, 0);
  
}

void writetothreemotors(int a, int b, int c)
{
  analogWrite(a, pwmval);
  delay(dtime);
  analogWrite(a, 0);
  analogWrite(b, pwmval);
  delay(dtime);
  analogWrite(b, 0);
  analogWrite(c, pwmval);
  delay(dtime);
  analogWrite(c, 0);

  delay(2000);
}

void writetotwomotors(int a, int b){
  analogWrite(a, pwmval);
  delay(dtime);
  analogWrite(a, 0);
  analogWrite(b, pwmval);
  delay(dtime);
  analogWrite(b, 0);

  delay(2000);
}

void writepattern(int a,int b, int c){
  analogWrite(a, pwmval);
  analogWrite(b, pwmval);
  delay(dtime);
  analogWrite(a, 0);
  analogWrite(b, 0);
  analogWrite(c, pwmval);
  delay(dtime);
  analogWrite(c, 0);

  delay(2000);
}

void writepatterninverse(int a,int b,int c){
  analogWrite(c, pwmval);
  delay(dtime);
  analogWrite(c, 0);
  analogWrite(a, pwmval);
  analogWrite(b, pwmval);
  delay(dtime);
  analogWrite(a, 0);
  analogWrite(b, 0);

  delay(2000);
}
void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte);
        }


        switch (incomingByte) {
          case 'a':
            writetothreemotors(6, 9, 11);
            break;
          case 'b':
            writetothreemotors(11, 9, 6);
            break;
          case 'c':
            writetothreemotors(5, 9, 10);
            break;
          case 'd':
            writetothreemotors(10, 9, 5);
            break;
          case 'e':
            writetothreemotors(5, 9, 6);
            break;
          case 'f':
            writetothreemotors(6, 9, 5);
            break;
          case 'g':
            writetothreemotors(11, 9, 10);
            break;
          case 'h':
            writetothreemotors(10, 9, 11);
            break;
          case 'i':
            writetothreemotors(6, 9, 10);
            break;
          case 'j':
            writetothreemotors(10, 9, 6);
            break;
          case 'k':
            writetothreemotors(5, 9, 11);
            break;
          case 'l':
            writetothreemotors(11, 9, 5);
            break;
          case 'm':
            writepattern(6, 10, 9);
            break;
          case 'n':
            writepattern(5, 11, 9);
            break;
          case 'o':
            writepatterninverse(9, 5, 11);
            break;
          case 'p':
            writepatterninverse(9, 6, 10);
            break;
          case'q':
            writetotwomotors(5,6);
            break;
          case'r':
            writetotwomotors(6,5);
            break;
          case's':
            writetotwomotors(11, 10);
            break;
          case't':
            writetotwomotors(10, 11);
            break;
          case'u':
            writetotwomotors(10,6);
            break;
          case 'v':
            analogWrite(

          case'z':
            clearAllMotors();
            break;

           
          
                  

                
            
            
                 
          
          
          
          }


}
