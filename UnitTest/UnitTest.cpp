#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../main-project/goods_subscription.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace unittestproject
{
	//        
	//             ,
	//   ,     
	GoodsSubscription* build_subscription(double price, string category)
	{
		GoodsSubscription* subscription = new GoodsSubscription;
		subscription->price.money = price;
		subscription->category.categoryofgoods = category;
		return subscription;
	}

	//       
	void delete_subscription(GoodsSubscription* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		TEST_METHOD(TestMethod1)     
		{
			GoodsSubscription* subscriptions[9];
			subscriptions[0] = build_subscription(120.5,"����������");
			subscriptions[1] = build_subscription(110.1,"�������");
			subscriptions[2] = build_subscription(123.5,"��������");
			subscriptions[3] = build_subscription(100.6,"��������");
			subscriptions[4] = build_subscription(1.1,"�������");
			subscriptions[5] = build_subscription(1.6,"��������");
			subscriptions[6] = build_subscription(2.8,"�������");
			subscriptions[7] = build_subscription(3.9,"����������");
			subscriptions[8] = build_subscription(6.7,"����������");
			Assert::AreEqual(114., process(subscriptions, 9, "�������"),0.01);
			delete_subscription(subscriptions, 9);
		}
		TEST_METHOD(TestMethod2)
		{
			GoodsSubscription* subscriptions[9];
			subscriptions[0] = build_subscription(120.5, "����������");
			subscriptions[1] = build_subscription(110.1, "�������");
			subscriptions[2] = build_subscription(123.5, "��������");
			subscriptions[3] = build_subscription(100.6, "��������");
			subscriptions[4] = build_subscription(1.1, "�������");
			subscriptions[5] = build_subscription(1.6, "��������");
			subscriptions[6] = build_subscription(2.8, "�������");
			subscriptions[7] = build_subscription(3.9, "����������");
			subscriptions[8] = build_subscription(6.7, "����������");
			Assert::AreEqual(131.1, process(subscriptions, 9, "����������"), 0.01);
			delete_subscription(subscriptions, 9);
		}

		TEST_METHOD(TestMethod3)
		{
			GoodsSubscription* subscriptions[9];
			subscriptions[0] = build_subscription(120.5, "����������");
			subscriptions[1] = build_subscription(110.1, "�������");
			subscriptions[2] = build_subscription(123.5, "��������");
			subscriptions[3] = build_subscription(100.6, "��������");
			subscriptions[4] = build_subscription(1.1, "�������");
			subscriptions[5] = build_subscription(1.6, "��������");
			subscriptions[6] = build_subscription(2.8, "�������");
			subscriptions[7] = build_subscription(3.9, "����������");
			subscriptions[8] = build_subscription(6.7, "����������");
			Assert::AreEqual(125.1, process(subscriptions, 9, "��������"), 0.01);
			delete_subscription(subscriptions, 9);
		}
		TEST_METHOD(TestMethod4)
		{
			GoodsSubscription* subscriptions[9];
			subscriptions[0] = build_subscription(120.5, "����������");
			subscriptions[1] = build_subscription(110.1, "�������");
			subscriptions[2] = build_subscription(123.5, "��������");
			subscriptions[3] = build_subscription(100.6, "��������");
			subscriptions[4] = build_subscription(1.1, "�������");
			subscriptions[5] = build_subscription(1.6, "��������");
			subscriptions[6] = build_subscription(2.8, "�������");
			subscriptions[7] = build_subscription(3.9, "����������");
			subscriptions[8] = build_subscription(6.7, "����������");
			Assert::AreEqual(100.6, process(subscriptions, 9, "��������"), 0.01);
			delete_subscription(subscriptions, 9);
		}
	};
}
