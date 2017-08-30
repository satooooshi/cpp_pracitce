// Test find() function.

int main()
{
    int arr[6] = {2, 3, 3, 4, 3, 5};
    List list1(arr, 6);
    cout << list1.find(2) << endl;
    cout << list1.find(3) << endl;
    cout << list1.find(100) << endl;
    cout << list1.find(5) << endl;
    
    return 0;
}
