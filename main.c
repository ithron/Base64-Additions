#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ITBase64.h"

int main (int argc, const char * argv[]) {
	
	const char *str = "Hello, World!\nThis is my Base64 encoded text!\nHope you enjoy!?";
	
	char *encodedString = NULL;
	
	encodedString = ITBase64EncodedStringCreate(str, strlen(str));
	
	printf("%s\n", encodedString);
	
	unsigned int len = 0;
	char *decodedString = ITBase64DecodedDataCreate(encodedString, strlen(encodedString), &len);
	
	if (decodedString != NULL) {
		decodedString = (char *) realloc(decodedString, len + 1);
		decodedString[len] = '\0';
		
		printf("%s", decodedString);
		
		free(decodedString);
	}
	   
	free(encodedString);
	
    return 0;
}
