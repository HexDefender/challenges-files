#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char flag[64];
char books[5][64];

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    char *env_flag = getenv("FLAG");
    if (env_flag) {
        strncpy(flag, env_flag, 63);
    } else {
        strncpy(flag, "HexDefender{FAKE_FLAG_FOR_TESTING}", 63);
    }

    strcpy(books[0], "Intro to Cybersecurity");
    strcpy(books[1], "Python for Hackers");
    strcpy(books[2], "Network Defense 101");
    strcpy(books[3], "Reverse Engineering");
    strcpy(books[4], "The Art of Deception");
}

void menu() {
    puts("\n=== Hex Defender Library ===");
    puts("1. Read a book title");
    puts("2. Exit");
    printf("> ");
}

int main() {
    init();
    int idx;
    int choice;

    while(1) {
        menu();
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            printf("Enter book index (0-4): ");
            if (scanf("%d", &idx) != 1) break;

            if (idx > 4) {
                puts("Error: Index out of bounds!");
            } else {
                printf("Book Title: %s\n", books[idx]);
            }
        } else {
            puts("Goodbye!");
            break;
        }
    }
    return 0;
}
