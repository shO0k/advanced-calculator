#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "functions.h"

// error message function
void error(std::string s) {
    std::cout << s << std::endl;
    exit(EXIT_FAILURE);
}
// make an entire string lowercase
std::string l(std::string input) {
    for (const char &c: input) tolower(c);
    return input;
}

// LINEAR ALGEBRA:
// dot product
double dot_product(const std::vector<double> &v1, const std::vector<double> &v2) {
    if (v1.size() != v2.size()) error("Argument error - 'dot_product': Vectors must have equivalent dimensionality.");
    else if (v1.size() == 0 or v2.size() == 0) error("Argument error - 'dot_product': Vectors cannot be empty");
    double scalar = 0.0;
    for (size_t i = 0; i < v1.size(); i++) {
        scalar += (v1[i]*v2[i]);
    }
    return scalar;
}
// cross product
std::vector<double> cross_product(const std::vector<double> &v1, const std::vector<double> &v2) {
    if (v1.size() != 3 and v2.size() != 3) error("Argument error - 'cross_product': Vectors must be 3-Dimensional.");
    std::vector<double> result = {};
    result.push_back(v1[1]*v2[2] - v1[2]*v2[1]);
    result.push_back(v1[2]*v2[0] - v1[0]*v2[2]);
    result.push_back(v1[0]*v2[1] - v1[1]*v2[0]);
    return result;
}
// add two vectors component-wise
std::vector<double> sum(const std::vector<double> &v1, const std::vector<double> &v2) {
    if (v1.size() != v2.size()) error("Argument error - 'sum': Vectors must have equivalent dimensions.");
    std::vector<double> result = {};
    for (size_t i = 0; i < v1.size(); i++) {
        result.push_back(v1[i]+v2[i]);
    }
    return result;
}
// subtract two vectors component-wise, order matters!
std::vector<double> difference(const std::vector<double> &v1, const std::vector<double> &v2) {
    if (v1.size() != v2.size()) error("Argument error 'difference': Vectors must have equivalent dimensions.");
    std::vector<double> result = {};
    for (size_t i = 0; i < v1.size(); i++) {
        result.push_back(v1[i]-v2[i]);
    }
    return result;
}
// returns magnitude of vector in question
double magnitude(const std::vector<double> &v) {
    if (v.size() == 0) error("Argument error - 'magnitude': Vector cannot be empty");
    double sum = 0.0;
    for (size_t i = 0; i < v.size(); i++) {
        sum += pow(v[i],2);
    }
    return sqrt(sum);
}
// normalizes vector in question
std::vector<double> normalize(const std::vector<double> &v) {
    if (v.size() == 0) error("Argument error: Vector cannot be empty");
    std::vector<double> result = {};
    double temp = 0.0;
    double mag = magnitude(v);
    for (size_t i = 0;  i < v.size(); i++) {
        temp = v[i] / mag;
        result.push_back(temp);
    }
    return result;
}

// ROOTS:
// roots to a quadratic equation
void roots(double a, double b, double c, int num_dec) {
    double rootArgument = pow(b,2) - (4 * a * c);
    double rootTermR = sqrt(rootArgument);
    double rootTermI = sqrt(fabs(rootArgument));
    double leadTerm = -1 * b;
    double denominator = 2 * a;
    double plusBranch = leadTerm + rootTermR;
    double minusBranch = leadTerm - rootTermR;
    double zero1 = minusBranch / denominator;
    double zero2 = plusBranch / denominator;
    std::cout << std::endl;
    std::cout << "input: ";
    // quadratic formatting (obesessive compulsive disorder as defined by the DSM IV)
    if (a == 0) {
        std::cout << "error: linear equation.\n";
    }
    // 1x² -> x²
    else if (a == 1) {
        // accounts for b <= 0 and c <= 0
        if (b == 0 && c == 0) {
            std::cout << "f(x) = x²" << std::endl;
        }
        else if (b == 0) {
            std::cout << "f(x) = x² + " << c << std::endl;
        }
        else if (c == 0) {
            std::cout << "f(x) = x² + " << b << "x" << std::endl;
        }
        else if (b < 0 && c < 0) {
            std::cout << "f(x) = x² - " << fabs(b) << "x - " << fabs(c) << std::endl;
                  }
        else if (b < 0) {
            std::cout << "f(x) = x² - " << fabs(b) << "x + " << c << std::endl;
        }
        else if (c < 0) {
            std::cout << "f(x) = x² + " << b << "x - " << fabs(c) << std::endl;
        }
        else {
            std::cout << "f(x) = x² + " << b << "x + " << c << std::endl;
        }
    }
    // -1x² -> -x²
    else if (a == -1) {
        // accounts for b <= 0 and c <= 0
        if (b == 0 && c == 0) {
            std::cout << "f(x) = -x²" << std::endl;
        }
        else if (b == 0) {
            std::cout << "f(x) = -x² + " << c << std::endl;
        }
        else if (c == 0) {
            std::cout << "f(x) = -x² + " << b << "x" << std::endl;
        }
        else if (b < 0 && c < 0) {
            std::cout << "f(x) = -x² - " << fabs(b) << "x - " << fabs(c) << std::endl;
        }
        else if (b < 0) {
            std::cout << "f(x) = -x² - " << fabs(b) << "x + " << c << std::endl;
        }
        else if (c < 0) {
            std::cout << "f(x) = -x² + " << b << "x - " << fabs(c) << std::endl;
        }
        else {
            std::cout << "f(x) = -x² + " << b << "x + " << c << std::endl;
        }
    }
    else if ((a != 1) && (a != -1)) {
        // accounts for b <= 0 and c <= 0
        if (b == 0 && c == 0) {
            std::cout << "f(x) = " << a << "x²" << std::endl;
        }
        else if (b == 0) {
            std::cout << "f(x) = " << a << "x² + " << c << std::endl;
        }
        else if (c == 0) {
            std::cout << "f(x) = " << a << "x² + " << b << "x" << std::endl;
        }
        else if (b < 0 && c < 0) {
            std::cout << "f(x) = " << a << "x² - " << fabs(b) << "x - " << fabs(c) << std::endl;
        }
        else if (b < 0) {
            std::cout << "f(x) = " << a << "x² - " << fabs(b) << "x + " << c << std::endl;
        }
        else if (c < 0) {
            std::cout << "f(x) = " << a << "x² + " << b << "x - " << fabs(c) << std::endl;
        }
        else {
            std::cout << "f(x) = " << a << "x² + " << b << "x + " << c << std::endl;
        }
    }
    if (rootArgument < 0) {
        std::cout << "x₁ = " << std::fixed << std::setprecision(num_dec) << (leadTerm / denominator) << " + " << fabs(rootTermI / denominator) << "i" << std::endl;
        std::cout << "x₂ = " << std::fixed << std::setprecision(num_dec) << (leadTerm / denominator) << " - " << fabs(rootTermI / denominator) << "i" << std::endl;
    }
    else {
        std::cout << "x₁ = " << std::fixed << std::setprecision(num_dec) << zero1 << std::endl;
        std::cout << "x₂ = " << std::fixed << std::setprecision(num_dec) << zero2 << std::endl;
    }
    std::cout << std::endl;
}

// STATISTICS:
//function that computes the population variance
double pop_variance(const std::vector<double> &vec, const double &mean, const int &pop_size) {
    double pop_var = 0.0;
    double diff_sqr = 0.0;
    for (int i = 0; i < vec.size(); i++) {
        diff_sqr += pow((mean - vec.at(i)), 2);
    }
    pop_var = diff_sqr / pop_size;
    return pop_var;
}
//function that computes the sample variance
double sam_variance(const std::vector<double> &vec, const double &mean, const int &sam_size) {
    double sam_var = 0.0;
    double diff_sqr = 0.0;
    for (int i = 0; i < vec.size(); i++) {
        diff_sqr += pow((mean - vec.at(i)), 2);
    }
    sam_var = diff_sqr / (sam_size - 1);
    return sam_var;
}
// function that takes in a sorted vector and computes min, max, q1, q2, q3
double box_and_whisker(const std::vector<double> &vec, const std::string &desired_output) {
    double output = 0.0;
    size_t size = vec.size();
    double min = 0.0;
    double q1 = 0.0;
    double median = 0.0;
    double q3 = 0.0;
    double max = 0.0;
    double index1 = 0.0;
    double index2 = 0.0;
    // min
    if (l(desired_output) == "min") {
        min = vec.at(0);
        output = min;
    }
    // q1
    if (l(desired_output) == "q1") {
        if (vec.size() % 2 == 0) {
            q1 = vec.at(((size / 4) + (size / 4 - 1)) / 2);
        }
        else q1 = vec.at(size/4);
        output = q1;
    }
    // median
    if (l(desired_output) == "median") {
        if (vec.size() % 2 == 0) {
            index1 = vec.at(size / 2 - 1);
            index2 = vec.at(size / 2);
            median = (index1 + index2) / 2;
        }
        else median = vec.at(vec.size() / 2);
        output = median;
    }
    // q3
    if (l(desired_output) == "q3") {
        if (vec.size() % 2 == 0) {
            q3 = vec.at(((3 * size / 4) + (3 * size / 4 - 1)) / 2);
        }
        else q3 = vec.at(3 * size / 4);
        output = q3;
    }
    // max
    if (l(desired_output) == "max") {
        max = vec.at(size - 1);
        output = max;
    }
    return output;
}
//function that takes in a sorted vector and returns the outliers
std::vector<double> outliers(const std::vector<double> &vec, const double &q1, const double &q3, const double &iqr) {
    std::vector<double> outliers = {};
    for (double a : vec) {
        if ((a < (q1 - (1.5 * iqr))) or (a > (q3 + (1.5 * iqr)))) outliers.push_back(a);
    }
    return outliers;
}
