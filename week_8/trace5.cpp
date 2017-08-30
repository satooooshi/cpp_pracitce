// Test split() function. (Invalid split)
#include"week8_516413990003.h"
int main()
{
    int arr[6] = {2, 3, 3, 4, 3, 5};
    List list1(arr, 6);
    List list2(arr + 1, 4);
    cout << list1.split(-1, list2) << endl;
    cout << list1.split(20, list2) << endl;
    cout << list1.length() << endl;
    list1.printAll();
    cout << list2.length() << endl;
    list2.printAll();

    return 0;
}
