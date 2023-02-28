//
// Created by lenovo on 2023/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "main.h"
void modify_drug(struct node *head) {
    int id;
    printf("Enter the ID of the drug you want to modify: ");
    scanf("%d", &id);

    struct node *current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            printf("Enter the new name of the drug: ");
            scanf("%s", current->data.name);

            printf("Enter the new type of the drug: ");
            scanf("%s", current->data.type);

            printf("Enter the new price of the drug: ");
            scanf("%f", &current->data.price);
            printf("Enter the new stock of the drug: ");
            scanf("%d", &current->data.stock);

            printf("Enter the new production date of the drug: ");
            scanf("%s", current->data.production_date);

            printf("Enter the new expiration date of the drug: ");
            scanf("%s", current->data.expiration_date);

            printf("Enter the new manufacturer of the drug: ");
            scanf("%s", current->data.manufacturer);

            printf("Drug with ID %d has been modified.\n", id);
            return;
        }
        current = current->next;
    }

    printf("Error: Drug with ID %d not found.\n", id);
}