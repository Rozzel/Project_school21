---
tag:
- Git
- Git/Консоль
---
```shell
git config --global credential.helper wincred
```

## Caching your GitHub password in Git

- [MAC](https://help.github.com/articles/caching-your-github-password-in-git/#platform-mac)
- [WINDOWS](https://help.github.com/articles/caching-your-github-password-in-git/#platform-windows)
- [LINUX](https://help.github.com/articles/caching-your-github-password-in-git/#platform-linux)
- [ALL](https://help.github.com/articles/caching-your-github-password-in-git/#platform-all)

If you're [cloning GitHub repositories using HTTPS](https://help.github.com/articles/which-remote-url-should-i-use), you can use a credential helper to tell Git to remember your GitHub username and password every time it talks to GitHub.

If you clone GitHub repositories using SSH, then you authenticate using SSH keys instead of a username and password. For help setting up an SSH connection, see [Generating an SSH Key](https://help.github.com/articles/generating-an-ssh-key).

Tip: You need Git 1.7.10 or newer to use the credential helper.

You can also install a native Git shell, such as [Git for Windows](https://git-for-windows.github.io/). With Git for Windows, running the following in the command line will store your credentials:

```shell
git config --global credential.helper wincred
```


[help.github.com](https://help.github.com/articles/caching-your-github-password-in-git/)
