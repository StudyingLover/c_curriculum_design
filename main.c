#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "actions/count.h"
#include "actions/search.h"
#include "log/log.h"
#include "user/user.h"
#include "actions/add.h"
#include "actions/delete.h"
#include "actions/modify.h"
#include "actions/sort.h"
#include "actions/insert.h"

//将这两个路径根据自己的情况换成drugs.txt和user.txt所在的绝对路径
char config_path[100] = "D:\\Proj\\c_curriculum_design\\data\\drugs.txt";
char users_config_path[100] = "D:\\Proj\\c_curriculum_design\\config\\user.txt";

struct node *read_from_file()
{
    FILE *fp = fopen(config_path, "r+");
    if (fp == NULL)
    {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    struct node *head = NULL;
    struct node *tail = NULL;

    char line[100];
    while (fgets(line, 100, fp) != NULL)
    {
        // printf("len:%d  ,  %s",strlen(line),line);
        struct drug new_drug;
        if(strlen(line) == 1)
            continue;
        sscanf(line, "%d,%[^,],%[^,],%f,%d,%[^,],%[^,],%[^,]", &new_drug.id, new_drug.name,
               new_drug.type, &new_drug.price, &new_drug.stock, new_drug.production_date, new_drug.expiration_date, new_drug.manufacturer);
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = new_drug;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    fclose(fp);
    return head;
}

void save_to_file(struct node *head)
{
    FILE *fp = fopen(config_path, "w+");
    if (fp == NULL)
    {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    struct node *current = head;
    while (current != NULL)
    {
        fprintf(fp, "%d,%s,%s,%.2f,%d,%s,%s,%s\n", current->data.id, current->data.name,
                current->data.type, current->data.price, current->data.stock, current->data.production_date, current->data.expiration_date, current->data.manufacturer);
        current = current->next;
    }

    fclose(fp);
}

int main()
{
    int t;
    t = login();
    if (t == 1)
    {
        //        printf("���Ѿ���������������󣬳����˳���");
        printf("you have entered the wrong password for three times, the program will exit.");
        return 0;
    }

    struct node *head = read_from_file();
    int option = -1;
    while (option != 0)
    {
        printf("Please select an option:\n");
        printf("1. Add a new drug\n");
        printf("2. Modify an existing drug\n");
        printf("3. Display drug list\n");
        printf("4. Delete a drug\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Statistics\n");
        printf("8. insert\n");
//        printf("9. Get Expiration Date\n");
        printf("0. Quit\n");

        scanf("%d", &option);

        if (option == 1)
        {
            add_drug(&head);
            int save_option = 0;
            printf("Save changes to file?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &save_option);

            if (save_option == 1)
            {
                save_to_file(head);
            }
        }
        else if (option == 2)
        {
            modify_drug(head);
            int save_option = 0;
            printf("Save changes to file?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &save_option);

            if (save_option == 1)
            {
                save_to_file(head);
            }
        }
        else if (option == 3)
        {
            struct node *current = head;
            while (current != NULL)
            {
                print_drug(current->data);
                printf("\n");
                current = current->next;
            }
        }
        else if (option == 4)
        {
            int delete_id;
            //            scanf("input the id of you want to delete:%d", &delete_id);
            //            printf("test");
            scanf("%d", &delete_id);
            printf("%d\n", delete_id);
            delete_drug(&head, delete_id);
        }
        else if (option == 5)
        {
            int search_option = 0;
            printf("Choose a search criteria:\n");
            printf("1. Simple search\n");
            printf("2. Complex search\n");
            scanf("%d", &search_option);
            if (search_option == 1)
            {
                search(head);
            }
            else if (search_option == 2)
            {
                search_complex(head);
            }
            else
            {
                printf("Invalid option. Please try again.\n");
            }
        }
        else if (option == 6)
        {
            drug_sort(head);
        }
        else if (option == 7)
        {
            printf("total:%d\n", countMedicine(head));
            printf("total price:%.2f\n", countTotalValue(head));
        }
        else if (option == 8)
        {
            int insert_id;
            scanf("%d", &insert_id);
            insert_drug(&head, insert_id);
        }
        else if (option == 0)
        {
            printf("Bye!\n");
        }

        else
        {
            printf("Invalid option. Please try again.\n");
        }

    }

    save_to_file(head);

    return 0;
}
