#ifndef FILTER_H
#define FILTER_H

#include "goods_subscription.h"

GoodsSubscription** filter(GoodsSubscription* array[], int size, bool (*check)(GoodsSubscription* element), int& result_size);



bool check_GoodsSubscription_by_promtovari(GoodsSubscription* element);




bool check_GoodsSubscription_by_price(GoodsSubscription* element);


#endif
