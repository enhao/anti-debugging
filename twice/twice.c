#include <sys/ptrace.h>
#include <stdio.h>
#include <stdlib.h>


enum CHECK {
    CHECK_INIT = 1,
    CHECK_TRACEME_SUCCESS,
    CHECK_TRACEME_FAILED,
    CHECK_OK = CHECK_TRACEME_SUCCESS * CHECK_TRACEME_FAILED
};

#define INIT_STATE(v) do { v = CHECK_INIT; } while (0);
#define UPDATE_STATE(v, s) do { v *= s; } while (0);

void check(void) __attribute__((constructor));

void check(void)
{
    int state;
    INIT_STATE(state);

    if (ptrace(PTRACE_TRACEME, 0, 0, 0) == 0) {
        UPDATE_STATE(state, CHECK_TRACEME_SUCCESS);
    }

    if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1) {
        UPDATE_STATE(state, CHECK_TRACEME_FAILED);
    }

    if (state != CHECK_OK) {
        printf("Debugger detected \n");
        exit(-1);
    }
}

int main(void)                                                                      
{
    printf("Normal execution\n");
    return 0;
}

