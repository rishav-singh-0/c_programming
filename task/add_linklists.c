#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

ListNode *populateList(const int);
ListNode *addTwoNumbers(ListNode *, ListNode *);
int lenList(const ListNode *);
void printList(const ListNode *);
void freeList(ListNode *);

int main() {
    ListNode* Num1 = populateList(342);
    ListNode* Num2 = populateList(465);

    ListNode* result = addTwoNumbers(Num1, Num2);
    printList(result);
    freeList(Num1); Num1 = NULL;
    freeList(Num2); Num2 = NULL;
    freeList(result); result = NULL;

    return 0;
}

ListNode* populateList(int iNum){
    int rem = iNum%10;
    iNum = iNum/10;

    ListNode* newListPtr = (ListNode*)malloc(sizeof(ListNode));
    newListPtr->data = rem;
    if(iNum!=0){
        newListPtr->next = populateList(iNum);
        return newListPtr;
    }
    newListPtr->next = NULL;
    return newListPtr;
}

int lenList(const ListNode* iHead){
    int len = 0;
    const ListNode* ptr = iHead;
    for(len=0; NULL!=ptr; ptr=ptr->next, len++);
    printf("%d\n", len);
    return len;
}

void freeList(ListNode* iHead){
    ListNode* tmp;

    while (iHead != NULL){
        tmp = iHead;
        iHead = iHead->next;
        free(tmp);
    }
}

void printList(const ListNode* iHead){
    const ListNode* tmp = iHead;

    while ( NULL != tmp){
        printf("%d ->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

ListNode * addTwoNumbers(ListNode* iList1_Ptr, ListNode* iList2_Ptr){


    if( NULL ==iList1_Ptr){
        printf("[%s]:[%d] iList1_Ptr of Link List is pointing to NULL\n", __func__, 75);
        return NULL ;
    }
    if( NULL ==iList2_Ptr){
        printf("[%s]:[%d] iList2_Ptr of Link List is pointing to NULL\n", __func__, 79);
        return NULL ;
    }

    ListNode* newListPtr = (ListNode*)malloc(sizeof(ListNode));
    ListNode* ptr1 = iList1_Ptr;
    ListNode* ptr2 = iList2_Ptr;
    ListNode* result = newListPtr;
    int listLen1 = lenList(iList1_Ptr);
    int listLen2 = lenList(iList2_Ptr);

    int addition, carry = 0;
    while( NULL !=ptr1 || NULL !=ptr2){

        addition = carry + ptr1->data + ptr2->data;
        carry = addition/10;
        addition = addition%10;
        printf("%d, %d\n", carry, addition);
        result->data = addition;
        result->next = (ListNode*)malloc(sizeof(ListNode));


            ptr1 = ptr1->next;


            ptr2 = ptr2->next;

        result = result->next;

    }
    free(result->next);
    result = NULL ;

    return newListPtr;
}
