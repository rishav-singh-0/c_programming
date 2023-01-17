Date: 10th Jan 2023

## General Points
- If no data type is given to a variable, the compiler automatically converts
  it to int data type.
- Signed is the default modifier for char and int data types.
- We can’t use any modifiers(signed or unsigned) in float data type. Only long
  modifier is allowed in double data types.

## Boolean
Unlike C++, where no header file is needed to use bool, a header file “stdbool.h” must be included to use bool in C. 

## Long data type
CPU calls data from RAM by giving the address of the location to MAR (Memory
Address Register). The location is found and the data is transferred to MDR
(Memory Data Register). This data is recorded in one of the Registers in the
Processor for further processing. That’s why size of Data Bus determines the
size of Registers in Processor. Now, a 32 bit register can call data of 4 bytes
size only, at a time. And if the data size exceeds 32 bits, then it would
required two cycles of fetching to have the data in it. This slows down the
speed of 32 bit Machine compared to 64 bit, which would complete the operation
in ONE fetch cycle only. So, obviously for the smaller data, it makes no
difference if my processors are clocked at the same speed. Compilers are
designed to generate the most efficient code for the target machine
architecture.

If it is important to you for integer types to have the same size on all Intel
platforms, then consider replacing “long” by either “int” or “long long”. The
size of the “int” integer type is 4 bytes and the size of the “long long”
integer type is 8 bytes for all the above combinations of operating system,
architecture and compiler.

```
Output in 32 bit gcc compiler:-
Size of int = 4
Size of long = 4
Size of long long = 8

Output in 64 bit gcc compiler:-
Size of int = 4
Size of long = 8
Size of long long = 8
```

## Float and Double
float is a 32-bit IEEE 754 single precision Floating Point Number – 1 bit for
the sign, 8 bits for the exponent, and 23* for the value. float has 7 decimal
digits of precision. double is a 64-bit IEEE 754 double precision Floating
Point Number – 1 bit for the sign, 11 bits for the exponent, and 52* bits for
the value. double has 15 decimal digits of precision. 

## size_t
if the compiler is 32 bit then it is simply a typedef(i.e., alias) for
`unsigned int` but if the compiler is 64 bit then it would be a typedef for
`unsigned long long`. The size_t data type is never negative.