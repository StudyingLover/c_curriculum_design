#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "main.h"
#include "count/count.h"
#include "search/search.h"
#include "log/log.h"
#include "user/user.h"
#include "actions/add.h"
#include "actions/delete.h"
#include "actions/modify.h"
#include "actions/sort.h"

char config_path[100] = "E:\\college\\2023\\c_curriculum_design\\config\\drugs.txt";

struct node *read_from_file() {
    FILE *fp = fopen(config_path, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    struct node *head = NULL;
    struct node *tail = NULL;

    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        struct drug new_drug;
        sscanf(line, "%d,%[^,],%[^,],%f,%d,%[^,],%[^,],%[^,]", &new_drug.id, new_drug.name,
                   new_drug.type, &new_drug.price, &new_drug.stock, new_drug.production_date, new_drug.expiration_date, new_drug.manufacturer);
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = new_drug;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    fclose(fp);
    return head;
}

void save_to_file(struct node *head) {
    FILE *fp = fopen(config_path, "w");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    struct node *current = head;
    while (current != NULL) {
        fprintf(fp, "%d,%s,%s,%.2f,%d,%s,%s,%s", current->data.id, current->data.name,
                current->data.type, current->data.price, current->data.stock, current->data.production_date, current->data.expiration_date, current->data.manufacturer);
        current = current->next;
    }

    fclose(fp);
}

int main() {
    int t;
    t = login();
    if (t == 1)
    {
        printf("您已经连续三次输入错误，程序退出。");
        return 0;
    }

    struct node *head = read_from_file();
    int option = 0;
    while (option != 8) {
        printf("Please select an option:\n");
        printf("1. Add a new drug\n");
        printf("2. Modify an existing drug\n");
        printf("3. Display drug list\n");
        printf("4. Delete a drug\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Statistics\n");
        printf("8. Quit\n");

        scanf("%d", &option);

        if (option == 1) {
            add_drug(&head);
            int save_option = 0;
            printf("Save changes to file?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &save_option);

            if (save_option == 1) {
                save_to_file(head);
            }
        }
        else if (option == 2) {
            modify_drug(head);
            int save_option = 0;
            printf("Save changes to file?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &save_option);

            if (save_option == 1) {
                save_to_file(head);
            }
        }
        else if (option == 3) {
            struct node *current = head;
            while (current != NULL) {
                print_drug(current->data);
                printf("\n");
                current = current->next;
            }
        }
        else if(option == 4) {
            int delete_id;
//            scanf("input the id of you want to delete:%d", &delete_id);
//            printf("test");
            scanf("%d", &delete_id);
            printf("%d\n", delete_id);
            delete_drug(&head, delete_id);
        }
        else if(option == 5) {
            int search_option = 0;
            printf("Choose a search criteria:\n");
            printf("1. Simple search\n");
            printf("2. Complex search\n");
            scanf("%d", &search_option);
            if(search_option == 1)
            {
                search(head);
            }
            else if(search_option == 2)
            {
                search_complex(head);
            }
            else
            {
                printf("Invalid option. Please try again.\n");
            }
        }
        else if(option == 6) {
            drug_sort(head);
        }
        else if(option == 7) {
            printf("%d\n", countMedicine( head ));
        }
        else if(option == 8) {
            printf("Bye!\n");
        }

        else {
            printf("Invalid option. Please try again.\n");
        }

    }

    save_to_file(head);

    return 0;
}
