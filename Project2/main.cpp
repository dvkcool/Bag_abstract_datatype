#include "RegisterQueue.cpp"
#include "Customer.hpp"
#include <fstream>
using namespace std;

int main(){
    RegisterQueue checkoutLane;
    double checkOutTime;
    int items;

    ifstream myfile ("customer_checkout_data.txt");
    if (myfile.is_open()){
        while ( myfile >> checkOutTime >> items){
            Customer cust(checkOutTime, items) ;
            checkoutLane.enqueue(cust);
        }
        myfile.close();
    }else{
        throw(1);
    }

    while(!checkoutLane.isEmpty()){
        checkoutLane.dequeue();
    }

    checkoutLane.print();

    return 0;
}
