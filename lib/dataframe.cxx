#include<iostream>
#include<fstream>
#include<sstream>
#include "mystat.cxx"

using namespace std;

struct column {
    string index;
    vector<double> data;
};

class DataFrame {
    public:
        vector<string> index;
        vector<vector<double>> data;
        DataFrame(vector<string> indx, vector<vector<double>> table) {
            index = indx;
            data = table;
            for (vector<double> i: data) {
                if (i.size() != index.size()) {
                    throw invalid_argument("the size of all the columns must be the same.");
                }
            }
        }
        vector<int> dim() {
            vector<int> d;
            d.push_back(data.size());
            d.push_back(index.size());
            return d;
        }
        void printr() {
            showvec(index);
            for (vector<double> i: data) {
                showvec(i);
            }
        }
        void printr(int inx) {
            showvec(index);
            showvec(data[inx]);
        }
        void printr(int v[2]) {
            showvec(index);

            for (int i = v[0]; i <= v[1]; i++) {
                showvec(data[i]);
            }
        }
        void printr(vector<int> v) {
            showvec(index);
            for (int i = v[0]; i <= v[1]; i++) {
                showvec(data[i]);
            }
        }
        column getColumn(int n) {
            vector<double> ds;
            for (vector<double> i: data) {
                ds.push_back(i[n]);
            }
            column dfsc = {index[n], ds};
            return dfsc;
        }
        column mapColumn(column cc, double (*func)(double)) {
            vector<double> vct;
            for (double i: cc.data) {
                vct.push_back(func(i));
            }
            column ctr = {cc.index, vct};
            return ctr;
        }
};

DataFrame importFromCSV(string route) {
    fstream fdata;
    fdata.open(route, ios::in);
    vector<string> frow;
    vector<double> row;
    vector<vector<double>> table;
    string index, line, word, temp;
    
    if (fdata.is_open()) {
        getline(fdata, line);
            
            stringstream s(line);

            while (getline(s, word, ',')) {
                frow.push_back(word);
            }
        while (fdata) {
            row.clear();
            getline(fdata, line);
            
            stringstream s(line);

            while (getline(s, word, ',')) {
                row.push_back(stod(word));
            }
            table.push_back(row);
        }
    }
    DataFrame df(frow, table);
    return df;
}
