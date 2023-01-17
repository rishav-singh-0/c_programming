# Operators

## 

- In the case of logical AND, the second operand is not evaluated if the first operand is false
- In the case of logical OR, the second operand is not evaluated if the first operand is true
- The left shift and right shift operators should not be used for negative numbers. Results of both 1 <<- 1 and 1 >> -1 is undefined. Also, if the number is shifted more than the size of the integer, the behaviour is undefined.
- The bitwise OR of two numbers is just the sum of those two numbers if there is no carry involved, otherwise you just add their bitwise AND

## Comma
- A comma operator in C++ is a binary operator. It evaluates the first operand & discards the result, evaluates the second operand & returns the value as a result. It has the lowest precedence among all C++ Operators. 

```
x = 12, 20, 24;

// Evaluation is as follows
(((x = 12), 20), 24);
```

## sizeof operator
It is a compile-time unary operator which can be used to compute the size of its operand. The result of sizeof is of the unsigned integral type which is usually denoted by size_t.

- Expressions written in sizeof() are never executed.
- Used to find out the number of elements in an array
```
len = sizeof(arr) / sizeof(arr[0]));
```

- To allocate a block of memory dynamically
```
int* ptr = (int*)malloc(10 * sizeof(int));
```

## L-value and R-value
- In C/C++ the pre-increment (decrement) and the post-increment (decrement) operators require an L-value expression as operand. Providing an R-value or a const qualified variable results in compilation error.
- The unary operators such as -, +, won’t need L-value as operand. The expression -(++i) is valid.
- So overall this means that the postfix and prefix operators require a l value operatand whereas appending a `-` to a expression converts it into a r value opearnd therefore the compiler will through an error. However -(++x) is valid.
- In pre-increment, i.e., ++a, it will increase the value by 1 before printing, and in post-increment, i.e., a++, it prints the value at first, and then the value is incremented by 1.

## Precedence of postfix ++ and prefix ++
In C/C++, precedence of Prefix ++ (or Prefix --) has same priority than dereference (\*) operator, and precedence of Postfix ++ (or Postfix --) is higher than both Prefix ++ and \*.  If p is a pointer then \*p++ is equivalent to \*(p++) and ++\*p is equivalent to ++(\*p) (both Prefix ++ and \* are right associative).

## Ternary Operator
```
exp1 ? exp2 : exp3
```

- It is another interesting fact. The ternary operator has return type. The return type depends on exp2, and convertibility of exp3 into exp2 as per usual\overloaded conversion rules. If they are not convertible, the compiler throws an error.

## strlen()
- strlen() accepts a pointer to an array as argument and walks through memory at run time from the address we give it looking for a NULL character and counts up how many memory locations it passed before it finds one.
- sizeof() is a compile-time expression giving you the size of a type or a variable’s type. It doesn’t care about the value of the variable. Strlen on the other hand, gives you the length of a C-style NULL-terminated string.