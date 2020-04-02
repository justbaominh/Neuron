#include "final.h"
void lala(){
    printf("*");}
// first step
double q[2][2][3];
double p[4][4][3];
double pix[400][500][4];
int color [1000000];

void allcolor (char* s) {
    FILE *filename;
    FILE *header;
    int array[20];
    int i = 0;
    int a;

    filename = fopen(s,"rb");
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

    for(int i = 0; i < 300; i++)
    for (int j = 0; j < 400; j++) {
        //printf("%d %d \n", i, j);
        int r, g, b;
        r = g = b = 0;
        fread(&r,1,1,filename);
        fread(&g,1,1,filename);
        fread(&b,1,1,filename);
        double cal[3];
        cal[0] = 1.0 * r / 255;
        cal[1] = 1.0 * g / 255;
        cal[2] = 1.0 * b / 255;
        pix[i][j][0] = cal[0];
        pix[i][j][1] = cal[1];
        pix[i][j][2] = cal[2];
//        printf("*");
//        printf("%f %f %f\n", cal[0], cal[1], cal[2]);
//        red(cal);
//        green(cal);
//        blue(cal);
        //i = i + 3;
    }
    double vr, vg, vb;
    vr = vg = vb = 0;
    for(int i = 0; i < 300; i++)
    for(int j = 0; j < 400; j++) {
        vr += pix[i][j][0];
        vg += pix[i][j][1];
        vb += pix[i][j][2];
    }
    vr /= 120000;
    vg /= 120000;
    vb /= 120000;
    double inp[3] = {vr, vg, vb};
    rgb(inp);
    printf("*");


    for(int i = 0; i < 300; i++)
    for(int j = 0; j < 400; j++) {
        int x = i / 150;
        int y = j / 200;
        q[x][y][0] += pix[i][j][0];
        q[x][y][1] += pix[i][j][1];
        q[x][y][2] += pix[i][j][2];
    }
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++) {
        q[i][j][0] /= 30000;
        q[i][j][1] /= 30000;
        q[i][j][2] /= 30000;
        double inp[3] = {q[i][j][0], q[i][j][1], q[i][j][2]};
        rgb(inp);
    }

    for(int i = 0; i < 300; i++)
    for(int j = 0; j < 400; j++) {
        int x = i / 75;
        int y = j / 100;
        p[x][y][0] += pix[i][j][0];
        p[x][y][1] += pix[i][j][1];
        p[x][y][2] += pix[i][j][2];
    }
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) {
        p[i][j][0] /= 7500;
        p[i][j][1] /= 7500;
        p[i][j][2] /= 7500;
        double inp[3] = {p[i][j][0], p[i][j][1], p[i][j][2]};
        rgb(inp);
    }
    fclose(header);
    fclose(filename);

}



