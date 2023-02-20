#include<cmath>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include "sorting.cxx"

using namespace std;

double mean(vector<double> v) {
    double a = 0;
    for(int i = 0; i < v.size(); i++) {
        a += v[i];
    }
    return a/(v.size());
}

double median(vector<double> v) {
    int n = v.size();
    quickSort(v, 0, v.size()-1);
    if (n % 2 == 1) {
        return v[floor(n/2)-1];
    } 
    else {
        return (v[n/2-1] + v[floor(n/2)])/2.0;
    }
}

double stdev(vector<double> v) {
    double a = 0;
    for (double i: v) {
        a += pow(i - mean(v), 2);
    }
    return sqrt(a/(v.size()-1));
}
