#include <stdio.h>
#include <string.h>

int main() {
    char home_number[100];      // ตัวแปรเก็บบ้านเลขที่
    int electric_units;         // ตัวแปรเก็บจำนวนหน่วยไฟฟ้าที่ใช้
    float rate_per_unit;        // ตัวแปรเก็บอัตราค่าไฟฟ้าต่อหน่วย
    float electric_cost;        // ตัวแปรเก็บค่าไฟฟ้าที่คำนวณได้
    
    // แสดงหัวข้อโปรแกรม
    printf("------------------------------------------------\n");
    printf("            Calculate Pay Electric\n");
    printf("------------------------------------------------\n");
    
    // รับบ้านเลขที่
    printf("Enter home number : ");
    fgets(home_number, sizeof(home_number), stdin);
    // ลบ newline character
    home_number[strcspn(home_number, "\n")] = '\0';
    
    // รับจำนวนหน่วยไฟฟ้าที่ใช้
    printf("Enter unit of electric use : ");
    scanf("%d", &electric_units);
    
    // กำหนดอัตราค่าไฟฟ้าตามจำนวนหน่วยที่ใช้
    if (electric_units <= 20) {
        rate_per_unit = 5.00;       // ไม่เกิน 20 หน่วย = 5.00 บาท/หน่วย
    } else if (electric_units > 20 && electric_units < 50) {
        rate_per_unit = 4.50;       // 21-49 หน่วย = 4.50 บาท/หน่วย
    } else {
        rate_per_unit = 4.00;       // 50+ หน่วย = 4.00 บาท/หน่วย
    }
    
    // คำนวณค่าไฟฟ้าทั้งหมด
    electric_cost = electric_units * rate_per_unit;
    
    // แสดงผลลัพธ์
    printf("------------------------------------------------\n");
    printf("Home number: %s\n", home_number);
    printf("Electric units used: %d units\n", electric_units);
    printf("Rate per unit: %.2f baht\n", rate_per_unit);
    printf("Pay for electric use : %.2f baht\n", electric_cost);
    printf("------------------------------------------------\n");
    
    return 0;
}