#include <iostream>
using namespace std;
#ifndef _REG_QUE
#define _REG_QUE
#include "Customer.hpp"
#include <vector>
// Nodde for Queue
struct node{
  Customer cust;
  struct node* next; //Pointer to next node
};
typedef struct node Node;

class RegisterQueue {

private:
   Node *front;
   Node *rear;
   void calculateStats();          //Private method to calculate stats
   double clocktime;           //Class variable clock time
   vector <double> waittime;       //waiting time by each customer
   int maxlength;                  //max length of Customers
   int len;                        // Lane length at any time

public:
  RegisterQueue();             // Constructor
  ~RegisterQueue();            // Destructor
  void enqueue(Customer a);   //enqueue operation
  void dequeue();              //dequeue operation
  void print();                // Public print method
  bool isEmpty();              // isEmpty method to check if queue is empty
};

#endif
