#include <stdio.h>
#include <stdlib.h>
#include "final.h"
#include <string.h>

int main() {
    char file1[200];
    char file2[200];
    printf("Enter first file's name to analyze: ");
    scanf("%s",file1);
//    char *s = "final.ppm";
    allcolor(file1, "file2.txt", "result.txt");
    printf("Enter second file's name to analyze: ");
    scanf("%s",file2);
    getchar();
    allcolor(file2, "file2test.txt", "resulttest.txt");
    printf("Do you want to clean screen?\n");
    printf("Type Y(YES) or N(NO): ");
    char ask[10];
    scanf("%s",ask);
    if (strcmp(ask,"Y") == 0) {
    system("cls");
    compare("result.txt","resulttest.txt");
    }
    else
        compare("result.txt","resulttest.txt");
    return 0;
}
