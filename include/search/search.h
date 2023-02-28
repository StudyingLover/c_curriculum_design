//
// Created by lenovo on 2023/2/28.
//

#ifndef C_CURRICULUM_DESIGN_SEARCH_H
#define C_CURRICULUM_DESIGN_SEARCH_H
#include "../main.h"
void search_by_id(struct node *head, int id);
void search_by_name(struct node *head, char *name);
void search(struct node *head);
void search_complex_by_id(struct node *head, int id);
void search_complex_by_name(struct node *head, char *name);
void search_complex_by_stock(struct node *head, int stock);
void search_complex(struct node *head);
#endif //C_CURRICULUM_DESIGN_SEARCH_H
