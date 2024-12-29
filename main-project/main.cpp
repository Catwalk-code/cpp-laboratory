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
        std::cout << "���������: " << subscription->category.categoryofgoods << '\n';
        std::cout << "�������� ������: " << subscription->naming.nameofgoods << '\n';
        std::cout << "���� ������: " << subscription->price.money << " ���.\n";
        std::cout << "���������� �� ������: " << subscription->quantity << '\n';
        std::cout << '\n';
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #10. ������� �������\n";
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
        cout << "\n�������� ����������:\n";
        cout << "1) ������� ��� ������ � ��������� ������������\n";
        cout << "2) ������� ��� ������ ���������� ���� 100 ������\n";
        cout << "\n��� �����: ";
        int item;
        cin >> item;
        cout << '\n';

        cout << "\n�������� ����� ����������:\n";
        cout << "1) ���������� ������� (Selection sort)\n";
        cout << "2) ���������� �������� (Merge sort)\n";
        cout << "\n������� ����� ���������� ������: ";

        int item_sort_method;
        cin >> item_sort_method;

        if (item_sort_method != 1 && item_sort_method != 2) {
            throw std::runtime_error("������������ ����� ������ ����������!");
        }

        cout << "\n�������� �������� ����������:\n";
        cout << "1) �� �������� ���������� ������ �� ������\n";
        cout << "2) �� ����������� ��������� ������, � � ������ ����� ��������� �� �������� ���������\n";
        cout << "\n������� ����� ���������� ������: ";

        int item_criteria;
        cin >> item_criteria;

        if (item_criteria != 1 && item_criteria != 2) {
            throw std::runtime_error("������������ ����� �������� ����������!");
        }

        cout << '\n';

        switch (item) {
        case 1:
            check_function = check_GoodsSubscription_by_promtovari;
            cout << "***** ������ � ��������� ������������ *****\n\n";
            break;
        case 2:
            check_function = check_GoodsSubscription_by_price;
            cout << "***** ������ ���������� ���� 100 ������ *****\n\n";
            break;
        default:
            throw std::runtime_error("�������� �����!");
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

        cout << "***** ��������������� ������ *****\n";
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
