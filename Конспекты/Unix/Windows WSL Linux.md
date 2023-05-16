

```PowerShell
wsl --install
```

 Примечание

Приведенная выше команда работает, только если WSL не установлена вообще. Если вы выполнили `wsl --install` и видите текст справки WSL, попробуйте выполнить `wsl --list --online`, чтобы просмотреть список доступных дистрибутивов. Затем выполните `wsl --install -d <DistroName>` для установки дистрибутива. Сведения об удалении WSL см. в разделе [Удаление устаревшей версии WSL](https://learn.microsoft.com/ru-ru/windows/wsl/troubleshooting#uninstall-legacy-version-of-wsl) или [Отмена регистрации или удаление дистрибутива Linux](https://learn.microsoft.com/ru-ru/windows/wsl/basic-commands#unregister-or-uninstall-a-linux-distribution).
