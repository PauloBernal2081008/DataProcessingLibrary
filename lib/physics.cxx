#include<iostream>
#include<cmath>
#include<math.h>
#include "dataframe.cxx"

double gravityM(vector<double> times, double length) {
    return 4*pow(M_PI, 2)*length/pow(mean(times), 2);
}
double gravity(double time, double length) {
    return 4*pow(M_PI, 2)*length/pow(time, 2);
}
double gravityT(vector<double> times, double length) {
    vector<double> grts;
    for (double i: times) {
        grts.push_back(gravity(i, length));
    }
    return mean(grts);
}
double errorM(vector<double> times, double length) {
    double A, B, C, D;
    A = pow(4*pow(M_PI, 2)*(1/pow(mean(times), 2)), 2);
    B = (0.001/sqrt(12));
    C = pow(8*pow(M_PI, 2)*(length/pow(mean(times), 3)), 2);
    D = (stdev(times)/sqrt(times.size()));
    return sqrt(A*B+C*D);
}
void describeColumn(column cc, double length) {
    cout << endl << "Column name: " << cc.index << endl;
    cout << "Mean: " << mean(cc.data) << endl;
    cout << "Median: " << median(cc.data) << endl;
    cout << "Standard dev.: " << stdev(cc.data) << endl;
    cout << "Gravity M: " << gravityM(cc.data, length) << " +- " << errorM(cc.data, length) << "[m/s^2]" << endl;
    cout << "Gravity T: " << gravityT(cc.data, length) << endl;
}
