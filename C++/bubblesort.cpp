#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &arr) {
    int n = static_cast<int>(arr.size());
    while (n > 0) {
        int lastModifiedIndex = 0;
        for (int currentIndex = 1; currentIndex < n; currentIndex++) {
            // if the item at the previous index is greater than the item at the `currentIndex`, swap them
            if (arr[currentIndex - 1] > arr[currentIndex]) {
                // swap
                int temp = arr[currentIndex - 1];
                arr[currentIndex - 1] = arr[currentIndex];
                arr[currentIndex] = temp;
                // save the index that was modified
                lastModifiedIndex = currentIndex;
            }
        }
        // save the last modified index so we know not to iterate past it since all proceeding values are sorted
        n = lastModifiedIndex;
    }
}

int main() {
    std::vector<int> arr = {12, 11, 15, 10, 9, 1, 2, 3, 13, 14, 4, 5, 6, 7, 8};
    bubbleSort(arr);
    for (int i; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
}
