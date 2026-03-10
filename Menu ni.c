#include <stdio.h>
#include <string.h>

// ฟังก์ชันหลักของโปรแกรม
int main() {
    // ตัวแปรสำหรับรับข้อมูลและคำนวณ
    char name[100];
    char phone_number[15];
    int num_people;
    float price_per_person = 0.0;
    float total_pay = 0.0;

    // ส่วนหัวของโปรแกรม
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("   Calculate Pay Package Tour\n");
    printf("+++++++++++++++++++++++++++++++++++++++\n");

    // 1. รับข้อมูลจากผู้ใช้
    printf("Enter name : ");
    // ใช้ fgets เพื่อรับชื่อที่มีช่องว่างได้
    fgets(name, 100, stdin);
    // ลบอักขระขึ้นบรรทัดใหม่ (\n) ที่ fgets อาจเพิ่มเข้ามา
    name[strcspn(name, "\n")] = 0; 
    
    printf("Enter phone number : ");
    scanf("%s", phone_number);

    printf("Enter number of group tour : ");
    scanf("%d", &num_people);

    // 2. ตรวจสอบเงื่อนไขและกำหนดราคาต่อคน (PricePerPerson)
    // หลักเกณฑ์:
    // 1 - 2 คน    : 300 บาท/คน
    // 3 - 5 คน    : 250 บาท/คน
    // 6 - 10 คน   : 210 บาท/คน
    // 11 คนขึ้นไป : 150 บาท/คน

    if (num_people >= 11) {
        price_per_person = 150.0;
    } else if (num_people >= 6) { 
        // 6 ถึง 10 คน
        price_per_person = 210.0;
    } else if (num_people >= 3) {
        // 3 ถึง 5 คน
        price_per_person = 250.0;
    } else if (num_people >= 1) {
        // 1 ถึง 2 คน
        price_per_person = 300.0;
    } else {
        // กรณีจำนวนคนเป็น 0 หรือติดลบ
        price_per_person = 0.0;
    }

    // 3. คำนวณค่าใช้จ่ายรวม
    total_pay = num_people * price_per_person;

    // 4. แสดงผลลัพธ์
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("Group Leader Name: %s\n", name);
    printf("Phone Number: %s\n", phone_number);
    printf("Number of People: %d\n", num_people);
    printf("Pay total for package tour is : %.2f Baht\n", total_pay);
    printf("+++++++++++++++++++++++++++++++++++++++\n");

    return 0;
}