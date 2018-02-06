// Katie Timmerman
// Assignment 1
#include <stdlib.h> //srad, rand
#include <iostream>
#include "MagicBag.hpp"

using namespace std;

void testInt();
void testDouble();
void testChar();
void basicTesting();
void moreTesting();
void emptyTesting();

int main() {
 	testInt();
	testDouble();
	testChar();
	//testString();
	return 0;

}

void testInt(){
	basicTesting();
	emptyTesting();
	moreTesting();

}

void basicTesting(){
	MagicBag<int> mb1;
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
	MagicBag<int> mb2(mb1);
	cout << mb2<<endl;
	mb1.draw();
	mb1.draw();
	cout << "mb1 " << mb1 << endl;
	cout << "mb2 " << mb2 << endl;
	mb2.draw();
	cout << "mb1 " << mb1 << endl;
	cout << "mb2 " << mb2 << endl;


	cout << "Testing the ability to add an unlimited number of items." << endl;
	MagicBag<int> mb3;
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
	MagicBag<int> mb1;

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
	MagicBag<int> mb2(mb1);
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
	MagicBag<int> mb1;
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
	MagicBag<int> mb3;
	for (int i = 0; i < 5000; i++) {
		mb3.insert(i + 1);
	}
	cout << mb3 << endl << endl;

}


void testDouble(){
	MagicBag<double> mb1;
	mb1.insert(1.5);
	mb1.insert(2.6);
	mb1.insert(3.7);

	cout << mb1 << endl << endl;

	MagicBag<double> mb2(mb1);

	cout << "The number of 1.5's in the bag is " << mb1.peek(1.5) << endl;
	cout << "The number of 2.6's in the bag is " << mb1.peek(2.6) << endl;
	cout << "The number of 3.7's in the bag is " << mb1.peek(3.7) << endl;
	cout << endl;

	double itemDrawn = mb1.draw();
	cout << "A " << itemDrawn << " was drawn from the bag." << endl << endl;

	cout << "The number of 1.5's in the bag is " << mb1.peek(1.5) << endl;
	cout << "The number of 2.6's in the bag is " << mb1.peek(2.6) << endl;
	cout << "The number of 3.7's in the bag is " << mb1.peek(3.7) << endl;
	cout << endl;

	cout << mb1 << endl;
	cout << mb2 << endl << endl;


	// Testing the ability to add an "unlimited" number of items
	MagicBag<double> mb3;
	for (int i = 0; i < 301; i++) {
		mb3.insert(i * 100 / 3.33);
	}
	cout << mb3 << endl << endl;

	mb3 = mb2 = mb1;
	cout << mb3 << endl << endl;
}

void testChar(){
	MagicBag<char> mb1;
	mb1.insert('a');
	mb1.insert('b');
	mb1.insert('c');

	cout << mb1 << endl << endl;

	MagicBag<char> mb2(mb1);

	cout << "The number of a's in the bag is " << mb1.peek('a') << endl;
	cout << "The number of b's in the bag is " << mb1.peek('b') << endl;
	cout << "The number of c's in the bag is " << mb1.peek('c') << endl;
	cout << endl;

	char itemDrawn = mb1.draw();
	cout << "A " << itemDrawn << " was drawn from the bag." << endl << endl;

	cout << "The number of a's in the bag is " << mb1.peek('a') << endl;
	cout << "The number of b's in the bag is " << mb1.peek('b') << endl;
	cout << "The number of c's in the bag is " << mb1.peek('c') << endl;
	cout << endl;

	cout << mb1 << endl;
	cout << mb2 << endl << endl;


	// Testing the ability to add an "unlimited" number of items
	MagicBag<char> mb3;
	for (int i = 0; i < 301; i++) {
		mb3.insert(rand() % 26 + 97);
	}
	cout << mb3 << endl << endl;

	mb3 = mb2 = mb1;
	cout << mb3 << endl << endl;
}
