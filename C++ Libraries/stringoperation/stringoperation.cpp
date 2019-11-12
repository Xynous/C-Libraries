//
//  stringoperation.cpp
//
//  Created by Ashleigh Day on 03/08/2019.
//  Copyright © 2019 Ashleigh Day. All rights reserved.
//
//
// The purpose of the C++ library "stringoperation" is to provide an abstraction layer for common programming tasks within the C++ programming language.
// The abstraction layer provides easy to use functions to perform common operations within the C++ programming language, without understanding the technical
// details and usage of the standard C++ libraries provided by the language.


#include <algorithm>	// Include directives
#include <string>		
#include <cstring>
#include <cstdlib>

std::string replace(std::string stringValue, const std::string stringToReplace, const std::string newString)	//  replaces function replaces a specific string value with a new string.
{
    std::string::size_type position = 0;		// Declared and initialized variable for character positioning, "size_type" type provides a large enough size for any string size which is calculated.

	int maximum_character_replacement = 1024;	// Maximum amount of characters which can be replaced, during string replacement operation. "1024" is the maximum number of characters what can be replaced (This should be enough by default).

    while((position = stringValue.find(stringToReplace, position)) != std::string::npos)	// Finds the first character/string to replace and returns the starting position to begin the string replacement process.
    {
        stringValue.replace(position, maximum_character_replacement, newString);	// Replaces the old string with the new string from the detected starting position of the string.
    }
    
    return stringValue;	
}

std::string toLowerCase(std::string stringToLower)  // toLowerCase function converts all characters within the string to lowercase.
{
    transform(stringToLower.begin(), stringToLower.end(), stringToLower.begin(), ::tolower);
    
    return stringToLower;
}

std::string toUpperCase(std::string stringToUpper)   // toUpperCase function converts all characters within the string to uppercase.
{
    transform(stringToUpper.begin(), stringToUpper.end(), stringToUpper.begin(), ::toupper);
    
    return stringToUpper;
}

int size(std::string stringSize)   // Function returns the length of a string in bytes
{
    int returnSize = stringSize.size();
    
    return returnSize;
}

std::string* split(std::string stringToSplit, std::string delimiters)    // Function splits the passed string and returns the results, this function is a wrapper for the 'C Language' strtok implementation.
{
	std::string characters = "\t\n\v\f\r ";
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

   for(int i = 0; i < counter; i++)	// For loop removes leading and trailing whitespaces within each string split.
   {
   		returnedArray[i].erase(0, returnedArray[i].find_first_not_of(characters));

   		returnedArray[i].erase(returnedArray[i].find_last_not_of(characters) + 1);
   }

   return returnedArray;	// Returns array base pointer, which gives access to all of the returned strings stored within the array.
}

bool findstring(std::string stringToSearch, std::string stringToFind)   // Functions checks if a set of characters/strings can be found, returns true (1) if characters are found and false (0) if not found.
{
    std::size_t found = stringToSearch.find(stringToFind);
    
    bool stringFound = false;
    
    if (found!=std::string::npos) {
        
        stringFound = true;
    }
    
    return stringFound;
}

int find(std::string stringToSearch, std::string stringToFind) // Function checks if a set of characters/strings can be found, returns the starting position of the character/string if found and returns "string::npos" (0) if character/string cannot be found.
{
    std::size_t found = stringToSearch.find(stringToFind);
    
    std::size_t positionReturn;
    
    if (found!=std::string::npos) {
        
        positionReturn = found;
    }
    
    return positionReturn;
}

std::string trim(std::string stringValue, std::string trimmingOption)  // Function trims the passed string and returns the results.
{
	std::string errorMessage;
	std::string characters = "\t\n\v\f\r ";
    std::string convertToUpperCase = toUpperCase(trimmingOption);

    if(convertToUpperCase == "L")	// Condition checks if the passed trimming operation is a left trim, which removes whitespaces at the start of the string.
    {
    	stringValue.erase(0, stringValue.find_first_not_of(characters));
    }

    if(convertToUpperCase == "R")	// Condition checks if the passed trimming operation is a right trim, which removes whitespaces at the end of the string.
    {
    	stringValue.erase(stringValue.find_last_not_of(characters) + 1);
    }

    if(convertToUpperCase == "A")	// Condition checks if the passed trimming operation is a trim all operation, which removes leading and trailing whitespaces.
    {
    	stringValue.erase(0, stringValue.find_first_not_of(characters));

    	stringValue.erase(stringValue.find_last_not_of(characters) + 1);
    }

    if(convertToUpperCase != "L" && convertToUpperCase !="R" && convertToUpperCase !="A")   // Condition checks if the trimming operation is valid.
    {
    	errorMessage = "Error: Invalid trimming operation, refer to the project wiki for the list of trimming operations";

    	return errorMessage;
    }

    if(convertToUpperCase.empty() || stringValue.empty())	// Condition checks if the passed string value and trimming option is empty.
    {
        errorMessage = "Error: String and trimming operation cant be empty, refer to the project wiki for further information and examples";

        return errorMessage;
    }
    
    return stringValue;
}
