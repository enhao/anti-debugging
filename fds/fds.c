#define _POSIX_C_SOURCE 2
#include <stdio.h>
#include <stdlib.h>


#define ANYWHERE "/tmp"

void check(void) __attribute__((constructor));

void check(void)
{
    FILE *fd = fopen(ANYWHERE, "r");
    if (fd == NULL)
        goto out;

    if (fileno(fd) > 5) {
        printf("Debugger detected\n");
        fclose(fd);
        exit(-1);
    }

out:
    if (fd)
        fclose(fd);
}

int main(void)
{
    printf("Normal execution\n");
    return 0;
}

