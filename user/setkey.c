#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"


int
main(int argc, char *argv[])
{
    int n;
    int buff[512];
    if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
        fprintf(2, "Usage: setkey -s [keynumber]\n");
    }else if(!strcmp(argv[1], "-s") || !strcmp(argv[1], "--secret")) {
        fprintf(2, "Enter the key: ");
        setecho(0);
        read(0, buff, 512);
        n = atoi(buff);
        setkey(n);
        setecho(1);
    }else{
        setkey(atoi(argv[1]));
        exit();
    }
    exit();

}