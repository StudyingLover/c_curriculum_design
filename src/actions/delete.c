//
// Created by lenovo on 2023/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "main.h"
void delete_drug(struct node **head, int id) {
    struct node *current = *head;
    struct node *previous = NULL;

    while (current != NULL) {
        if (current->data.id == id) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            printf("Drug with ID %d has been deleted.\n", id);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Error: Drug with ID %d not found.\n", id);
}