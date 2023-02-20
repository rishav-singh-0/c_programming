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
    
    This will generate 2 files named `file_1.o` and `file_2.o` which are object files for corresponding .c files

2. Archive/zip object files to create the static library

    Common practice is to put all library files(archive) inside `lib`
    directory. Library name should start with `lib` and name after it is actual
    library name which will be used in next step

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
[rishav@rishav-MS-7D48] ➜ day14_library (U master) readelf -a file_main.out | grep Shared
 0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]

[rishav@rishav-MS-7D48] ➜ day14_library (U master) gcc file_main.c -lfile -o file_main.out -I include -L lib -static
[rishav@rishav-MS-7D48] ➜ day14_library (U master) readelf -a file_main.out | grep Shared                           
[rishav@rishav-MS-7D48] [1] ➜ day14_library (U master) ./file_main.out
[rishav@rishav-MS-7D48] [15] ➜ day14_library (U master) ll
Permissions Size User   Date Modified Name
drwxrwxr-x     - rishav 20 Feb 12:30  include/
drwxrwxr-x     - rishav 20 Feb 12:32  lib/
.rw-rw-r--    57 rishav 20 Feb 12:29  file_1.c
.rw-rw-r--  1.2k rishav 20 Feb 12:32  file_1.o
.rw-rw-r--    57 rishav 20 Feb 12:29  file_2.c
.rw-rw-r--  1.2k rishav 20 Feb 12:32  file_2.o
.rw-rw-r--    87 rishav 20 Feb 12:31  file_main.c
.rwxrwxr-x  817k rishav 20 Feb 14:48  file_main.out*
[rishav@rishav-MS-7D48] ➜ day14_library (U master) 
```
</details>

## Dynamic Linking

Dynamically Linked Library (DLL) remains separate from the client program and can be shared anywhere. There are two ways to link a library dynamically:

- Load-time dynamic linking
- Run-time dynamic linking

### Steps to create Dynamic Library

1. Generate an object file for the source code
   
   We have created the object file with the -fPIC flag. This flag is known as a position-independent code.

    ```bash
    gcc -Wall -fPIC -c lib_dynamic.c
    ```

2. Create a shared object (.so file) that can be linked with other objects to create an executable
   
   ```bash
   gcc -shared -Wl,-soname,libfile_dynamic.so -o lib/libfile_dynamic.so file_1.o file_2.o
   ```

3. Update `LD_LIBRARY_PATH`
   
   ```bash
   export LD_LIBRARY_PATH=$PWD/lib:＄LD_LIBRARY_PATH
   ```

4. Use this library
   
   For compiling the .c file where this library is used, following options are needed
   ``` bash
   gcc file_main.c -lfile_dynamic -o file_main.out -I include -L lib
   ```
   
   Options of `gcc`:
   - `-I include`: telling linker to include the `include` directory when looking for header files
   - `-L lib`: to specify a non-standard library directory
   - `-l`: specify library name by `-lfile` in this case
     > This option should be after all the .c files needed for current translation unit.

<details>
<summary>Demo</summary>

```console
[rishav@rishav-MS-7D48] ➜ day14_library (U! master) gcc -Wall -fPIC -c file_1.c file_2.c
[rishav@rishav-MS-7D48] ➜ day14_library (U! master) gcc -shared -Wl,-soname,libfile_dynamic.so -o lib/libfile_dynamic.so file_1.o file_2.o
[rishav@rishav-MS-7D48] ➜ day14_library (U! master) gcc -shared -Wl,-soname,libfile_dynamic.so -o lib/libfile_dynamic.so file_1.o file_2.o
[rishav@rishav-MS-7D48] ➜ day14_library (U! master) file lib/libfile_dynamic.so
lib/libfile_dynamic.so: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, BuildID[sha1]=099ca326dda3becbdf9dd70461d3e35858050b10, not stripped
[rishav@rishav-MS-7D48] ➜ day14_library (U! master) gcc file_main.c -lfile_dynamic -o file_main.out -I include -L lib 
[rishav@rishav-MS-7D48] ➜ day14_library (U! master) ./file_main.out 
./file_main.out: error while loading shared libraries: libfile_dynamic.so: cannot open shared object file: No such file or directory
[rishav@rishav-MS-7D48] [127] ➜ day14_library (U! master) export LD_LIBRARY_PATH=$PWD/lib:＄LD_LIBRARY_PATH
[rishav@rishav-MS-7D48] ➜ day14_library (U! master) gcc file_main.c -lfile_dynamic -o file_main.out -I include -L lib
[rishav@rishav-MS-7D48] ➜ day14_library (U! master) ./file_main.out                                                  
[rishav@rishav-MS-7D48] [15] ➜ day14_library (U! master) ll
Permissions Size User   Date Modified Name
drwxrwxr-x     - rishav 20 Feb 12:30  include/
drwxrwxr-x     - rishav 20 Feb 15:11  lib/
.rw-rw-r--    57 rishav 20 Feb 12:29  file_1.c
.rw-rw-r--  1.2k rishav 20 Feb 15:08  file_1.o
.rw-rw-r--    57 rishav 20 Feb 12:29  file_2.c
.rw-rw-r--  1.2k rishav 20 Feb 15:08  file_2.o
.rw-rw-r--    87 rishav 20 Feb 12:31  file_main.c
.rwxrwxr-x   16k rishav 20 Feb 15:21  file_main.out*
.rw-rw-r--  1.8k rishav 20 Feb 14:52  typescript
[rishav@rishav-MS-7D48] ➜ day14_library (U! master) 
```
</details>
