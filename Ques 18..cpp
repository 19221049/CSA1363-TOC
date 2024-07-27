#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 5

bool is_valid_char(char c) {
    return c == '0' || c == '1';
}

bool simulate_nfa(const char *str) {
    int len = strlen(str);
    bool dp[len + 1][MAX_STATES];

    memset(dp, false, sizeof(dp));
    dp[0][0] = true; 

    int i, state; 

    for (i = 0; i < len; i++) {
        char c = str[i];
        if (!is_valid_char(c)) {
            return false;
        }

        for (state = 0; state < MAX_STATES; state++) {
            if (dp[i][state]) {
                switch (state) {
                    case 0:
                        if (c == '0') {
                            dp[i + 1][1] = true; 
                        }
                        break;
                    case 1:
                        if (c == '0') {
                            dp[i + 1][2] = true; 
                        }
                        break;
                    case 2:
                        dp[i + 1][2] = true; 
                        if (c == '1') {
                            dp[i + 1][3] = true; 
                        }
                        break;
                    case 3:
                        if (c == '1') {
                            dp[i + 1][3] = true; 
                        } else {
                            dp[i + 1][4] = true; 
                        }
                        break;
                    case 4:
                        dp[i + 1][4] = true;
                        break;
                }
            }
        }
    }

    return dp[len][3]; 
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (simulate_nfa(str)) {
        printf("String is accepted by the NFA.\n");
    } else {
        printf("String is not accepted by the NFA.\n");
    }

    return 0;
}

