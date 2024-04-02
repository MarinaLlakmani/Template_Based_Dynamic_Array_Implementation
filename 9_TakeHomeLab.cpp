// 9_Takehome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<string>
#include "ListType.h"
using namespace std;

int main() {
    listType<int> fibonacci = listType<int>(20);
    listType<string> userInput = listType<string>(5);

    fibonacci.insert(1);
    fibonacci.insert(1);

    //TODO: Write a for loop to fill the for loop with elements
    // of the fibonacci sequence. Use isFull() as your terminating condition 
    //Fibonacci reminder: f(n) = f(n-1) + f(n-2)



    for (int i = 2; i <= 20 && !fibonacci.isFull(); i++) {
        int Element = fibonacci.get(i - 1) + fibonacci.get(i - 2);
        fibonacci.insert(Element);

    }

    fibonacci.remove(55);

    cout << fibonacci;

    cout << "Location of 89: " << fibonacci.search(89) << endl;
    cout << "Location of 14: " << fibonacci.search(14) << endl;

    string val;
    do {
        cout << "Enter a string to insert" << endl;
        getline(cin, val);
        if (val != "") {
            userInput.insert(val);
        }
    } while (!val.empty());

    //TODO: prompt the user for a string to search for
    // in userInput and remove it if it is there

    cout << "Enter a string to insert: ";
    getline(cin, val);
    if (userInput.search(val) != 1) {
        userInput.remove(val);
    }

    cout << userInput;
    userInput.destroyList();
}