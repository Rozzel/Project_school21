Termux uses utility
```
termux-setup-storage
```
to configure access to the shared storage and setup these symlinks for quick access to various kinds of storages

Simple backup with auto compression:

```sh
termux-backup /sdcard/backup.tar.xz
```

Restoring backup is also simple:

```sh
termux-restore /sdcard/backup.tar.xz
```