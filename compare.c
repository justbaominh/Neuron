#include "final.h"

double per (double a, double b) {
    if (a/b <=1)
        return (a/b)*100;
    else return (b/a)*100;
}
void compare(char *res1, char *res2) {
    FILE *file1;
    FILE *file2;

struct Pic1all {
    double red;
    double green;
    double blue;
    };
typedef struct Pic1all P1;

struct Pic2all {
    double red;
    double green;
    double blue;
    };
typedef struct Pic2all P2;

    P1 p1all[1], p1quad[4], p1div4[16];
    P2 p2all[1], p2quad[4], p2div4[16];

    file1 = fopen(res1,"r");
    file2 = fopen(res2,"r");


    fscanf(file1, "%lf %lf %lf",&p1all[0].red,&p1all[0].green,&p1all[0].blue);
    fscanf(file2, "%lf %lf %lf",&p2all[0].red,&p2all[0].green,&p2all[0].blue);
    printf("Analysis: \n");
    printf("Pass entire picture \n");
    double nor[3];  // normalization
    nor[0] = per(p1all[0].red,p2all[0].red);
    printf("Percent similar in red element: %lf\n", nor[0]);
    nor[1] = per(p1all[0].green,p2all[0].green);
    printf("Percent similar in green element: %lf\n", nor[1]);
    nor[2] = per(p1all[0].blue,p2all[0].blue);
    printf("Percent similar in blue element: %lf\n", nor[2]);
    double allnor = (nor[0] + nor[1] + nor[2])/3 ;
    printf("\n=> Percent similar by (r,g,b): %lf\n", allnor);
    printf("*\n");
    printf("*\n");
    printf("Pass 4 equal - sized parts of picture\n");
    double sumquadnor = 0;
    for (int i = 0; i < 4; i++){
        fscanf(file1, "%lf %lf %lf",&p1quad[i].red,&p1quad[i].green,&p1quad[i].blue);
        fscanf(file2, "%lf %lf %lf",&p2quad[i].red,&p2quad[i].green,&p2quad[i].blue);
            printf("Part %d: \n",i + 1);
            double nor[3];  // normalization
            nor[0] = per(p1quad[i].red,p2quad[i].red);
            printf("Percent similar in red element: %lf\n", nor[0]);
            nor[1] = per(p1quad[i].green,p2quad[i].green);
            printf("Percent similar in green element: %lf\n", nor[1]);
            nor[2] = per(p1quad[i].blue,p2quad[i].blue);
            printf("Percent similar in blue element: %lf\n", nor[2]);
            double quadnor = (nor[0] + nor[1] + nor[2])/3 ;
            printf("Percent similar by (r,g,b) in part %d : %lf\n", i + 1, quadnor);
            sumquadnor += quadnor;
            }
            sumquadnor /= 4;
            printf("\n=> Percent similar by (r,g,b) after calculating 4 parts : %lf\n", sumquadnor);
    printf("*\n");
    printf("*\n");
    printf("Pass 16 equal - sized parts of picture\n");
    double sumdiv4nor = 0;
    for (int i = 0; i < 16; i++){
        fscanf(file1, "%lf %lf %lf",&p1div4[i].red,&p1div4[i].green,&p1div4[i].blue);
        fscanf(file2, "%lf %lf %lf",&p2div4[i].red,&p2div4[i].green,&p2div4[i].blue);
            printf("Part %d: \n",i + 1);
            double nor[3];  // normalization
            nor[0] = per(p1div4[i].red,p2div4[i].red);
            printf("Percent similar in red element: %lf\n", nor[0]);
            nor[1] = per(p1div4[i].green,p2div4[i].green);
            printf("Percent similar in green element: %lf\n", nor[1]);
            nor[2] = per(p1div4[i].blue,p2div4[i].blue);
            printf("Percent similar in blue element: %lf\n", nor[2]);
            double div4nor = (nor[0] + nor[1] + nor[2])/3 ;
            printf("Percent similar by (r,g,b) in part %d : %lf\n", i + 1, div4nor);
            sumdiv4nor += div4nor;
            }
            sumdiv4nor /= 16;
            printf("\n=> Percent similar by (r,g,b) after calculating 16 parts : %lf\n", sumdiv4nor);

    printf("Do you want to clear screen and see final results?\n");
    printf("Press Y(YES) or N(NO): ");
    char ask[10];
    scanf("%s",ask);
    if (strcmp(ask,"Y") == 0) {
    system("cls");
    printf("\n=> Percent similar by (r,g,b): %lf\n", allnor);
    printf("\n=> Percent similar by (r,g,b) after calculating 4 parts : %lf\n", sumquadnor);
    printf("\n=> Percent similar by (r,g,b) after calculating 16 parts : %lf\n", sumdiv4nor);
    }
    printf("***\n");
    if (allnor == 100 || sumquadnor == 100 || sumdiv4nor == 100 )
        printf("This is my picture.\n");
        else
            printf("This is not my picture. \n");
    fclose(file1);
    fclose(file2);
}
