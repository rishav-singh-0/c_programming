# Pointers

## Pointer arithmatic

- Increment/Decrement of a Pointer
- Addition of integer to a pointer
- Subtraction of integer to a pointer
- Subtracting two pointers of the same type
- Comparison of pointers of the same type.
- Assignment of pointers to the same type of pointers.

## Types of pointer

- Dangling pointer - A pointer pointing to a memory location that has been deleted (or freed) is called dangling pointer.
- File Pointer - The pointer to a FILE data type is called as a stream pointer or a file pointer.
- Far pointer - A far pointer is typically 32 bit that can access memory outside current segment.
- Huge pointer - A huge pointer is 32 bit long containing segment address and offset address.
- Complex pointer - Pointers with multiple levels of indirection.
- Near pointer - Near pointer is used to store 16 bit addresses means within current segment on a 16 bit machine.
- Normalized pointer - It is a 32 bit pointer, which has as much of its value in the segment register as possible.
- Generic pointer - In C void* acts as a generic pointer.

## Void pointers

- Any pointer type is convertible to a void pointer hence it can point to any value.
- void pointers cannot be dereferenced. It can however be done using typecasting the void pointer
- Pointer arithmetic is not possible on pointers of void due to lack of concrete value and thus size.

## NULL

- NULL is typically defined as `((void*)0)`
- `sizeof(void)` will give `0`. From clause 6.2.5, “A pointer to void shall have the same representation and alignment requirements as a pointer to a character type”.
- `sizeof(NULL)` will give `8`.

### Rules
1. Always initialize pointer variables to NULL. 
2. Always perform a NULL check before accessing any pointer.

## Function Pointer

- 