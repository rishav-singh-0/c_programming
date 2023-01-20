# Arrays and String

## Arrays

- It is a group of variables of similar data types referred to by a single element.
- Its elements are stored in a contiguous memory location.
- The size of the array should be mentioned while declaring it.
- In C, it is possible to have array of all types except void and functions.
- Arrays are always passed as pointer to functions.
- Like other variables, arrays can be allocated memory in any of the three segments, data, heap, and stack (See this for details). Dynamically allocated arrays are allocated memory on heap, static or global arrays are allocated memory on data segment and local arrays are allocated memory on stack segment.
- Unlike the normal arrays, variable sized arrays cannot be initialized. 

### Shorthand
``` 
    int array[10] = {[0 ... 3]1, [6 ... 9]2}; 
    // will be equal to int array[10] = {1, 1, 1, 1, 0, 0, 2, 2, 2, 2};
```

### Out of bound
- C don’t provide any specification which deal with problem of accessing invalid index (Undefined Behavior)
- **Access non allocated location of memory:** The program can access some piece of memory which is owned by it.
- **Segmentation fault:** The program can access some piece of memory which is not owned by it, which can cause crashing of program such as segmentation fault.
- C++ however offers the std::vector class template, which does not require to perform bounds checking. A vector also has the std::at() member function which can perform bounds-checking.

### sizeof array
- Avoid using sizeof() operator for finding size of array. In C, array parameters are treated as pointers when array is passed as a parameter of a function. So, the expression `sizeof(arr)/sizeof(arr[0])` becomes `sizeof(int *)/sizeof(int)` which results in `8/4=2`
- We can use (&arr)[1] – arr to find the size of the array. Here, arr points to the first element of the array and has the type as int*. And, &arr has the type as int*[n] and points to the entire array. Hence their difference is equivalent to the size of the array.

### pass by value
- make a `struct` wrapper around array

## String

- The difference between a character array and a string is the string is terminated with a unique character ‘\0’.
- A character array initialized with double quoted string has last element as ‘\0’.
- When strings are declared as character arrays, they are stored like other types of arrays in C. For example, if str[] is an auto variable then the string is stored in stack segment, if it’s a global or static variable then stored in data segment, etc.

### string pointers
- The statement `char *s = "some text"` creates a string literal. The string literal is stored in the read-only part of memory by most of the compilers. The C and C++ standards say that string literals have static storage duration, any attempt at modifying them gives undefined behavior. 
```
char *str = "GfG";     /* Stored in read only part of data segment */
char str1[] = "GfG";   /* Stored in stack segment like other auto variables */

/* Stored in heap segment like other dynamically allocated things */
char *str = (char *)malloc(sizeof(char)*size);    
```

- Here `s` is just a pointer and like any other pointer stores address of string literal. 
- Must read [storage for strings](https://www.geeksforgeeks.org/storage-for-strings-in-c/)


### Functions in `<string.h>`

- strlen(string_name):	Returns the length of string name.
- strcpy(s1, s2):	Copies the contents of string s2 to string s1.
- strcmp(str1, str2):	Compares the first string with the second string. If strings are the same it returns 0.
- strcat(s1, s2):	Concat s1 string with s2 string and the result is stored in the first string.
- strlwr():	Converts string to lowercase.
- strupr():	Converts string to uppercase.
- strstr(s1, s2):	Find the first occurrence of s2 in s1.
## `vector` in C++
A vector in C++ is a class in STL that represents an array. The advantages of vectors over normal arrays are, 

- We do not need pass size as an extra parameter when we declare a vector i.e, Vectors support dynamic sizes (we do not have to specify size of a vector initially). We can also resize a vector.
- Vectors have many in-built functions like removing an element, etc.

## Multidimention arrays

- In C/C++, initialization of a multidimensional arrays can have left most dimension as optional. Except the left most dimension, all other dimensions must be specified. 
```
int a[][][2] = { {{1, 2}, {3, 4}}, 
                   {{5, 6}, {7, 8}}
                 };  // error
int a[][2] = {{1,2},{3,4}}; // Works
```