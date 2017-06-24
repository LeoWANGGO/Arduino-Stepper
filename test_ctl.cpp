int PUL = 7;
int DIR_1 = 6;

void setup()
{
  //set up here
  pinMode (DIR_1, OUTPUT);
  pinMode (PUL_1, OUTPUT);
}

void Motor_one_up (unsinged int number, unsigned int time)
{
  unsigned char i=1;
  digitalWrite(DIR,HIGH)
  while(number>0)
  {
  if(i==1)
    {
      digitalWrite(PUL,HIGH);
      delayMicroseconds(time);
      
    
    }
  }
}
