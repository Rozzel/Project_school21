---
tag:
- C
---
```C
for(i=0;i<10;i++)
```

`i=0` - счетчик
`i<10` - до чего считать
`i++` - увеличение счетчика аналог i=i+1 (на 2 операции меньше)
`++i` - инкремента - меняет приоритет исполнения

---

`a=a++-++a` - низкоуровневое программирование, чему равно и почему.

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    for(i=0;i<10;i++) printf("%d\n\n",i);
    system("PAUSE");
    return 0;
}

```

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    for(i=0;i<10;i++) printf("%d\n\n",i+1);
    system("PAUSE");
    return 0;
}
```

от 1 до 10

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    for(i=0;i<10;i++) printf("%d\n\n",i*10);
    system("PAUSE");
    return 0;
}
```

шаг 10 домножение счетчика

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    for(i=0;i<10;i++) printf("%d\n\n",i++);
    system("PAUSE");
    return 0;
}
```

Четные

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    for(i=0;i<10;i++) printf("%d\n\n",++i);
    system("PAUSE");
    return 0;
}
```

Не четные

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    for(i=0;;i++) printf("%d\n\n",i);
    system("PAUSE");
    return 0;
}
```

Увеличение до придела `int`

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    for( ; ; ) printf("%d\n\n",i);
    system("PAUSE");
    return 0;
}
```

Бесконечный цикл - используется в работе мышки

for (_1_;_2_;_3_) оператор;

1 - Операторы выполняющиеся до цикла
2 - Операторы задающее условие работы цикла
3 - Операторы выполняющиеся в конце каждого шага цикла


```C
printf("Start\n");
for (i=0;i<10;i++) printf ("%d\n",i);
```

Аналог while
`for (i=0;условие;i++) оператор;`

---

```C
#include <stdio.h>
#include <stdlib.h>

int main () {
	int i,s=0,n;
	printf("/nKOL? ");
	scanf("%d",&n);
	for(i=1;i<=n;i++) s=s+i;
	printf("%d\n",s);
	//system("PAUSE");
	return 0;
}
```
