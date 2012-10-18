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
    char	*nl = "\n";

    readln(mem);
    println(mem);
    println(nl);
}