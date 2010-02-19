#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ITBase64.h"

int main (int argc, const char * argv[]) {
	
	const char *str = "Hello, World!\nThis is my test message.\r\nAnd some more text to test my program.";
	
	char *encodedString = NULL;
	
	encodedString = ITBase64EncodedStringCreate(str, strlen(str));
	
	printf("%s\n", encodedString);
	
	unsigned int len = 0;
	char *decodedString = ITBase64DecodedDataCreate(encodedString, strlen(encodedString), &len);
	
	if (decodedString != NULL) {
		decodedString = (char *) realloc(decodedString, len + 1);
		decodedString[len] = '\0';
		
		printf("%s\n", decodedString);
		
		free(decodedString);
	}
	   
	free(encodedString);
	
    return 0;
}
