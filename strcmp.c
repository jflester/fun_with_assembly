#include	<stdio.h>

/* NOTE that your string arrays will be integers, not characters */
char	mem[1024];

void readln(char *p)
{
    int		c;

    while ((c = getchar()) != 10) {
	*p++ = c;
    }
    *p = 0;
}


void println(char *p)
{
    while (*p) {
	putchar(*p++);
    }
}


int  main()
{
    char	*ptr;
    int		res;

    readln(mem);

    for (ptr = mem; *ptr != ' '; ptr++)
	;

    *ptr++ = 0;

    res = strcmp(mem, ptr);
    if (res < 0) {
	res = -1;
    } else if (res > 0) {
	res = 1;
    }
    printf("%d\n", res);
}