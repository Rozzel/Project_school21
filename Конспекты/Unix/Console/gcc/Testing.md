Инструкция по запуску тестов
===

Cкрипт для быстрых команд
---

```sh
vim ~/.bashrc
echo alias start='sh ~/.start.sh' >> ~/.bashrc
```

```sh
source ~/.bashrc
```

`start`
```sh
alias start='sh ~/Documents/start/start.sh'
alias gcc -w='gcc -Wall -Werror -Wextra'
alias cf -n='clang-format -n'
alias cf -i='clang-format -i'
alias leaks='leaks -atExit -- ./a.out'
alias cppcheck='cppcheck --enable=all --suppress=missingIncludeSystem'
alias o='./a.out'

```

`start.sh`
```sh
#/bin/bash

clear
echo "ˁ˚ᴥ˚ˀ Loading... ████████████] 99%" $1
clang-format -n $1
clang-format -i $1
cppcheck --enable=all --suppress=missingIncludeSystem $1
gcc -Wall -Werror -Wextra $1
leaks -atExit -- ./a.out

```

Стилевые тесты
---
`.clang-format`

```txt
---
BasedOnStyle: Google
IndentWidth: 4
ColumnLimit: 110

```

`sh start.sh file.c`
Показать ошибки разметки кода
`clang-format -n`
Поправить по гайду
`clang-format -i` 

`clang-format -n *.c`
Найти ошибки в разметки

Чтобы проверить, насколько красота вашего кода соответствует стандартам, вы можете протестировать ваш код с помощью утилиты _clang-format_. В папке
`materials/linters` лежит файл `.clang-format`, который содержит необходимые настройки для стилевого теста. Данный конфигурационный файл распространяет свое действие на все файлы, которые лежат с ним в директории или в директориях ниже. Поэтому, чтобы данные настройки применились к вашим файлам с исходным кодом, скопируйте `.clang-format` в папку src.
Чтобы запустить проверку на стиль, выполните следующую команду:
```sh
clang-format -n src/sourcefile_name.c
```
Чтобы скачать clang-format, введите в терминал одну из следующих команд:
```sh
brew install clang-format
```
или, если у вас есть root-права (для Ubuntu / Linux Mint / Debian) 
```sh
sudo apt install clang-format
```
Статический анализ кода
---

Иногда (или не совсем иногда) встречается такое, что 
корректно компилирующаяся C-программа работает совершенно неправильно или завершается
с ошибкой попытки доступа не к своей области памяти. Чтобы предотвратить подобные
ошибки на этапе написания программы, используют специальные утилиты, которые анализируют
ваш исходный код на предмет потенциальных ошибок. Наша система автотестов использует
для этого `cppcheck`. Чтобы установить эту утилиту, введите в терминал одну из следующих команд:
```sh
brew install cppcheck
```
или, если у вас есть root-права (для Ubuntu / Linux Mint / Debian)
```sh
sudo apt install cppcheck
``` 

Установив cppcheck, вы можете протестировать ваш исходный код:
```sh
cppcheck --enable=all --suppress=missingIncludeSystem src/soursefile_name.c
```
Также можно проверить сразу все файлы с исходным кодом в директории:
```sh
cppcheck --enable=all --suppress=missingIncludeSystem src/`
```

Тест на корректную работу с памятью
---
При написании C-программ очень важно следить за утечками памяти. Для этого в Unix-подобных операционных системах довольно часто используют утилиту valgrind. Однако, на OS X имеются проблемы с поддержкой valgrind, поэтому вместо нее можно использовать утилиту leaks. Вдаваться в механизм работы этих утилит мы сейчас не будем - если интересно, можете почитать в гугле.
Чтобы запустить ваш исполняемый файл с помощью этой утилиты, наберите в терминале: 
```sh
leaks -atExit -- ./main.out | grep LEAK:
```
Обратите внимание на команду `| grep LEAK:`. Мы используем ее для короткого вывода, чтобы видеть только линии с утечками, если они есть. Если вы хотите увидеть весь вывод, просто удалите эту команду.
При запуске исполняемого файла с помощью `leaks` может появиться сообщение об ошибке:

> ```sh
> dyld: could not load inserted library ‘/usr/local/lib/libLeaksAtExit.dylib’ because image not found
> ```

Ошибка возникает из-за того, что leaks не может найти библиотеку `libLeaksAtExit.dylib`. 
В этом случае вам необходимо ввести следующие команды:
```sh
cd /usr/local/lib  
sudo ln -s /Applications/Xcode.app/Contents/Developer/usr/lib/libLeaksAtExit.dylib
```
*Дополнительно*
Используйте флаг `-exclude` утилиты `leaks` для того, чтобы отфильтровать утечки в функциях, где известно об утечках памяти. Этот флаг позволяет уменьшить количество посторонней информации, сообщаемой `leaks`.
