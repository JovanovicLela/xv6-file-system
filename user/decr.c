#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
    int fd;
    char buf[512];
    char *p;
    struct dirent de;
    struct stat st;

    if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help" || (argc == 1))) {
        fprintf(2, "Usage: encr [-path or -a]\n");
    }else if(!strcmp(argv[1], "-a") || !strcmp(argv[1], "--encrypt-all")) {

        if((fd == open(".", 0)) < 0)
        fprintf(2, "decr: cannot open %s\n", ".");
        strcpy(buf, ".");
        p = buf + strlen(buf);
        *p++ = '/';

        while(read(fd, &de, sizeof(de)) == sizeof(de)) {
            if(de.inum == 0)
            continue;
        memmove(p, de.name, 512);
        p[511] = 0;

        if(stat(buf, &st) < 0) {
            printf("decr: cannot stat %s\n", buf);
            continue;
        }
         if(st.type == 1) {
            printf("Fail to open: %s\n", de.name);
        }

        if(st.type == 2) {


            if((fd = open(de.name, 2)) < 0) {
                printf("decr: cannot open %s\n", de.name);
                exit();
            }
            int status;
            status = decr(fd);
            fprintf(2, "%d\n", status);

            if(status == -1) {
                fprintf(2, "nije postavljen kljuc enkripcije\n");

            }else if(status == -2) {
                fprintf(2, "%s datoteka je T_DEV tipa\n", de.name);

            }else if(status == -3) {
                fprintf(2, "%s datoteka nije enkriptovana\n", de.name);

            }else if(status == 0) {
                fprintf(2, "deenkriptovana datoteka %s\n", de.name);
            }
            close(fd);
        }
    }
    }else {

        if((fd = open(argv[1], 2)) < 0) {
            printf("decr: cannot open %s\n", argv[1]);
            exit();
        }

        int status;
        status = decr(fd);

            if(status == -1) {
                fprintf(2, "nije postavljen kljuc enkripcije\n");

            }else if(status == -2) {
                fprintf(2, "%s datoteka je T_DEV tipa\n");

            }else if(status == -3) {
                fprintf(2, "%s datoteka nije enkriptovana\n");

            }
            close(fd);

    }

    exit();

}