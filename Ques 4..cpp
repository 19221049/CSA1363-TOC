#include <stdio.h>
#include <stdbool.h>
#define MAX_LENGTH 100

bool is_valid(char str[], int index, char target) {
    return str[index] == target;
}

bool match_S(char str[], int index, int length) {
    if (index >= length) {
        return true; 
    }

    char first_char = str[index];
    if (first_char == '0') {
        if (index + 2 < length && is_valid(str, index + 1, 'S') && is_valid(str, index + 2, '0')) {
            return match_S(str, index + 3, length); 
        } else {
            return false; 
        }
    } else if (first_char == '1') {
        if (index + 2 < length && is_valid(str, index + 1, 'S') && is_valid(str, index + 2, '1')) {
            return match_S(str, index + 3, length); 
        } else {
            return false; 
        }
    } else {
        return first_char == '0' || first_char == '1'; 
    }
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    if (match_S(str, 0, length)) {
        printf("String belongs to the language defined by the CFG.\n");
    } else {
        printf("String does not belong to the language defined by the CFG.\n");
    }

    return 0;
}

