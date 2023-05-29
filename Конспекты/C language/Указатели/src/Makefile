# Компилятор
CC=gcc

# Флаги компиляции
CFLAGS=-Wall -Wextra -Werror -std=c11 -O2

# Список исходных файлов
SRCS=$(wildcard *.c)

# Список объектных файлов
OBJS=$(SRCS:.c=.o)

# Список исполняемых файлов
TARGETS=$(SRCS:.c=)

# Процесс компиляции и линковки
all: $(TARGETS)

# Шаблонная цель
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Шаблонная цель для исполняемых файлов
%: %.o
	$(CC) $< -o $@

# cppcheck цель
cppcheck: $(SRCS)
	cppcheck --enable=all --suppress=missingIncludeSystem $^

# clang-format проверка
cformat-n: $(SRCS)
	clang-format -n $^

# clang-format применение
cformat-i: $(SRCS)
	clang-format -i $^

# Цель для очистки терминала
clear:
	clear

# Цель для запуска
run: $(TARGETS)
	@for TARGET in $(TARGETS); do \
		echo "Running $$TARGET"; \
		./$$TARGET; \
	done

# Цель для проверки утечек памяти
leaks: $(TARGETS)
	leaks -atExit -- ./$^

# Цель для начала работы
start: clear cppcheck cformat-n cformat-i

# Цель для очистки
clean:
	rm -f $(OBJS) $(TARGETS)
