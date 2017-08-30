// Test initializers.
#include"week8_516413990003.h"

int main()
{
    int arr[6] = {2, 3, 3, 4, 3, 5};
    List list1(arr, 6);
    cout << list1.length() << endl;
    list1.printAll();

    vector<int> vec(10, 233);
    List list2(vec);
    cout << list2.length() << endl;
    list2.printAll();

    return 0;
}
