---
tag:
- C
---
``` c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int b,c;
    float a;
    b=5;
    c=0;
    if(c!=0) {
	    a=(float)b/c;
	    printf("a = %f\n\n",a);
     }
    else printf("error\n\n")
    system("PAUSE");   
return 0;
}

```


Операторы
---
`if` 
`else`

``` C
    if{

     } else {

          }
```


``` C
#include <stdio.h>
#include <stdlib.h>

int main() {
	float  a,b,c,d;
	printf("\na?: "); scanf("%f",&a);
	printf("b?: "); scanf("%f",&b);
	if(a>=b) {
		c=a-b;
		d=a/b;
		printf("\n\t%.0f>%.0f na %.0f",a,b,c);
		printf("\n\t%.0f>%.0f v %.2f\n\n",a,b,d);
     } else {
	     printf("\n\n\ta<b\n\n");
	     c=b-a;
	     d=b/a;
	     printf("\n\t%.0f>%.0f na %.0f",b,a,c);
	     printf("\n\t%.0f>%.0f v %.2f\n\n",b,a,d);
     }
return 0;
}
```


Размещать так условия, чтобы проверок было минимально


```C
if (x>0) printf (">");
else if (x<0) printf ("<");
else printf ("==");
```

if
else if
else if
else if
else
