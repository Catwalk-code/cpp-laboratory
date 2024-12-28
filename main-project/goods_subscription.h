#ifndef GOODS_SUBSCRIPTION_H
#define GOODS_SUBSCRIPTION_H

#include <iostream>
#include <string>
#include "constants.h"

// Структура для хранения цены товара
struct Price {
    float money; // Дробное неотрицательное число
};

// Структура для хранения категории товара
struct Category {
    std::string categoryofgoods; // Категория товара (строка без пробелов)
};

// Структура для хранения названия товара
struct Naming {
    char nameofgoods[MAX_STRING_SIZE]; // Название товара (может содержать пробелы)
};

// Основная структура для подписки на товары
struct GoodsSubscription {
    Price price;             // Цена товара
    int quantity;            // Количество товара на складе (целое неотрицательное число)
    Category category;       // Категория товара
    Naming naming;           // Название товара
};

#endif 
