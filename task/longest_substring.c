#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 100

enum STATUS {SUCCESS, ERROR};

int getLongestSubstring(const char * iStrPtr, int iLen, int * ioStartIdx);

int main() {
    
    // char string[ARRAY_SIZE] = "abcabcbb";
    // char string[ARRAY_SIZE] = "bbbbb";
    char string[ARRAY_SIZE] = "pwwkew";
    int startIdx = 0;
    int subStringLen = getLongestSubstring(string, strlen(string), &startIdx);
    
    printf("%d\n", subStringLen);
    for(int index=startIdx; index<startIdx+subStringLen; index++){
        fputc(string[index], stdout);
    }

    return 0;
}

int getLongestSubstring(const char * iStrPtr, int iLen, int * ioStartIdx)
{
    // validating arguments
    if(NULL==iStrPtr){
        printf("[%s]:[%d] iStrPtr pointing to NULL\n", __func__, __LINE__);
        return ERROR;
    }
    if(NULL==ioStartIdx){
        printf("[%s]:[%d] ioStartIdx pointing to NULL\n", __func__, __LINE__);
        return ERROR;
    }
    
    char indexPointer=0, tPtr=0, maxSubStrLen=0, subStrLen=0;
    char char1, char2;

    int indexIter1 = 0, indexIter2 = 0; 
    for(indexIter1=0; indexIter1<iLen; indexIter1++){
        // printf("%c %c, ", iStrPtr[indexIter1+subStrLen], iStrPtr[indexIter2]);
        // printf("\t\t\tI1=%d\tI2=%d\tsubLen=%d\tptr=%d\n", indexIter1, indexIter2, subStrLen, indexPointer);
        
        

    }

    return maxSubStrLen;
}

/*
            if(iStrPtr[indexIter1]==iStrPtr[indexIter2]){
                indexPointer = indexIter1;
                subStrLen = indexIter2 - indexPointer;
                break;
            }
            subStrLen++;
            
            

    for(indexIter1=0; indexIter1<iLen; indexIter1++){

        for(indexIter2=indexIter1+1; indexIter2<iLen-1; indexIter2++){
            printf("%c %c, ", iStrPtr[indexIter1+subStrLen], iStrPtr[indexIter2]);
            printf("\t\t\tI1=%d\tI2=%d\tsubLen=%d\tptr=%d\n", indexIter1, indexIter2, subStrLen, indexPointer);
            
            for(int i=0; i<indexIter2; i++){
                
                char1 = iStrPtr[indexIter1];
                char2 = iStrPtr[indexIter2];
                
                if(char1==char2){
                    indexIter1 = indexIter1+subStrLen;
                    // break;
                }
                else{
                    subStrLen++;
                }
            }
        if(maxSubStrLen < subStrLen){
            maxSubStrLen = subStrLen;
            indexPointer = indexIter1;
        }
        subStrLen = 1;
            
        }
    }




            
Example 1:
Input: s = "abcabcbb"
Output: abc, 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: b, 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: wke, 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/