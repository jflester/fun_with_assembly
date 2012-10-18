#include	<stdio.h>

/* NOTE that your string arrays will be integers, not characters */
char	mem[1024];
char	*ptrs[100];

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


void stringify(char *mem, char **ptrs)
{
    char	*ptr;

    *ptrs++ = mem;
    for (ptr = mem; *ptr; ptr++) {
	if (*ptr == ' ') {
	    *ptr = 0;
	    *ptrs++ = ptr + 1;
	}
    }
    *ptrs = 0;
}


/* print a space all but the first time */
void maybespace()
{
    static int	first = 1;

    if (first) {
	first = 0;
    } else {
	putchar(' ');
    }
}


/* simple, stupid bubblesort */
void bubsort(char **strs) 
{
    char	**strs2;
    int		num;

    for (strs2 = strs; *strs2; strs2++)
	;

    /* get num strings */
    for (num = strs2 - strs; num > 0; num--) {
	for (strs2 = strs; strs2[1]; strs2++) {
	    if (strcmp(strs2[0], strs2[1]) > 0) {
		char	*tmp = strs2[0];
		strs2[0] = strs2[1];
		strs2[1] = tmp;
	    }
	}
    }
}


int  main()
{
    int		res;
    char	**ptrptr;
    char	*nl = "\n";

    readln(mem);

    stringify(mem, ptrs);

    bubsort(ptrs);

    for (ptrptr = ptrs; *ptrptr; ptrptr++) {
	maybespace();
	println(*ptrptr);
    }
    println(nl);
}