
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

MagicBag::MagicBag()    // Constructor
{
   // set the initial state of the bag
   count = 0;
   //set initial max length to 10
   max = 10;
   //getting fresh address for data
   data = new bag_type[max];
  srand((int)time(0));
}

MagicBag::MagicBag(const MagicBag& other)    // Copy Constructor
{
   // Copying all the data members of the Magic bag
   count=other.count;
   max = other.max;
   data = other.data;
}

MagicBag::~MagicBag()  // Destructing the  magic bag
{
   count=0;
}

void MagicBag::insert(bag_type value) //Place a value in Bag
{
    if(count < max){
    data[count] = value;
    count ++;
   }
   if (count >= max) {
    max = max * 2;                        // double the previous size
    bag_type* temp = new bag_type[max]; // create new bigger array.
    for (int i=0; i<count; i++) {
        temp[i] = data[i];       // copy values to new array.
    }
    delete data;                 // free old array memory, Handling memory leak
    data = temp;                 // now data points to new array.
    data[count] = value;         // setting the entered value itself
    count ++;
  }
}

bag_type MagicBag::draw()  //Draw and delete a random item
{
  bag_type rv;
  if(count ==0){
    throw std::invalid_argument( "Empty bag" );
    return rv;
  }
  int ri = rand();    //Perfect random integer
  ri = ri% count;
  rv = data[ri];
  for(; ri<(count-1); ri++){
    data[ri] = data[ri+1];  //Shifting value of array one step back for deleting the random value
  }
  count--;              //Decreasing the size of elements present
  return rv;
}

int MagicBag::peek(bag_type value) //How many of element;
{
   int thismany=0;
   int index;
   for(index=0;index<count;index++)
      if(data[index]==value) thismany++;
   return thismany;
}

MagicBag& MagicBag::operator=( const MagicBag& other){
  // Copying all the data members of the Magic bag
  count=other.count;
  max = other.max;
  data = other.data;
  return *this;
}

ostream& operator<<(ostream& os, const MagicBag& me){
  os<<"[";
  for(int i=0; i<me.count; i++){
    os<< me.data[i];
    if(i!=(me.count-1)){
      os<<", ";
    }
  }
  os<<"]";
  return os;
}
