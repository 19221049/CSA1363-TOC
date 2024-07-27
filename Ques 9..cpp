#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

bool is_valid(char c) {
    return c == 'b' || c == 'a' || (c >= 'c' && c <= 'z');
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    int state = 0; 
    bool accepted = false;
    int i; 

    for (i = 0; str[i] != '\0'; i++) {
        switch (state) {
            case 0:
                if (str[i] == 'b') {
                    state = 1; 
                } else {
                    state = 0; 
                }
                break;
            case 1:
                if (str[i] == 'a') {
                    state = 2; 
                } else {
                    state = 1; 
                }
                break;
            case 2:
                accepted = true; 
                state = 2; 
                break;
            default:
                break;
        }
    }

    if (accepted && state == 2) { // Must end in state 2 after 'a'
        printf("String is accepted by the NFA.\n");
    } else {
        printf("String is not accepted by the NFA.\n");
    }

    return 0;
}

