#include <stdio.h>
#include <string.h>

int main() {
    char renter_name[100];      // ตัวแปรเก็บชื่อผู้เช่าแท็กซี่
    char car_number[50];        // ตัวแปรเก็บหมายเลขทะเบียนรถ
    int rental_hours;           // ตัวแปรเก็บจำนวนชั่วโมงที่เช่า
    float rate_per_hour;        // ตัวแปรเก็บอัตราค่าเช่าต่อชั่วโมง
    float total_cost;           // ตัวแปรเก็บค่าเช่าทั้งหมด
    
    // แสดงหัวข้อโปรแกรม
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("         Calculate Pay Taxi Rental\n");
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    
    // รับชื่อผู้เช่าแท็กซี่
    printf("Enter name : ");
    fgets(renter_name, sizeof(renter_name), stdin);
    // ลบ newline character
    renter_name[strcspn(renter_name, "\n")] = '\0';
    
    // รับหมายเลขทะเบียนรถ
    printf("Enter car number : ");
    fgets(car_number, sizeof(car_number), stdin);
    // ลบ newline character
    car_number[strcspn(car_number, "\n")] = '\0';
    
    // รับจำนวนชั่วโมงที่เช่า
    printf("Enter hour for rent : ");
    scanf("%d", &rental_hours);
    
    // กำหนดอัตราค่าเช่าตามช่วงเวลา
    if (rental_hours <= 5) {
        rate_per_hour = 100.00;     // 1-5 ชั่วโมง = 100 บาท/ชั่วโมง
    } else if (rental_hours >= 6 && rental_hours <= 10) {
        rate_per_hour = 90.50;      // 6-10 ชั่วโมง = 90.50 บาท/ชั่วโมง
    } else if (rental_hours >= 11 && rental_hours <= 15) {
        rate_per_hour = 80.00;      // 11-15 ชั่วโมง = 80 บาท/ชั่วโมง
    } else {
        rate_per_hour = 70.50;      // 16+ ชั่วโมง = 70.50 บาท/ชั่วโมง
    }
    
    // คำนวณค่าเช่าทั้งหมด
    total_cost = rental_hours * rate_per_hour;
    
    // แสดงผลลัพธ์
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("Renter name: %s\n", renter_name);
    printf("Car number: %s\n", car_number);
    printf("Rental hours: %d hours\n", rental_hours);
    printf("Rate per hour: %.2f baht\n", rate_per_hour);
    printf("Pay for rent is : %.2f baht\n", total_cost);
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    
    return 0;
}