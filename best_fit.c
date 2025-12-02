#include <stdio.h>

int main() {
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};

    int b = 5, p = 4, alloc[4];

    for (int i = 0; i < p; i++) alloc[i] = -1;

    for (int i = 0; i < p; i++) {
        int best = -1;

        for (int j = 0; j < b; j++) {
            if (block[j] >= process[i]) {
                if (best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if (best != -1) {
            alloc[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nBEST FIT RESULT\n");
    for (int i = 0; i < p; i++) {
        if (alloc[i] != -1) 
            printf("Process %d -> Block %d\n", i+1, alloc[i]+1);
        else 
            printf("Process %d -> Not Allocated\n", i+1);
    }
}
