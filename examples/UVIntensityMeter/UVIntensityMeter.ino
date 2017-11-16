/*
************************************************************************
* 作者:  IntoRobot Team 
* 版本:  V1.0.0
* 日期:  03-30-15
************************************************************************
功能描述：
紫外线强度计：检测紫外线强度

所需器件:
1.紫外线检测传感器

接线说明:
紫外线检测传感器              Atom
1.VIN                         +5V
1.3.3v                        悬空
2.GND                         GND
3.OUT                         A0
4.EN                          悬空
*/

#include <WidgetUltraviolet.h>

#define SENSOR_PIN    A0 //紫外线AD转换脚

WidgetUltraviolet ultraviolet = WidgetUltraviolet();

//针对于浮点数的map函数
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
    if(x < in_min) 
    {
    	x = in_min;
   	}

    if(x>in_max) 
    {
    	x = in_max;
    }

	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float CalculateUVintensity(void)
{
	float outputVoltage = 0;
	outputVoltage = 3.3 * analogRead(SENSOR_PIN)/4095; //计算电压
	return mapfloat(outputVoltage, 0.99, 2.9, 0.0, 15.0);
}

void setup()
{
	pinMode(SENSOR_PIN, INPUT);
}

void loop()
{
	ultraviolet.displayUltraviolet(CalculateUVintensity());
	delay(3000);
}
