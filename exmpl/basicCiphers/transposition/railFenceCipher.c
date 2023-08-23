#include <stdio.h>
#include <string.h>

void encryptRailFence(char *message, int rails) {
    int messageLen = strlen(message);
    char railFence[rails][messageLen];
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < messageLen; j++) {
            railFence[i][j] = ' ';
        }
    }
    int row = 0;
    int direction = 1; 
    for (int i = 0; i < messageLen; i++) {
        railFence[row][i] = message[i];
        if (row == 0) {
            direction = 1; 
        } else if (row == rails - 1) {
            direction = -1; 
        }
        row += direction;
    }
    printf("Encrypted Message: ");
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < messageLen; j++) {
            if (railFence[i][j] != ' ') {
                printf("%c", railFence[i][j]);
            }
        }
    }
    printf("\n");
}
