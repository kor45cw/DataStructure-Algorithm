//
//  ArrayBaseStack.c
//  ArrayBaseStack
//
//  Created by SonChangWoo on 2016. 7. 11..
//  Copyright © 2016년 SonChangWoo. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack) {
    pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack) {
    if (pstack->topIndex == -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void SPush(Stack * pstack, Data data) {
    pstack->topIndex += 1;
    pstack->stackArray[pstack->topIndex] = data;
}

Data SPop(Stack * pstack) {
    int rIdx;
    
    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    
    return pstack->stackArray[rIdx];
}

Data SPeek(Stack * pstack) {
    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    return pstack->stackArray[pstack->topIndex];
}