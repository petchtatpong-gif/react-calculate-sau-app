#include <stdio.h>
#include <string.h>

int main() {
    char borrower_name[100];    // ตัวแปรเก็บชื่อผู้กู้
    float loan_amount;          // ตัวแปรเก็บจำนวนเงินกู้
    float interest_rate;        // ตัวแปรเก็บอัตราดอกเบี้ย
    float interest;             // ตัวแปรเก็บจำนวนดอกเบี้ย
    
    // แสดงหัวข้อโปรแกรม
    printf("------------------------------------------------\n");
    printf("           Calculate Loan Interest\n");
    printf("------------------------------------------------\n");
    
    // รับชื่อผู้กู้
    printf("Enter name : ");
    fgets(borrower_name, sizeof(borrower_name), stdin);
    // ลบ newline character ที่เกิดจาก Enter
    borrower_name[strcspn(borrower_name, "\n")] = '\0';
    
    // รับจำนวนเงินกู้
    printf("Enter money : ");
    scanf("%f", &loan_amount);
    
    // คำนวณดอกเบี้ยตามเงื่อนไข
    if (loan_amount >= 1000) {
        interest_rate = 2.5;    // ดอกเบี้ย 2.5% สำหรับเงินกู้ 1000 บาทขึ้นไป
    } else {
        interest_rate = 5.5;    // ดอกเบี้ย 5.5% สำหรับเงินกู้ต่ำกว่า 1000 บาท
    }
    
    // คำนวณจำนวนดอกเบี้ย
    interest = (loan_amount * interest_rate) / 100;
    
    // แสดงผลลัพธ์
    printf("------------------------------------------------\n");
    printf("Borrower: %s\n", borrower_name);
    printf("Loan amount: %.2f baht\n", loan_amount);
    printf("Interest rate: %.1f%%\n", interest_rate);
    printf("Loan interest is : %.2f baht\n", interest);
    printf("------------------------------------------------\n");
    
    return 0;
}

// gcc loan_interest.c -o loan_interest.exe
cd "c:\Users\Victus\OneDrive\code"