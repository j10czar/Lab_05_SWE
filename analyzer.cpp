
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "StringData.h"
using std::string, std::cin, std::vector, std::cout;

int linear_search(vector<string> container, string element) {
    for (int i; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

int binary_searchy(vector<string> container, string element) {
    int max_index = container.size() - 1;
    int min_index = 0;
    while (min_index <= max_index) {
        int midpoint = int((min_index + (max_index - min_index) / 2));
        if (container[midpoint] == element) {
            return midpoint;
        }else if (element < container[midpoint]) {
            max_index = midpoint-1;
        
        } else {
            min_index = midpoint+1;
        }
    }
    return -1;
}

int main() {

    std::string target = "mzzzz";
    vector<string> stringDataSet = getStringData();
    std::chrono::time_point<std::chrono::system_clock>start, end;

    // binary search
    start = std::chrono::system_clock::now();
    cout << "found"<<target<<" at index; " << binary_searchy(getStringData(), target) << "\n";
    end = std::chrono::system_clock::now();
    std::cout<< "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";

    // linear search
    start = std::chrono::system_clock::now();
    cout << "found"<<target<<" at index; " << linear_search(getStringData(), target) << "\n";
    end = std::chrono::system_clock::now();
    std::cout<< "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";



}
