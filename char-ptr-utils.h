#include <Windows.h>
#include <cstdio>

/**
	small namespace for my char pointer utils (string-like operations)
*/
namespace char_ptr_utils {
	/**
		function to get the index of a character in a string
		@param string to search in, character to search for(, optional: offset)
		@return position of character in string
	*/
	int index_of_char(char* array, char character, int offset = 0) 
	{
		for (int i = offset; i < strlen(array); i++)  { if (array[i] == character) { return i; } }
		return -1;
	}

	/**
		function to get the index of a substring
		@param string to search in, substring to find(, optional: offset)
		@return position of substring in string
	*/
	int index_of_substr(char* array, char* substr, int offset = 0) {
		for (int i = offset; i < strlen(array); i++)
		{
			if (array[i] == substr[0]) {
				for (int j = 0; i < strlen(substr); j++) { if (array[i + j] != substr[j]) { return -1; } }
				return i;
			}
		}
		return -1;
	}

	/**
		function to get the last occurrence of a character in a string (function index_of_char reversed)
		@param string to search in, character to search for(, optional: offset)
		@return position of character in string
	*/
	int last_index_of_char(char* array, char character, int offset = 0) {
		for (int i = strlen(array) - 1; i > offset; i--) {
			if (array[i] == character) { return i; }
		}
		return -1;
	}

	/**
		function to get a substring of a string
		@param start string, offset, length
		@return substring of string
	*/
	char* substr(char* array, int offset, int length = -1) {
		int len = strlen(array) - offset - (length == -1 ? 0 : strlen(array) - length);
		char* dest = new char[len + 1];
		dest[len] = '\0';
		memcpy(dest, &array[0] + offset, len);
		return dest;
	}

	/**
		function to concatenate two strings
		@param first string, second string
		@return combined string
	*/
	char* concat(char* array, char* array2) {
		int len = strlen(array) + strlen(array2);
		char* result = new char[len + 1];
		result[len] = '\0';
		memcpy(result, &array[0], strlen(array));
		memcpy(&result[strlen(array)], &array2[0], strlen(array2));
		return result;
	}

	/**
		function to check if a given string starts with a given substring
		@param string to search in, wanted string
		@return bool if string starts with substring
	*/
	bool starts_with(char* array, char* wanted) {
		return strncmp(array, wanted, strlen(wanted)) == 0;
	}

	/**
		function to get the length of a string
		@param string
		@return string length
	*/
	int len(char* array) {
		return strlen(array);
	}
}
