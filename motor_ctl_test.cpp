//TB6600驱动器
//采用共阳极接发，脉冲频率设置为600Hz，高低电压电平差4.2V
//低电平的持续时间为4us，占空比接近0.24%，可见其占空比很小
//当脉冲频率设置为1000Hz,脉冲宽度9us，占空比0.09%
//当脉冲频率设置为200Hz,脉冲宽度3.5us，占空比0.07%
//当脉冲频率设置为100Hz,脉冲宽度3.5us，

const int MOTOR1_ENA = 2;
const int MOTOR1_DIR = 3;
const int MOTOR1_PUL = 4;

void setup()
{
  // put your setup code here, to run once:
  pinMode(MOTOR1_ENA, OUTPUT);
  pinMode(MOTOR1_DIR, OUTPUT);
  pinMode(MOTOR1_PUL, OUTPUT);
}

//move_motor函数：step_deg 转动角度, velocity 转/秒
void move_motor( boolean direction, unsigned int step_deg, int velocity)
{
  const int PULSE_R = 200; //每转脉冲数,由硬件设置决定
  float pulse_number;
  float pulse_fre;
  float T_pul;

  pulse_fre = PULSE_R * velocity ; //脉冲频率
  T_pul = 1000 / pulse_fre; //周期,ms
  pulse_number = (step_deg / 360) * PULSE_R;// 需要走的脉冲数

  if (direction == 0)
  {
    digitalWrite(MOTOR1_DIR, HIGH);
  }
  else
  {
    digitalWrite(MOTOR1_DIR, LOW);
  }
  while (pulse_number > 0)
  {
    digitalWrite(MOTOR1_PUL, LOW);
    delayMicroseconds(T_pul * 0.01);
    digitalWrite(MOTOR1_PUL, HIGH);
    delayMicroseconds(T_pul * 0.99);
  }
  pulse_number--;
}
//delayMicroseconds(time);//延迟time微秒
//示波器实测最终输出会加上指令执行延时2.5us
//eg：delayMicroseconds(10);实际延时12.5us
void loop()
{
  // put your main code here, to run repeatedly:
  /* digitalWrite(MOTOR1_ENA, HIGH);
    move_motor(0, 1080, 5);
    digitalWrite(MOTOR1_ENA, LOW);
    delay(1000);

    digitalWrite(MOTOR1_ENA, HIGH);
    move_motor(1, 1080, 5);
    digitalWrite(MOTOR1_ENA, LOW);
    delay(1000);*/
    
  digitalWrite(MOTOR1_DIR, LOW);
  unsigned int number = 1080; unsigned int fre = 600;
  long Tm = 1000/fre;
  long Tu = Tm*1000;
  while (number > 0)
  {
    digitalWrite(MOTOR1_PUL, LOW);
    delayMicroseconds(Tu*0.005);
    digitalWrite(MOTOR1_PUL, HIGH);
    delayMicroseconds(Tu*0.995);
  }
  number--;
}
