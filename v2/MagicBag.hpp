#include <iostream>
using namespace std;
#ifndef _MAGIC_BAG_
#define _MAGIC_BAG_

template <class bag_type>

class MagicBag {

private:
   int count;     // members in bag
   int max;       // Initially 10 but increases according to the requirement
   bag_type*  data;      // data store to store  values

public:
             MagicBag();                        // Constructor
             MagicBag(const MagicBag& other);   //Copy Constructor
            ~MagicBag();                        //Destructor
   void      insert(bag_type item);             // Put a member in the bag
   bag_type  draw();                            //Draw a random item and delte it
   int       peek(bag_type item);               // To see how many elements with same data are present
  MagicBag<bag_type>& operator=( const MagicBag<bag_type>& other); //Assignment Operator overloading
  template <class b> friend    ostream& operator<<(ostream& os, const MagicBag<b>& me); //Friend function to output the bag
};
#include "MagicBag.cpp"
#endif
