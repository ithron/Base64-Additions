/*
 *  ITBase64Additions.h
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
