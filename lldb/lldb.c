#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>


int main(void)
{
    struct winsize win;

    if (isatty(1) && !ioctl (1, TIOCGWINSZ, &win) && !win.ws_col) {
        printf("Debugger detected\n");
        return -1;
    }

    printf("Normal execution\n");
    return 0;
}

