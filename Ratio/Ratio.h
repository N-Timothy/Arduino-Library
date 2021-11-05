// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
// SPDX-License-Identifier: MIT
//
// Copyright (c) 2021 Nathanael Timothy
// Copyright (c) 2021 Nathanael Timothy <timmynathan10@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE
//
//Ratio.h
//By Nathanael Timothy
//A Ratio library for arduino project

#ifndef ARDUINO_RATIO_H_
#define ARDUINO_RATIO_H_

#include <Arduino.h>

template<int _num = 1 , int _den = 1>
struct Ratio {
    static constexpr int num = _num;
    static constexpr int den = _den;
    typedef Ratio<num, den> type;
};

// aritmetic

template<typename _R1, typename _R2>
struct ratio_add {
    private:
         static constexpr int n1 = _R1::num * _R2::den;
         static constexpr int n2 = _R2::num * _R1::den;
         static constexpr int d = _R1::den * _R2::den;
    public :
         static constexpr int num = n1+n2;
         static constexpr int den = d;
         static constexpr float desc = (float)num/den;
};

template<typename _R1, typename _R2>
struct ratio_subtract {
    private:
         static constexpr int n1 = _R1::num * _R2::den;
         static constexpr int n2 = _R2::num * _R1::den;
         static constexpr int d = _R1::den * _R2::den;
    public:
         static constexpr int num = n1-n2;
         static constexpr int den = d;
         static constexpr float desc = (float)num/den;
};

template<typename _R1, typename _R2>
struct ratio_multiply {
    public:
         static constexpr int num = _R1::num * _R2::num;
         static constexpr int den = _R1::den * _R2::den;
         static constexpr float desc = (float)num/den;
};

template<typename _R1, typename _R2>
struct ratio_divide {
    public:
         static constexpr int num = _R1::num * _R2::den;
         static constexpr int den = _R1::den * _R2::num;
         static constexpr float desc = (float)num/den;
};

// comparison

template<typename _R1, typename _R2>
bool ratio_equal () {

    return (((float)_R1::num/_R1::den) == ((float)_R2::num/_R2::den));
}

template<typename _R1, typename _R2>
bool ratio_not_equal () {

    return (((float)_R1::num/_R1::den) != ((float)_R2::num/_R2::den));
}

template<typename _R1, typename _R2>
bool ratio_less () {

    return (((float)_R1::num/_R1::den) < ((float)_R2::num/_R2::den));
}

template<typename _R1, typename _R2>
bool ratio_less_equal () {

    return (((float)_R1::num/_R1::den) <= ((float)_R2::num/_R2::den));
}

template<typename _R1, typename _R2>
bool ratio_greater () {

    return (((float)_R1::num/_R1::den) > ((float)_R2::num/_R2::den));
}

template<typename _R1, typename _R2>
bool ratio_greater_equal () {

    return (((float)_R1::num/_R1::den) >= ((float)_R2::num/_R2::den));
}

#endif // ARDUINO_RATIO_H_
