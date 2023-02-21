## Breakpoints

Breakpoints are used to break execution at a specified line, function, or file. If you want to set up a breakpoint at line 6, enter the following command in the gdb mode:

```gdb
gdb) break 6
gdb) run
```

> Note: We can also add conditional breakpoints.

## Step

If you want to step through one line of source code, then enter the following command in the gdb mode:

```gdb
gdb) step
```

## Next

If you want to step through one function of source code, then enter the following command in the gdb mode:

```gdb
gdb) next
```

Print variable values

If you want to print the variable value, you can run the following command:

```gdb
gdb) print {variable name}
```