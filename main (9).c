/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;


template <typename S>
S calibrateValue(const S& x, char factor) {
    int f = factor - '0';      
    return x * f;              
}


void adjustReading(double* value, double offset = 1.25) {
    if (value != nullptr) {
        *value += offset;
    }
}


void clampReading(double& r) {
    if (r < 0.0)
        r = 0.0;
    else if (r > 100.0)
        r = 100.0;
}


double computeDifference(int a, double b) {
    return static_cast<double>(a) - b;
}

int main() {
    int intSensor;
    double doubleSensor;

  
    cout << "Enter integer sensor reading: ";
    cin >> intSensor;

    cout << "Enter double sensor reading: ";
    cin >> doubleSensor;

 
    int calibratedInt = calibrateValue(intSensor, '2');
    double calibratedDouble = calibrateValue(doubleSensor, '2');

    cout << fixed << setprecision(4);

    cout << "\nCalibrated readings:\n";
    cout << setw(10) << calibratedInt << endl;
    cout << setw(10) << calibratedDouble << endl;


    double intAsDouble = static_cast<double>(calibratedInt);

    adjustReading(&intAsDouble);           
    adjustReading(&calibratedDouble, 3.4);

    cout << "\nAdjusted readings:\n";
    cout << setw(10) << intAsDouble << endl;
    cout << setw(10) << calibratedDouble << endl;


    clampReading(intAsDouble);
    clampReading(calibratedDouble);

    cout << "\nClamped readings:\n";
    cout << setw(10) << intAsDouble << endl;
    cout << setw(10) << calibratedDouble << endl;


    int finalIntValue = static_cast<int>(intAsDouble);

    cout << "\nInteger sensor after clamping & conversion back to int:\n";
    cout << setw(10) << finalIntValue << endl;


    double diff = computeDifference(finalIntValue, calibratedDouble);

    cout << "\nDifference (int - double):\n";
    cout << setw(10) << diff << endl;

    return 0;
}