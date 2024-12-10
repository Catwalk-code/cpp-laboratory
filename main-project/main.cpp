#include <iostream>
#include <iomanip>
using namespace std;

#include "book_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(book_subscription* subscriptions)
{
 /********** ����� �������� **********/
            cout << "��������........: ";
            // ����� �������
            cout << subscriptions->reader.last_name << " ";
            // ����� ������ ����� �����
            cout << subscriptions->reader.first_name[0] << ". ";
            // ����� ������ ����� ��������
            cout << subscriptions->reader.middle_name[0] << ".";
            cout << '\n';
            /********** ����� ����� **********/
            cout << "�����...........: ";
            // ����� ������� ������
            cout << subscriptions->author.last_name << " ";
            // ����� ������ ����� ����� ������
            cout << subscriptions->author.first_name[0] << ". ";
            // ����� ������ ����� �������� ������
            cout << subscriptions->author.middle_name[0] << ".";
            cout << ", ";
            // ����� ��������
            cout << '"' << subscriptions->title << '"';
            cout << '\n';
            /********** ����� ���� ������ **********/
            // ����� ����
            cout << "���� ������.....: ";
            cout << setw(4) << setfill('0') << subscriptions->start.year << '-';
            // ����� ������
            cout << setw(2) << setfill('0') << subscriptions->start.month << '-';
            // ����� �����
            cout << setw(2) << setfill('0') << subscriptions->start.day;
            cout << '\n';
            /********** ����� ���� �������� **********/
            // ����� ����
            cout << "���� ��������...: ";
            cout << setw(4) << setfill('0') << subscriptions->finish.year << '-';
            // ����� ������
            cout << setw(2) << setfill('0') << subscriptions->finish.month << '-';
            // ����� �����
            cout << setw(2) << setfill('0') << subscriptions->finish.day;
            cout << '\n';
            cout << '\n';
}


int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #10. ������� �������\n";
    cout << "Author: Egor Orlov\n";
    book_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** ������������ ��������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            output(subscriptions[i]);
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
bool (*check_function)(book_subscription*) = NULL; // check_function -    ,    bool,
		                                                   //        book_subscription*
		cout << "\n     :\n";
		cout << "1)       \n";
		cout << "2)        2015- \n";
		cout << "3)   ,      \n";
		cout << "\n   : ";
		int item;
		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:
			check_function = check_book_subscription_by_author; //       
			cout << "*****        *****\n\n";
			break;
		case 2:
			check_function = check_book_subscription_by_date; //       
			cout << "*****        2015-  *****\n\n";
			break;
		
		default:
			throw "  ";
		}
		if (check_function)
		{
			int new_size;
			book_subscription** filtered = filter(subscriptions, size, check_function, new_size);
			for (int i = 0; i < new_size; i++)
			{
				output(filtered[i]);
			}
			delete[] filtered;
		}
		for (int i = 0; i < size; i++)
		{
			delete subscriptions[i];
		}
	}
	catch (const char* error)
	{
		cout << error << '\n';
	}
	return 0;
}
