//
// Created by lenovo on 2023/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int countMedicine(struct node* head) {
    int count = 0;
    struct node* p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}
//int countMedicineByAttr(struct Medicine* head, char* attr, char* value) {
//    int count = 0;
//    struct node* p = head;
//    while (p != NULL) {
//        if (strcmp(getMedicineAttr(p, attr), value) == 0) {
//            count++;
//        }
//        p = p->next;
//    }
//    return count;
//}
float countTotalValue(struct node* head) {
    float totalValue = 0.0;
    struct node* p = head;
    while (p != NULL) {
        totalValue += (p->data.price * p->data.stock);
        p = p->next;
    }
    return totalValue;
}
