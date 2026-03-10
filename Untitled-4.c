#include<stdio.h>

int main() {
    int mainMenu = 1, subMenu = 2;
    switch(mainMenu) {
        case 1:
            printf("Main Menu : File\n");
            switch(subMenu) {
                case 1: printf("Sub Menu : New\n"); break;
                case 2: printf("Sub Menu : Open\n"); break;
                default: printf("Sub Menu : Invalid\n"); break;
            }
            break;
        case 2:
            printf("Main Menu : Edit\n");
            switch(subMenu) {
                case 1: printf("Sub Menu : Copy\n"); break;
                case 2: printf("Sub Menu : Paste\n"); break;
                default: printf("Invalid Sub Menu\n"); break;
            }
            break;
        default:
            printf("Invalid Main Menu\n");
            break;
    }
    return 0;
}
