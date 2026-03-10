do {
    // 1. แสดง Main Menu
    display_main_menu();

    // 2. รับตัวเลือกจากผู้ใช้
    printf("Select Menu : ");
    if (scanf("%d", &choice) != 1) {
        // การจัดการข้อผิดพลาดในการป้อนข้อมูลที่ไม่ใช่ตัวเลข
        printf("Invalid input. Please enter a number (1-4).\n");
        // ล้างบัฟเฟอร์อินพุตเพื่อป้องกันลูปไม่สิ้นสุด
        while (getchar() != '\n'); 
        choice = 0; // ตั้งค่าตัวเลือกที่ไม่ถูกต้อง
        continue;
    }

    // 3. ตรวจสอบตัวเลือกและดำเนินการ
    switch (choice) {
        case 1:
        case 2:
        case 3:
            // แสดง Sub Menu
            display_sub_menu(choice);
            break;
        case 4:
            // ออกจากโปรแกรม
            printf("+++++++++++++++++++++++++++++++++++++++\n");
            printf(" Thank you\n");
            printf("+++++++++++++++++++++++++++++++++++++++\n");
            break;
        default:
            // ตัวเลือกนอกเหนือจาก 1-4
            printf("Invalid selection. Please choose 1, 2, 3, or 4.\n");
            break;
    }
    
    // เพิ่มบรรทัดว่างเพื่อแยกเมนูในแต่ละรอบ
    if (choice != 4) {
        printf("\n"); 
    }

} while (choice != 4); // ทำซ้ำจนกว่าผู้ใช้จะเลือก '4'

return 0;