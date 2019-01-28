#include <vector>
#include <math.h>  // sqrt, pow

using std::vector;

vector<int> sort(vector<int> &numbers);
int min(const vector<int> &numbers);
int max(const vector<int> &numbers);
double mean(const vector<int> &numbers);
double median(const vector<int> &sorted_numbers);
double variance(const vector<int> &numbers, double mean);
double std_deviation(double variance);
double std_deviation(const vector<int> &numbers);
double str_score(int x, double mean, double std_deviation);

//template <class T>
//T min(const vector<T> &numbers);
