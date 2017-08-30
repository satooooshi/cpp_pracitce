// Test insert() function.
#include"week8_516413990003.h"
int main()
{
    int arr[6] = {2, 3, 3, 4, 3, 5};
    List list1(arr, 6);
    cout << list1.length() << endl;
    cout << list1.insert(1, 100) << endl;
    cout << list1.insert(0, 100) << endl;
    cout << list1.insert(-1, 100) << endl;
    cout << list1.length() << endl;
    cout << list1.insert(20, 100) << endl;
    list1.printAll();
    cout << list1.insert(8, 100) << endl;
    list1.printAll();

    return 0;
}
