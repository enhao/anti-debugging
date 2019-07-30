#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sched.h>
#include <sys/prctl.h>
#include <linux/limits.h>


void check(void)
{
    pid_t ppid = getppid();
    FILE *fp;
    char file[PATH_MAX];
    char line[BUFSIZ];

    sprintf(file, "/proc/%d/wchan", ppid);
    fp = fopen(file, "r");
    if (fp == NULL) {
        perror("fopen");
        goto out;
    }

    while (fgets(line, BUFSIZ, fp)) {
        if (strstr(line, "ptrace_stop") != NULL) {
            printf("Debugger detected\n");
            fclose(fp);
            kill(ppid, SIGTERM); 
            exit(-1);
        }
    }

out:
    if (fp)
        fclose(fp);
}

int main(void)                                                                      
{
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        prctl(PR_SET_PDEATHSIG, SIGHUP);
        while (1) {
            check();
            sched_yield();
        }

    }

    printf("Normal execution (Press CTRL-C to exit)\n");
    while (1) {
        sleep(3);
        printf(".");
        fflush(stdout);
    }

    return 0;
}

