// Comprehensive test without split() and combine(). A more complex one.

int main()
{
    int arr[6] = {2, 3, 3, 4, 3, 5};
    vector<int> vec(arr, arr + 6);
    List list1(vec);
    cout << list1.insert(2, 4) << endl;
    list1.printAll();
    cout << list1.length() << endl;
    cout << list1.find(4) << endl;
    cout << list1.insert(10, 2) << endl;
    cout << list1.remove(3) << endl;
    cout << list1.find(6) << endl;
    list1.printAll();
    cout << list1.insert(4, 2) << endl;
    cout << list1.remove(1) << endl;
    cout << list1.length() << endl;
    cout << list1.remove(2) << endl;
    list1.printAll();
    cout << list1.insert(-2, 2) << endl;
    cout << list1.find(5) << endl;
    cout << list1.remove(5) << endl;
    cout << list1.length() << endl;
    cout << list1.insert(0, 7) << endl;
    list1.printAll();

    return 0;
}
