#include<iostream>
#include<math.h>
#include<string>
#include "./lib/physics.cxx"

using namespace std;

int main() {
    DataFrame df = importFromCSV("../data.csv");

    column tempi1 = df.getColumn(0);
    column tempi2 = df.getColumn(1);
    column tempi3 = df.getColumn(2);
    column tempi4 = df.getColumn(3);



    return 0;
}



