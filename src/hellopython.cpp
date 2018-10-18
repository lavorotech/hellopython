//============================================================================
// Name        : hellopython.cpp
// Author      : Keith Thomson
// Version     :
// Copyright   : BSD Licensed
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const char * get_greetings()
    {
    return "!!!Hello World!!!";
    }

int hello() 
    {
	cout << get_greetings() << endl; // prints !!!Hello World!!!
	return 0;
    }
