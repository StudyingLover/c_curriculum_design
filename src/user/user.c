//
// Created by lenovo on 2023/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

char users_config_path[100] = "E:\\college\\2023\\c_curriculum_design\\config\\users.txt";

//void get_hidden_input(char *str, int max_length) {
//    int i = 0;
//    char ch;
//
//    while ((ch = getch()) != '\r' && i < max_length - 1) {
//        if (ch == '\b') {
//            if (i > 0) {
//                i--;
//                putchar('\b');
//                putchar(' ');
//                putchar('\b');
//            }
//        } else {
//            str[i] = ch;
//            putchar('*');
//            i++;
//        }
//    }
//    str[i] = '\0';
//    putchar('\n');
//}

int cheak(char *account,char *password)
{
    FILE *fp = fopen(users_config_path, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        char account1[50];
        char password1[50];
        sscanf(line, "%[^,],%[^,]", account1, password1);
        if (strcmp(account, account1) == 0 && strcmp(password, password1) == 0) {
            return 1;
        }
    }
    return 0;
}

int login()
{
    int n, i;
    char pass[15] = "abc123", ch[15] = "12345678";

//    printf("请输入用户名和正确的密码：（您一共有三次输入机会）//用户名：12345678；正确密码：abc123\n\n\n");
    printf("please enter the correct username and password: (you have three chances to enter) \n//username: 12345678; correct password: abc123");
    for (i = 0; i < 3; i++)
    {
        char pass1[15], ch1[15];

        //		printf("\t\t _____________________________________________\n");
        //		printf("\t\t|                                             |\n");
        //		printf("\t\t|                    登录                     |\n");
        //		printf("\t\t|_____________________________________________|\n");
        //		printf("\t\t|账户：                                       |\n");
        //		scanf(" \t\t|      %s                                     |\n",ch);
        //		printf("\t\t|_____________________________________________|\n");
        //		printf("\t\t|密码：                                       |\n");
        //		scanf(" \t\t|      %s                                     |\n",pass1);
        //		printf("\t\t|_____________________________________________|\n");

        printf("**************************************************\n");
        printf("--------------------------------------------------\n");
        printf("\t\t\tlogin\n");
        printf("--------------------------------------------------\n");
        printf("account:\n");
        gets(ch1);
        printf("--------------------------------------------------\n");
        printf("password:\n");
        gets(pass1);
//        get_hidden_input(pass1, 15);
        printf("--------------------------------------------------\n");
        printf("**************************************************\n\n\n");

        if (strcmp(ch, ch1) == 0 && strcmp(pass, pass1) == 0)
        { // 两字符串相等时为0
            printf("password correct\n");
            system("cls");

            return 0;
        }
        else
        {
            printf("wrong,please try again");
            printf("you only have %d chance(s) to try", 3 - i - 1);
            if (3 - 1 - i == 0)
            {
                return 1;
            }
        }
        system("cls");
    }
}