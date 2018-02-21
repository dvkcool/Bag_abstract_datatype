#ifndef _CUSTOMER_
#define _CUSTOMER_
class Customer{
  public:
    int time;    //Time of entering to Lane
    int items;   //Number of items
    //Parameterized constructor
    Customer(int t, int i){
      time = t;
      items = i;
    }
};
#endif
