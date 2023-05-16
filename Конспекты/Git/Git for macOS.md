---
tag:
- Git
- Git/macOS
- macOS/Homebrew
---
[Homebrew](https://brew.sh/index_ru)

Install [homebrew](https://brew.sh/) if you don't already have it, then:  
`$ brew install git`

```shell
cd /opt/homebrew/bin/
PATH=$PATH:/opt/homebrew/bin
cd
touch .zshrc
echo export PATH=$PATH:/opt/homebrew/bin >> .zshrc
```

Запустите команды в этом порядке в терминале, вы будете редактировать путь и создавать отсутствующий файл `.zshrc`, экспортируя путь в этот новый файл.

Теперь вы должны иметь возможность использовать:
```shell
brew doctor
```

---

1. Набрать в терминале  
```shell
open ~/.bash_profile  
```
  
2. В открывшемся окне добавить строку  
```shell
export PATH="/usr/local/bin:${PATH}"  
```
Сохранить и закрыть  
  
3. Набрать в терминале  
source ~/.bash_profile1. Набрать в терминале  
open ~/.bash_profile  
  
2. В открывшемся окне добавить строку  
```shell
export PATH="/usr/local/bin:${PATH}"  
```
Сохранить и закрыть  
  
3. Набрать в терминале  
```shell
source ~/.bash_profile
```
