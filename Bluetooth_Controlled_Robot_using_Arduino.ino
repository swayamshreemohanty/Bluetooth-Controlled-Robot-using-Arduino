//Bluetooth Controlled Bot using Arduino UNO
//By Swayamshree

int state;
int flag=0;       
void stp();
void fwd();
void left();
void right();
void back();
void setup()
{
    pinMode(7,OUTPUT);                  
    pinMode(8,OUTPUT);                  
    pinMode(5,OUTPUT);                  
    pinMode(6,OUTPUT);                  
    Serial.begin(9600);                                         // Baud rate set to 9600bps
}
void loop() {
    if(Serial.available() > 0)      // Ckeck for command Recieved
    {    
      state = Serial.read();
      Serial.println(state);  
      flag=0;
    }  
    if (state == 's' || state == 'S')     // Checking Command from User
    {
        stp();
        if(flag == 0){
          Serial.println("Stop");
          flag=1;
       }
    }
    else if (state == 'f' || state == 'F')
    {
        fwd();
        if(flag == 0)
        {
          Serial.println("Forward");
          flag=1;
         }
    }
    else if (state == 'b' || state == 'B')
    {
        back();
        if(flag == 0)
        {
          Serial.println("Backward");
          flag=1;
        }
    }
    else if (state == 'l' || state == 'L')
    {
        left();
        if(flag == 0)
        {
          Serial.println("Left");
          flag=1;
         }
    }
   else if (state == 'r' || state == 'R')
  {
        right();
        if(flag == 0)
        {
          Serial.println("Right");
          flag=1;
         }
    }
}                
//loop() ends here


void fwd()          // Forward
{
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
}
void back()          // Backward
{
  digitalWrite(8,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
}
void left()          //LEFT
{
  digitalWrite(7,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(8,LOW);
  digitalWrite(6,LOW);
}
void right()          // Right
{
  digitalWrite(7,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(6,LOW);
}
void stp()            // Robot STops
{
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}
