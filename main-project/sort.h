#include "goods_subscription.h"
#include "constants.h"
#include <iostream>
#include <iomanip>
using namespace std;
void selectionSort_DownQuantity(GoodsSubscription* array[], int size);
void selectionSort_UpCategory(GoodsSubscription* array[], int size);
void selectionSort_DownPrice(GoodsSubscription* array[], int left, int right);
void merge_DownCount(GoodsSubscription* array[], int left, int mid, int right);
void mergeSort_DownCount(GoodsSubscription* array[], int left, int right);
void merge_UpCategory(GoodsSubscription* array[], int left, int mid, int right);
void mergeSort_UpCategory(GoodsSubscription* array[], int left, int right);
void merge_DownPrice(GoodsSubscription* array[], int left, int mid, int right);
void mergeSort_DownPrice(GoodsSubscription* array[], int left, int right);