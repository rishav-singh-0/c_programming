# Makefile

## Capabilities of Make

- Make enables the end user to build and install your package without knowing the details of how that is done -- because these details are recorded in the makefile that you supply. 

- Make figures out automatically which files it needs to update, based on which source files have changed. It also automatically determines the proper order for updating files, in case one non-source file depends on another non-source file. 

- Make is not limited to any particular language. For each non-source file in the program, the makefile specifies the shell commands to compute it. These shell commands can run a compiler to produce an object file, the linker to produce an executable, ar to update a library, or TeX or Makeinfo to format documentation.

- Make is not limited to building a package. You can also use Make to control installing or deinstalling a package, generate tags tables for it, or anything else you want to do often enough to make it worth while writing down how to do it. 

## Make Rules and Targets

A rule in the makefile tells Make how to execute a series of commands in order to build a target file from source files. It also specifies a list of dependencies of the target file. This list should include all files (whether source files or other targets) which are used as inputs to the commands in the rule.

Here is what a simple rule looks like:

```
target:   dependencies ...
          commands
          ...
```

### Example:
```
CC = gcc
CFLAGS = -Wall
DEPS = primes.h
OBJ = go.o primes.o

%.o: %.c $(DEPS)
        $(CC) $(CFLAGS) -c -o $@ $<

go: $(OBJ)
        gcc $(CFLAGS) -o $@ $^
```

## References

- [GNU Make](https://www.gnu.org/software/make/)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- [Simple tutorial/example](https://cs.colby.edu/maxwell/courses/tutorials/maketutor/)