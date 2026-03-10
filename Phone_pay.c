#include <stdio.h>
#include <string.h>

// ฟังก์ชันหลักของโปรแกรม
int main() {
    // ตัวแปรสำหรับรับข้อมูลและคำนวณ
    char name[100];
    char phone_number[15];
    int minutes;
    float total_pay = 0.0;

    // ส่วนหัวของโปรแกรม
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("      Calculate Pay Use Phone\n");
    printf("+++++++++++++++++++++++++++++++++++++++\n");

    // 1. รับข้อมูลจากผู้ใช้
    printf("Enter name : ");
    // ใช้ fgets เพื่อรับชื่อที่มีช่องว่างได้
    fgets(name, 100, stdin);
    // ลบอักขระขึ้นบรรทัดใหม่ (\n) ที่ fgets อาจเพิ่มเข้ามา
    name[strcspn(name, "\n")] = 0; 
    
    printf("Enter phone number : ");
    scanf("%s", phone_number);

    printf("Enter minute for use phone : ");
    scanf("%d", &minutes);

    // 2. ตรวจสอบเงื่อนไขและคำนวณค่าโทรศัพท์
    // กฎการคิดค่าโทรศัพท์:
    // นาทีที่ 1 - 15  : 5 บาท/นาที
    // นาทีที่ 16 - 30 : 3 บาท/นาที
    // นาทีที่ 31 เป็นต้นไป : 1.50 บาท/นาที

    if (minutes <= 0) {
        // กรณีที่ไม่ใช้โทรศัพท์เลย
        total_pay = 0.0;
    } 
    else if (minutes <= 15) {
        // กรณีใช้ 1 ถึง 15 นาที
        total_pay = minutes * 5.0;
    } 
    else if (minutes <= 30) {
        // กรณีใช้ 16 ถึง 30 นาที
        // ค่าคงที่สำหรับ 15 นาทีแรก (15 * 5 = 75 บาท)
        float pay_phase1 = 15 * 5.0; 
        // นาทีที่เกิน 15
        int remaining_minutes = minutes - 15; 
        
        total_pay = pay_phase1 + (remaining_minutes * 3.0);
    } 
    else {
        // กรณีใช้ตั้งแต่ 31 นาทีขึ้นไป
        // ค่าคงที่สำหรับ 15 นาทีแรก (15 * 5 = 75 บาท)
        float pay_phase1 = 15 * 5.0; 
        // ค่าคงที่สำหรับ 15 นาทีถัดมา (15 * 3 = 45 บาท)
        float pay_phase2 = 15 * 3.0; 
        // นาทีที่เกิน 30
        int remaining_minutes = minutes - 30; 
        
        total_pay = pay_phase1 + pay_phase2 + (remaining_minutes * 1.50);
    }

    // 3. แสดงผลลัพธ์
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("User Name: %s\n", name);
    printf("Phone Number: %s\n", phone_number);
    printf("Total Minute: %d\n", minutes);
    printf("Pay for use phone is : %.2f Baht\n", total_pay);
    printf("+++++++++++++++++++++++++++++++++++++++\n");

    return 0;
}