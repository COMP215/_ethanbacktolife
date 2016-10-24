#include "Satchel.h"

Satchel::Satchel()
{
    //ctor
}

Satchel::~Satchel()
{
    //dtor
}
short Satchel::getWeight()
{
    short weight = 0;
    for (short i = 0; i < satchel.size(); i++)
    {
       weight += satchel.at(i).quantity_;
    }
}
