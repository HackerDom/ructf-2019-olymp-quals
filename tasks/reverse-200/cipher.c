#include <stdio.h>
#include <stdint.h>

#define FLAG_LENGTH 38


/*
gcc -o cipher -O0 cipher.c
*/


char expected[FLAG_LENGTH] = {52, 25, 34, 51, 61, 38, 86, 123, 105, 83, 85, 93, 6, 93, 105, 24, 0, 55, 58, 67, 82, 119, 93, 89, 82, 104, 66, 84, 90, 10, 102, 92, 5, 82, 83, 90, 12, 72};
char key[FLAG_LENGTH] = "flag{yoO_k1ddo_y0U_waNnna_s0m3_h4ck??}";

int check_flag(char buffer[])
{
    int i;
    int result;

    result = 1;
    
    for (i = 0; i < FLAG_LENGTH; i++) {
        if ((buffer[i] ^ key[i]) != expected[i])
            result = 0;
    }

    return result;
}

int main(int argc, char** argv, char** envp)
{
    char buffer[FLAG_LENGTH + 1];

    puts("[*] Hello! Please, enter the flag");
    fgets(buffer, FLAG_LENGTH + 1, stdin);

    if (check_flag(buffer))
        puts("[+] Correct flag :)");
    else
        puts("[-] Wrong flag :(");

    return 0;
}
