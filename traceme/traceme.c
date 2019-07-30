#include <sys/ptrace.h>
#include <stdio.h>


int main(void)                                                                      
{
    if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0 ) {
        printf("Debugger detected\n");
        return -1;
    }

    printf("Normal execution\n");
    return 0;
}

