//
// Created by lenovo on 2023/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "main.h"
void print_drug(struct drug d) {
//    printf("%-10d%-20s%-10d\n", d.id, d.name, d.stock);
    printf("ID: %d, Name: %s, Type: %s, Price: %.2f, Stock: %d, Production Date: %s, Expiration Date: %s, Manufacturer: %s\n", d.id, d.name, d.type, d.price, d.stock, d.production_date, d.expiration_date, d.manufacturer);
}