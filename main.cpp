#include <iostream>
#include <vector>
#include <iomanip>
#include "Calculation.h"

using namespace std;

char get_selection();
void print_numbers(const vector<int> &numbers);
void print_mode(const vector<int> &sorted_numbers);
void print_std_scores(const vector<int> &numbers, double mean, double std_deviation);
void show_statistics(const vector<int> numbers);

//template <class T>
//T min(const vector<T> &numbers);
//
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

char get_selection() {
    char selection {};
    cin >> selection;
    return toupper(selection);
}


void print_numbers(const vector<int> &numbers) {
    if(numbers.empty())
        cout << "[] - the list is empty" << endl;
    else {
        cout << "[ ";
        for (auto num: numbers)
            cout << num << " ";
        cout << "]" << endl;
    }
}


void print_mode(const vector<int> &sorted_numbers) {
    if(sorted_numbers.empty()) 
        cout << "- (no values)" << endl;
    else {
        vector<int> values {sorted_numbers.at(0)};
        vector<int> frequencies {1};
        int count_fr {0};

        for(size_t i{1}; i < sorted_numbers.size(); i++)
            if(sorted_numbers.at(i) == sorted_numbers.at(i-1))
                frequencies.at(count_fr)++;
            else {
                values.push_back(sorted_numbers.at(i));
                frequencies.push_back(1);
                count_fr++;
            }
 
        int max_frequency = max(frequencies);
                
        bool no_mean = true;
        for(size_t i{0}; i < frequencies.size(); i++)
            if(frequencies.at(i) < max_frequency) {
                no_mean = false;
                break;
            }
                
        if(no_mean)
            cout << "- (all numbers have equal frequency = " << max_frequency << ")" << endl;
        else {
            for(size_t i{0}; i < frequencies.size(); i++)
                if(frequencies.at(i) == max_frequency)
                    cout << values.at(i) << " ";
            cout << " (" << max_frequency << " times)" << endl;
        }
    }
}


void print_std_scores(const vector<int> &numbers, double mean, double std_deviation) {
    if(numbers.empty())
        throw "exeption catch: 'standard score' from empty array";

    // output initial array
    cout << "[ ";
    for (auto num: numbers)
        printf("%3d     ", num);
    cout << "]" << endl;
    
    if(std_deviation == 0)
        cout << "- (since standart deviation = 0)" << endl; 
    else {
        // output corresponding standard score
        cout << "[ ";
        for (auto num: numbers)
            printf("%6.3f  ", str_score(num, mean, std_deviation));
        cout << "]" << endl; 
    }
}


void show_statistics(const vector<int> numbers) {
    if (numbers.empty())
        cout << "Array is empty, no statistics" << endl;
    else 
        try {
            vector<int> sorted_numbers {numbers};
            sort(sorted_numbers);
            
            cout << "Original array: "; print_numbers(numbers);
            cout << "Sorted array:   "; print_numbers(sorted_numbers);
            
            int _min = min(numbers);
            cout << "min number:     " << _min << endl;
            
            int _max = max(numbers);
            cout << "max number:     " << _max << endl;

            double _mean = mean(numbers);
            cout << "Mean:           " << _mean << endl;
            
            double _median = median(sorted_numbers);
            cout << "Median:         " << _median << endl;
            
            cout << "Mode:           "; print_mode(sorted_numbers);
            
            double _variance = variance(numbers, _mean);
            cout << "Variance:       " << _variance << endl;
            
            double _std_deviation = std_deviation(_variance);
            cout << "Std. deviation (way_1): " << _std_deviation << endl;
            
            double _std_deviation2 = std_deviation(numbers);
            cout << "Std. deviation (way_2): " << _std_deviation2 << endl;
            
            cout << endl;
            cout << "Sorted numbers and their standard scores (z-values):" << endl;
            print_std_scores(sorted_numbers, _mean, _std_deviation);
            
            cout << endl;
            cout << "Interquartile range (midspread or middle fifty):" << endl;
            int size = sorted_numbers.size();
            int quarter_size = size / 4;
            vector<int> interquartile_range( size - quarter_size * 2 );
            copy(sorted_numbers.begin() + quarter_size,
                 sorted_numbers.end() - quarter_size,
                 interquartile_range.begin() );
            print_numbers(interquartile_range);
                 
            cout << "Mean for interquartile range: " << mean(interquartile_range) << endl;
        } catch (const char* e_msg) {
            cout << e_msg;
        }
    cout << endl;
}

int main() {
    vector<int> numbers = {100,87,82,78,74,72,61,58};
    show_statistics(numbers);

    return 0;
}
