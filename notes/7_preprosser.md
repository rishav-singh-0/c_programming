# Preprocessor

- #define is a preprocessor directive. Data defined by the #define macro definition are preprocessed, so that your entire code can use it. This can free up space and increase compilation times.
- CONSTs are handled by the compiler, where as #DEFINEs are handled by the pre-processor

## Const

- They are fixed values in a program. 
- Every constant has some range. The integers that are too big to fit into an int will be taken as long.
- Could be defined from
  - Using #define preprocessor directive `#define identifierName value`
  - Using a const keyword `const int intVal = 10;`

## Preprocessor tasks

1. Removing comments
2. File inclusion
3. Macro expansion

## Types of Preprocessor Directives:  

1. Macros
2. File Inclusion
3. Conditional Compilation
    - Conditional Compilation directives are a type of directive that helps to compile a specific portion of the program or to skip the compilation of some specific part of the program based on some conditions.
4. Line control
5. Error directive
6. Other directives