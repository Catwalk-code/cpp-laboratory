#include <iostream>

using namespace std;

int main()
{
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #10. Каталог товаров\n";
    cout << "Author: Egor Orlov\n";
    book_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->reader.last_name << '\n';
            cout << subscriptions[i]->reader.first_name << '\n';
            cout << subscriptions[i]->reader.middle_name << '\n';
            cout << subscriptions[i]->finish.day << ' ';
            cout << subscriptions[i]->finish.month << ' ';
            cout << subscriptions[i]->finish.year << '\n';
            cout << subscriptions[i]->start.day << ' ';
            cout << subscriptions[i]->start.month << ' ';
            cout << subscriptions[i]->start.year << '\n';
            cout << subscriptions[i]->author.last_name << '\n';
            cout << subscriptions[i]->author.first_name << '\n';
            cout << subscriptions[i]->author.middle_name << '\n';
            cout << subscriptions[i]->title << '\n';
            cout << '\n';
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
