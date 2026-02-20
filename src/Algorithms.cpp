#include "Algorithms.h"
#include <algorithm>

void Algorithms::bubbleSort(std::vector<int>& arr, StepCallback onStep) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            onStep(arr, j, j + 1, false, "Comparing...");
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                onStep(arr, j, j + 1, true, "Swapped!");
            }
        }
    }
}

void Algorithms::insertionSort(std::vector<int>& arr, StepCallback onStep) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            onStep(arr, j, j + 1, false, "Comparing...");
            arr[j + 1] = arr[j];
            onStep(arr, j, j + 1, true, "Shifting...");
            j--;
        }
        arr[j + 1] = key;
        onStep(arr, j + 1, j + 1, true, "Inserted key");
    }
}

int Algorithms::partition(std::vector<int>& arr, int low, int high, StepCallback onStep) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        onStep(arr, j, high, false, "Comparing with pivot");
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            onStep(arr, i, j, true, "Moving smaller element");
        }
    }
    std::swap(arr[i + 1], arr[high]);
    onStep(arr, i + 1, high, true, "Pivot placed");
    return (i + 1);
}

void Algorithms::quickSort(std::vector<int>& arr, int low, int high, StepCallback onStep) {
    if (low < high) {
        int pi = partition(arr, low, high, onStep);
        quickSort(arr, low, pi - 1, onStep);
        quickSort(arr, pi + 1, high, onStep);
    }
}