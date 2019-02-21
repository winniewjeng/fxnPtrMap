#include <cstdlib>
#include <iostream>
#include <ctime>
#include <map>
using namespace std;

//turing everything into pointer dereference to optimize speed

typedef void(*fptr)(); // fptr is a void function pointer

void up();
void down();
void left();
void right();
void nothing();
void quitProgram();
fptr mapFunc(string input);

int main(int argc, const char * argv[]) {
    
    map<string, fptr> aMap; //create a map of key: input, value: void function
    string input;
    cout << "Strat: ";
    while (true) {
        cin >> input;
        mapFunc(input)();
    }
    return 0;
}

void up() {
    cout << "Up!" << endl;
}
void down(){
    cout << "Down!" << endl;
}
void left() {
    cout << "Left!" << endl;
}
void right(){
    cout << "Right!" << endl;
}
void nothing(){
    //Do nothing, just an empty fxn
}

void quitProgram() {
    // exit the part of cstdlib to end the program
    exit(0);
}

// take an array of void fxns, return a map with string as key and fucntion as values
fptr mapFunc(string input) {
    // initialize a map
    map<string, fptr> myMap;
    // any un-mapped input gets assigned the nothing function
    myMap[input] = nothing;
    // if the input is mapped as key, another function is assigned based on key
    myMap["U"] = myMap["u"] = up;
    myMap["D"] = myMap["d"] = down;
    myMap["L"] = myMap["l"] = left;
    myMap["R"] = myMap["r"] = right;
    myMap["Q"] = myMap["q"] = quitProgram;
    
    return myMap.find(input)->second;
}
