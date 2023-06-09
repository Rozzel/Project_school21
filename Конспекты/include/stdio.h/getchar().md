---
tag:
- C/include/stdio.h
---
getchar() на языке Си используется для чтения одного символа из стандартного ввода (обычно клавиатуры). Функция возвращает целочисленное значение, которое представляет собой ASCII-код считанного символа.

Например, следующий код на языке Си считывает символ с клавиатуры и выводит его ASCII-код:

```c
#include <stdio.h>

int main() {
    int c = getchar();
    printf("ASCII code: %d\n", c);
    return 0;
}

```

После запуска программы, вы можете ввести символ на клавиатуре и нажать клавишу "Enter". Затем программа выведет ASCII-код этого символа.

Обратите внимание, что getchar() может возвращать значение EOF (конец файла) в случае, если был достигнут конец ввода. Поэтому перед использованием возвращаемого значения рекомендуется проверять, является ли оно равным EOF.