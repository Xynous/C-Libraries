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

std::string Replace(std::string stringValue, const std::string stringToReplace, const std::string newString)	//  Replaces function, which replaces a specific string value with a new string.
{
    std::string::size_type position = 0;		// Declared and initialized variable for character positioning, "size_type" type provides a large enough size for any string size which is calculated.

	int maximum_character_replacement = 1024;	// Maximum amount of characters which can be replaced, during string replacement operation. "1024" is the maximum number of characters what can be replaced (This should be enough by default).

    while((position = stringValue.find(stringToReplace, position)) != std::string::npos)	// Finds the first character/string to replace and returns the starting position to begin the string replacement process.
    {
        stringValue.replace(position, maximum_character_replacement, newString);	// Replaces the old string with the new string from the detected starting position of the string.
    }
    
    return stringValue;		// Returns the new string value.
}

