#include <iostream>

using namespace std;

int arr[50];
int n = -1;

void down_heapify(int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        down_heapify(largest);
    }
}

void up_heapify(int i) {
    int parent = (i-1)/2;
    if(parent >= 0 && arr[parent] < arr[i]) {
        swap(arr[parent], arr[i]);
        up_heapify(parent);
    }
}

void insert(int num) {
    n++;
    arr[n] = num;
    up_heapify(n);
}

void remove_max() {
    arr[0] = arr[n];
    n--;
    down_heapify(0);
}

void remove(int i) {
    arr[i] = arr[0] + 1;
    up_heapify(i);
    remove_max();
}

void change_priority(int p, int i) {
    int old_p = arr[i];
    arr[i] = p;
    if(p > old_p)
        up_heapify(i);
    else if(p < old_p)
        down_heapify(i);
}

void heapSort(int arr[]) {

    for(int i = n - 1; i >= 0; i--)
        down_heapify(i);

    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        down_heapify(0);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main() {


  
    heapSort(arr); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 

    return 0;
}