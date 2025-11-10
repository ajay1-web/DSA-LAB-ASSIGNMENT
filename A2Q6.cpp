#include <stdio.h>

#define MAX 50

// Function to display triplet form
void display(int t[][3]) {
    printf("\nRow\tCol\tVal\n");
    for (int i = 0; i <= t[0][2]; i++)
        printf("%d\t%d\t%d\n", t[i][0], t[i][1], t[i][2]);
}

// ---------- TRANSPOSE ----------
void transpose(int A[][3], int B[][3]) {
    B[0][0] = A[0][1];
    B[0][1] = A[0][0];
    B[0][2] = A[0][2];

    int k = 1;
    for (int col = 0; col < A[0][1]; col++) {
        for (int i = 1; i <= A[0][2]; i++) {
            if (A[i][1] == col) {
                B[k][0] = A[i][1];
                B[k][1] = A[i][0];
                B[k][2] = A[i][2];
                k++;
            }
        }
    }
}

// ---------- ADDITION ----------
void add(int A[][3], int B[][3], int C[][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("\nMatrix addition not possible (Dimension mismatch)\n");
        return;
    }

    int i = 1, j = 1, k = 1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
        else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
    }

    while (i <= A[0][2]) C[k][0] = A[i][0], C[k][1] = A[i][1], C[k][2] = A[i][2], i++, k++;
    while (j <= B[0][2]) C[k][0] = B[j][0], C[k][1] = B[j][1], C[k][2] = B[j][2], j++, k++;

    C[0][2] = k - 1;
}

// ---------- MULTIPLICATION ----------
void multiply(int A[][3], int B[][3], int C[][3]) {
    if (A[0][1] != B[0][0]) {
        printf("\nMultiplication not possible (Dimension mismatch)\n");
        return;
    }

    int Btranspose[MAX][3];
    transpose(B, Btranspose);

    int k = 1;
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= Btranspose[0][2]; j++) {
            if (A[i][1] == Btranspose[j][1]) {
                C[k][0] = A[i][0];
                C[k][1] = Btranspose[j][0];
                C[k][2] = A[i][2] * Btranspose[j][2];
                k++;
            }
        }
    }

    C[0][2] = k - 1;
}

// ---------- MAIN ----------
int main() {
    int A[MAX][3] = {{3, 3, 3}, {0, 0, 5}, {1, 2, 8}, {2, 1, 6}};
    int B[MAX][3] = {{3, 3, 3}, {0, 0, 3}, {1, 2, 7}, {2, 1, 4}};
    
    int T[MAX][3], SUM[MAX][3], MUL[MAX][3];

    printf("\nMatrix A (Triplet Form):");
    display(A);

    printf("\nTRANSPOSE of A:");
    transpose(A, T);
    display(T);

    printf("\nADDITION of A + B:");
    add(A, B, SUM);
    display(SUM);

    printf("\nMULTIPLICATION of A × B:");
    multiply(A, B, MUL);
    display(MUL);

    return 0;
}
