#include <stdio.h>

void cube(int *num) {
    *num = (*num) * (*num) * (*num);
}

int main() {
    int num = 5;
    printf("Before cubing: %d\n", num);
    cube(&num);
    printf("After cubing: %d\n", num);
    return 0;
}
