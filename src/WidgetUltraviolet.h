#ifndef WIDGET_ULTRAVIOLET_H_
#define WIDGET_ULTRAVIOLET_H_

#include "application.h"


class WidgetUltraviolet
{
public:
    WidgetUltraviolet(uint8_t ucItem = 0);
    ~WidgetUltraviolet();
    void begin(void (*UserCallBack)(void) = NULL);
    void displayUltraviolet(float fUltraviolet);

    
private:
    char pDataUltravioletTopic[64];
    uint8_t _Item=0;         
};

#endif
