#include "RegisterQueue.hpp"
#include<stdlib.h>
#include<malloc.h>
using namespace std;

 // Constructor
RegisterQueue::RegisterQueue(){
  *front = NULL;
  *rear = NULL;
  clockt = 0.0;
  maxlength = 0;
  len = 0;
}

RegisterQueue::~RegisterQueue(){
  while(front!=NULL){
    dequeue();
  }
  front = NULL;
  rear = NULL;
}

void RegisterQueue::enqueue(Customer a){
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
  temp->cust = a;

  //Checking waitig time
  if(clockt > a.time){
    waittime.push_back(clockt-a.time);
  }
  else{
    waittime.push_back(0.0);
  }

  //Checking Length of Lane
  if(clockt > a.time){
    len++;
  }
  else{
    // Resetting length of queue and checking for max length
    if(maxlength<len){
      maxlength=len;
    }
    len =0;
  }

  // Updating clock time
  if(clockt < a.time){
    clockt = a.time;
  }

  //Updating clock time to checkout time of customer

  //Billing time addition 0.01 minutes per item
  clockt = clockt + 0.01 * a.items;

  //Payment time addition i.e. 1.5 minutes
  clockt = clockt + 1.5;
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
  //Mean calculation
  double sum = 0.0;
  for(int i=0; i< waittime.size(); i++){
    sum = sum + waittime.at(i);
  }
  cout<<"\n Mean waiting time of customers: "<< sum/ waittime.size()<<" minutes\n";

  //Median calculation
  //Even customers
  double median;
  if( waittime.size()%2==0){
    //If even then sum of the two middle values
    median =  waittime.at( waittime.size()/2)+  waittime.at( waittime.size()/2 - 1);
  }
  else{
    //Odd number of customers
    median =  waittime.at( waittime.size()/2);
  }
  cout<<" Median waiting time of customers: "<< median<<" minutes\n";

  //Percentage of customers more than 2 minutes
  double sum2 = 0.0;
  for(int i=0; i< waittime.size(); i++){
    if(waittime.at(i) > 2.0){
      sum2++;
    }
  }
  cout<<"Percentage of Customers who waited for more than 2 minutes "<< sum2/waittime.size() *100 <<'%'<<"\n";

  //Percentage of customers more than 3 minutes
  sum2 = 0.0;
  for(int i=0; i< waittime.size(); i++){
    if(waittime.at(i) > 3.0){
      sum2++;
    }
  }
  cout<<"Percentage of Customers who waited for more than 3 minutes "<< sum2/waittime.size() *100 <<'%'<<"\n";

  //Percentage of customers more than 5 minutes
  sum2 = 0.0;
  for(int i=0; i< waittime.size(); i++){
    if(waittime.at(i) > 5.0){
      sum2++;
    }
  }
  cout<<"Percentage of Customers who waited for more than 5 minutes "<< sum2/waittime.size() *100 <<'%'<<"\n";

  //Percentage of customers more than 10 minutes
  sum2 = 0.0;
  for(int i=0; i< waittime.size(); i++){
    if(waittime.at(i) > 10.0){
      sum2++;
    }
  }
  cout<<"Percentage of Customers who waited for more than 2 minutes "<< sum2/waittime.size() *100 <<'%'<<"\n";

  //Total number of customers that passed through the Lane
  cout<<"Total number of customers that passed through the Lane: "<< waittime.size()<<" customers \n";

  //Max Length of queue at the Lane
  cout<<" Maximum length of queue in the checkout lane: "<< maxlength<<"\n";



}

void RegisterQueue::print(){
  calculateStats();
}

bool RegisterQueue::isEmpty(){
  return (front==NULL);
}
