#include "lanemarker.h"

LaneMarker::LaneMarker()
{

}
void LaneMarker::Update(const QStringList& Csvdata,const QStringList& Header,E_Platform Platform)
{
    this->LeftLeft.Update(Csvdata,Header,E_LanePosition::SecClsLe,Platform);
    this->Left.Update(Csvdata,Header,E_LanePosition::ClsLe,Platform);
    this->Right.Update(Csvdata,Header,E_LanePosition::ClsRi,Platform);
    this->RightRight.Update(Csvdata,Header,E_LanePosition::SecClsRi,Platform);
}

