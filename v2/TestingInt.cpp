// Katie Timmerman
// Assignment 1

#include <iostream>
#include "MagicBagInt.hpp"
using namespace std;

void basicTesting();
void moreTesting();
void emptyTesting();
int main() {

	basicTesting();
	emptyTesting();
	moreTesting();

}

void basicTesting(){
	MagicBag mb1;
	mb1.insert(1);
	mb1.insert(2);
	mb1.insert(3);

	cout << "Testing Peek on " << mb1 <<endl;
	cout << "The number of ones in the bag is " << mb1.peek(1) << endl;
	cout << "The number of twos in the bag is " << mb1.peek(2) << endl;
	cout << "The number of threes in the bag is " << mb1.peek(3) << endl;
	cout << "The number of fours in the bag is " << mb1.peek(4) << endl;
	cout << endl << endl;


	cout << "Testing Draw on " << mb1 <<endl;
	int itemDrawn = mb1.draw();
	cout << "A " << itemDrawn << " was drawn from the bag." << endl << endl;
	cout << "The number of ones in the bag is " << mb1.peek(1) << endl;
	cout << "The number of twos in the bag is " << mb1.peek(2) << endl;
	cout << "The number of three in the bag is " << mb1.peek(3) << endl;
	itemDrawn = mb1.draw();
	cout << "A " << itemDrawn << " was drawn from the bag." << endl << endl;
	cout << "The number of ones in the bag is " << mb1.peek(1) << endl;
	cout << "The number of twos in the bag is " << mb1.peek(2) << endl;
	cout << "The number of three in the bag is " << mb1.peek(3) << endl;
	cout << endl << endl;

	mb1.insert(1);
	mb1.insert(2);
	mb1.insert(3);

	cout << "Testing copy constructor on " << mb1 << endl;
	MagicBag mb2(mb1);
	cout << mb2<<endl;
	mb1.draw();
	mb1.draw();
	cout << "mb1 " << mb1 << endl;
	cout << "mb2 " << mb2 << endl;
	mb2.draw();
	cout << "mb1 " << mb1 << endl;
	cout << "mb2 " << mb2 << endl;


	cout << "Testing the ability to add an unlimited number of items." << endl;
	MagicBag mb3;
	for (int i = 0; i < 50; i++) {
		mb3.insert(i + 1);
	}
	cout << mb3 << endl << endl;
	for (int i = 0; i < 50000; i++) {
		mb3.insert(i + 1);
	}

	cout << "Testing = operator on " << mb1 << endl;
	mb3 = mb2 = mb1;
	cout << mb3 << endl << endl;
	mb2.draw();
	cout << mb2 << endl << endl;
	cout << mb1 << endl << endl;

}

void emptyTesting(){
	MagicBag mb1;

	cout << "Testing Peek on " << mb1 <<endl;
	cout << "The number of ones in the bag is " << mb1.peek(1) << endl;
	cout << endl << endl;

	cout << "Testing Draw on " << mb1 <<endl;
	try{
		int itemDrawn = mb1.draw();
	}catch(...){
		cout << "Draw handled empty";
	}
	cout << endl << endl;

	cout << "Testing copy constructor on " << mb1 << endl;
	MagicBag mb2(mb1);
	cout << mb2<<endl;
	try{
		int itemDrawn = mb2.draw();
	}catch(...){
		cout << "Draw handled empty";
	}

	cout << "Testing = operator on " << mb1 << endl;
	mb2 = mb1;
	cout << mb2 << endl << endl;
	cout << mb1 << endl << endl;

}

void moreTesting(){
	MagicBag mb1;
	mb1.insert(1);
	mb1.insert(2);
	mb1.insert(3);
	mb1.insert(1);
	mb1.insert(2);
	mb1.insert(3);
	mb1.insert(1);
	mb1.insert(2);
	mb1.insert(3);

	cout << "Testing Peek on " << mb1 <<endl;
	cout << "The number of ones in the bag is " << mb1.peek(1) << endl;
	cout << "The number of twos in the bag is " << mb1.peek(2) << endl;
	cout << "The number of threes in the bag is " << mb1.peek(3) << endl;
	cout << "The number of fours in the bag is " << mb1.peek(4) << endl;
	cout << endl << endl;

	for(int i = 0; i < 10; i++){
		cout << "Testing Draw on " << mb1 <<endl;
		try{
			int itemDrawn = mb1.draw();

			cout << "A " << itemDrawn << " was drawn from the bag." << endl << endl;
			cout << "The number of ones in the bag is " << mb1.peek(1) << endl;
			cout << "The number of twos in the bag is " << mb1.peek(2) << endl;
			cout << "The number of three in the bag is " << mb1.peek(3) << endl;
		}catch(...){
			cout << "Draw handled empty";
		}
	}
	cout << endl << endl;

	cout << "Testing the ability to add an unlimited number of items." << endl;
	MagicBag mb3;
	for (int i = 0; i < 5000; i++) {
		mb3.insert(i + 1);
	}
	cout << mb3 << endl << endl;

}
