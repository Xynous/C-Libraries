//
//  main.cpp
//
//  Created by Ashleigh Day on 03/08/2019.
//  Copyright © 2019 Ashleigh. All rights reserved.
//
//
// Simple console application program which demonstrates the usage of the "Replace" function within the
// "stringoperation".


#include <iostream>				// Header defines the standard input/output stream.
#include "stringoperation.hpp"	// Header defines the "stringoperation.hpp" functions.

int main(int argc, const char * argv[]) {
    
    std::string stringValue = "Hello World, my name is Bob";	// Declared and initialized string variables for basic demonstration.
    std::string stringToReplace = "Bob";
    std::string newString = "Sarah";

    std::string returnValue = Replace(stringValue, stringToReplace, newString);	// Calls the "Replace" function and expects three string parameters.

    std::cout << returnValue << std::endl;	// Outputs the results to the console.
    
    return 0;
}
