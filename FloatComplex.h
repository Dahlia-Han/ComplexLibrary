//
// Created by Dahlia.Han on 2019/12/21.
//
// MIT License
//
// Copyright (c) [2019] [Dahlia.Han]
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
//         of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
//         to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//         copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
//         copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//         AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef COMPLEXOPERATION_FLOATCOMPLEX_H
#define COMPLEXOPERATION_FLOATCOMPLEX_H

#include <math.h>
#include <ostream>
#define PI 3.14159265358979323846

using namespace std;

/*
 * 定义float类型的复数
 * 该类实现存储一个复数的实部和虚部
 * 实现了基本的运算包括: +=, -=, +, -, *, /,
 * 实现取模，角
 * 实现以e为底的指数计算
 * 实现通过流输出存储的复数
 */
class FloatComplex {
public:
    FloatComplex(void);
    FloatComplex(float r, float i);

    // 基本运算
    FloatComplex &operator +=(const FloatComplex & c);
    FloatComplex &operator -=(const FloatComplex & c);

    FloatComplex operator +(const FloatComplex & c) const;
    FloatComplex operator -(const FloatComplex & c) const;
    FloatComplex operator *(const FloatComplex & c) const;
    FloatComplex operator /(const FloatComplex & c) const;

    // 模，角，指数
    float abs(void) const;
    float angle(void) const;
    FloatComplex Exp(void) const;

    // 输出
    friend ostream & operator<<(ostream & o, const FloatComplex & c);

    float real;
    float imag;
};

FloatComplex::FloatComplex(void): real(0), imag(0){

}

FloatComplex::FloatComplex(float r, float i): real(r), imag(i) {

}

FloatComplex &FloatComplex::operator+=(const FloatComplex &c) {
    this->real += c.real;
    this->imag += c.imag;
    return *this;
}

FloatComplex &FloatComplex::operator-=(const FloatComplex &c) {
    this->real -= c.real;
    this->imag -= c.imag;
    return *this;
}

FloatComplex FloatComplex::operator*(const FloatComplex &c) const {
    float a = this->real*c.real - this->imag*c.imag;
    float b = c.real*this->imag + this->real*c.imag;
    FloatComplex t(a, b);
    return t;
}

FloatComplex FloatComplex::operator+(const FloatComplex &c) const {
    float a = this->real + c.real;
    float b = this->imag + c.imag;
    FloatComplex t(a, b);
    return t;
}

FloatComplex FloatComplex::operator-(const FloatComplex &c) const {
    float a = this->real - c.real;
    float b = this->imag - c.imag;
    FloatComplex t(a, b);
    return t;
}

FloatComplex FloatComplex::operator/(const FloatComplex &c) const {
    float a = (this->real*c.real+this->imag+c.imag)/(c.real*c.real+c.imag*c.imag);
    float b = (c.real*this->imag-this->real*c.imag)/(c.real*c.real+c.imag*c.imag);
    FloatComplex t(a, b);
    return t;
}

float FloatComplex::abs(void) const {
    return sqrt(this->real*this->real + this->imag*this->imag);
}

float FloatComplex::angle(void) const {
    if(this->real>0 && this->imag>=0)
        return atan(this->imag/this->real);
    else if(this->real>0 && this->imag<0)
        return atan(this->imag/this->real);
    else if(this->real==0 && this->imag>0)
        return PI/2;
    else if(this->real==0 && this->imag<0)
        return -PI/2;
    else if(this->real<0 && this->imag>0)
        return atan(this->imag/this->real) + PI;
    else if(this->real<0 && this->imag<0)
        return atan(this->imag/this->real) - PI;
    else if(this->real<0 && this->imag==0)
        return PI;
    else
        return 2*PI;
}

FloatComplex FloatComplex::Exp(void) const {
    FloatComplex t;
    t.real = exp(this->real)*cos(this->real);
    t.imag = exp(this->real)*sin(this->imag);
    return t;
}

ostream &operator<<(ostream &o, const FloatComplex &c) {
    o << c.real << "+" << c.imag << "i";
    return o;
}


#endif //COMPLEXOPERATION_FLOATCOMPLEX_H
