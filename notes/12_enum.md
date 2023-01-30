# Enum, Struct and Union

## Enum

- Two enum names can have same value
- We can assign values to some name in any order. All unassigned names get value as value of previous name plus one.
- All enum constants must be unique in their scope

### Diffrence from macro

- Enums follow scope rules.
- Enum variables are automatically assigned values.

## Structures

A structure is a keyword that creates user-defined data types in C/C++. A structure creates a data type that can be used to group items of possibly different types into a single type. 

- Structure members cannot be initialized with declaration. Reason: when a datatype is declared, no memory is allocated for it. Memory is allocated only when variables are created.
- Structure members can be initialized using curly braces `{}`.
```
struct Point
{
   int x, y;
};

struct Point p1 = {0, 1};
struct Point p2 = { .y = 1, .x = 0 };
```

- operations on struct
```
struct Point p1 = {10, 20};
struct Point p2 = p1; // works: contents of p1 are copied to p2
if (p1 == p2){}  // compiler error: cannot do equality check for whole structures
```

### Limitations
- No Data Hiding: Structure members can be accessed by any function, anywhere in the scope of the Structure
- Functions inside Structure: C structures do not permit functions inside Structure 
- Static Members: C Structures cannot have static members inside their body
- Access Modifiers: C Programming language does not support access modifiers. So they cannot be used in C Structures.
- Construction creation in Structure: Structures in C cannot have a constructor inside Structures.

## Unions

Like Structures, union is a user defined data type. In union, all members share the same memory location.
For example in the following C program, both x and y share the same location. If we change x, we can see the changes being reflected in y.
```
union test {
    int x, y;
};
```

- Size of a union is taken according the size of largest member in union.
- 

## Structure padding

```
typedef struct structc_tag
{
   char        c;
   double      d;
   int         s;
} structc_t;

structc_t structc_array[3];
```

Assume, the base address of structc_array is 0x0000 for easy calculations. If the structc_t occupies 20 (0x14) bytes as we calculated, the second structc_t array element (indexed at 1) will be at 0x0000 + 0x0014 = 0x0014. It is the start address of index 1 element of array. The double member of this structc_t will be allocated on 0x0014 + 0x1 + 0x7 = 0x001C (decimal 28) which is not multiple of 8 and conflicting with the alignment requirements of double. As we mentioned on the top, the alignment requirement of double is 8 bytes. It will be as that of the largest member of the structure.



