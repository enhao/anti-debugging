#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ptrace.h>


void check(void)
{
    if (getenv("LD_PRELOAD")) {
        printf("Debugger detected\n");
        exit(-1);
    }

    if (access("/etc/ld.so.preload", F_OK) == 0) {
        printf("Debugger detected\n");
        exit(-1);
    }

    if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0 ) {
        printf("Debugger detected\n");
        exit(-1);
    }
}

int main(void)                                                                      
{
    check();
    printf("Normal execution\n");
    return 0;
}

