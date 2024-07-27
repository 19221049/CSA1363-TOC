#include <stdio.h>

#define MAX_STATE 3

int main() {
    int current_state = 0;  

    char input_string[100];
    printf("Enter a string: ");
    scanf("%s", input_string);

    int i;
    for (i = 0; input_string[i] != '\0'; i++) {
        char symbol = input_string[i];

        if (current_state == 0) {
            if (symbol == '0') {
                current_state = 1;
            } else {
                printf("String rejected: Not starting with '0'\n");
                return 1;
            }
        } else if (current_state == 1) {
            if (symbol != '0' && symbol != '1') {
                printf("String rejected: Invalid symbol\n");
                return 1;
            } else if (symbol == '1') {
                current_state = 2;  
            }
        } else if (current_state == 2) {
            if (symbol != '1') {
                printf("String rejected: Not ending with '1'\n");
                return 1;
            }
        } else {
            printf("String rejected: Unexpected state\n");
            return 1;
        }
    }

    if (current_state == 2) {
        printf("String accepted!\n");
    } else {
        printf("String rejected: Invalid transition or not ending with '1'\n");
    }

    return 0;
}

