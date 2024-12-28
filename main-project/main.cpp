#include <iostream>
#include <iomanip>
using namespace std;

#include "goods_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(const GoodsSubscription* subscription) {
    // Вывод информации о товаре
    std::cout << "Категория: " << subscription->category.categoryofgoods << '\n';

    // Вывод названия товара
    std::cout << "Название товара: " << subscription->naming.nameofgoods << '\n';

    // Вывод цены товара
    std::cout << "Цена товара: " << subscription->price.money << " руб.\n";

    // Вывод количества товара
    std::cout << "Количество на складе: " << subscription->quantity << '\n';

    std::cout << '\n'; // Пустая строка для разделения записей
}

bool check_Category(GoodsSubscription* subscription) {
    return subscription->category.categoryofgoods == "Промтовары";
}

bool check_Price(GoodsSubscription* subscription) {
    return subscription->price.money > 100;
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #10. Каталог товаров\n";
    cout << "Author: Egor Orlov\n";
    cout << "\n";
    GoodsSubscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++) {
            output(subscriptions[i]);
        }

        bool (*check_function)(GoodsSubscription*) = NULL; // check_function - указатель на функцию проверки
        cout << "\nВыберите фильтрацию:\n";
        cout << "1) Вывести все товары в категории «Промтовары»\n";
        cout << "2) Вывести все товары стоимостью выше 100 рублей\n";
        cout << "\nВаш выбор: ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item) {
        case 1:
            check_function = check_GoodsSubscription_by_promtovari; // Фильтрация по категории
            cout << "***** Товары в категории «Промтовары» *****\n\n";
            break;
        case 2:
            check_function = check_GoodsSubscription_by_price; // Фильтрация по цене
            cout << "***** Товары стоимостью выше 100 рублей *****\n\n";
            break;
        default:
            throw "Неверный выбор!";
        }
        if (check_function) {
            int new_size;
            GoodsSubscription** filtered = filter(subscriptions, size, check_function, new_size);
            for (int i = 0; i < new_size; i++) {
                output(filtered[i]);
            }
            delete[] filtered;
        }
        for (int i = 0; i < size; i++) {
            delete subscriptions[i];
        }
    }
    catch (const char* error) {
        cout << error << '\n';
    }
    return 0;
}
