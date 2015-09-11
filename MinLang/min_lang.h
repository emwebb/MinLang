//
//  min_lang.h
//  MinLang
//
//  Created by Ethan Webb on 06/09/2015.
//  Copyright (c) 2015 Ethan. All rights reserved.
//

#ifndef __MinLang__min_lang__
#define __MinLang__min_lang__


#define SUCCESS 0
#define ERROR_NO_PROGRAM 1
#define ERROR_PP_GREATER_THAN_SIZE 2
#define ERROR_STACK_EMPTY 3

#include <stdio.h>
int run(FILE* in, FILE* out, char* program, unsigned int size);
#endif /* defined(__MinLang__min_lang__) */
