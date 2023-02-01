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
- fopen(): to create or to open a file.
- fclose(): to close a file.
- fgets(): to read a file.
- fprintf(): to write blocks of data into a file.
- fscanf(): to read blocks of data from a file.
- getc(): to read a single character to a file.
- putc(): to write a single character to a file.
- fseek(): to set the position of a file pointer to a mentioned location.
- ftell(): to return the current position of a file pointer.
- rewind(): to set the file pointer to the beginning of a file.
- putw(): to write an integer to a file.
- getw(): to read an integer from a file.

### fseek()
```
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

```
(void)fseek(stream, 0L, SEEK_SET)
```

-  Except that the error indicator for the stream is also cleared

## fsetpos()
