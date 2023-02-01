#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void beforeMain (void) __attribute__ ((constructor));

void afterMain (void) __attribute__ ((destructor));

void beforeMain (void)
{
	printf ("constructor code before main()\n");
}

void afterMain (void)
{
	printf ("destructor after main()\n");
}

void funExit(){
    printf("Inside atexit\n");
}

int main (void)
{
    int a = 5;
    // atexit(funExit);
	printf ("start of main\n");
    // exit(1);
    // abort();
    // assert(a==0);
    printf("\nEnd of main\n");
	return 0;
}