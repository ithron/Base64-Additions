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

/*! \brief Returns an NSData object that contains the decoded data that 
 *         was base64 encoded in the given string.
 *
 *  \param[in] aString A base64 encoded string.
 *  \return A NSData object that contains the (decoded) data from the (encoded) string.
 *          If the string is not a valid base64 string, nil is returned.
 */
+ (id)dataWithBase64EncodedString:(NSString *)aString;


/*! \brief Returns a NSString that is a base64 encoded representaation of the reciever.
 *
 *  \returns A base64 representation of the reciever. nil may be returned on failure.
 */
- (NSString *)base64EncodedString;

@end
