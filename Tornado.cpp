//Member functions for the storm program
#include <iostream>
#include "Tornado.h"

using namespace std;

//Tornado member function to set the location of the item
void Tornado::setLocation(string loc)
{
    location = loc;

    return;
}

//Tornado member function to set the category of the item

void Tornado::setCategory(Category c)
{
    cat = c;
}

//Tornado member function to set the damage of the item
void Tornado::setDamage(double d)
{

    if (d > 0)
    damage = d;
    else
    {
        cout <<"Invalid input setting damage to 0!|n";
        damage = 0;
    }


    return;
}

//Tornado member function to return the location of the item
string Tornado::getLocation() const
{
    return location;

}

//Tornado member function to return the category of the item
Category Tornado:: getCategory() const
{
    return cat;
}

//Tornado member function to return the damage of the item
double Tornado::getDamage() const
{
    return damage;
}






