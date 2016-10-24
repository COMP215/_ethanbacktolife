#include <vector>
#include <Mushroom.h>

#ifndef SATCHEL_H
#define SATCHEL_H


class Satchel
{
     public:
        Satchel();
        virtual ~Satchel();
        std::vector<Mushroom> satchel;
        short getWeight();
};

#endif // SATCHEL_H
