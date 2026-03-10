#include <stdio.h>

int main() {
    int i, j;
    int rows = 6;

    for (i = 0; i < rows; i++) {
        // พิมพ์ตัวอักษรจาก A ถึง A+i
        for (j = 0; j <= i; j++) {
            printf("%c ", 'A' + j);
        }

        // พิมพ์ตัวอักษรจาก A+i-1 ลงมาถึง A
        for (j = i - 1; j >= 0; j--) {
            printf("%c ", 'A' + j);
        }

        printf("\n");
    }

    return 0;
}