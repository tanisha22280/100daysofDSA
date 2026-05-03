#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];   // store unique names
    int count[MAX] = {0};   // vote count
    int size = 0;

    char temp[LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", temp);

        int found = -1;

        for (int j = 0; j < size; j++) {
            if (strcmp(names[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(names[size], temp);
            count[size] = 1;
            size++;
        }
    }

    int maxVotes = -1;
    char winner[LEN];

    for (int i = 0; i < size; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}