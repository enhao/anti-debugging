#include <stdio.h>
#include <signal.h>


static volatile sig_atomic_t is_detected = 1;

static void int3_handler(int signo)
{
    is_detected = 0;
}

int main(void)
{
    signal(SIGTRAP, int3_handler);
    __asm__ __volatile__("int3");
    
    if (is_detected) {
        printf("Debugger detected\n");
        return -1;
    }

    printf("Normal execution\n");
    return 0;
}

