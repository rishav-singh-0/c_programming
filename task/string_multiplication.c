#include <stdio.h>
#include <string.h>

enum STATUS {SUCCESS, ERROR};
#define STR_LEN 10
#define CAST(ch) (ch - '0')

int stringMultiply(const char*, const char*, char*, const int);
int stringAddition(const char*, const char*, char*);

int main() {
    char num1[STR_LEN] = "15"; 
    char num2[STR_LEN] = "12";
    char result[2*STR_LEN];
    
    int returnStatus = stringMultiply(num1, num2, result, STR_LEN);
    printf("Multiplication of %s and %s is %s\n", num1, num2, result);
    
    return 0;
}

int stringMultiply(const char* iNum1, const char* iNum2, char * ioResult, const int maxLen){
    // validating arguments
    if(NULL==iNum1){
        printf("[%s]:[%d] iNum1 pointing to NULL\n", __func__, __LINE__);
        return ERROR;
    }
    if(NULL==iNum2){
        printf("[%s]:[%d] iNum2 pointing to NULL\n", __func__, __LINE__);
        return ERROR;
    }
    if(NULL==ioResult){
        printf("[%s]:[%d] ioResult pointing to NULL\n", __func__, __LINE__);
        return ERROR;
    }

    int lenNum1 = strlen(iNum1)-1;
    int lenNum2 = strlen(iNum2)-1;

    unsigned long int mulStage0 = 0, mulStage1 = 0, powS0, powS1=1;
    int indexNum1, indexNum2;
    // printf("%d\t%d", lenNum1, lenNum2);
    
    for(indexNum2=lenNum2; indexNum2>=0; indexNum2--){
        
        mulStage0 = 0;
        powS0 = 1;
        for(indexNum1=lenNum1; indexNum1>=0; indexNum1--){
            mulStage0 += powS0 * CAST(iNum1[indexNum1]) * CAST(iNum2[indexNum2]);
            powS0 *= 10;
            // printf("%lu, %d, %d\n", powS0, CAST(iNum1[indexNum1]), CAST(iNum2[indexNum2]));
        }
        // printf("%lu\n", mulStage0);
        mulStage1 += powS1 * mulStage0;
        powS1 *= 10;
    }
    // printf("%lu\n", mulStage1);
    
    sprintf(ioResult, "%lu", mulStage1);
    return SUCCESS;
    
}

int stringAddition(const char* iNum1, const char* iNum2, char* ioResult){
    return 0;
}