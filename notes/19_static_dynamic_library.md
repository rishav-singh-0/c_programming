# Libraries
Libraries typically contain functions that can be reused by different programs. Before the function can be used in your program, the library must be linked with your program.

Libraries can be linked to the client program that uses them in either of the following ways:
- statically
- dynamically

## Static Linking

The library becomes part of the client’s `executable` file. This leads to a waste of space on the hard disk and memory, as different copies of the library code gets repeated.

### Steps to create Static Library

1. Generate an object file for the source code
   
   Common practice is to create a header file(.h) which contains all the
   declarations and store it in `include` directory

    ``` bash
    gcc -c file_1.c file_2.c
    ```
    
    this will generate 2 files named `file_1.o` and `file_2.o` which are object files for corresponding .c files

2. Archive/zip object files to create the static library

    Common practice is to put all library files(archive) inside `lib` directory
    ``` bash
    ar rcs lib/libfile.a file_1.o file_2.o
    ```
    
    Creates an archive file named `libfile.a`
    > Check with `file` command or `ar t lib/libfile.a` for printing table of contents

    Options of `ar` command:
    - `c`: Create the archive
    - `r`: Insert the files member... into archive (with replacement)
    - `s`: Add an index to the archive, or update it if it already exists

3. Use this library
   
   For compiling the .c file where this library is used, following options are needed
   ``` bash
   gcc file_main.c -lfile -o file_main.out -I include -L lib
   ```
   
   Options of `gcc`:
   - `-I include`: telling linker to include the `include` directory when looking for header files
   - `-L lib`: to specify a non-standard library directory
   - `-l`: specify library name by `-lfile` in this case
     > This option should be after all the .c files needed for current translation unit.
<details>
<summary>Demo</summary>

``` console
[rishav@rishav-MS-7D48] ➜ day14_library (! master) gcc -c file_1.c file_2.c 
[rishav@rishav-MS-7D48] ➜ day14_library (! master) ls
include  lib  file_1.c  file_1.o  file_2.c  file_2.o  file_main.c
[rishav@rishav-MS-7D48] ➜ day14_library (! master) ar rcs lib/libfile.a file_1.o file_2.o 
[rishav@rishav-MS-7D48] ➜ day14_library (! master) file lib/libfile.a 
lib/libfile.a: current ar archive
[rishav@rishav-MS-7D48] ➜ day14_library (! master) ar t lib/libfile.a
file_1.o
file_2.o
[rishav@rishav-MS-7D48] ➜ day14_library (! master) gcc file_main.c -o file_main.out
file_main.c:1:10: fatal error: file_header.h: No such file or directory
    1 | #include "file_header.h"
      |          ^~~~~~~~~~~~~~~
compilation terminated.
[rishav@rishav-MS-7D48] [1] ➜ day14_library (! master) gcc file_main.c -o file_main.out -I include 
/usr/bin/ld: /tmp/ccWWF8Xe.o: in function `main':
file_main.c:(.text+0x25): undefined reference to `addNum'
collect2: error: ld returned 1 exit status
[rishav@rishav-MS-7D48] [1] ➜ day14_library (! master) gcc file_main.c -o file_main.out -I include -L lib 
/usr/bin/ld: /tmp/ccDwPfLA.o: in function `main':
file_main.c:(.text+0x25): undefined reference to `addNum'
collect2: error: ld returned 1 exit status
[rishav@rishav-MS-7D48] [1] ➜ day14_library (! master) gcc file_main.c -lfile -o file_main.out -I include -L lib
[rishav@rishav-MS-7D48] ➜ day14_library (! master) gcc file_main.c -llibfile -o file_main.out -I include -L lib
/usr/bin/ld: cannot find -llibfile: No such file or directory
/usr/bin/ld: note to link with lib/libfile.a use -l:libfile.a or rename it to liblibfile.a
collect2: error: ld returned 1 exit status
[rishav@rishav-MS-7D48] [1] ➜ day14_library (! master) gcc file_main.c -lfile -o file_main.out -I include -L lib 
[rishav@rishav-MS-7D48] ➜ day14_library (! master) ./file_main.out 
[rishav@rishav-MS-7D48] [15] ➜ day14_library (! master)
```
</details>

## Dynamic Linking

A dynamic library remains separate from the client program and can be shared anywhere. There are two ways to link a library dynamically:

- Load-time dynamic linking
- Run-time dynamic linking
