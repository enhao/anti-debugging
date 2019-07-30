#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/limits.h>


void check(void)
{
    pid_t pid = getpid();
    pid_t tracerpid;
    FILE *fp;
    char file[PATH_MAX];
    char line[BUFSIZ];

    sprintf(file, "/proc/%d/status", pid);
    fp = fopen(file, "r");
    if (fp == NULL) {
        perror("fopen");
        goto out;
    }

    while (fgets(line, BUFSIZ, fp)) {
        if (strstr(line, "TracerPid:") != NULL) {
            tracerpid = atoi(&line[10]);
            if (tracerpid > 0) {
                printf("Debugger detected\n");
                fclose(fp);
                exit(-1);
            }
            break;
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

