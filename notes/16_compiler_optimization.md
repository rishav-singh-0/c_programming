# Optimizer compiler flags

There are a number of levels of “optimization” that you can request from the gcc compiler at compile time. 
Turning on the optimizer flags asks the compiler to attempt to improve the performance (speed) of the code, typically at the expense of compilation time, (sometimes code size), and (usually) debugging ease.

```
gcc -Q --help=optimizers
```

## Effects on debugging

As a general rule, in fact, you should not use optimization flags when you are still debugging your code with gdb. When your code is compiled with optimization flags, strange things can happen, for example, variables you have defined may no longer be present, some statements may be executed in different places than where they are coded (and sometimes not at all), etc.

Sometimes you can get impressive speedups with optimization, simply by compiling with an optimizer flag, you might get a speedup even of twice as fast.


## References
- [GCC Optimization Options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)
- [LinuxJournal Article](https://www.linuxjournal.com/article/7269)