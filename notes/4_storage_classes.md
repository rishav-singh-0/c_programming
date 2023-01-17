# Storage Classes
Date: 11th Jan 2023

## auto
This is the default storage class for all the variables declared inside a
function or a block.

## extern 
Extern storage class simply tells us that the variable is defined
elsewhere and not within the same block where it is used.

- Extends the visibility of the variables/functions
- Extern variable says to compiler "go outside my scope and you will find the
  definition of the variable that I declared."
- Compiler believes that whatever that extern variable said is true and produce
  no error. Linker throws an error when it finds no such variable exists.
- When an extern variable is initialized, then memory for this is allocated and
  it will be considered defined.

- When a function is declared or defined, the extern keyword is implicitly
  assumed since functions are visible throughout the program by default.
- As an exception, when an extern variable is declared with initialization, it
  is taken as the definition of the variable as well.

## static 
Static variables have the property of preserving their value even
after they are out of their scope. They are initialized only once and exist
till the termination of the program. Their scope is local to the function to
which they were defined. Global static variables can be accessed anywhere in
the program. By default, they are assigned the value 0 by the compiler. 

- Static variables are allocated memory in data segment, not stack segment. 
- Default value is 0. For pointers it is NULL pointer.
- In C, static variables can only be initialized using constant literals(Not
  true in C++). All objects with static storage duration must be initialized
  (set to their initial values) before execution of main() starts. So a value
  which is not known at translation time cannot be used for initialization of
  static variables.
- Static variables should not be declared inside structure. All structure
  members should reside in the same memory segment because the value for the
  structure element is fetched by counting the offset of the element from the
  beginning address of the structure.


## register 
Functionality is same as `auto` but the only difference is that the
compiler tries to store these variables in the register of the microprocessor
if a free registration is available. If a free registration is not available,
    these are then stored in the memory only. We cannot obtain the address of a
    register variable using pointers. 
- The keyword register hints(request) to compiler that a given variable can be
  put in a register. It’s compiler’s choice to put it in a register or not.
- Register is a storage class, and C doesn’t allow multiple storage class
  specifiers for a variable. So, register can not be used with static.
- Register can only be used within a block (local), it can not be used in the
  global scope (outside main).
- There is no limit on number of register variables in a C program, but the
  point is compiler may put some variables in register and some not.

## volatile qualifier 
- The volatile keyword is intended to prevent the compiler from applying any
  optimizations on objects that can change in ways that cannot be determined by
  the compiler. 
- An object that has volatile-qualified type may be modified in ways unknown to
  the implementation or have other unknown side effects.
- A volatile declaration may be used to describe an object corresponding to a
  memory-mapped input/output port or an object accessed by an asynchronously
  interrupting function. Actions on objects so declared shall not be "optimized
  out" by an implementation or reordered except as permitted by the rules for
  evaluating expressions.
- Too many `volatile` variables in your program would also result in lesser &
  lesser compiler optimization. 
- The system always reads the current value of a volatile object from the
  memory location rather than keeping its value in a temporary register at the
  point it is requested, even if a previous instruction asked for the value
  from the same object.

## const quantifier
- The qualifier const can be applied to the declaration of any variable to
  specify that its value will not be changed ( Which depends upon where const
  variables are stored, we may change the value of const variable by using
  pointer ). The result is implementation-defined if an attempt is made to
  change a const. 

```
int a = 5, b = 10, c = 15;

const int* foo;     // pointer to constant int.
foo = &a;           // assignment to where foo points to.

/* dummy statement*/
*foo = 6;           // the value of a can´t get changed through the pointer.

foo = &b;           // the pointer foo can be changed.



int *const bar = &c;  // constant pointer to int 
                      // note, you actually need to set the pointer 
                      // here because you can't change it later ;)

*bar = 16;            // the value of c can be changed through the pointer.    

/* dummy statement*/
bar = &a;             // not possible because bar is a constant pointer.  
```

[`const int *` and `int const *`](https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const)