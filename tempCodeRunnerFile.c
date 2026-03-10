#include <stdio.h>

int main() {
    int i, j, sum = 0;
    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            if (i == j)
                continue;
            if ((i + j) % 2 == 0)
                sum += i * j;
            else if ((i + j) > 5)
                break;
            else
                sum -= i + j;
        }
        sum += i;
    }
    printf(" Sum = %d\n", sum);
    return 0;
}