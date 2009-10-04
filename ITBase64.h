/*
 *  ITBase64.h
 *  Base64Encoder
 *
 *  Created by Stefan Reinhold on 04.10.09.
 *  Copyright 2009 Stefan Reinhold. All rights reserved.
 *
 */

#ifndef ITBASE64_H_
#define ITBASE64_H_

char * ITBase64EncodedStringCreate(const void *data, const unsigned int len);
void * ITBase64DecodedDataCreate(const char *string, const unsigned int len, unsigned int *dataLength);

#endif
