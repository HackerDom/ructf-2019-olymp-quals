#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XOR 0xFF

#define COMMAND_SIZE 1024

/*
movcc movie.c -o movie -s
*/


// "/tmp/your_favourite_movie"
char* FILENAME = "\xd0\x8b\x92\x8f\xd0\x86\x90\x8a\x8d\xa0\x99\x9e\x89\x90\x8a\x8d\x96\x8b\x9a\xa0\x92\x90\x89\x96\x9a";

// "(/bin/sleep 0.1 && /bin/rm %s 2>/dev/null &); /bin/bash %s"
char* COMMAND_MASK = "\xd7\xd0\x9d\x96\x91\xd0\x8c\x93\x9a\x9a\x8f\xdf\xcf\xd1\xce\xdf\xd9\xd9\xdf\xd0\x9d\x96\x91\xd0\x8d\x92\xdf\xda\x8c\xdf\xcd\xc1\xd0\x9b\x9a\x89\xd0\x91\x8a\x93\x93\xdf\xd9\xd6\xc4\xdf\xd0\x9d\x96\x91\xd0\x9d\x9e\x8c\x97\xdf\xda\x8c";

// "echo \"[*] Hello! Please, enter the flag\"; read flag; if [ \"${flag:0:1}\" == \"R\" ]; then if [ \"${flag:1:1}\" == \"u\" ]; then if [ \"${flag:2:1}\" == \"C\" ]; then if [ \"${flag:3:1}\" == \"T\" ]; then if [ \"${flag:4:1}\" == \"F\" ]; then if [ \"${flag:5:1}\" == \"_\" ]; then if [ \"${flag:6:1}\" == \"7\" ]; then if [ \"${flag:7:1}\" == \"2\" ]; then if [ \"${flag:8:1}\" == \"e\" ]; then if [ \"${flag:9:1}\" == \"d\" ]; then if [ \"${flag:10:1}\" == \"5\" ]; then if [ \"${flag:11:1}\" == \"f\" ]; then if [ \"${flag:12:1}\" == \"3\" ]; then if [ \"${flag:13:1}\" == \"c\" ]; then if [ \"${flag:14:1}\" == \"4\" ]; then if [ \"${flag:15:1}\" == \"6\" ]; then if [ \"${flag:16:1}\" == \"7\" ]; then if [ \"${flag:17:1}\" == \"3\" ]; then if [ \"${flag:18:1}\" == \"4\" ]; then if [ \"${flag:19:1}\" == \"e\" ]; then if [ \"${flag:20:1}\" == \"1\" ]; then if [ \"${flag:21:1}\" == \"d\" ]; then if [ \"${flag:22:1}\" == \"8\" ]; then if [ \"${flag:23:1}\" == \"8\" ]; then if [ \"${flag:24:1}\" == \"6\" ]; then if [ \"${flag:25:1}\" == \"8\" ]; then if [ \"${flag:26:1}\" == \"7\" ]; then if [ \"${flag:27:1}\" == \"d\" ]; then if [ \"${flag:28:1}\" == \"3\" ]; then if [ \"${flag:29:1}\" == \"e\" ]; then if [ \"${flag:30:1}\" == \"9\" ]; then if [ \"${flag:31:1}\" == \"9\" ]; then if [ \"${flag:32:1}\" == \"c\" ]; then if [ \"${flag:33:1}\" == \"e\" ]; then if [ \"${flag:34:1}\" == \"e\" ]; then if [ \"${flag:35:1}\" == \"7\" ]; then if [ \"${flag:36:1}\" == \"8\" ]; then if [ \"${flag:37:1}\" == \"e\" ]; then echo \"[+] Correct flag :)\"; exit 0; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi; fi;  echo \"[-] Wrong flag :(\"; exit 1;"
char* SCRIPT = "\x9a\x9c\x97\x90\xdf\xdd\xa4\xd5\xa2\xdf\xb7\x9a\x93\x93\x90\xde\xdf\xaf\x93\x9a\x9e\x8c\x9a\xd3\xdf\x9a\x91\x8b\x9a\x8d\xdf\x8b\x97\x9a\xdf\x99\x93\x9e\x98\xdd\xc4\xdf\x8d\x9a\x9e\x9b\xdf\x99\x93\x9e\x98\xc4\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcf\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xad\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x8a\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xbc\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcc\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xab\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcb\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xb9\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xca\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xa0\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xc9\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc8\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xc8\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xcd\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xc7\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9a\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xc6\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9b\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xcf\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xca\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xce\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x99\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xcd\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xcc\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xcc\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9c\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xcb\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xcb\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xca\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc9\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xc9\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc8\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xc8\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xcc\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xc7\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xcb\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xce\xc6\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9a\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xcf\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xce\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xce\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9b\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xcd\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc7\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xcc\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc7\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xcb\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc9\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xca\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc7\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xc9\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc8\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xc8\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9b\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xc7\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xcc\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcd\xc6\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9a\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcc\xcf\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc6\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcc\xce\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc6\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcc\xcd\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9c\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcc\xcc\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9a\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcc\xcb\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9a\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcc\xca\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc8\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcc\xc9\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\xc7\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x96\x99\xdf\xa4\xdf\xdd\xdb\x84\x99\x93\x9e\x98\xc5\xcc\xc8\xc5\xce\x82\xdd\xdf\xc2\xc2\xdf\xdd\x9a\xdd\xdf\xa2\xc4\xdf\x8b\x97\x9a\x91\xdf\x9a\x9c\x97\x90\xdf\xdd\xa4\xd4\xa2\xdf\xbc\x90\x8d\x8d\x9a\x9c\x8b\xdf\x99\x93\x9e\x98\xdf\xc5\xd6\xdd\xc4\xdf\x9a\x87\x96\x8b\xdf\xcf\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\x99\x96\xc4\xdf\xdf\x9a\x9c\x97\x90\xdf\xdd\xa4\xd2\xa2\xdf\xa8\x8d\x90\x91\x98\xdf\x99\x93\x9e\x98\xdf\xc5\xd7\xdd\xc4\xdf\x9a\x87\x96\x8b\xdf\xce\xc4";


void decode()
{
    int i;

    for (i = 0; i < strlen(FILENAME); i++)
        FILENAME[i] ^= XOR;

    for (i = 0; i < strlen(COMMAND_MASK); i++)
        COMMAND_MASK[i] ^= XOR;

    for (i = 0; i < strlen(SCRIPT); i++)
        SCRIPT[i] ^= XOR;
}

void write_script()
{
    FILE* stream = fopen(FILENAME, "w");

    if (!stream)
    {
        printf("Looks like you aren't a movie lover :(\n");
        exit(-1);
    }
    
    fputs(SCRIPT, stream);
    fclose(stream);
}

int main(int argc, char** argv, char** envp)
{
    char command[COMMAND_SIZE + 1];

    decode();
    write_script();
    
    snprintf(command, COMMAND_SIZE, COMMAND_MASK, FILENAME, FILENAME);

    system(&command);
    unlink(FILENAME);

    return 0;
}
