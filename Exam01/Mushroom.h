#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <string>

class Mushroom
{
    public:
        Mushroom();
        virtual ~Mushroom();
        //Mushroom(string name, string scientific_name, short amount, short total_value);
        std::string common_name_;
        std::string scientific_name_;
        short quantity_;
        float total_quantity_val_;


};

#endif // MUSHROOM_H
