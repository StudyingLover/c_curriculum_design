//
// Created by lenovo on 2023/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "main.h"

void search_by_id(struct node *head, int id) {
    struct node *current = head;
    int found = 0;

    while (current != NULL) {
        if (current->data.id == id) {
            print_drug(current->data);
            found = 1;
        }

        current = current->next;
    }

    if (!found) {
        printf("No drug with ID %d found.\n", id);
    }
}

void search_by_name(struct node *head, char *name) {
    struct node *current = head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            print_drug(current->data);
            found = 1;
        }

        current = current->next;
    }

    if (!found) {
        printf("No drug with name \"%s\" found.\n", name);
    }
}

void search(struct node *head) {
    int choice, id;
    char name[50];

    printf("Choose a search criteria:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the ID of the drug to search: ");
            scanf("%d", &id);
            search_by_id(head, id);
            break;

        case 2:
            printf("Enter the name of the drug to search: ");
            scanf("%s", name);
            search_by_name(head, name);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

void search_complex_by_id(struct node *head, int id) {
    struct node *current = head;
    int found = 0;

    while (current != NULL) {
        if (current->data.id == id) {
            print_drug(current->data);
            found = 1;
        }

        current = current->next;
    }

    if (!found) {
        printf("No drug with ID %d found.\n", id);
    }
}

void search_complex_by_name(struct node *head, char *name) {
    struct node *current = head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            print_drug(current->data);
            found = 1;
        }

        current = current->next;
    }

    if (!found) {
        printf("No drug with name \"%s\" found.\n", name);
    }
}

void search_complex_by_stock(struct node *head, int stock) {
    struct node *current = head;
    int found = 0;

    while (current != NULL) {
        if (current->data.stock == stock) {
            print_drug(current->data);
            found = 1;
        }

        current = current->next;
    }

    if (!found) {
        printf("No drug with stock %d found.\n", stock);
    }
}

void search_complex(struct node *head) {
    int choice, id, stock;
    char name[50];

    printf("Choose a search criteria:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("3. Stock\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the ID of the drug to search: ");
            scanf("%d", &id);
            search_complex_by_id(head, id);
            break;

        case 2:
            printf("Enter the name of the drug to search: ");
            scanf("%s", name);
            search_complex_by_name(head, name);
            break;

        case 3:
            printf("Enter the stock of the drug to search: ");
            scanf("%d", &stock);
            search_complex_by_stock(head, stock);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}
