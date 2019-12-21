#include <iostream>
#include "FloatComplex.h"
#include "DoubleComplex.h"

using namespace std;

int main() {

    FloatComplex a0;
    FloatComplex a1;

    a0.real = 1; a0.imag = 2;
    a1.real = 3; a1.imag = 4;

    cout << "a0 = " << a0 << endl;
    cout << "a1 = " << a1 << endl;

    cout << "a0+a1=" << (a0+a1) << endl;
    cout << "a0*a1=" << (a0*a1) << endl;

    a0.real = 1;
    a0.imag = 1;
    cout << "a0 = " << a0 << ", angle(a0)=" << a0.angle() << endl;

    a0.real = 1;
    a0.imag = -1;
    cout << "a0 = " << a0 << ", angle(a0)=" << a0.angle() << endl;

    a0.real = -1;
    a0.imag = 1;
    cout << "a0 = " << a0 << ", angle(a0)=" << a0.angle() << endl;

    a0.real = -1;
    a0.imag = -1;
    cout << "a0 = " << a0 << ", angle(a0)=" << a0.angle() << endl;


    DoubleComplex b0;
    DoubleComplex b1;

    b0.real = 1; b0.imag = 2;
    b1.real = 3; b1.imag = 4;

    cout << "b0 = " << b0 << endl;
    cout << "b1 = " << b1 << endl;

    cout << "b0+b1=" << (b0+b1) << endl;
    cout << "b0*b1=" << (b0*b1) << endl;

    b0.real = 1;
    b0.imag = 1;
    cout << "b0 = " << b0 << ", angle(b0)=" << b0.angle() << endl;

    b0.real = 1;
    b0.imag = -1;
    cout << "b0 = " << b0 << ", angle(b0)=" << b0.angle() << endl;

    b0.real = -1;
    b0.imag = 1;
    cout << "b0 = " << b0 << ", angle(b0)=" << b0.angle() << endl;

    b0.real = -1;
    b0.imag = -1;
    cout << "b0 = " << b0 << ", angle(b0)=" << b0.angle() << endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
