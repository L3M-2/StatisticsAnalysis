#include "Calculation.h"

vector<int> sort(vector<int> &numbers) {        // use algorithm of insertion sort
    for (size_t i = 1; i < numbers.size(); ++i) {
        int key = numbers[i];                   //value of current element
        int j = i-1;                            //counter of inner cycle
        while (j > -1 && numbers[j] > key) {
            numbers[j+1] = numbers[j];
            j--;
        }
        numbers[j+1] = key;
    }
    
    return numbers;
}


//template <class T>
//T min(const vector<T> &numbers) {
//    if(numbers.empty())
//        throw "exeption catch: 'min' from empty array";
//    T smallest = numbers.at(0);
//        for (auto num: numbers)
//            if (num < smallest)
//                smallest = num;
//    return smallest;
//}

int min(const vector<int> &numbers) {
    if(numbers.empty())
        throw "exeption catch: 'min' from empty array";
    int smallest = numbers.at(0);
        for (auto num: numbers)
            if (num < smallest)
                smallest = num;
    return smallest;
}


int max(const vector<int> &numbers) {
    if(numbers.empty())
        throw "exeption catch: 'max' from empty array";
    int largest = numbers.at(0);
        for (auto num: numbers)
            if (num > largest)
                largest = num;
    return largest;
}


double mean(const vector<int> &numbers){
    if(numbers.empty())
        throw "exeption catch: 'mean' from empty array";
    int total {};
        for (auto num: numbers)
            total += num;
    return static_cast<double>(total)/numbers.size();
}


double median(const vector<int> &sorted_numbers){
    if(sorted_numbers.empty())
        throw "exeption catch: 'median' from empty array";
    size_t size = sorted_numbers.size();
    if(size % 2 == 1)
        return sorted_numbers.at(size/2);
    else 
        return static_cast<double>(sorted_numbers.at(size/2-1) + sorted_numbers.at(size/2)) / 2;
}


double variance(const vector<int> &numbers, double mean) {
    if(numbers.empty())
        throw "exeption catch: 'variance' from empty array";

    double accumulator {};
    for(size_t i{0}; i < numbers.size(); i++)
        accumulator += pow(numbers.at(i) - mean, 2);
    
    return accumulator / numbers.size();
}


// overloading
double std_deviation(double variance) { // way through mean
    return sqrt(variance);
}


// overloading
double std_deviation(const vector<int> &numbers) { // way without mean
    int accumulator1{0};
    int accumulator2{0};
    for(int x: numbers) {
        accumulator1 += x * x;
        accumulator2 += x;
    }

    return sqrt( static_cast<double>(accumulator1) / numbers.size() -
                 static_cast<double>(accumulator2 * accumulator2) / pow(numbers.size(), 2) );
}
    
    
double str_score(int x, double mean, double std_deviation){
    return (x - mean) / std_deviation;
}