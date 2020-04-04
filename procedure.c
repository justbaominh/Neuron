#include "final.h"

// first step
double quadrants[2][2][3];
double p[4][4][3];
double pix[400][500][4];


void allcolor (char *file,char *hf, char *res) {
    FILE *filename;
    FILE *header;
    FILE *result;
    int array[20];
    int a;
    remove(res);
    filename = fopen(file,"rb");
    header = fopen(hf,"wb");



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
    printf("Pass all picture through sigmoid\n");
    double inp[3] = {vr, vg, vb};
    rgb(inp,res);

    printf("Pass 1/4 picture \n");
    for(int i = 0; i < 300; i++)
    for(int j = 0; j < 400; j++) {
        int x = i / 150;
        int y = j / 200;
        quadrants[x][y][0] += pix[i][j][0];     // ví du
        quadrants[x][y][1] += pix[i][j][1];
        quadrants[x][y][2] += pix[i][j][2];
    }
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++) {
        quadrants[i][j][0] /= 30000;
        quadrants[i][j][1] /= 30000;
        quadrants[i][j][2] /= 30000;
        double inp[3] = {quadrants[i][j][0], quadrants[i][j][1], quadrants[i][j][2]};
        rgb(inp,res);
    }
    printf("Pass 1/16 picture\n");
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
        rgb(inp,res);
    }
    fclose(header);
    fclose(filename);

}




