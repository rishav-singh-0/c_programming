#include <stdio.h>

int main() {
    FILE* f1 = fopen("string.txt", "w");

    char str[50] = {'a', 'b', '\0', 'c', 'd', -1, 'e', 'f'};
    
    for(int i=0; i<50; i++){
        fputc(str[i], f1);
        printf("%d\t%c\n", str[i], str[i]);
    }
    // fputs(str, f1);
    fclose(f1);

    return 0;
}