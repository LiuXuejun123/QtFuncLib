#include "sfobject.h"

SFObject::SFObject()
{

}
void SFObject::Update(const QStringList& Csvdata,const QStringList& Header,int ID,double Vehself_Spd,E_Platform Platform)
{
    if(E_Platform::FVC3 == Platform)
    {
        QString str1 = "Obj[" + QString::number(ID) + "].";
        this->PosnLgt = Csvdata[Header.indexOf(str1+"Estimn.PosnLgt")].toDouble();
        this->PosnLat = Csvdata[Header.indexOf(str1+"Estimn.PosnLat")].toDouble();
        this->VLgt = Csvdata[Header.indexOf(str1+"Estimn.VLgt")].toDouble();
        this->VLat = Csvdata[Header.indexOf(str1+"Estimn.VLat")].toDouble();
        this->object_ID = Csvdata[Header.indexOf(str1+"Ppty.Idn")].toInt();
        this->FusionSrc = Csvdata[Header.indexOf(str1+"Ppty.FusnSrc")].toInt();
        this->Length = Csvdata[Header.indexOf(str1+"Info.Length")].toDouble();
        this->Width = Csvdata[Header.indexOf(str1+"Info.Width")].toDouble();
        this->Type_Number = Csvdata[Header.indexOf(str1+"Info.Typ")].toInt();
        this->SideNear = Csvdata[Header.indexOf(str1+"Info.SideNear")].toInt();
    }
    else if (E_Platform::FVC2_8 == Platform)
    {
        QString str1 = "obj[" + QString::number(ID) + "].";
        this->PosnLgt = Csvdata[Header.indexOf(str1+"Estimn.PosnLgt")].toDouble();
        this->PosnLat = Csvdata[Header.indexOf(str1+"Estimn.PosnLat")].toDouble();
        this->VLgt = Csvdata[Header.indexOf(str1+"Estimn.VLgt")].toDouble();
        this->VLat = Csvdata[Header.indexOf(str1+"Estimn.VLat")].toDouble();
        this->object_ID = Csvdata[Header.indexOf(str1+"Ppty.Idn")].toInt();
        this->FusionSrc = Csvdata[Header.indexOf(str1+"Ppty.FusnSrc")].toInt();
        this->Length = Csvdata[Header.indexOf(str1+"Info.Length")].toDouble();
        this->Width = Csvdata[Header.indexOf(str1+"Info.Width")].toDouble();
        this->Type_Number = Csvdata[Header.indexOf(str1+"Info.Typ")].toInt();
        this->SideNear = Csvdata[Header.indexOf(str1+"Info.SideNear")].toInt();
    }

    this->calculateTTC(Vehself_Spd);
    this->calculateTimeGap(Vehself_Spd);
}
bool SFObject::isObjectValid()//判断有效位及长宽比例
{
    if((this->object_ID != 0)&&(this->Width >=0.45)&&(this->Length >= 0.45))
    {
        return true;
    }
    else
    {
        return false;
    }

}
void SFObject::calculateTTC(double vehself_Spd)
{
    double diffSpd = vehself_Spd - this->VLgt;
    this->TTC = this->PosnLgt/diffSpd;
    double MaxValue =100;
    double MinValue =-100;
    if (this->TTC < MinValue)
    {
        this->TTC = MinValue;
    }
    else if(this->TTC > MaxValue)
    {
        this->TTC = MaxValue;
    }
    else
    {

    }
}
void  SFObject::calculateTimeGap(double vehself_Spd)
{
    this->TG = this->PosnLgt/vehself_Spd;
}

