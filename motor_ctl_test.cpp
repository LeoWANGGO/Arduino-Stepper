
int motor1_ena = 2;
int motor1_dir = 3;
int motor1_pul = 4;

void setup()
{
  // put your setup code here, to run once:
  pinMode(motor1_ena, OUTPUT);
  pinMode(motor1_dir, OUTPUT);
  pinMode(motor1_pul, OUTPUT);
}

//step_deg 转动角度, velocity 转/秒
void move_motor( boolean direction, unsigned int step_deg, int velocity)
{
  long pulse_r = 200; //每转脉冲数,由硬件设置决定
  long pulse_number = 0;
  long pulse_fre = 0;
  float T_pul = 0;

  if ((velocity <= 0)|(step_deg <= 0))
  {
    //输入参数错误,中断处理
  }
  else
  {
    pulse_fre = velocity * pulse_r; //脉冲频率
    T_pul = 1000 / pulse_fre;  //周期,ms
    pulse_number = (step_deg / 360) * pulse_r;// 需要走的脉冲数
  }

  //  digitalWrite(motor1_ena, HIGH);
  if (direction == 0)
  {
    digitalWrite(motor1_dir, HIGH);
  }
  else
  {
    digitalWrite(motor1_dir, LOW);
  }

  while (pulse_number > 0)
  {
    digitalWrite(motor1_pul, HIGH);
    delayMicroseconds(T_pul * 0.2);
    digitalWrite(motor1_pul, LOW);
    delayMicroseconds(T_pul * 0.8);
  }
  pulse_number --;
}

void loop()
{
  // put your main code here, to run repeatedly:
  move_motor(0, 90, 1);
  delay(1000);
  move_motor(1, 90, 1);
}
