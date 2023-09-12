//include gaurd
#ifndef TORNADO_H
#define TORNADO_H
#include <string>
using namespace std;


//Declaring enum datatype
enum Category{TBD,F0,F1,F2,F3,F4,F5};


//Class declaration named Tornado
class Tornado
{
private:
    string location;
    Category cat;     //Enumerated data type
    double damage;


public:
   // Constructor #1 (default constructor)
   Tornado()
   {
       location = "";
       cat = TBD;
       damage = 0.0;

   }

     // Constructor #2
   Tornado(string loc,Category c, double d)
      {
        // Assign values to Location, Category, and Damage.
		location = loc;
        cat = c;
        damage = d;
      }

    //Mutator Functions
    void setLocation(string loc);
    void setCategory(Category c);
    void setDamage(double d);

    //Accessor Functions
    string getLocation() const;
    Category getCategory() const;
    double getDamage() const;


};

#endif




