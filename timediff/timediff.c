#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


void check(void)
{
    struct timeval begin;
    struct timeval end;
    struct timezone tz;

    if (gettimeofday(&begin, &tz) < 0) {
        perror("gettimeofday");
        return;
    }

    if (gettimeofday(&end, &tz) < 0) {
        perror("gettimeofday");
        return;
    }

    int diff = (begin.tv_sec) - (end.tv_sec);
    if (diff > 1) {
        printf("Debugger detected\n");
        exit(-1);
    }
}

int main(void)                                                                      
{
    printf("Normal execution\n");
    return 0;
}

