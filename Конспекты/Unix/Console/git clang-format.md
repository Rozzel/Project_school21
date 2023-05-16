```
usage: git clang-format [OPTIONS] [<commit>] [<commit>|--staged] [--] [<file>...]
```

If zero or one commits are given, run clang-format on all lines that differ
between the working directory and `<commit>`, which defaults to HEAD.  Changes are
only applied to the working directory, or in the stage/index.

Examples:
  To format staged changes, i.e everything that's been `git add`ed:
    git clang-format

  To also format everything touched in the most recent commit:
    git clang-format HEAD~1

  If you're on a branch off main, to format everything touched on your branch:
    git clang-format main

If two commits are given (requires --diff), run clang-format on all lines in the
second `<commit>` that differ from the first `<commit>`.

The following git-config settings set the default of the corresponding option:
`  clangFormat.binary
  clangFormat.commit
  clangFormat.extensions
  clangFormat.style`

positional arguments:
```sh
  <commit>              revision from which to compute the diff
  <file>...             if specified, only consider differences in these files
```

optional arguments:
```sh
  -h, --help            show this help message and exit
  --binary BINARY       path to clang-format
  --commit COMMIT       default commit to use if none is specified
  --diff                print a diff instead of applying the changes
  --diffstat            print a diffstat instead of applying the changes
  --extensions EXTENSIONS
                        comma-separated list of file extensions to format, excluding the period and case-insensitive
  -f, --force           allow changes to unstaged files
  -p, --patch           select hunks interactively
  -q, --quiet           print less information
  --staged, --cached    format lines in the stage instead of the working dir
  --style STYLE         passed to clang-format
  -v, --verbose         print extra information
```