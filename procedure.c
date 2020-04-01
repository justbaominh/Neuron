#include "final.h"

// first step
void allcolor () {
    FILE *filename;
    FILE *header;
    int array[20];
    int color [1000000];
    int i = 0;
    int a;

    filename = fopen("m.ppm","rb");
    header = fopen("file2.txt","wb");
    if (filename == NULL) {
        printf("Can not open file.ppm.\n");
        return 1;
    }
    if (header == NULL) {
        printf("Can not write in this file");
        return 1;
    }
    a = fread(array,1,15,filename);
    fwrite(array,1,a,header);

    while (!feof(filename)) {
        fread(color,sizeof(char),3,filename);
        double cal[3] = {color[i],color[i+1],color[i+2]};
        red(cal);
        green(cal);
        blue(cal);
        i = i + 3;
    }
    fclose(header);
    fclose(filename);

    }




