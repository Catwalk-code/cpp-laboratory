#include <iostream>
#include <iomanip>
using namespace std;

#include "goods_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(const GoodsSubscription* subscription) {
    // ����� ���������� � ������
    std::cout << "���������: " << subscription->category.categoryofgoods << '\n';

    // ����� �������� ������
    std::cout << "�������� ������: " << subscription->naming.nameofgoods << '\n';

    // ����� ���� ������
    std::cout << "���� ������: " << subscription->price.money << " ���.\n";

    // ����� ���������� ������
    std::cout << "���������� �� ������: " << subscription->quantity << '\n';

    std::cout << '\n'; // ������ ������ ��� ���������� �������
}

bool check_Category(GoodsSubscription* subscription) {
    return subscription->category.categoryofgoods == "����������";
}

bool check_Price(GoodsSubscription* subscription) {
    return subscription->price.money > 100;
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #10. ������� �������\n";
    cout << "Author: Egor Orlov\n";
    cout << "\n";
    GoodsSubscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++) {
            output(subscriptions[i]);
        }

        bool (*check_function)(GoodsSubscription*) = NULL; // check_function - ��������� �� ������� ��������
        cout << "\n�������� ����������:\n";
        cout << "1) ������� ��� ������ � ��������� ������������\n";
        cout << "2) ������� ��� ������ ���������� ���� 100 ������\n";
        cout << "\n��� �����: ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item) {
        case 1:
            check_function = check_GoodsSubscription_by_promtovari; // ���������� �� ���������
            cout << "***** ������ � ��������� ������������ *****\n\n";
            break;
        case 2:
            check_function = check_GoodsSubscription_by_price; // ���������� �� ����
            cout << "***** ������ ���������� ���� 100 ������ *****\n\n";
            break;
        default:
            throw "�������� �����!";
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
