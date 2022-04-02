//
// Created by Aikko Walker on 2022/4/2.
//

#ifndef MYARRAY_MYARRAY_HPP

#pragma once
#include <iostream>
#include <string>

using namespace std;

#define MYARRAY_MYARRAY_HPP

template<class T>
class MyArray {

public:

    T * m_pAddress;

private:

    int m_Capacity;
    int m_Size;

public:

    MyArray() {}
    MyArray(int capacity) : m_Capacity(capacity) {

        m_Size = 0;
        m_pAddress = new T[m_Capacity];

    }

    MyArray(const MyArray &arr) {

        m_Capacity = arr.m_Capacity;
        m_Size = arr.m_Size;
        m_pAddress = new T[arr.m_Capacity];

        if (arr.m_Size != 0) {

            for (int i = 0; i < arr.m_Size; ++i) {

                m_pAddress[i] = arr.m_pAddress[i];

            }

        }

    }

    MyArray & operator=(const MyArray arr) {

        if (m_pAddress != NULL) {

            delete[] m_pAddress;
            m_pAddress = NULL;

        }

        m_Capacity = arr.m_Capacity;
        m_Size = arr.m_Size;
        m_pAddress = new T[arr.m_Capacity];

        if (arr.m_Size != 0) {

            for (int i = 0; i < arr.m_Size; ++i) {

                m_pAddress[i] = arr.m_pAddress[i];

            }

        }

        return *this;

    }

    void pushBack(T data) {

        if (m_Size == m_Capacity) {

            cout << "やめてください、いっぱいです" << endl;
            return;

        }

        m_pAddress[m_Size] = data;
        m_Size++;

    }

    void popBack() {

        if (m_Size == 0) {

            cout << "やめてください、すでに空" << endl;
            return;

        }

        m_Size--;

    }

    friend ostream &operator<<(ostream &os, const MyArray &array) {

        os << "m_Capacity: " << array.m_Capacity << " m_Size: " << array.m_Size << " m_pAddress: " << array.m_pAddress;

        return os;

    }

    T & operator[](int index) {

        return m_pAddress[index];

    }

    int getMCapacity() const {

        return m_Capacity;

    }

    int getMSize() const {

        return m_Size;

    }

    virtual ~MyArray() {

        if (m_pAddress != NULL) {

            delete[] m_pAddress;
            m_pAddress = NULL;

        }

    }

};

#endif //MYARRAY_MYARRAY_HPP
