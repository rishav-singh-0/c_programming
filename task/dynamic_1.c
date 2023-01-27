#include<stdio.h>
#include "prototypes.h"

int add(int num1, int num2){
  return num1 + num2;
}

int subtract(int num1, int num2){
  return num1 - num2;
}

int multiply(int num1, int num2){
  return num1 * num2;
}
int divide(int num1, int num2){
  return num1 / num2;
}
int modulo(int num1, int num2){
  return num1 % num2;
}

int (*gOperation[])(int, int) = {add, subtract, multiply, divide, modulo};

int doOperation(int operationType, int num1, int num2){

  // printf("%d\t%d\t%d\n", num1, num2, operationType);
  int result = (*gOperation[operationType])(num1, num2);
  printf("%d\n", result);
  return result;
}

int getInput(int * operationType, int * num1, int * num2){

  // Input validation
  if(NULL==operationType){
    printf("[%s]:[%d] Invalid operationType, NULL found\n", __func__, __LINE__);
    return 1;
  }

  if(NULL==num1){
    printf("[%s]:[%d] Num 1 pointing to NULL\n", __func__, __LINE__);
    return 1;
  }

  if(NULL==num2){
    printf("[%s]:[%d] Num 2 pointing to NULL\n", __func__, __LINE__);
    return 1;
  }

  printf("Enter operation type:\n");
  scanf("%d", operationType);
  printf("Enter two intergers:\n");
  scanf("%d", num1);
  scanf("%d", num2);

  printf("%d\t%d\t%d\n", *num1, *num2, *operationType);

  return 0;
}

int main(){
  int num1, num2, operationType;

  // getInput();
  int returnValue = getInput(&operationType, &num1, &num2);

  if(returnValue){
    printf("Input error\n");
    return 1;
  }
  doOperation(operationType, num1, num2);

  return 0;
}
