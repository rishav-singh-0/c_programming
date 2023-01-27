
int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);
int modulo(int num1, int num2);

enum OPERATION {
  OPERATION_ADD, 
  OPERATION_SUBSTRACT, 
  OPERATION_MULTIPLY, 
  OPERATION_DIVIDE, 
  OPERATION_MODULO, 
  OPERATION_MAX
};

int doOperation(int operationType, int num1, int num2);
int getInput(int * operationType, int * num1, int * num2);
