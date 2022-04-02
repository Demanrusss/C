#include <stdio.h>

union integer {
    char c;
    short s;
    int i;
    long l;
};

int main() {

    union integer value;

    scanf("%c", &value.c);
    scanf("%hd", &value.s);
    scanf("%d", &value.i);
    scanf("%ld", &value.l);

    printf("%c\n", value.c);
    printf("%hd\n", value.s);
    printf("%d\n", value.i);
    printf("%ld\n", value.l);

return 0;
}
