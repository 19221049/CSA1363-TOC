#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

bool is_valid(char str[], int index, char target) {
    return str[index] == target;
}

bool match_S(char str[], int index, int length);
bool match_A(char str[], int index, int length);

bool match_S(char str[], int index, int length) {
    if (index >= length) {
        return false; 
    }

    if (is_valid(str, index, '0')) {
        if (index + 2 < length && is_valid(str, index + 2, '1')) {
            return match_A(str, index + 1, length - 2); 
        } else {
            return false;
        }
    } else {
        return match_A(str, index, length); 
    }
}

bool match_A(char str[], int index, int length) {
    if (index >= length) {
        return true;
    }

    if (is_valid(str, index, '1')) {
        return match_A(str, index + 1, length); 
    } else {
        return false; 
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

