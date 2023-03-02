//
// Created by lenovo on 2023/3/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <time.h>

// On Windows platform, the function strptime() from time.h is not supported, I found.

char* getOverDate(char* productionDate, char* shelfLife_str) {
    char* temp= shelfLife_str;
    int shelfLife = atoi(temp);
    // 将生产日期字符串按照 "-" 分割为年、月、日三个字符串
    char* year = strtok(productionDate, "-");
    char* month = strtok(NULL, "-");
    char* day = strtok(NULL, "-");

    // 将年、月、日字符串转换为整型变量
    int year_int = atoi(year);
    int month_int = atoi(month);
    int day_int = atoi(day);

    // 计算过期日期的年、月、日
    year_int += (shelfLife / 365);
    shelfLife %= 365;
    month_int += (shelfLife / 30);
    day_int += (shelfLife % 30);
    if (day_int > 30) {
        day_int -= 30;
        month_int++;
    }
    if (month_int > 12) {
        month_int -= 12;
        year_int++;
    }

    // 将过期日期的年、月、日转换为字符串
    char* expirationDate = (char*) malloc(sizeof(char) * 11);
    sprintf(expirationDate, "%04d-%02d-%02d", year_int, month_int, day_int);

    return expirationDate;
}



//int main() {
//    char productionDate[] = "2022-03-01";
//    int shelfLife = 365;
//    char* expirationDate = getExpirationDate(productionDate, shelfLife);
//    printf("过期日期为：%s\n", expirationDate);
//    free(expirationDate);
//    return 0;
//}
