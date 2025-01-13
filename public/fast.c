#include <stdio.h>
#define MAX 100

typedef struct {
    int rows;
    int cols;
    int value;
} SparseMatrix;

void transpose(SparseMatrix sparse[], SparseMatrix transpose[]) {
    int rowTerms[MAX] = {0};
    int startPos[MAX] = {0};
    int numCols = sparse[0].cols;
    int numNonZero = sparse[0].value;

    transpose[0].rows = numCols;
    transpose[0].cols = sparse[0].rows;
    transpose[0].value = numNonZero;

    for (int i = 1; i <= numNonZero; i++) {
        rowTerms[sparse[i].cols]++;
    }

    startPos[0] = 1; 
    for (int i = 1; i < numCols; i++) {
        startPos[i] = startPos[i - 1] + rowTerms[i - 1];
    }

    for (int i = 1; i <= numNonZero; i++) {
        int pos = startPos[sparse[i].cols];
        startPos[sparse[i].cols]++;  

        transpose[pos].rows = sparse[i].cols;
        transpose[pos].cols = sparse[i].rows;
        transpose[pos].value = sparse[i].value;
    }
}

void print(SparseMatrix sparse[], int nonZeroCount) {
    printf("Row Col Value\n");
    for (int i = 0; i <= nonZeroCount; i++) {
        printf("%d   %d   %d\n", sparse[i].rows, sparse[i].cols, sparse[i].value);
    }
}

int main() {
    int rows, cols, nonZeroCount;
    SparseMatrix sparse[MAX];
    SparseMatrix transposed[MAX];

    printf("Enter number of rows and cols:\n");
    scanf("%d %d", &rows, &cols);

    printf("Enter number of non-zero values:\n");
    scanf("%d", &nonZeroCount);

    if (rows > MAX || cols > MAX || nonZeroCount > MAX) {
        printf("Input exceeds allowed matrix size.\n");
        return 1;
    }

    sparse[0].rows = rows;
    sparse[0].cols = cols;
    sparse[0].value = nonZeroCount;

    printf("Enter sparse matrix (row col value):\n");
    for (int i = 1; i <= nonZeroCount; i++) {
        scanf("%d %d %d", &sparse[i].rows, &sparse[i].cols, &sparse[i].value);

        if (sparse[i].rows >= rows || sparse[i].cols >= cols || sparse[i].value == 0) {
            printf("Invalid input: row or column out of bounds, or value is zero.\n");
            return 1;
        }
    }

    transpose(sparse, transposed);

    printf("Transposed matrix is:\n");
    print(transposed, nonZeroCount);

    return 0;
}
