#include<stdio.h>

#include<stdio.h>

int main() {
    int x, z;
    x = 20 * 6 % 20;
    z = x % 6 * x;
    switch (z) {
        case 0: printf("aa\n"); break;
        case 1: printf("bb\n"); break;
        case 2: printf("cc\n"); break;
        case 3: printf("dd\n"); break;
        default:
            printf("ee\n");
            printf("ff\n");
            printf("Value of z is %d\n", z);
            break;
    }
    return 0;
}