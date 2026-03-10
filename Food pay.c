#include <stdio.h>

// ฟังก์ชันหลักของโปรแกรม
int main() {
    int member_type;
    float food_price;
    float discount_rate = 0.0;
    float final_price = 0.0;

    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("              Food Pay\n");
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("Member type\n");
    printf("1 = Silver\n");
    printf("2 = Gold\n");
    printf("3 = Platinum\n");
    printf("4 = No Member\n");
    printf("+++++++++++++++++++++++++++++++++++++++\n");

    // 1. รับข้อมูลประเภทสมาชิก
    printf("Select member type: ");
    if (scanf("%d", &member_type) != 1) {
        printf("Error: Invalid input for member type.\n");
        return 1;
    }

    // 2. รับข้อมูลราคาอาหาร
    printf("Enter food price : ");
    if (scanf("%f", &food_price) != 1 || food_price < 0) {
        printf("Error: Invalid input for food price.\n");
        return 1;
    }

    // 3. ตรวจสอบเงื่อนไขส่วนลดตามประเภทสมาชิก (Switch-Case)
    switch (member_type) {
        case 1: // Silver
            if (food_price >= 5000.0) {
                discount_rate = 0.05; // ลด 5%
            } else {
                discount_rate = 0.02; // ลด 2%
            }
            break;
        case 2: // Gold
            if (food_price >= 5000.0) {
                discount_rate = 0.10; // ลด 10%
            } else {
                discount_rate = 0.05; // ลด 5%
            }
            break;
        case 3: // Platinum
            if (food_price >= 5000.0) {
                discount_rate = 0.15; // ลด 15%
            } else {
                discount_rate = 0.10; // ลด 10%
            }
            break;
        case 4: // No Member
            discount_rate = 0.0; // ไม่มีส่วนลด
            break;
        default:
            printf("\nInvalid member type selected. No discount applied.\n");
            discount_rate = 0.0;
            break;
    }

    // 4. คำนวณราคาสุทธิ
    final_price = food_price * (1.0 - discount_rate);
    
    // 5. แสดงผลลัพธ์
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("Discount Rate: %.0f%%\n", discount_rate * 100);
    printf("Food price after discount is : %.2f\n", final_price);
    printf("+++++++++++++++++++++++++++++++++++++++\n");

    return 0;
}