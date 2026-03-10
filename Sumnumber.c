#include <stdio.h>

int main() {
    int n, i;
    int sum_odd = 0, sum_even = 0;

    printf("------------------------------------------------\n");
    printf("                  Sum Number\n");
    printf("------------------------------------------------\n");
    printf("Enter number : ");
    scanf("%d", &n);
    printf("------------------------------------------------\n");

    // Sum of odd numbers
    printf("Sum of odd number ");
    int first = 1;
    for (i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            sum_odd += i;
            if (!first) printf(" + ");
            printf("%d", i);
            first = 0;
        }
    }
    printf(" is %d\n", sum_odd);

    // Sum of even numbers
    printf("Sum of even number ");
    first = 1;
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum_even += i;
            if (!first) printf(" + ");
            printf("%d", i);
            first = 0;
        }
    }
    printf(" is %d\n", sum_even);
    printf("------------------------------------------------\n");

    return 0;
}