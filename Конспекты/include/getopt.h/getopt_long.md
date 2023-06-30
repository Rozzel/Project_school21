---
tag:
- C/include/getopt.h
- С/getopt
---

`getopt_long` - это функция стандартной библиотеки C, которая предоставляет возможность обработки командной строки с длинными опциями (long options). Она является расширением более простой функции `getopt`, которая работает только с короткими опциями (short options).

Вот пример использования функции `getopt_long`:

```c
#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int option;
    int option_index = 0;

    // Определение массива структур для опций
    struct option long_options[] = {
        {"input", required_argument, NULL, 'i'},
        {"output", required_argument, NULL, 'o'},
        {"verbose", no_argument, NULL, 'v'},
        {NULL, 0, NULL, 0} // Завершающий элемент массива
    };

    while ((option = getopt_long(argc, argv, "i:o:v", long_options, &option_index)) != -1) {
        switch (option) {
            case 'i':
                printf("Input file: %s\n", optarg);
                break;
            case 'o':
                printf("Output file: %s\n", optarg);
                break;
            case 'v':
                printf("Verbose mode enabled\n");
                break;
            case '?':
                // Некорректная опция или недостающий аргумент
                break;
            default:
                break;
        }
    }

    return 0;
}
```

В этом примере определены три опции: `--input` (или `-i`) с обязательным аргументом, `--output` (или `-o`) с обязательным аргументом и `--verbose` (или `-v`) без аргументов. Функция `getopt_long` проходит по аргументам командной строки, разбирает опции и вызывает соответствующие обработчики для каждой опции.

Функция `getopt_long` принимает следующие аргументы:
- `argc`: Количество аргументов командной строки.
- `argv`: Массив строк аргументов командной строки.
- `optstring`: Строка, содержащая короткие опции. Например, `"i:o:v"` означает, что опции `-i`, `-o` и `-v` принимают аргументы.
- `long_options`: Массив структур `option`, представляющих длинные опции.
- `option_index`: Указатель на переменную, в которую будет записываться индекс найденной длинной опции.

Возвращаемое значение функции `getopt_long`:
- Если опция успешно разобрана, то функция возвращает ее символ (короткую опцию) или 0 (ноль) для длинных опций.
- Если все опции разобраны, то функция возвращает -1.

Обработка аргументов командной строки с помощью `getopt_long` позволяет программе гибко и удобно

 работать с командными параметрами, поддерживать длинные опции и обрабатывать ошибки ввода.

[getopt](../unistd.h/getopt.md)
`getopt` поддерживает только короткие опции, которые представляют собой одиночный символ, предшествующий дефис. Например, `-a` или `-b`.

`getopt_long`, с другой стороны, поддерживает как короткие, так и длинные опции. Длинные опции обычно состоят из нескольких символов или слов и начинаются с двух дефисов. Например, `--help` или `--version`.

Прототип `getopt_long` выглядит следующим образом:

```c
#include <getopt.h>

int getopt_long(int argc, char * const argv[],
   const char *optstring,
   const struct option *longopts, int *longindex);
```

Здесь `longopts` - это массив структур, каждая из которых представляет длинную опцию. Каждая структура опции содержит следующие поля:

- `name`: имя длинной опции.
- `has_arg`: указывает, требует ли опция аргумент. Это может быть `no_argument` (опция не требует аргумента), `required_argument` (опция требует аргумента) или `optional_argument` (опция может иметь аргумент).
- `flag`: указатель на переменную, которая устанавливается, если опция обнаружена. Если этот параметр равен `NULL`, `getopt_long` возвращает значение, указанное в поле `val`.
- `val`: значение, которое `getopt_long` возвращает, или которое устанавливается в переменную, указанную в поле `flag`, если опция обнаружена.

Поле `longindex` является необязательным и, если оно не равно `NULL`, `getopt_long` устанавливает в него индекс текущей обнаруженной длинной опции.

Вот пример использования `getopt_long`:

```c
#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int opt;
    struct option longopts[] = {
        {"add", required_argument, 0, 'a'},
        {"subtract", required_argument, 0, 's'},
        {"multiply", no_argument, 0, 'm'},
        {0, 0, 0, 0}
    };

    while((opt = getopt_long(argc, argv, "a:s:m", longopts, NULL)) != -1) {
        switch (opt) {
            case 'a':
                printf("add with value %s\n", optarg);
                break;
            case 's':
                printf("subtract with value %s\n", optarg);
                break;
            case 'm':
                printf("multiply with no value\n");
                break;
           

            case '?':
                printf("unknown option\n");
                break;
        }
    }
    return 0;
}
```

В этом примере программа принимает длинные опции `--add`, `--subtract` и `--multiply`. Опции `--add` и `--subtract` требуют аргумента, а `--multiply` - нет. Эти длинные опции также имеют короткие эквиваленты `-a`, `-s` и `-m` соответственно. Если вы запустите эту программу с аргументами `--add 1 --subtract 2 --multiply`, она распечатает:

```
add with value 1
subtract with value 2
multiply with no value
```

Также можно использовать короткие опции, например `-a 1 -s 2 -m`.

Таким образом, основное отличие `getopt` от `getopt_long` заключается в поддержке последним длинных опций.