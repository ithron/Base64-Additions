/*
 *  ITBase64.h
 *  Base64Encoder/Decoder
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

#ifndef ITBASE64_H_
#define ITBASE64_H_

/*! \brief Encodes the given bytes into an ASCII string using base64.
 *
 *  The given bytes are base64 encoded into an ASCII C string. The returned string
 *  must be freed after usage.
 *
 *  \param[in] data Byte data to be encoded.
 *  \param[in] len The length of the byte data.
 *  \param[out] stringLength If not NULL the length of the resulting string (as returned by strlen)
 *              is saved here.
 *  \return An base64 encoded ASCII C string or NULL on error.
 */
char * ITBase64EncodedStringCreate(const void *data, const unsigned int len, unsigned int *stringLength);

/*! \brief Decodes the given base64 encoded ASCII string into a byte buffer.
 *
 *  The given base64 encoded ASCII string is decoded (if possible) and a pointer to the resulting
 *  byte data is returned. This function will fail if the string contains invalid base64 characters.
 *  All whitespace characters (space, tab, newline, carriage return) are ignored.
 *  The last parameter must point to a valid memory location where the length of the decoded byte data
 *  can be stored.
 *
 *  \param[in] string An base64 encoded string.
 *  \param[in] len The length of the input string (as returned by strlen).
 *  \param[out] dataLength The length of the decoded byte data is stored here, so pass a valid pointer.
 *  \return A pointer to the decoded byte data or NULL on failure.
 */
void * ITBase64DecodedDataCreate(const char *string, const unsigned int len, unsigned int *dataLength);

#endif
