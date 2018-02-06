## Steps for compilation
```sh
# Compiling for Int
$  g++ -c MagicBagInt.cpp -o MagicBagInt.o
$  g++ -c TestingInt.cpp -o TestingInt.o
# To see the output
$  g++ TestingInt.o  MagicBagInt.o -o  Inttest
# Compiling for ADT
$  g++ -c MagicBag.cpp -o MagicBag.o
$  g++ -c TestingADT.cpp -o TestingADT.o
# To see the output
$  g++ TestingADT.o  MagicBag.o -o  ADTtest
```

## Pre-compiled demo
I have included the compiled outputs in demo folder, for your reference

## Bugs in TestingADT.cpp
The file uses MagicBag.h instead of MagicBag.hpp in row 5.
It has called a function testString() in main() in row 20 which is never defined.
However the MagicBag.cpp is combatible to create strings too, in case instructor wants to test them later with modifications.
Also I have included MagicBag.h, in case instructor wants to run the TestingADT.cpp without modifications, but correct way is to include MagicBag.hpp instead.
A proper README is also attached with instructions to compile.
