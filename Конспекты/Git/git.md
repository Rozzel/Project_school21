https://git-scm.com/book/ru/v2

git status
--

git checkout -b develop
--
Создание новой ветки developt


Памятка git:

git clone — В начале работы.
git commit — Когда добавил изменения. Не забыть добавить понятное название коммита.
git push origin — Чтобы сохранить изменения на удаленном сервере.
git status — Текущее состояние репозитория.
Не пушить в репозиторий объектные и исполняемые файлы! Никогда!
Всегда работать в ветках. Для работы использовать ветку develop.

git commit -m

git branch -a
Показывает как локальные, так и удаленные ветки



```sh
git clone http://whatever.git -b branch-name
```
Этот вариант склонирует ПОЛНОСТЬЮ весь репозиторий и просто переключится на ветку branch-name

```sh
git clone --branch=branch-name http://whatever.git
```
Иногда нужно склонировать ТОЛЬКО конкретную ветку, тогда