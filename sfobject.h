#ifndef SFOBJECT_H
#define SFOBJECT_H

#include "lanemkr.h"
#include "general.h"
#include "CustomDataType.h"
class SFObject
{
public:
    double PosnLgt;
    double PosnLat;
    double Width;
    double Length;
    double VLgt;
    double VLat;
    int FusionSrc;
    int SideNear;
    int object_ID;
    int Type_Number;

    double Dis2LeftLane;
    double Dis2RigthLane;
    double Dis2Host;
    double TG;
    double TTC;

    SFObject();
    void Update(const QStringList& Csvdata,const QStringList& Header,int ID,double Vehself_Spd,E_Platform Platform);
    bool isObjectValid();//判断有效位及长宽比例
    E_FusionSrc PlotColorMode();
private:
    void calculateTTC(double vehself_spd);
    void calculateTimeGap(double vehself_spd);
};


#endif // SFOBJECT_H
