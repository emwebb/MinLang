//
//  main.c
//  MinLang
//
//  Created by Ethan Webb on 06/09/2015.
//  Copyright (c) 2015 Ethan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "min_lang.h"
#include "string_utils.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    while(1) {
        char input[512];
        scanf("%s",input);
        if(!strncmp(input,"STOP",4))
            break;
        
        char* buffer_1 = str_replace(input, "\n", "");
        char* buffer_2 = str_replace(buffer_1, "\\n", "\n");
        free(buffer_1);
        char* program = str_replace(buffer_2, "\\\n", "\\n");
        free(buffer_2);
        getc(stdin);
        run(stdin,stdout,program,strlen(program));
        free(program);
        printf("\n");
    }
    return 0;
}
