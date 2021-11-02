// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
// SPDX-License-Identifier: MIT
//
// Copyright (c) 2021 Nathanarl Timothy
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
//Queue.h
//By Nathanael Timothy
//Forked & referenced from Steven de Salas
//(https://github.com/sdesalas/Arduino-Queue.h)
//A Queue library for arduino project

#ifndef ARDUINO_QUEUE_H
#define ARDUINO_QUEUE_H

#include <Arduino.h>

template<class T>
class Queue {
  private:
    unsigned short _front, _back, _count;
    T *_data;
    unsigned short _maxitems;
  public:
    Queue(int maxitems = 256) {
      _front = 0;
      _back = 0;
      _count = 0;
      _maxitems = maxitems;
      _data = new T[maxitems + 1];
    }
    ~Queue() {
      delete[] _data;
    }
    inline int size();
    inline int front();
    inline int back();
    void push(const T &item);
    T pop();
    void clear();
    bool empty();
    bool full();
};

template<class T>
inline int Queue<T>::size()
{
  return _count;
}

template<class T>
inline int Queue<T>::front()
{
  if(_count <= 0) return T(); // Returns empty
  T result = _data[_front];
  return result;
}

template<class T>
inline int Queue<T>::back()
{
  T result = _data[_back - 1];
  return result;
}

template<class T>
void Queue<T>::push(const T &item)
{
  if(_count < _maxitems) { // Drops out when full
    _data[_back++]=item;
    ++_count;
    // Check wrap around
    if (_back > _maxitems)
      _back -= (_maxitems + 1);
  }
}

template<class T>
T Queue<T>::pop() {
  if(_count <= 0) return T(); // Returns empty
  else {
    T result = _data[_front];
    _front++;
    _count--;
    // Check wrap around
    if (_front > _maxitems)
      _front -= (_maxitems + 1);
    return result;
  }
}

template<class T>
void Queue<T>::clear()
{
  _front = _back;
  _count = 0;
}

template<class T>
bool Queue<T>::empty()
{
  if(_count <= 0) return true; // Returns true if empty
  return false; // Returns false if not empty
}

template<class T>
bool Queue<T>::full()
{
  if(_count == _maxitems) return true; // Returns true if full
  return false; // Returns false if not not full
}

#endif
