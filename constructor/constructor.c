#include <sys/ptrace.h>
#include <stdio.h>
#include <stdlib.h>


void check(void) __attribute__((constructor));
 
void check(void)
{
    if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1) {
        printf("Debugger detected\n");
        exit(-1);
    }
}

int main(void)                                                                      
{
    printf("Normal execution\n");
    return 0;
}

