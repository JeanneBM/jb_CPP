#ifndef SMARTPOINTITEM_H
#define SMARTPOINTITEM_H

#include <QRgb>

class SmartPointItem
{
public:
    SmartPointItem() {
        x = 0;
        y = 0;
        radius = 0;
        rgb = 0;
    }

    int x;
    int y;
    int radius;
    QRgb rgb;
};

#endif // SMARTPOINTITEM_H

