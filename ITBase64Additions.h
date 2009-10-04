/*
 *  ITBase64Additions.h
 *  CardTrainerMobileSyncTest
 *
 *  Created by Stefan Reinhold on 04.10.09.
 *  Copyright 2009 Stefan Reinhold. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

@interface NSData (ITBase64Additions)

+ (id)dataWithBase64EncodedString:(NSString *)aString;

- (NSString *)base64EncodedString;

@end
