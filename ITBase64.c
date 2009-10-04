/*
 *  ITBase64.c
 *  Base64Encoder
 *
 *  Created by Stefan Reinhold on 04.10.09.
 *  Copyright 2009 Stefan Reinhold. All rights reserved.
 *
 */

#include "ITBase64.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define isWhiteSpace(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')

static const char ITBase64AdditionsEncodingTable[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void encodeWord(const uint8_t *bytes, char *dest, const int lastWord);
unsigned int decodeWord(const char *chars, uint8_t *dest);
uint8_t charToByte(const char c);
unsigned int whiteSpaceFreeStringCreate(char **dest, const char *str, unsigned int len);

inline void encodeWord(const uint8_t *bytes, char *dest, const int lastWord) {
	
	dest[0] = ITBase64AdditionsEncodingTable[(bytes[0] & 0xFC) >> 2];
	dest[1] = ITBase64AdditionsEncodingTable[((bytes[0] & 0x03) << 4) | ((bytes[1] & 0xF0) >> 4)];
	
	if (dest[1] == 'A' && lastWord) {
		
		memset(&dest[1], '=', 3);
		return;
	}

	dest[2] = ITBase64AdditionsEncodingTable[((bytes[1] & 0x0F) << 2) | ((bytes[2] & 0xC0) >> 6)];
	
	if (dest[2] == 'A' && lastWord) {
		
		memset(&dest[1], '=', 2);
		return;
	}
	
	dest[3] = ITBase64AdditionsEncodingTable[bytes[2] & 0x3F];
	
	if (dest[3] == 'A' && lastWord) {
		
		dest[3] = '=';
	}
}

inline uint8_t charToByte(const char c) {
	
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	else if (c >= 'a' && c <= 'z')
		return c - 'a' + 26;
	else if (c >= '0' && c <= '9')
		return c - '0' + 52;
	else if (c == '+')
		return 62;
	else if (c == '/')
		return 63;
	else if (c == '=')
		return 0;
	else //error
		return 0xff;
}

inline unsigned int decodeWord(const char *chars, uint8_t *dest) {
	
	const uint8_t c0 = charToByte(chars[0]);
	const uint8_t c1 = charToByte(chars[1]);
	
	if (c0 == 0xff || c1 == 0xff)
		return 0;
	
	dest[0] = (c0 << 2) | ((c1 & 0x30) >> 4);
	
	if (chars[1] == '=')
		return 1;
	
	const uint8_t c2 = charToByte(chars[2]);
	const uint8_t c3 = charToByte(chars[3]);
	
	if (c2 == 0xff || c3 == 0xff)
		return 0;
	
	dest[1] = ((c1 & 0x0f) << 4) | ((c2 & 0x3c) >> 2);
	
	if (chars[2] == '=')
		return 2;
	
	dest[2] = ((c2 & 0x03) << 6) | c3;
	
	return 3;
}

inline unsigned int whiteSpaceFreeStringCreate(char **dest, const char *str, unsigned int len) {
	
	unsigned int i = 0, resultLen = 0;
	*dest = (char *) malloc(len * sizeof(char));
	char *destPtr = *dest;
	char c;
	
	for (i = 0; i < len; i++) {
		c = str[i];
		if (!isWhiteSpace(c)) 
			destPtr[resultLen++] = c;
	}
	
	return resultLen;
}

char * ITBase64EncodedStringCreate(const void *data, const unsigned int len) {
	
	const unsigned int resultSizeWithoutLineBreaks = ((len / 3) + ((len % 3) != 0)) * 4;
	const unsigned int numLineBreaks = resultSizeWithoutLineBreaks / 76;
	const unsigned int resultSize = resultSizeWithoutLineBreaks + numLineBreaks;
	const uint8_t *ptr = (uint8_t *)data;
	const unsigned int effLen = (len / 3) * 3;
	const unsigned int restLen = len % 3;
	unsigned int srcIndex = 0, destIndex = 0, charCounter = 0;
	
	char *dest = (char *) malloc((resultSize + 1) * sizeof(char));
	
	while (srcIndex < effLen) {
		
		charCounter = (charCounter + 4) % 76;
		
		encodeWord(&ptr[srcIndex], &dest[destIndex], 0);
		
		srcIndex += 3;
		destIndex += 4;
		
		if (charCounter == 0) {
			
			dest[destIndex] = '\n';
			destIndex++;
		}
	}
	
	if (restLen != 0) {
		
		uint8_t restWord[3] = {
			0, 0, 0
		};
		
		memcpy(restWord, &ptr[effLen], restLen);
		
		encodeWord(restWord, &dest[resultSize - 4], 1);
	}
	
	dest[resultSize] = '\0';
	
	return dest;
}

void * ITBase64DecodedDataCreate(const char *string, const unsigned int len, unsigned int *dataLength) {
	
	unsigned int srcIndex = 0, destIndex = 0, bytesDecoded = 0;
	char *characters = NULL;
	const unsigned int effLen = whiteSpaceFreeStringCreate(&characters, string, len);
	const unsigned int maxLen = 3 * effLen / 4;
	
	if (effLen % 4 != 0) {
		*dataLength = 0;
		free(characters);
		return NULL;
	}
	
	uint8_t *dest = (uint8_t *) malloc(maxLen);
	
	while (srcIndex < effLen) {
		
		bytesDecoded = decodeWord(&characters[srcIndex], &dest[destIndex]);
		
		if (bytesDecoded < 3)
			break;
		
		srcIndex += 4;
		destIndex += 3;
	}
	
	if (bytesDecoded > 0 && bytesDecoded < 3) {
		
		*dataLength = destIndex - (3 - bytesDecoded);
		
		dest = (uint8_t *) realloc(dest, *dataLength);
	}
	else if (bytesDecoded == 0) {
		
		// error
		free(dest);
		dest = NULL;
		*dataLength = 0;
	}
	else {
		
		*dataLength = destIndex;
	}

	
	free(characters);
	
	return dest;		
}
