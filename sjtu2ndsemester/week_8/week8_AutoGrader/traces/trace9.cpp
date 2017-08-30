// Complex comprehensive test with split() and combine().

int main()
{
    int arr[6] = {2, 3, 3, 4, 3, 5};
    vector<int> vec(arr, arr + 3);

    List list1(arr + 3, 1); // 4
    List list2(vec); // 2 3 3
    List list3(arr + 1, 5); // 3 3 4 3 5
    List list4(arr, 1); // 2
    List list5((int*)NULL, 0);
    List list6((int*)NULL, 0);

    list1.combine(list2); // 4 2 3 3
    list3.combine(list4); // 3 3 4 3 5 2

    list1.printAll();
    cout << list1.remove(3) << endl; // 4 2
    cout << list1.insert(0, 7) << endl; // 7 4 2
    cout << list1.length() << endl;

    list3.printAll();
    cout << list3.split(20, list6) << endl;
    cout << list3.insert(3, 7) << endl; // 3 3 4 7 3 5 2
    cout << list3.remove(4) << endl; // 3 3 7 3 5 2

    cout << list3.split(4, list5) << endl;
    list3.printAll(); // 3 3 7 3 5
    list5.printAll(); // 2
    cout << list3.find(5) << endl;

    list1.combine(list5); // 7 4 2 2
    list1.combine(list3); // 7 4 2 2 3 3 7 3 5
    cout << list1.split(-1, list6) << endl;
    list1.printAll();
    cout << list1.find(3) << endl;

    cout << list1.split(0, list6) << endl;
    cout << list1.length() << endl;
    list6.printAll(); // 4 2 2 3 3 7 3 5

    return 0;
}
