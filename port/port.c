#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void check(void)
{
    FILE *fp;
    char line[BUFSIZ];

    fp = fopen("/proc/net/tcp", "r");
    if (fp == NULL) {
        perror("fopen");
        goto out;
    }

    while (fgets(line, BUFSIZ, fp)) {
        if (strstr(line, "5D8A") != NULL) {
            printf("Debugger detected\n");
            fclose(fp);
            exit(-1);
        }
    }

out:
    if (fp)
        fclose(fp);
}

int main(void)                                                                      
{
    check();
    printf("Normal execution\n");
    return 0;
}

