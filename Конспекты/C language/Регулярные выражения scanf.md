```c
#include <stdio.h>

int main () {
    double value;
    char symbol;
    int pattern_success_count = scanf("%lf%c", &value, &symbol);
    if (pattern_success_count != 2 || n != '\n') {
        printf("Stroka nesootvetstvyet shablony %lf <%c>", value, n);
    } else {
        printf("Turbo pyshka");
    }
    return 0;
}

int main () {
    double value1, value2, value3;
    char symbol;
        int pattern_success_count = scanf("%lf %lf %lf%c", &value1, &value2, &value3,       &symbol);
    //  int pattern_success_count = scanf("%lf,%lf,%lf%c", &value1, &value2, &value3,       &symbol);
    //  int pattern_success_count = scanf("%d,%lf,%d%c",  &value1, &value2, &value3,        &symbol);
    //  int pattern_success_count = scanf("%d %lf %d%c",  &value1, &value2, &value3,        &symbol);
    if (pattern_success_count != 4 || symbol != '\n') {
        printf("Stroka nesootvetstvyet shablony %lf <%c>", value, n);
    } else {
        printf("Turbo pyshka");
    }

    return 0;
}

```