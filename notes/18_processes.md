# Processes

## getpid()
getpid( ) is a system function that returns the PID of the current process. When the execution of the program ends, the process is terminated. Every time you run the program, a new process is created.

requires `#include <unistd.h>` library

# fork()
fork() launches a child process. Control goes to fork() only once. Whereas, control returns from fork() twice.

```
# include <stdio.h>
# include <stdio.h>
 /* for prototype of fork( ) */
# include <unistd.h>   

int main( ) 
{
	printf ( "Before Forking\n" ) ;
	// fork() system call
	fork( ) ;
	printf ( "After Forking\n" ) ;
	return 0 ;
}
```

## Customized signal handling
