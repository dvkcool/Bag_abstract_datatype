#include <iostream>
using namespace std;
#ifndef _REG_QUE
#define _REG_QUE
#include "Customer.hpp"

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
   void calculateStats();  //Private method to calculate stats

public:
  RegisterQueue();             // Constructor
  ~RegisterQueue();            // Destructor
  static double clock;         //Class variable clock
  void enqueue(Customer &a);   //enqueue operation
  void dequeue();              //dequeue operation
  void print();                // Public print method
  bool isEmpty();              // isEmpty method to check if queue is empty
};

#endif
