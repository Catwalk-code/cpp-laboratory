#ifndef GOODS_SUBSCRIPTION_H
#define GOODS_SUBSCRIPTION_H

#include <iostream>
#include <string>
#include "constants.h"

// ��������� ��� �������� ���� ������
struct Price {
    float money; // ������� ��������������� �����
};

// ��������� ��� �������� ��������� ������
struct Category {
    std::string categoryofgoods; // ��������� ������ (������ ��� ��������)
};

// ��������� ��� �������� �������� ������
struct Naming {
    char nameofgoods[MAX_STRING_SIZE]; // �������� ������ (����� ��������� �������)
};

// �������� ��������� ��� �������� �� ������
struct GoodsSubscription {
    Price price;             // ���� ������
    int quantity;            // ���������� ������ �� ������ (����� ��������������� �����)
    Category category;       // ��������� ������
    Naming naming;           // �������� ������
};

#endif 
