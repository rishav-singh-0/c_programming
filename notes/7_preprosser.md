# Preprocessor

- #define is a preprocessor directive. Data defined by the #define macro definition are preprocessed, so that your entire code can use it. This can free up space and increase compilation times.
- CONSTs are handled by the compiler, where as #DEFINEs are handled by the pre-processor

## Const

- They are fixed values in a program. 
- Every constant has some range. The integers that are too big to fit into an int will be taken as long.
- Could be defined from
  - Using #define preprocessor directive `#define identifierName value`
  - Using a const keyword `const int intVal = 10;`

## Preprocessor tasks

1. Removing comments
2. File inclusion
3. Macro expansion

## Types of Preprocessor Directives:  

1. Macros
2. File Inclusion
3. Conditional Compilation
    - Conditional Compilation directives are a type of directive that helps to compile a specific portion of the program or to skip the compilation of some specific part of the program based on some conditions.
4. Line control
5. Error directive
6. Other directives

## Math.h

1. double ceil(double x): The C library function double ceil (double x) returns the smallest integer value greater than or equal to x. 
2. double floor(double x): The C library function double floor(double x) returns the largest integer value less than or equal to x. 
3. double fabs(double x): The C library function double fabs(double x) returns the absolute value of x. 
4. double log(double x): The C library function double log(double x) returns the natural logarithm (base-e logarithm) of x. 
5. double log10(double x): The C library function double log10(double x) returns the common logarithm (base-10 logarithm) of x. 
6. double fmod(double x, double y) : The C library function double fmod(double x, double y) returns the remainder of x divided by y. 
7. double sqrt(double x): The C library function double sqrt(double x) returns the square root of x. 
8. double pow(double x, double y): The C library function double pow(double x, double y) returns x raised to the power of y i.e. x^y. 
9. double modf(double x, double *integer): The C library function double modf(double x, double *integer) returns the fraction component (part after the decimal), and sets integer to the integer component.
    ```
    fractpart = modf(x, &intpart);
    ```

10. double exp(double x): The C library function double exp(double x) returns the value of e raised to the xth power. 
11. double cos(double x) : The C library function double cos(double x) returns the cosine of a radian angle x. 
12. double acos(double x) : The C library function double acos(double x) returns the arc cosine of x in radians. 
13. double tanh(double x): The C library function double tanh(double x) returns the hyperbolic tangent of x. Same syntax can be used for other hyperbolic trigonometric functions like sinh, cosh etc. 


## Difference between typedef and #define:

- typedef is limited to giving symbolic names to types only, whereas #define can be used to define an alias for values as well, e.g., you can define 1 as ONE, 3.14 as PI, etc.
- typedef interpretation is performed by the compiler where #define statements are performed by preprocessor.
- typedef follows the scope rule which means if a new type is defined in a scope (inside a function), then the new type name will only be visible till the scope is there. In case of #define, when preprocessor encounters #define, it replaces all the occurrences, after that (No scope rule is followed).

## Points to remember

- In C++, "const int" could not be assigned yo "int" datatype, but in C it is possible.

## Case Study

first_file.c
```
#include<stdio.h>
// #include "second_file.c"

extern int fun1();
extern int fun2();
//extern int var_1;

int main(){
    //printf("\n%d\t%p", var_1, &var_1);
    fun1();
    fun2();
    
    return 0;
}
```

second_file.c
```
#include<stdio.h>

static int var_1 = 5;

int fun1(){
    printf("\n%d\t%p", var_1, &var_1);
}
```

third_file.c
```
#include<stdio.h>

static int var_1 = 1;

int fun2(){
    printf("\n%d\t%p", var_1, &var_1);
}
```

- if file 1 and 2 both have static var_1, then functions fun1 and 2 will give differnt memory addresses
- if file 2 doesnt have static var_1 ie. global var_1, we could use var_1 using extern in file 1 and address will be same as file 2, but diffrent in file 3 which is having static var_1
- if we `#include file1.c` it will copy paste whole file here, means `static` in that file will be useless.