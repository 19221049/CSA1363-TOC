#include <stdio.h>
#include <stdbool.h>

bool is_valid_char(char c) {
    return c == 'a' || c == 'b';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int state = 0; 
    int i; 

    for (i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (!is_valid_char(c)) {
            state = 3; 
            break;
        }

        switch (state) {
            case 0:
                if (c == 'a') {
                    state = 1; 
                } else {
                    state = 3; 
                }
                break;
            case 1:
                if (c == 'a') {
                    state = 1; 
                } else if (c == 'b') {
                    state = 2; 
                } else {
                    state = 3; 
                }
                break;
            case 2:
                if (c == 'b') {
                    state = 2; /
                } else {
                    state = 3;
                }
                break;
            case 3:
            
                break;
        }
    }

    if (state == 2) {
        printf("String is accepted by the DFA.\n");
    } else {
        printf("String is not accepted by the DFA.\n");
    }

    return 0;
}

