#include<stdio.h>

int main() {
    int mainMenu = 1, subMenu = 2;
    if (mainMenu == 1) {
        if (subMenu == 1) {
            printf("You chose File -> New\n");
        } else if (subMenu == 2) {
            printf("You chose File -> Open\n");
        } else {
            printf("Invalid submenu in File\n");
        }
    } else if (mainMenu == 2) {
        if (subMenu == 1) {
            printf("You chose Edit -> Copy\n");
        } else if (subMenu == 2) {
            printf("You chose Edit -> Paste\n");
        } else {
            printf("Invalid subMenu in Edit\n");
        }
    } else {
        printf("Invalid main menu\n");
    }
    return 0;
}