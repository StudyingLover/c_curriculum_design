//
// Created by lenovo on 2023/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "date/date.h"
void add_drug(struct node **head) {
    struct drug new_drug;

    printf("Enter drug ID: ");
    scanf("%d", &new_drug.id);

    printf("Enter drug name: ");
    scanf("%s", new_drug.name);

    printf("Enter drug type: \n");
    printf("1 means prescription drugs , and 2 means OTC(over-the-counter drugs)");
    scanf("%s", new_drug.type);

    printf("Enter drug price: ");
    scanf("%f", &new_drug.price);

    printf("Enter drug stock: ");
    scanf("%d", &new_drug.stock);

    printf("Enter drug production date: \n");
    printf("the format of date is YYYY-MM-DD ,for example ,2022-03-02");
    scanf("%s", new_drug.production_date);

    printf("Enter drug expiration date(days): ");
    scanf("%s", new_drug.expiration_date);

    printf("Enter drug manufacturer: ");
    scanf("%s", new_drug.manufacturer);

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_drug;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}