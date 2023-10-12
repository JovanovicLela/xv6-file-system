#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    int fd;
    char *name = "long.txt";
    int blocks = 150;
    int n;
    char ch[1];

    if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help" || (argc == 1))) {
        fprintf(2, "Use this program to create a big file filled with a-z characters.\n");
        fprintf(2, "Default filename: long.txt\n");
        fprintf(2, "Default blocks: 150\n");
        fprintf(2, "Usage: blockwriter [OPTION]...\n\n");
        fprintf(2, "Command line options:\n");
        fprintf(2, "       -h, --help: Show help prompt.\n");
        fprintf(2, "       -b, --blocks: Numbers of block to write.\n");
        fprintf(2, "       -o, --output-file: Set output filename.\n");

        
    }else if(argc == 3 && (!strcmp(argv[1], "-o") || !strcmp(argv[1], "--output-file"))) {
       
        name = argv[2];

    }else if(argc == 3 && (!strcmp(argv[1], "-b") || !strcmp(argv[1], "--blocks"))) {
       
        blocks = atoi(argv[2]);

    }else if(argc == 5 && (!strcmp(argv[1], "-b") || !strcmp(argv[1], "--blocks"))) {
       
        blocks = atoi(argv[2]);
        name = argv[4];

    }else if(argc == 5 && (!strcmp(argv[1], "-o") || !strcmp(argv[1], "--output-file"))) {
       
        blocks = atoi(argv[4]);
        name = argv[2];

    }

    n = blocks * 512;

    fd = open(name, 0x200 | 0x001);

    ch[0] = 'a';

    int current_block = 1;

    while(n > 0) {

        if(n % 512 == 0)
        fprintf(2, "Write block %d \n", current_block++);

        if(ch[0] >= 'a' && ch[0] <= 'z') {
            ch[0] = ch[0] + 1;

            if(ch[0] > 'z') {
                ch[0] = 'a';
            }
            write(fd, ch, sizeof(ch));
        }

        n -= 1;

    }

    close(fd);
    exit();

}