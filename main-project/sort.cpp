#include "sort.h"
#include <algorithm>

// Сортировка выбором по убыванию количества товара на складе
void selectionSort_DownQuantity(GoodsSubscription* arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j]->quantity > arr[maxIdx]->quantity) {
                maxIdx = j;
            }
        }
        swap(arr[i], arr[maxIdx]);
    }
}

void selectionSort_UpCategory(GoodsSubscription* arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j]->category.categoryofgoods < arr[minIdx]->category.categoryofgoods) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void selectionSort_DownPrice(GoodsSubscription* arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        int maxIdx = i;
        for (int j = i + 1; j <= end; j++) {
            if (arr[j]->price.money > arr[maxIdx]->price.money) {
                maxIdx = j;
            }
        }
        swap(arr[i], arr[maxIdx]);
    }
}

void merge(GoodsSubscription* arr[], int left, int mid, int right, bool (*compare)(GoodsSubscription*, GoodsSubscription*)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    GoodsSubscription** leftArr = new GoodsSubscription * [n1];
    GoodsSubscription** rightArr = new GoodsSubscription * [n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(leftArr[i], rightArr[j])) {
            arr[k++] = leftArr[i++];
        }
        else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort_DownCount(GoodsSubscription* arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort_DownCount(arr, left, mid);
        mergeSort_DownCount(arr, mid + 1, right);

        merge(arr, left, mid, right, [](GoodsSubscription* a, GoodsSubscription* b) {
            return a->quantity > b->quantity;
            });
    }
}

void mergeSort_UpCategory(GoodsSubscription* arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort_UpCategory(arr, left, mid);
        mergeSort_UpCategory(arr, mid + 1, right);

        merge(arr, left, mid, right, [](GoodsSubscription* a, GoodsSubscription* b) {
            return a->category.categoryofgoods < b->category.categoryofgoods;
            });
    }
}

void mergeSort_DownPrice(GoodsSubscription* arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergeSort_DownPrice(arr, start, mid);
        mergeSort_DownPrice(arr, mid + 1, end);

        merge(arr, start, mid, end, [](GoodsSubscription* a, GoodsSubscription* b) {
            return a->price.money > b->price.money;
            });
    }
}