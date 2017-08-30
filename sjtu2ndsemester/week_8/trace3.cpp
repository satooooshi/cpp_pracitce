// Test remove() function.
#include"week8_516413990003.h"
int main()
{
    int arr[6] = {2, 3, 3, 4, 3, 5};
    List list1(arr, 6);
    cout << list1.remove(2) << endl;
    cout << list1.length() << endl;
    cout << list1.remove(100) << endl;
    cout << list1.length() << endl;
    cout << list1.remove(3) << endl;
    list1.printAll();

    return 0;
}
