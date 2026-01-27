#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *useful_string = "/bin/sh";

void secure_vault() {
    char buffer[64]; 

    puts("\n--- The Steel Vault v5.0 ---");
    printf("Enter credentials: ");

    read(0, buffer, 0x200);

    puts("Verifying...");
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    secure_vault();
    return 0;
}
