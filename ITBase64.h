/*
 *  ITBase64.h
 *  Base64Encoder/Decoder
 *
 *  Created by Stefan Reinhold on 04.10.09.
 *  Copyright 2009 Stefan Reinhold. All rights reserved.
 *
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
