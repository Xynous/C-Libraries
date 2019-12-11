#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *trim_left(char *stringValue) {
	int index = 0;
	int i;

	while (stringValue[index] == ' ' || stringValue[index] == '\t'
			|| stringValue[index] == '\n') {
		index++;
	}

	if (index != 0)	// If no leading whitespaces been found, then no trimming operation is required.
			{
		i = 0;

		while (stringValue[i + index] != '\0') {
			stringValue[i] = stringValue[i + index];
			i++;
		}

		stringValue[i] = '\0';
	}

	return stringValue;
}

char *trim_right(char *stringValue) {
	int stringLength;

	stringLength = strlen(stringValue) - 1;

	while (stringLength > -1) {
		if (stringValue[stringLength] == ' '
				|| stringValue[stringLength] == '\t') {
			stringLength--;
		} else {
			break;
		}
	}
	stringValue[stringLength + 1] = '\0';

	return stringValue;

}

char *toLowerCase(char *pCharactersToLower) {

	char *tmp = pCharactersToLower;

    for (;*tmp;tmp++) {
        *tmp = tolower((unsigned char) *tmp);
    }

    return pCharactersToLower;
}

char *toUpperCase(char *pCharactersToUpper) {

	char *tmp = pCharactersToUpper;

    for (;*tmp;tmp++) {
        *tmp = toupper((unsigned char) *tmp);
    }

    return pCharactersToUpper;
}

char *trim(char *stringValue, char *trimmingOption) {

	char *errorMessage;

	if (strcmp(trimmingOption, "L") == 0) {

		stringValue = trim_left(stringValue);

	}

	if (strcmp(trimmingOption, "R") == 0) {

		stringValue = trim_right(stringValue);

	}

	if (strcmp(trimmingOption, "A") == 0) {

		stringValue = trim_left(stringValue);
		stringValue = trim_right(stringValue);

	}

	if (trimmingOption != "L" && trimmingOption != "R" && trimmingOption != "A") {		// Condition checks if the trimming operation is valid.

		errorMessage = "Error: Invalid trimming operation, refer to the project wiki for the list of trimming operations";

		return errorMessage;
	}

	if (strcmp(stringValue, "") == 0) {		// Condition checks if the passed string value is empty.

		errorMessage = "Error: String cant be empty, refer to the project wiki for further information and examples";

		return errorMessage;
	}

	return stringValue;
}
