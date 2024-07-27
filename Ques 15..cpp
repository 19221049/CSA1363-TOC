#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 100

void epsilon_closure(int state, bool epsilon_transitions[MAX_STATES][MAX_STATES], bool visited[MAX_STATES]) {
    visited[state] = true;
    int i; 
    for (i = 0; i < MAX_STATES; i++) {
        if (epsilon_transitions[state][i] && !visited[i]) {
            epsilon_closure(i, epsilon_transitions, visited);
        }
    }
}

int main() {
    int num_states, num_transitions;
    printf("Enter the number of states: ");
    scanf("%d", &num_states);

    bool epsilon_transitions[MAX_STATES][MAX_STATES] = {false};

    printf("Enter the number of e-transitions: ");
    scanf("%d", &num_transitions);

    printf("Enter the e-transitions (format: from to):\n");
    int i;
    for (i = 0; i < num_transitions; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        epsilon_transitions[from][to] = true;
    }

    int state; 
    for (state = 0; state < num_states; state++) {
        bool visited[MAX_STATES] = {false};
        epsilon_closure(state, epsilon_transitions, visited);

        printf("e-closure of state %d: {", state);
        bool first = true;
        int j; 
        for (j = 0; j < num_states; j++) {
            if (visited[j]) {
                if (!first) {
                    printf(", ");
                }
                printf("%d", j);
                first = false;
            }
        }
        printf("}\n");
    }

    return 0;
}

