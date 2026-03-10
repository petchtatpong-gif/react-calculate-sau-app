#include <stdio.h>

int main() {
    int i, j;
    int rows = 5;

    // ส่วนบนของ Diamond
    for (i = 1; i <= rows; i++) {
        // พิมพ์ตัวเลขจาก 1 ถึง i
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // พิมพ์ตัวเลขจาก i-1 ลงมาถึง 1
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // ส่วนล่างของ Diamond
    for (i = rows - 1; i >= 1; i--) {
        // พิมพ์ตัวเลขจาก 1 ถึง i
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // พิมพ์ตัวเลขจาก i-1 ลงมาถึง 1
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}

