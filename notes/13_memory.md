# Memory Management

## Memory Layout in C

### 1. Text Segment: 

A text segment, also known as a code segment or simply as text, is one of the sections of a program in an object file or in memory, which contains executable instructions. 

As a memory region, a text segment may be placed below the heap or stack in order to prevent heaps and stack overflows from overwriting it.

### 2. Initialized Data Segment: 

Initialized data segment, usually called simply the Data Segment. A data segment is a portion of the virtual address space of a program, which contains the global variables and static variables that are initialized by the programmer.

This segment can be further classified into the initialized read-only area and the initialized read-write area.
For instance, the global string defined by char s[] = “hello world” in C and a C statement like int debug=1 outside the main (i.e. global) would be stored in the initialized read-write area. And a global C statement like const char* string = “hello world” makes the string literal “hello world” to be stored in the initialized read-only area and the character pointer variable string in the initialized read-write area.
   
### 3. Uninitialized Data Segment(bss): 

Initialized data segment, usually called simply the Data Segment. BSS stands for "block started by symbol". A data segment is a portion of the virtual address space of a program, which contains the global variables and static variables that are initialized by the programmerp.

Data in this segment is initialized by the kernel to arithmetic 0 before the program starts executing uninitialized data starts at the end of the data segment and contains all global variables and static variables that are initialized to zero or do not have explicit initialization in source code.

### 4. Stack

The stack area traditionally adjoined the heap area and grew in the opposite direction; when the stack pointer met the heap pointer, free memory was exhausted(stack overflow).

A "stack pointer" register tracks the top of the stack; it is adjusted each time a value is “pushed” onto the stack. The set of values pushed for one function call is termed a “stack frame”; A stack frame consists at minimum of a return address.

Stack, where automatic variables are stored, along with information that is saved each time a function is called. Each time a function is called, the address of where to return to and certain information about the caller’s environment, such as some of the machine registers, are saved on the stack.

### 5. Heap

Heap is the segment where dynamic memory allocation usually takes place.
The Heap area is shared by all shared libraries and dynamically loaded modules in a process.
> Remember to always manually free dynamically allocated memory otherwise it leads to **Memory Leak**.

Example:
```
#include <stdio.h>

int global_u; /* Uninitialized variable stored in bss*/
int global_i = 10; /* initialized global variable stored in DS*/

int main(void)
{
   static int i; /* Uninitialized static variable stored in bss */
   static int j = 100; /* Initialized static variable stored in DS*/
   return 0;
}
```

## malloc()

```
ptr = (cast-type*) malloc(byte-size)
```

The `malloc` or `memory allocation` method in C is used to dynamically allocate a single large block of memory with the specified size. It returns a pointer of type void which can be cast into a pointer of any form. It doesn’t Initialize memory at execution time so that it has initialized each block with the default garbage value initially. 

If space is insufficient, allocation fails and returns a NULL pointer.

## calloc()

```
ptr = (cast-type*)calloc(n, element-size);
// here, n is the no. of elements and element-size is the size of each element.
```

`calloc` or `contiguous allocation` method in C is used to dynamically allocate the specified number of blocks of memory of the specified type. 
Also initializes every byte in the allocated memory to 0. It has two parameters or arguments as compare to malloc().

If space is insufficient, allocation fails and returns a NULL pointer.

## free()

```
void free(void *ptr);
```

`free` method in C is used to dynamically de-allocate the memory. The memory allocated using functions `malloc()` and `calloc()` is not de-allocated on their own. Hence the `free()` method is used, whenever the dynamic memory allocation takes place. It helps to reduce wastage of memory by freeing it.

### How does free() know the size of memory to be deallocated?
- When memory allocation is done, the actual heap space allocated is one word larger than the requested memory. The extra word is used to store the size of the allocation and is later used by `free()`
- Typically, the size is stored adjacent to the allocated block, which is why things usually break badly if the bounds of the allocated block are even slightly overstepped. ([reference](https://c-faq.com/malloc/freesize.html))


## realloc()

```
void *realloc(void *ptr, size_t size);
ptr = realloc(ptr, newSize);
// where ptr is reallocated with new size 'newSize'.
```

`realloc` or `re-allocation` method in C is used to dynamically change the memory allocation of a previously allocated memory. In other words, if the memory previously allocated with the help of malloc or calloc is insufficient, realloc can be used to dynamically re-allocate memory. re-allocation of memory maintains the already present value and new blocks will be initialized with the default garbage value.

If `size` is zero, then call to realloc is equivalent to `free(ptr)`. And if `ptr` is NULL and size is non-zero then call to realloc is equivalent to `malloc(size)`.

realloc() should only be used for dynamically allocated memory

> malloc will return same address only if it doesnt find any allocated memory in its way of expanding previous memory.
