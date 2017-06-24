// Arduino IDE自带stepper.h库文件

# include<Stepper.h>

//定义每圈步数
# define STEPS 100
//设置步进电机的步数和引脚
Stepper stepper (STEPS,8,9,10,11);
//定义变量存储历史读数
int previous = 0;

void setup()
{
  //设置电机每分钟的转速为90步
  stepper.setSpeed(90);
}

void loop()
{
  //获取传感器读数
  int val = analogRead(0);
  //移动步数为当前读数减去历史读数
  stepper.step(val-previous);
  previous = val;
}

