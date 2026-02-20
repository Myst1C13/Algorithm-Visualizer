#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <functional>
#include <string>

using StepCallback = std::function<void(const std::vector<int>&, int, int, bool, std::string)>;

class Algorithms {
public:
    static void bubbleSort(std::vector<int>& arr, StepCallback onStep);
    static void insertionSort(std::vector<int>& arr, StepCallback onStep);
    static void quickSort(std::vector<int>& arr, int low, int high, StepCallback onStep);
private:
    static int partition(std::vector<int>& arr, int low, int high, StepCallback onStep);
};

#endif