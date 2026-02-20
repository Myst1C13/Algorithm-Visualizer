#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <limits>
#include "Algorithms.h"

void clear() { std::cout << "\033[H\033[J"; }

void draw(const std::vector<int>& arr, int a, int b, bool swap, std::string msg) {
    clear();
    std::string color = swap ? "\033[1;31m" : "\033[1;36m"; 
    std::string reset = "\033[0m";

    std::cout << "==========================================\n";
    std::cout << " STATUS: " << color << msg << reset << "\n";
    std::cout << "==========================================\n\n";
    
    for (int i = 0; i < (int)arr.size(); i++) {
        if (i == a || i == b) 
            std::cout << color << "[" << arr[i] << "]" << reset << " "; 
        else 
            std::cout << " " << arr[i] << "  ";
    }
    std::cout << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
}

int main() {
    std::vector<int> data;
    int mode, choice;

    clear();
    std::cout << "--- Step 1: Data Setup ---\n1. Random\n2. Custom\n> ";
    std::cin >> mode;

    if (mode == 1) {
        int s; std::cout << "Size: "; std::cin >> s;
        std::random_device rd; std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 99);
        for(int i=0; i<s; i++) data.push_back(dis(gen));
    } else {
        int n, v; std::cout << "Size: "; std::cin >> n;
        for(int i=0; i<n; i++) { std::cin >> v; data.push_back(v); }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n--- Step 2: Algorithm ---\n1. Bubble\n2. Insertion\n3. Quick\n> ";
    std::cin >> choice;

    if (choice == 1) Algorithms::bubbleSort(data, draw);
    else if (choice == 2) Algorithms::insertionSort(data, draw);
    else if (choice == 3) Algorithms::quickSort(data, 0, (int)data.size()-1, draw);

    std::cout << "\n\033[1;32m[SUCCESS] Sorted Result: \033[0m";
    for (int x : data) std::cout << x << " ";
    std::cout << "\n\n";
    return 0;
}