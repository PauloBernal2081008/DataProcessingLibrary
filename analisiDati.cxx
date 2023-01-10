#include<iostream>
#include<math.h>
#include<string>
#include "./lib/physics.cxx"

using namespace std;

double div4(double);

int main() {
    DataFrame df = importFromCSV("../data.csv");
    double length1 = 73.8/100;
    double length2 = 84.9/100;

    column tempi1 = df.getColumn(0);
    column tempi2 = df.getColumn(1);
    column tempi3 = df.getColumn(2);
    column tempi4 = df.getColumn(3);

    describeColumn(tempi1, length1);
    describeColumn(df.mapColumn(tempi2, div4), length1);
    describeColumn(tempi3, length2);
    describeColumn(df.mapColumn(tempi4, div4), length2);

    return 0;
}

double div4(double x) {
    return x/4;
}

