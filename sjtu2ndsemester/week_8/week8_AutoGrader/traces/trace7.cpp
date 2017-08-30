// Comprehensive test without split() and combine(). A simple one.
// Same as the test case that is already provided in the homework document. 

int main()
{
    int arr[6] = {2, 3, 3, 4, 3, 5};
    List list1(arr, 6);
    list1.insert(3, 6);
    list1.printAll();
    cout << list1.remove(3) << endl;
    cout << list1.length() << endl;
    return 0;
}
