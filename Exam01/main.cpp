#include <iostream>
#include "Mushroom.h"
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    struct sortWeight {
    bool operator() (Mushroom shroom_1, Mushroom shroom_2)
    { float value_1 = shroom_1.total_quantity_val_ / shroom_1.quantity_;
      float value_2 = shroom_2.total_quantity_val_ / shroom_2.quantity_;
      return (value_1 > value_2);
    }
} shroom_weight;
    char file_name[] = "mushrooms_1.csv";
    char buffer[] = "";
    char common_name[] = "";
    char scientific_name[] = "";
    short quantity;
    short room_left;
    float total_quantity_val;
    Mushroom temp_shroom;
    vector<Mushroom> satchel;
    vector <Mushroom> cache;
    short satchel_weight = 0;
    const short SATCHEL_SIZE = 30;
    FILE* file_pointer = fopen(file_name, "r");
    fgets(buffer, 500, file_pointer);
    while (fscanf(file_pointer, "%s, %s, %i, %f",
    common_name, scientific_name, quantity, total_quantity_val) != EOF) {

        temp_shroom.common_name_ = common_name;
        temp_shroom.scientific_name_ = scientific_name;
        temp_shroom.quantity_ = quantity;
        temp_shroom.total_quantity_val_ = total_quantity_val;
        cache.push_back(temp_shroom);
    }

    sort(cache.begin(), cache.end(), shroom_weight);

    Mushroom curr_shroom;
    float shroom_val;
    float total_val = 0;
    while (satchel_weight < SATCHEL_SIZE)
    {
        curr_shroom = cache.back();
        cache.pop_back();

        if (satchel_weight + curr_shroom.quantity_ < SATCHEL_SIZE)
        {
            satchel_weight += curr_shroom.quantity_;
            total_val += curr_shroom.total_quantity_val_;
        }
        else
        {
            room_left = SATCHEL_SIZE - satchel_weight;
            shroom_val = curr_shroom.total_quantity_val_ / curr_shroom.quantity_;
            new_total_quantity_val =
            curr_shroom.quantity_ = room_left;
            satchel_weight += room_left;

            total_val += new_total_quantity_val

        }
         satchel.push_back(curr_shroom);
    }
    for (short i = 0; i < satchel.size(); i++)
    {
        cout <<
    }
}
