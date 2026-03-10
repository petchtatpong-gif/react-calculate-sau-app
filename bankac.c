#include <stdio.h>

int main() {
    // Initial balance
    float balance = 10000.0;
    int choice;
    float amount;

    printf("==================================================\n");
    printf("       ยินดีต้อนรับสู่ธนาคารจำลอง\n");
    printf("==================================================\n");

    while(1) {
        // Show menu
        printf("\n==================================================\n");
        printf("                  เมนูธนาคาร\n");
        printf("==================================================\n");
        printf("1. ฝากเงิน\n");
        printf("2. ถอนเงิน\n");
        printf("3. เช็คยอดเงิน\n");
        printf("4. ออกจากโปรแกรม\n");
        printf("==================================================\n");
        printf("กรุณาเลือกเมนู (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Deposit
                printf("\n--- ฝากเงิน ---\n");
                printf("กรุณาใส่จำนวนเงินที่ต้องการฝาก: ");
                scanf("%f", &amount);

                if(amount > 0) {
                    balance += amount;
                    printf("✓ ฝากเงินสำเร็จ %.2f บาท\n", amount);
                    printf("ยอดเงินคงเหลือ: %.2f บาท\n", balance);
                } else {
                    printf("✗ ข้อผิดพลาด: จำนวนเงินต้องมากกว่า 0\n");
                }
                break;

            case 2:
                // Withdraw
                printf("\n--- ถอนเงิน ---\n");
                printf("กรุณาใส่จำนวนเงินที่ต้องการถอน: ");
                scanf("%f", &amount);

                if(amount <= 0) {
                    printf("✗ ข้อผิดพลาด: จำนวนเงินต้องมากกว่า 0\n");
                } else if(amount > balance) {
                    printf("✗ ข้อผิดพลาด: ยอดเงินไม่เพียงพอ\n");
                    printf("ยอดเงินคงเหลือของคุณ: %.2f บาท\n", balance);
                } else {
                    balance -= amount;
                    printf("✓ ถอนเงินสำเร็จ %.2f บาท\n", amount);
                    printf("ยอดเงินคงเหลือ: %.2f บาท\n", balance);
                }
                break;

            case 3:
                // Check balance
                printf("\n--- เช็คยอดเงิน ---\n");
                printf("ยอดเงินคงเหลือในบัญชี: %.2f บาท\n", balance);
                break;

            case 4:
                // Exit
                printf("\n==================================================\n");
                printf("       ขอบคุณที่ใช้บริการธนาคารจำลอง\n");
                printf("       ยอดเงินสุดท้าย: %.2f บาท\n", balance);
                printf("==================================================\n");
                return 0;

            default:
                printf("\n✗ ข้อผิดพลาด: กรุณาเลือกเมนู 1-4 เท่านั้น\n");
                break;
        }
    }

    return 0;
}