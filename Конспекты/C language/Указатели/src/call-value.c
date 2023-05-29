#include <stdio.h>

int cube(int num) {
    return num * num * num;
}

int main() {
    int num = 5;
    printf("Before cubing: %d\n", num);
    num = cube(num);
    printf("After cubing: %d\n", num);
    return 0;
}
