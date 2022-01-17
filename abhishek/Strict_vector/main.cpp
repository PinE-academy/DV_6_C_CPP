#include <iostream>
#include<stdexcept>
using namespace std;

template <typename T>
class MyVector {
private:
    T *arr;
    int capacity;
    int arrSize;
public:
    MyVector() {
        arr = new T[10];
        capacity = 10;
        arrSize = 0;
    }
    MyVector(int n) {
        arr = new T[n];
        capacity = n;
        arrSize = 0;
    }
    void push_back(T val) {
        if (arrSize == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0 ; i < capacity ; i++) {
                temp[i] = arr[i];
            }
            delete [] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[arrSize++] = val;
    }
    void pop_back() {
        arrSize--;
    }
    int size() {
        return arrSize;
    }
    T operator[](int index) {
        if (index >= arrSize) {
            throw invalid_argument("Array index out of bounds");
            exit(1);
        }
        return  arr[index];
    }
};
int main() {
    int n = 10;
    MyVector<string> vt(n);
    for (int i = 0 ; i < n ; i++) {
        vt.push_back("Hello PinE ");
    }
    for (int i = 0 ; i < n ; i++) {
        cout << vt[i] << " ";
    }
    return 0;
}