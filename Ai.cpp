#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double predict(vector<double> x, vector<double> y, double value) {
    double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0, n = x.size();
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumXX += x[i] * x[i];
    }
    double a = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    double b = (sumY - a * sumX) / n;
    return a * value + b;
}

int main() {
    vector<double> x; // historical data for x-axis
    vector<double> y; // historical data for y-axis
    double value; // value to predict
    int n; // number of historical data points
    cout << "Enter the number of historical data points: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        double xi, yi;
        cout << "Enter the x-coordinate of data point " << i + 1 << ": ";
        cin >> xi;
        x.push_back(xi);
        cout << "Enter the y-coordinate of data point " << i + 1 << ": ";
        cin >> yi;
        y.push_back(yi);
    }
    cout << "Enter the value to predict: ";
    cin >> value;
    double prediction = predict(x, y, value); // predict the value for the given input
    cout << "Prediction: " << prediction << endl;
    return 0;
}