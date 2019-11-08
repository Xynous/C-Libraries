//
//  stringoperation.hpp
//
//  Created by Ashleigh Day on 03/08/2019.
//  Copyright © 2019 Ashleigh. All rights reserved.
//
//
// C++ header file which provides function prototypes for common programming operations within the C++ programming language,
// add the header file into your C++ project / solution for usage of the abstracted C++ libraries within the "stringoperation"
// source file.


#ifndef stringoperation_hpp
#define stringoperation_hpp

#include <string>	// Includes the "string" object/class.

#endif /* stringoperation_hpp */

std::string replace(std::string, const std::string, const std::string);	// Declared function / function prototype for string replace functionality

std::string toLowerCase(std::string);   // Declared function / function prototype for converting strings to lowercase

std::string toUpperCase(std::string);   // Declared function / function prototype for converting strings to uppercase

int size(std::string);    // Declared function / function prototype for calculating and returning the total string size

std::string* split(std::string, std::string);	 // Declared function / function prototype for splitting strings into tokens

bool findstring(std::string, std::string);  // Declared function / function prototype for finding a set of characters/strings

int find(std::string, std::string);    // Declared function / function prototype for finding a set of characters/strings

