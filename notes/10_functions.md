# Functions

- Pass by Value
In this parameter passing method, values of actual parameters are copied to the function’s formal parameters and the two types of parameters are stored in different memory locations. So any changes made inside functions are not reflected in the actual parameters of the caller. 
 
- Pass by Reference
Both actual and formal parameters refer to the same locations, so any changes made inside the function are actually reflected in the actual parameters of the caller.

- Evaluation order of function parameters: 
  It is compiler dependent in C. It is never safe to depend on the order of evaluation of side effects.

- Function overloading is a feature of a programming language that allows one to have many functions with same name but with different signatures.

- `_Noreturn` function specifier that specify that the function does not return to the function that it was called from.

## exit()

``` c
void exit ( int status ); 
```
- Jobs of `exit()`
  - Flushes unwritten buffered data.
  - Closes all open files.
  - Removes temporary files.
  - Returns an integer exit status to the operating system.

- Objects with static storage duration are destroyed (C++) and functions registered with atexit are called.
- All C streams (open with functions in `<cstdio>`) are closed (and flushed, if buffered), and all files created with tmpfile are removed. 
- Control is returned to the host environment.
- Status value returned to the parent process. Generally, a status value of 0
  or EXIT_SUCCESS indicates success, and any other value or the constant
  EXIT_FAILURE is used to indicate an error.
- The mystery behind exit() is that it takes only integer args in the range 0 -
  255 . Out of range exit values can result in unexpected exit codes. An exit
  value greater than 255 returns an exit code modulo 256.

- destructor is executed here

### abort()

``` c
void abort ( void );
```
- Unlike exit() function, abort() may not close files that are open. It may also not delete temporary files and may not flush stream buffer. Also, it does not call functions registered with atexit().

- destructor is **not** executed

### assert()

``` c
void assert( int expression );
```
- If expression evaluates to 0 (false), then the expression, sourcecode filename, and line number are sent to the standard error, and then `abort()` function is called. If the identifier `NDEBUG` ("no debug") is defined with `#define NDEBUG` then the macro assert does nothing.

- destructor is **not** executed if condition(assertion) is false

### `atexit()`

``` c
int atexit (void (*func)(void));
```
- The function pointed by func is automatically called without arguments when the program terminates normally.
- If more than one atexit function has been specified by different calls to this function, they are all executed in reverse order as a stack (i.e. the last function specified is the first to be executed at exit).
- func points to a Function that is to be called. The function shall return no value and take no arguments.

### Points to remember

- `exit()` inside `_Noreturn` function runs destructor but simply `_Noreturn` doesnt.

## Callbacks

- In C, a callback function is a function that is called through a function pointer.
- In C++ STL, functors are also used for this purpose.

### Function pointer

``` c
// fun_ptr is a pointer to function fun() 
void (*fun_ptr)(int) = &fun;

// Invoking fun() using fun_ptr
(*fun_ptr)(10);
```
- If we remove bracket, then the expression `void (*fun_ptr)(int)` becomes `void *fun_ptr(int)` which is declaration of a function that returns void pointer.
-  Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer stores the start of executable code.
-  Unlike normal pointers, we do not allocate de-allocate memory using function pointers.
-  A function’s name can also be used to get functions’ address. For example, in the below program, we have removed address operator `&` in assignment. We have also changed function call by removing *, the program still works.
``` c
void (*fun_ptr)(int) = fun;  // & removed  
fun_ptr(10);  // * removed
```
