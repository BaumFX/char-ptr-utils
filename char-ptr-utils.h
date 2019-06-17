#include <Windows.h>
#include <cstdio>

/**
	small namespace for my char pointer utils (string-like operations)
*/
namespace char_ptr_utils {
	/**
		function to get the index of a character in a string
		@param string to search in, character to search for(, optional: offset)
		@return position of character in string (-1 if char is not found)
	*/
	int index_of_char(char* array, char character, int offset = 0) 
	{
		//iterate over the string to find character, return current index if its found, -1 if its not found
		for (int i = offset; i < strlen(array); i++)  { if (array[i] == character) { return i; } }
		return -1;
	}

	/**
		function to get the index of a substring
		@param string to search in, substring to find(, optional: offset)
		@return position of substring in string (-1 if substring is not found)
	*/
	int index_of_substr(char* array, char* substr, int offset = 0) {
		//iterate over the string
		for (int i = offset; i < strlen(array); i++)
		{
			//check if the current character matches the first character of the substring
			if (array[i] == substr[0]) {
				//iterate over the next (substring length) characters to determine whether they are the same
				//in both strings, if they are, return the start index, if theyre not, return -1
				for (int j = 0; i < strlen(substr); j++) { if (array[i + j] != substr[j]) { return -1; } }
				return i;
			}
		}
		//return -1 if the starting character of the substring is not found
		return -1;
	}

	/**
		function to get the last occurrence of a character in a string (function index_of_char reversed)
		@param string to search in, character to search for(, optional: offset)
		@return position of character in string (-1 if the character is not found)
	*/
	int last_index_of_char(char* array, char character, int offset = 0) {
		//iterate over the string
		for (int i = strlen(array) - 1; i > offset; i--) {
			//if the string at the current index is the wanted character, return the index, proceed if its not
			if (array[i] == character) { return i; }
		}
		//return -1 if the character is not found
		return -1;
	}

	/**
		function to get a substring of a string
		@param start string, offset, length
		@return substring of string
	*/
	char* substr(char* array, int offset, int length = -1) {
		//get substring length
		int len = strlen(array) - offset - (length == -1 ? 0 : strlen(array) - length);
		//create new c-style string for our substring
		char* dest = new char[len + 1];
		//add terminating null sequence to our string (end of c-style string)
		dest[len] = '\0';
		//copy the part of the first string into the substring
		memcpy(dest, &array[0] + offset, len);
		//return the substring
		return dest;
	}

	/**
		function to concatenate two strings
		@param first string, second string
		@return combined string
	*/
	char* concat(char* array, char* array2) {
		//calculate result string length
		int len = strlen(array) + strlen(array2);
		//create a new c-style string for our result
		char* result = new char[len + 1];
		//add terminating null sequence to our string (end of c-style string)
		result[len] = '\0';
		//copy the strings into our result
		memcpy(result, &array[0], strlen(array));
		memcpy(&result[strlen(array)], &array2[0], strlen(array2));
		//return result
		return result;
	}

	/**
		function to check if a given string starts with a given substring
		@param string to search in, wanted string
		@return bool if string starts with substring
	*/
	bool starts_with(char* array, char* wanted) {
		//check if string starts with the wanted sequence
		return strncmp(array, wanted, strlen(wanted)) == 0;
	}

	/**
		function to get the length of a string
		@param string
		@return string length
	*/
	int len(char* array) {
		//return string length :moyai:
		return strlen(array);
	}
}
