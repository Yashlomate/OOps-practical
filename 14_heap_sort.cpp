#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify(int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest]) 
            largest = left;

        if (right < n && heap[right] > heap[largest]) 
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(n, largest);
        }
    }

    void heapSort() {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(n, i);
        }

        for (int i = n - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            heapify(i, 0);
        }
    }

    void printHeap() {
        for (int val : heap) 
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;
    vector<int> arr = {5, 1, 10, 3, 7, 8, 2};

    for (int val : arr) {
        maxHeap.insert(val);
    }

    maxHeap.heapSort();
    maxHeap.printHeap();

    return 0;
}
