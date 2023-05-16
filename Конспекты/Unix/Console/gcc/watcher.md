# Установка watchexec

Чтобы легко установить инструмент watchexec, вставьте следующую ссылку в терминал или интерпретатор командной строки и нажмите Enter.

## Linux и macOS

```sh
curl -sS https://webi.sh/watchexec | zsh

source ~/.config/envman/PATH.env

watchexec --help

```

```sh
watchexec -e c 'clang-format -i ./**/*.c'

```