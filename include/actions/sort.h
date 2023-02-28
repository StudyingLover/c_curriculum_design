//
// Created by lenovo on 2023/2/28.
//

#ifndef C_CURRICULUM_DESIGN_SORT_H
#define C_CURRICULUM_DESIGN_SORT_H
void swap(struct node *a, struct node *b);
int compare_by_id(struct drug a, struct drug b);
int compare_by_name(struct drug a, struct drug b);
int compare_by_stock(struct drug a, struct drug b);
int compare_by_price(struct drug a, struct drug b);
void sort_by_id(struct node *head);
void sort_by_name(struct node *head);
void sort_by_stock(struct node *head);
void sort_by_price(struct node *head);
void drug_sort(struct node *head);
#endif //C_CURRICULUM_DESIGN_SORT_H
