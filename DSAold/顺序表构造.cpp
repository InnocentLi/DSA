#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
    vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int)*size);
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 100);
    clear(a);
    return 0;
}
