//
// Created by lenovo on 2023/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void swap(struct node *a, struct node *b) {
    struct drug temp = a->data;
    a->data = b->data;
    b->data = temp;
}
int compare_by_id(struct drug a, struct drug b) {
    return a.id - b.id;
}
int compare_by_name(struct drug a, struct drug b) {
    return strcmp(a.name, b.name);
}
int compare_by_stock(struct drug a, struct drug b) {
    return a.stock - b.stock;
}
int compare_by_price(struct drug a, struct drug b) {
    return a.price - b.price;
}
void sort_by_id(struct node *head) {
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (compare_by_id(ptr1->data, ptr1->next->data) > 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void sort_by_name(struct node *head) {
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (compare_by_name(ptr1->data, ptr1->next->data) > 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void sort_by_stock(struct node *head) {
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (compare_by_stock(ptr1->data, ptr1->next->data) > 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void sort_by_price(struct node *head) {
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (compare_by_price(ptr1->data, ptr1->next->data) > 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void drug_sort(struct node *head) {
    int choice;

    printf("Choose a sort criteria:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("3. Stock\n");
    printf("4. Price\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sort_by_id(head);
            break;
        case 2:
            sort_by_name(head);
            break;

        case 3:
            sort_by_stock(head);
            break;

        case 4:
            sort_by_price(head);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}