#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

void error(std::string s);
std::string l(std::string input);
double dot_product(const std::vector<double> &v1, const std::vector<double> &v2);
std::vector<double> cross_product(const std::vector<double> &v1, const std::vector<double> &v2);
std::vector<double> sum(const std::vector<double> &v1, const std::vector<double> &v2);
std::vector<double> difference(const std::vector<double> &v1, const std::vector<double> &v2);
double magnitude(const std::vector<double> &v);
std::vector<double> normalize(const std::vector<double> &v);
void roots(double a, double b, double c, int num_dec);
double pop_variance(const std::vector<double> &vec, const double &mean, const int &pop_size);
double sam_variance(const std::vector<double> &vec, const double &mean, const int &sam_size);
double box_and_whisker(const std::vector<double> &vec, const std::string &desired_output);
std::vector<double> outliers(const std::vector<double> &vec, const double &q1, const double &q3, const double &iqr);
