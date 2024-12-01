#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void* x, const void* y){
    int a = *(int*) x;
    int b = *(int*) y;
    return (a > b) - (a < b);
}

int main(void){
    int list_1[1000];
    int list_2[1000];
    long distance = 0;
    char line[16];
    char* token;
    int i = 0;
    FILE* data = fopen("data.txt", "r");

    if(data != NULL){
        while(fgets(line, sizeof(line), data)){
            token = strtok(line, " ");
            list_1[i] = atoi(token);
            token = strtok(NULL, " ");
            list_2[i] = atoi(token);
            i++;
        }
    }
    qsort(list_1, 1000, sizeof(int), comp);
    qsort(list_2, 1000, sizeof(int), comp);
    
    for(int j = 0; j < 1000; j++){
        distance += abs(list_1[j] - list_2[j]);
    }

    printf("total distance between lists: %ld\n", distance);
    
    return 0;
}