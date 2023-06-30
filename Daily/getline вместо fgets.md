Ваш текущий код использует `fgets()` для чтения строк из файла. Чтобы изменить это на использование `getline()`, вы можете внести следующие изменения в функцию `process_file()`:

```c
void process_file(int i, char *filename, char *argv[], struct options flag,
                  char *pattern, int file_indexes[], int count_of_files) {
  FILE *file = fopen(filename, "r");
  char last_symbol = '\0';
  int count_of_string = 0, count_of_match_string = 0;
  // Убираем char string[MAX_STRING_LENGHT];
  
  char *string = NULL; // Добавляем эту строку
  size_t len = 0; // И эту

  if (file == NULL && flag.s == 0) {
    fprintf(stderr, "grep: %s: No such file or directory\n", filename);
  } else if (file != NULL) {
    ssize_t read;
    // Меняем условие while и используем getline вместо fgets
    while ((read = getline(&string, &len, file)) != -1) {
      count_of_string++;
      regmatch_t pmatch[1024];
      int status = process_regex(flag, string, pattern, pmatch);
      if (status == 0 && flag.v == 0) {
        count_of_match_string++;
        print(argv, flag, file_indexes, count_of_files, string, &last_symbol, i,
              count_of_string, pmatch, pattern);
      } else if (status == REG_NOMATCH && flag.v == 1) {
        count_of_match_string++;
        print(argv, flag, file_indexes, count_of_files, string, &last_symbol, i,
              count_of_string, pmatch, pattern);
      }
    }
    free(string); // Не забываем освободить память после использования строки

    if (flag.c == 1 && flag.l == 1 && count_of_match_string > 0)
      count_of_match_string = 1;
    if (flag.c == 1) {
      if (count_of_files > 1 && flag.h == 0) printf("%s:", filename);
      printf("%d\n", count_of_match_string);
    }
    if (flag.l == 1 && count_of_match_string > 0) {
      printf("%s\n", filename);
    }
    fclose(file);
  }
}
```

Обратите внимание, что `getline()` считывает включая символ новой строки (`\n`), поэтому этот символ теперь будет присутствовать в каждой строке, прочитанной из файла.