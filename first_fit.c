#include <stdio.h>

int main() {
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};

    int b = 5, p = 4, alloc[4];

    for (int i = 0; i < p; i++) alloc[i] = -1;

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < b; j++) {
            if (block[j] >= process[i]) {
                alloc[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("\nFIRST FIT RESULT\n");
    for (int i = 0; i < p; i++) {
        if (alloc[i] != -1) 
            printf("Process %d -> Block %d\n", i+1, alloc[i]+1);
        else 
            printf("Process %d -> Not Allocated\n", i+1);
    }
}
