/*
 *  ITBase64Additions.m
 *  Base64 Additions
 *
 *  Copyright 2010 Stefan Reinhold (development@ithron.de). All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are
 *  permitted provided that the following conditions are met:
 * 
 *  1. Redistributions of source code must retain the above copyright notice, this list of
 *  conditions and the following disclaimer.
 * 
 *  2. Redistributions in binary form must reproduce the above copyright notice, this list
 *  of conditions and the following disclaimer in the documentation and/or other materials
 *  provided with the distribution.
 * 
 *  THIS SOFTWARE IS PROVIDED BY STEFAN REINHOLD ``AS IS'' AND ANY EXPRESS OR IMPLIED
 *  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 *  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL STEFAN REINHOLD OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 *  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 *  The views and conclusions contained in the software and documentation are those of the
 *  authors and should not be interpreted as representing official policies, either expressed
 *  or implied, of Stefan Reinhold.
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
	
	NSString *encodedString = [[NSString alloc] initWithBytesNoCopy:cString 
															   length:strLen 
															 encoding:NSASCIIStringEncoding
														 freeWhenDone:YES];
	
	if (!encodedString) {
		free(cString);
	}
	
	return [encodedString autorelease];
}


@end