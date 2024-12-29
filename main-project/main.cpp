#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

#include "sort.h"
#include "goods_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(const GoodsSubscription* subscription) {
    if (subscription) {
        std::cout << "Категория: " << subscription->category.categoryofgoods << '\n';
        std::cout << "Название товара: " << subscription->naming.nameofgoods << '\n';
        std::cout << "Цена товара: " << subscription->price.money << " руб.\n";
        std::cout << "Количество на складе: " << subscription->quantity << '\n';
        std::cout << '\n';
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #10. Каталог товаров\n";
    cout << "Author: Egor Orlov\n";
    cout << "\n";

    GoodsSubscription* subscriptions[MAX_FILE_ROWS_COUNT] = { nullptr };
    int size = 0;

    try {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++) {
            output(subscriptions[i]);
        }

        bool (*check_function)(GoodsSubscription*) = nullptr;
        cout << "\nВыберите фильтрацию:\n";
        cout << "1) Вывести все товары в категории «Промтовары»\n";
        cout << "2) Вывести все товары стоимостью выше 100 рублей\n";
        cout << "\nВаш выбор: ";
        int item;
        cin >> item;
        cout << '\n';

        cout << "\nВыберите метод сортировки:\n";
        cout << "1) Сортировка выбором (Selection sort)\n";
        cout << "2) Сортировка слиянием (Merge sort)\n";
        cout << "\nВведите номер выбранного пункта: ";

        int item_sort_method;
        cin >> item_sort_method;

        if (item_sort_method != 1 && item_sort_method != 2) {
            throw std::runtime_error("Некорректный номер пункта сортировки!");
        }

        cout << "\nВыберите критерий сортировки:\n";
        cout << "1) По убыванию количества товара на складе\n";
        cout << "2) По возрастанию категории товара, а в рамках одной категории по убыванию стоимости\n";
        cout << "\nВведите номер выбранного пункта: ";

        int item_criteria;
        cin >> item_criteria;

        if (item_criteria != 1 && item_criteria != 2) {
            throw std::runtime_error("Некорректный номер критерия сортировки!");
        }

        cout << '\n';

        switch (item) {
        case 1:
            check_function = check_GoodsSubscription_by_promtovari;
            cout << "***** Товары в категории «Промтовары» *****\n\n";
            break;
        case 2:
            check_function = check_GoodsSubscription_by_price;
            cout << "***** Товары стоимостью выше 100 рублей *****\n\n";
            break;
        default:
            throw std::runtime_error("Неверный выбор!");
        }

        if (check_function) {
            int new_size;
            GoodsSubscription** filtered = filter(subscriptions, size, check_function, new_size);
            for (int i = 0; i < new_size; i++) {
                output(filtered[i]);
            }
            delete[] filtered;
        }

        GoodsSubscription* sorted[MAX_FILE_ROWS_COUNT];
        for (int i = 0; i < size; i++) {
            sorted[i] = subscriptions[i];
        }

        if (item_sort_method == 1) {
            if (item_criteria == 1) {
                selectionSort_DownQuantity(sorted, size);
            } else if (item_criteria == 2) {
                selectionSort_UpCategory(sorted, size);
                int start = 0;
                while (start < size) {
                    int end = start;
                    while (end + 1 < size && sorted[end]->category.categoryofgoods == sorted[end + 1]->category.categoryofgoods) {
                        end++;
                    }
                    selectionSort_DownPrice(sorted, start, end);
                    start = end + 1;
                }
            }
        } else if (item_sort_method == 2) {
            if (item_criteria == 1) {
                mergeSort_DownCount(sorted, 0, size - 1);
            } else if (item_criteria == 2) {
                mergeSort_UpCategory(sorted, 0, size - 1);
                int start = 0;
                while (start < size) {
                    int end = start;
                    while (end + 1 < size && sorted[end]->category.categoryofgoods == sorted[end + 1]->category.categoryofgoods) {
                        end++;
                    }
                    mergeSort_DownPrice(sorted, start, end);
                    start = end + 1;
                }
            }
        }

        cout << "***** Отсортированные товары *****\n";
        for (int i = 0; i < size; i++) {
            output(sorted[i]);
        }

    } catch (const std::runtime_error& error) {
        cout << error.what() << '\n';
    }

    for (int i = 0; i < size; i++) {
        delete subscriptions[i];
    }

    return 0;
}
