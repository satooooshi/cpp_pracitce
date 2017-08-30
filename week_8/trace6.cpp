// Test combine() function.
#include"week8_516413990003.h"
int main()
{
    int arr[6] = {2, 3, 3, 4, 3, 5};
    List list1(arr, 6);
    List list2(arr + 3, 2);
    list1.combine(list2);
    cout << list1.length() << endl;
    list1.printAll();

    return 0;
}
