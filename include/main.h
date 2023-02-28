//
// Created by lenovo on 2023/2/28.
//

#ifndef C_CURRICULUM_DESIGN_MAIN_H
#define C_CURRICULUM_DESIGN_MAIN_H
struct drug {
    int id;
    char name[50];
    char type[50];
    float price;
    int stock;
    char production_date[50];  // 生产日期
    char expiration_date[50];  // 保质期
    char manufacturer[50];  // 生产厂家
};


struct node {
    struct drug data;
    struct node *next;
};
#endif //C_CURRICULUM_DESIGN_MAIN_H
