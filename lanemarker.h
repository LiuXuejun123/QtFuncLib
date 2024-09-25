#ifndef LANEMARKER_H
#define LANEMARKER_H

#include "lanemkr.h"
class LaneMarker
{
public:
    LaneMkr LeftLeft;
    LaneMkr Left;
    LaneMkr Right;
    LaneMkr RightRight;
    LaneMarker();
    void Update(const QStringList& Csvdata,const QStringList& Header,E_Platform Platform);

private:

};


#endif // LANEMARKER_H
