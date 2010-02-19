/*
 *  ITBase64Additions.m
 *  CardTrainerMobileSyncTest
 *
 *  Created by Stefan Reinhold on 04.10.09.
 *  Copyright 2009 Stefan Reinhold. All rights reserved.
 *
 */

#import "ITBase64Additions.h"
#import "ITBase64.h"

@implementation NSData (ITBase64Additions)

+ (id)dataWithBase64EncodedString:(NSString *)aString {
	
	if (!aString)
		return nil;
	
	if ([aString length] == 0)
		return [NSData data];
	
	const char *cString = [aString cStringUsingEncoding:NSASCIIStringEncoding];
	
	if (cString == NULL)
		return nil;
	
	unsigned int dataLength = 0;
	uint8_t *bytes = ITBase64DecodedDataCreate(cString, [aString length], &dataLength);
	
	if (bytes == NULL)
		return nil;
	
	NSData *data = [[NSData alloc] initWithBytesNoCopy:bytes length:dataLength freeWhenDone:YES];
	
	if (!data) {
		free(bytes);
	}
	
	return [data autorelease];
}

- (NSString *)base64EncodedString {
	
	if ([self length] == 0)
		return [NSString string];
	
	unsigned int strLen = 0;
	
	char *cString = ITBase64EncodedStringCreate([self bytes], [self length], &strLen);
	
	if (cString == NULL)
		return nil;
	
	NSString *encodedString = [[NSString alloc] initWithCStringNoCopy:cString length:strLen freeWhenDone:YES];
	
	if (!encodedString) {
		free(cString);
	}
	
	return [encodedString autorelease];
}


@end