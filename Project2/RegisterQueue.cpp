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

void RegisterQueue::dequeue(){
  if(front==rear){
    free(front);
    front = NULL;
    rear = NULL;
  }
  else if(front!=NULL){
    Node *temp;
    temp = front;
    front = front->next;
    free(temp);
  }
}

void RegisterQueue::calculateStats(){

}

void RegisterQueue::print(){

}

bool RegisterQueue::isEmpty(){
  return (front==NULL);
}
