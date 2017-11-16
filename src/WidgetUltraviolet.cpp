
#include "WidgetUltraviolet.h"


WidgetUltraviolet::WidgetUltraviolet(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pDataUltravioletTopic,0,sizeof(pDataUltravioletTopic));
    sprintf(pDataUltravioletTopic,"channel/ultraviolet_%d/data/uvIntensity",_Item);
}

WidgetUltraviolet::~WidgetUltraviolet()
{
    
}

void WidgetUltraviolet::begin(void (*UserCallBack)(void))
{

}

void WidgetUltraviolet::displayUltraviolet(float fUltraviolet)
{
	IntoRobot.publish(pDataUltravioletTopic,fUltraviolet);
}









