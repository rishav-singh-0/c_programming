# File Handeling

## Types of files

1. Text Files: 

   Text files contain data in the form of ASCII characters and are generally used to store a stream of characters. Each line in a text file ends with a new line character (‘/n’).

2. Binary Files: 

   Binary files contain data that is stored in a similar manner to how it is stored in the main memory. Instead of ASCII characters, it is stored in binary format. The binary files can be created only from within a program and their contents can only be read by a program.

## Different operations that can be performed on a file

- Creation of a new file (fopen() with attributes as “a” or “a+” or “w” or “w+”)
- Opening an existing file (fopen())
- Reading from file (fscanf() or fgets())
- Writing to a file (fprintf() or fputs())
- Moving to a specific location in a file (fseek(), rewind())
- Closing a file (fclose())

## fopen(): File access modes

```
FILE *fopen(const char *file_name, const char *mode_of_operation);
```

### r
Searches file. If the file is opened successfully fopen( ) loads it into memory and sets up a pointer that points to the first character in it. If the file cannot be opened fopen( ) returns NULL.

### w
Searches file. If the file exists, its contents are overwritten. If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file.

### a
Searches file. If the file is opened successfully fopen( ) loads it into memory and sets up a pointer that points to the last character in it. If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file.

### `+` after any above modes
- `r+` : Opens the file for both reading and writing
- `w+` : The difference between w and w+ is that we can also read the file created using w+
- `a+` : The file is opened for reading and appending(writing at end of file).

### `b` after any above modes
`b` stands for binary file

> When `x` is used with `w`, fopen() returns `NULL` if file already exists or could not open.


## More Functions for File Handling in C
- `fopen()`: to create or to open a file.
- `fclose()`: to close a file.
- `fgets()`: to read a file.
- `fprintf()`: to write blocks of data into a file.
- `fscanf()`: to read blocks of data from a file.
- `getc()`: to read a single character to a file.
- `putc()`: to write a single character to a file.
- `ftell()`: to return the current position of a file pointer.
- `fseek()`: to set the position of a file pointer to a mentioned location.
- `rewind()`: to set the file pointer to the beginning of a file.
- `putw()`: to write an integer to a file.
- `getw()`: to read an integer from a file.

### fgetc() and fputc()

``` c
int fgetc(FILE *pointer)
pointer: pointer to a FILE object that identifies 
the stream on which the operation is to be performed.

int fputc(int char, FILE *pointer)
char:  character to be written. 
This is passed as its int promotion.
pointer: pointer to a FILE object that identifies the 
stream where the character is to be written.
```

- fputc() is used to write a single character at a time to a given file. It
  writes the given character at the position denoted by the file pointer and
  then advances the file pointer.
- fputc() function returns the character that is written in case of
  successful write operation else in case of error EOF is returned.

### fgets()

``` c
char *fgets(char *str, int n, FILE *stream)
```

- `str` : Pointer to an array of chars where the string read is copied.
- `n` : Maximum number of characters to be copied into str (including the terminating null-character).
- `*stream` : Pointer to a FILE object that identifies an input stream. stdin can be used as argument to read from the standard input.
- `returns` : the function returns str
- It is safe to use because it checks the array bound.
- It keep on reading until new line character encountered or maximum limit of character array.

### ftell()

``` c
long ftell(FILE *pointer)
```
ftell() in C is used to find out the position of file pointer in the file with respect to starting of the file. 

### fseek()
``` c
int fseek(FILE *pointer, long int offset, int position)
pointer: pointer to a FILE object that identifies the stream.
offset: number of bytes to offset from position
position: position from where offset is added.

returns:
zero if successful, or else it returns a non-zero value 
```

SEEK_END : It denotes end of the file.
SEEK_SET : It denotes starting of the file.
SEEK_CUR : It denotes file pointer’s current position.


### rewind()

- The rewind function sets the file position indicator for the stream pointed to by stream to the beginning of the file. It is equivalent to.

``` c
(void)fseek(stream, 0L, SEEK_SET)
```

-  Except that the error indicator for the stream is also cleared

### fwrite() and fread()

``` c
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
ptr - This is pointer to array of elements to be written
size -  This is the size in bytes of each element to be written
nmemb - This is the number of elements, each one with a size of size bytes
stream - This is the pointer to a FILE object that specifies an output stream

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
ptr - This is the pointer to a block of memory with a minimum size of size*nmemb bytes.
size - This is the size in bytes of each element to be read.
nmemb - This is the number of elements, each one with a size of size bytes.
stream - This is the pointer to a FILE object that specifies an input stream.
```



### fgetpos() and fsetpos()

``` c
int fgetpos(FILE *stream, fpos_t *pos)

int fsetpos(FILE *stream, const fpos_t *pos)
// pos: This is the pointer to a fpos_t object containing a position previously obtained with fgetpos.
```
- This function returns zero value if successful, or else it returns a non-zero value and sets the global variable errno to a positive value, which can be interpreted with perror.
- The fsetpos() function moves the file position indicator to the location specified by the object pointed to by position. When fsetpos() is executed ,the end-of-file indicator is reset

## rename()

``` c
int rename (const char *old_name, const char *new_name);

ret_value = rename("old_name.txt", "new_name.txt");
```

If the file is renamed successfully, zero is returned. On failure, a nonzero value is returned.

## remove()

``` c
int remove(const char *file_name);
```
The remove function in C/C++ can be used to delete a file. The function returns 0 if files is deleted successfully, other returns a non-zero value.

## tempfile()

``` c
FILE *tmpfile(void) 
```
- The created temporary file will automatically be deleted after the termination of program.
- It opens file in binary update mode i.e., wb+ mode.
- The tmpfile() function always returns a pointer after the creation of file to
  the temporary file. If by chance temporary file can not be created, then the
  tmpfile() function returns NULL pointer.

## Points to remember

- EOF means -1
- if we read same file 2 times then the file pointers are both diffrent.
- if assigning a file pointer to another file pointer, closing any one will automatically close other.
- while writing to a file, the actual content is written to the file if the location of the "head"(position/index of file pointer) is changed or file is closed with fclose().
- `argv` could be passed to main for taking arguments from console/shell