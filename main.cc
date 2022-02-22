#include "functions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

// TO-DO:
// - impliment linear algebra functionality
// - cubic equation
// - probability testing (z-test, t-test, chi-squared test, etc)

int main() {
    string user_choice = "";
    cout << "welcome to shook's advanced C++ calculator v1.0!\n";
    cout << "please select an operation:\n"
         << "1) compute the roots of a quadratic equation\n"
         << "2) statistics\n"
         << "3) linear algebra\n";
    cout << "choice: ";
    getline(cin,user_choice);
    if (user_choice == "1") {
        string a = "", b = "", c = "", d = "";
        double ad = 0.0, bd = 0.0, cd = 0.0;
        int dd = 0.0;
        cout << "please enter the coefficients for a quadratic equation of the form: ax² + bx + c = 0\n";
        cout << "a = ";
        getline(cin,a);
        try {ad = stod(a);} 
        catch(...) {error("Argument error - 'roots': Coefficient must be a numerical value.");}
        cout << "b = ";
        getline(cin,b);
        try {bd = stod(b);}
        catch(...) {error("Argument error - 'roots': Coefficient must be a numerical value.");}
        cout << "c = ";
        getline(cin,c);
        try {cd = stod(c);}
        catch(...) {error("Argument error - 'roots': Coefficient must be a numerical value.");}
        cout << "enter the desired decimal precision:\n";
        getline(cin,d);
        try {dd = stoi(d);}
        catch(...) {error("Argument error - 'roots': Coefficient must be a numerical value.");}
        roots(ad,bd,cd,dd);
    
    }
else if (user_choice == "2") {
        cout << "please enter numerical values (done to quit):\n";
        string s = "";
        vector<double> data = {};
        int size = 0;
        double x = 0;
        double sum = 0.0;
        double average = 0.0;
        double min = 0.0;
        double max = 0.0;
        double q1 = 0.0;
        double q3 = 0.0;
        double median = 0.0;
        double iqr = 0.0;
        double popVar = 0.0;
        double samVar = 0.0;
        double popSD = 0.0;
        double samSD = 0.0;
        // read in a user input (string)
        while (true) {
            getline(cin,s);
            // if user input = "done" break;
            if (l(s) == "done") break;
            // else convert string to double and return "invalid input" if not double
            else {
                try {x = stod(s);}
                catch (...) {
                    cout << "invalid input (value must be numerical)" << endl;
                    continue;
                }
            }
            data.push_back(x);
            sum += x;
        }
        sort(data.begin(),data.end());
        // sorted data output (visual)
        cout << "sorted data: ";
        cout << "{";
        for (size_t i = 0; i < data.size() - 1; i++) {
            cout << data[i] << ",";
        }
        cout << data.at(data.size() - 1) << "}" << endl;

        // data calculations
        average = round(sum / data.size() * 100) / 100.0;
        min = round(box_and_whisker(data, "min") * 100) / 100.0;
        q1 = box_and_whisker(data, "q1");
        median = round(box_and_whisker(data, "median") * 100) / 100.0;
        q3 = box_and_whisker(data, "q3");
        max = round(box_and_whisker(data, "max") * 100) / 100.0;
        iqr = q3-q1;
        size = data.size();
        popVar = pop_variance(data, average, size);
        samVar = sam_variance(data, average, size);
       popSD = sqrt(popVar);
        samSD = sqrt(samVar);
        vector<double> outs = outliers(data, q1, q3, iqr);

        // data output
        cout << "size of data set: " << size << endl;
        cout << "min/max: " << min << ", " << max << endl;
        cout << "data set mean: " << average << endl;
        cout << "data set median: " << median << endl;
        if (outs.size() != 0) {
            cout << "outliers: ";
            cout << "{";
            for (int i = 0; i < outs.size() - 1; i++) {
                cout << outs[i] << ",";
            }
            cout << outs.at(outs.size() - 1) << "}" << endl;
        }
        else cout << "outliers: none" << endl;;

        cout << "σ: " << round(popSD * 100) / 100.0 << endl;
        cout << "σ²: " << round(popVar * 100) / 100.0 << endl;
        cout << "s: " << round(samSD * 100) / 100.0 << endl;
        cout << "s²: " << round(samVar * 100) / 100.0 << endl;
    }
    else if (user_choice == "3") {
        cout << "linear algebra" << endl;
    }
    else cout << "no such operation.\n";

    return 0;
}
