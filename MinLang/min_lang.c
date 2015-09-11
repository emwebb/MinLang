//
//  min_lang.c
//  MinLang
//
//  Created by Ethan Webb on 06/09/2015.
//  Copyright (c) 2015 Ethan. All rights reserved.
//

#include "min_lang.h"
#include <stdlib.h>

int run(FILE* in, FILE* out, char* program, unsigned int size) {
    if (size == 0) {
        return ERROR_NO_PROGRAM;
    }
    
    unsigned int pp = 0;
    unsigned char* r = calloc(sizeof(char), 256);
    unsigned char rp = 0;
    unsigned int stackSize = 32;
    unsigned int sp = 0;
    unsigned char* stack = malloc(sizeof(char)*stackSize);
    unsigned int funcPoint = 0;
    while(1) {
        if (pp == size) {
            break;
        }
        if(pp > size) {
            free((void*)stack);
            return ERROR_PP_GREATER_THAN_SIZE;
        }
        char i = program[pp];
        if(i == '<'){
            pp = pp - r[rp];
        }
        if(i == '>'){
            pp = pp + r[rp];
        }
        if(i == '+'){
            r[rp]++;
        }
        if(i == '-'){
            r[rp]--;
        }
        if(i == '?'){
            if(r[rp]){
                pp++;
            }
        }
        if(i == '/'){
            if(r[rp] == 0){
                pp++;
            }
        }
        if(i == '^'){
            
            fprintf(out,"%s",r + rp);
        }
        if(i == '*'){
            fprintf(out,"%d",r[rp]);
        }
        
        if(i == 'v'){
            r[rp] = getc(in);
        }
        if(i == 'V'){
            char buffer[255];
            fscanf(in,"%s",buffer);
            r[rp] =atoi(buffer);
        }
        if(i == '.') {
            
            if(sp + 1 == stackSize) {
                stack = realloc(stack,stackSize + 1);
                stackSize++;
            }
            stack[sp] = r[rp];
            sp++;
        }
        if(i == '!') {
            if(sp == 0) {
                free((void*)stack);
                return ERROR_STACK_EMPTY;
            }
            sp--;
            r[rp] = stack[sp];
        }
        if(i == '|') {
            if(sp == 0) {
                free((void*)stack);
                return ERROR_STACK_EMPTY;
            }
            r[rp] = stack[sp - 1];
        }
        
        if(i == '('){
            funcPoint = pp;
        }
        
        if(i == ')'){
            pp = funcPoint;
        }
        if(i == '='){
            pp++;
            r[rp] = program[pp];
        }
        if(i == '{'){
            while(program[pp] != '}'){
                if(pp == size) {
                    free((void*)stack);
                    return SUCCESS;
                }
                pp++;
                
            }
        }
        
        if(i == '}'){
            while(pp > 0 || program[pp] != '{'){
                if(pp == 0) {
                    free((void*)stack);
                    return SUCCESS;
                }
                pp--;
                
            }
        }
        if(i == ']') {
            rp++;
        }
        if(i == '[') {
            rp--;
        }
        pp++;
        
        
    }
    free((void*)stack);
    return SUCCESS;
}