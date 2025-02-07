#include <stdio.h>

int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    if(a >= -100000 && a <= 100000 && b >= -100000 && b<= 100000)    printf("a = %d\nb = %d", a, b);
    return 0;
}