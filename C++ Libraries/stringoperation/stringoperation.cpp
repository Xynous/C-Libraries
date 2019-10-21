//
//  stringoperation.cpp
//
//  Created by Ashleigh Day on 03/08/2019.
//  Copyright © 2019 Ashleigh. All rights reserved.
//
//
// The purpose of the C++ library "stringoperation" is to provide an abstraction layer for common programming tasks within the C++ programming language.
// The abstraction layer provides easy to use functions to perform common operations within the C++ programming language, without understanding the technical
// details and usage of the standard C++ libraries provided by the language.


#include <algorithm>	// Includes the "find()" and "replace()" function.
#include <string>		// Includes the "string" object/class.
#include <cstring>
#include <cstdlib>

std::string Replace(std::string stringValue, const std::string stringToReplace, const std::string newString)	//  Replaces function, which replaces a specific string value with a new string.
{
    std::string::size_type position = 0;		// Declared and initialized variable for character positioning, "size_type" type provides a large enough size for any string size which is calculated.

	int maximum_character_replacement = 1024;	// Maximum amount of characters which can be replaced, during string replacement operation. "1024" is the maximum number of characters what can be replaced (This should be enough by default).

    while((position = stringValue.find(stringToReplace, position)) != std::string::npos)	// Finds the first character/string to replace and returns the starting position to begin the string replacement process.
    {
        stringValue.replace(position, maximum_character_replacement, newString);	// Replaces the old string with the new string from the detected starting position of the string.
    }
    
    return stringValue;	
}

std::string toLower(std::string stringToLower)  // toLower function, which converts all characters within the string to lowercase.
{
    transform(stringToLower.begin(), stringToLower.end(), stringToLower.begin(), ::tolower);
    
    return stringToLower;
}

std::string toUpper(std::string stringToUpper)   // toUpper function, which converts all characters within the string to uppercase.
{
    transform(stringToUpper.begin(), stringToUpper.end(), stringToUpper.begin(), ::toupper);
    
    return stringToUpper;
}

int stringSize(std::string stringSize)   // Function returns the total size of a string.
{
    int returnSize = stringSize.size();
    
    return returnSize;
}

std::string* split(std::string stringToSplit, std::string delimiters)    // Function splits the passed string and returns the results, this function is a wrapper for the 'C Language' strtok implementation.
{

	std::string* returnedArray = new std::string[1024];		// String pointer array, with a set size of "1024" elements.
	int counter = 0;

   char stringToConvert[stringToSplit.size() + 1];		// Convert strings to character arrays for splitting
   char delimiterToConvert[delimiters.size() + 1];
   
   stringToSplit.copy(stringToConvert, stringToSplit.size() + 1);	// Copies the string data to a C style character array for processing.
   delimiters.copy(delimiterToConvert, delimiters.size() + 1);
   
   stringToConvert[stringToSplit.size()] = '\0';	// Sets the ending character in C style character arrays.
   delimiterToConvert[delimiters.size()] = '\0';
   
   char* tokens = strtok(stringToConvert, delimiterToConvert);	// Splits and returns the string tokens.

   while(tokens !=NULL)		// Assigns each split token to the string array, until the last delimiter within the string
   {
	   returnedArray[counter] = tokens;
	   tokens = strtok(NULL, delimiterToConvert);
	   counter++;
   }

    return returnedArray;	// Returns array base pointer, which gives access to all of the returned strings stored within the array.
}    
