#include "RegisterQueue.hpp"
#include<stdlib.h>
#include<malloc.h>
using namespace std;

 // Constructor
RegisterQueue::RegisterQueue(){
  *front = NULL;
  *rear = NULL;
}

RegisterQueue::~RegisterQueue(){
  while(front!=NULL){
    dequeue();
  }
  front = NULL;
  rear = NULL;
}

void RegisterQueue::enqueue(Customer &a){
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  if(front==NULL){
    front = temp;
    rear = temp;
  }
  else{
    rear->next = temp;
    temp->next = NULL;
    rear = temp;
  }
  temp->cust = *a;
}
