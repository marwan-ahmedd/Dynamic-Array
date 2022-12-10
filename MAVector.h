#ifndef _MAVECTOR_H
#define _MAVECTOR_H

#include <bits/stdc++.h>
using namespace std;

template <class T>
class MAVector
{
private:
    T *arr;
    int sze;
    int cap;
    typedef T* iterator;

public:
    // ----> Marwan
    MAVector(int cap = 0);
    MAVector(const MAVector &other);
    MAVector &operator=(const MAVector<T> &other);
    T &operator[](int index);
    T pop_back();
//    void erase(iterator itr1, iterator itr2);
//    void insert(iterator itr, T item);
    iterator end();
    bool operator<(const MAVector<T> &other);
    int capacity() const;
    bool empty();

    /////////////////////////////////////////////////////////////////////////
    // ----> Abo bakr
    MAVector(iterator other, int n);
    ~MAVector();
    MAVector &operator=(const MAVector<T> &&other);
    void push_back(T item);
    //        void erase();
    void clear();
    //        iterator begin();
    bool operator==(const MAVector<T> &other);
    int size();
    void resize(int num);
    friend ostream &operator<<(ostream &out, MAVector<T> &other)
    {
        out << "{";
        for (int l = 0; l < other.size() - 1; ++l)
            out << other[l] << ", ";
        out << other[other.size() - 1] << "}\n";
        return out;
    }
};

// -> Marwan ///////////////////////////////////////////////////////////////////////
template <class T>
MAVector<T>::MAVector(int cap) : cap(cap), sze(cap)
{
    arr = new T[cap];
    for (int i = 0; i < cap; i++)
        arr[i] = 0;
}
//---------------------------------->
template <class T>
MAVector<T>::MAVector(const MAVector<T> &other) : cap(other.cap), sze(other.sze)
{
    arr = new T[cap];
    for (int i = 0; i < sze; i++)
        arr[i] = other.arr[i];
}
//---------------------------------->
template <class T>
MAVector<T>& MAVector<T> :: operator=(const MAVector<T> &other)
{
    if (this != &other)
    {
        cap = other.cap;
        sze = other.sze;

        delete[] arr;
        arr = new T[cap];

        for (int i = 0; i < sze; i++)
            arr[i] = other.arr[i];
        return *this;
    }
    else
        throw invalid_argument("Error. Cannot assign self.\n");
}
//---------------------------------->
template <class T>
T& MAVector<T> :: operator[](int index)
{
    if (index > sze - 1 or index < 0)
        throw invalid_argument("Out of range!\n");
    return arr[index];
}
//---------------------------------->
template <class T>
T MAVector<T> :: pop_back()
{
    T lastElement = arr[sze - 1];
    sze--;
    if (cap / 2 == sze)
        cap /= 2;
    else
    {
        T* newArr = new T[cap];
        for (int i = 0; i < sze; i++)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
        newArr = nullptr;
    }
    return lastElement;
}
//---------------------------------->
// template <class T>
// void MAVector<T> ::erase(iterator itr1, iterator itr2) {}
//---------------------------------->
// template <class T>
// void MAVector<T> ::insert(iterator itr, T item) {}
//---------------------------------->
template <class T>
T* MAVector<T>::end()
{
    return T(arr + sze);
}
//---------------------------------->
template <class T>
bool MAVector<T>::operator<(const MAVector<T> &other)
{
    if (sze != other.sze or cap != other.cap)
        return false;
    else
    {
        for (int i = 0; i < sze; i++)
        {
            if (arr[i] > other.arr[i] or arr[i] == other.arr[i])
                return false;
        }
    }
    return true;
}
//---------------------------------->
template <class T>
int MAVector<T>::capacity() const
{
    return cap;
}
//---------------------------------->
template <class T>
bool MAVector<T> :: empty()
{
    return !sze;
}

// -> Abo bakr ///////////////////////////////////////////////////////////////////////
template <class T>
MAVector<T>::MAVector(T* other, int n)
{
    cap = n;
    sze = cap;
    arr = new T[cap];
    for (int i = 0; i < sze; ++i)
        arr[i] = other[i];
}
///////////////////////////////////////////////
template <class T>
MAVector<T>::~MAVector()
{
    delete[] arr;
}
///////////////////////////////////////////////
// template <class T>
// MAVector MAVector::&operator= (const MAVector&& other){}
///////////////////////////////////////////////
template <class T>
void MAVector<T>::push_back(T item)
{
    if (sze < cap)
    {
        arr[sze++] = item;
    }
    else
    {
        T *newArr = new T[cap + 5];
        cap += 5;

        for (int i = 0; i < sze; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        delete[] newArr;
        newArr = nullptr;
        arr[sze++] = item;
    }
}
///////////////////////////////////////////////
// void MAVector<T>::erase(){}
///////////////////////////////////////////////
template <class T>
void MAVector<T>::clear()
{
    T *newArr = new T[cap];
    delete[] arr;
    arr = newArr;
    sze = 0;
    delete[] newArr;
    newArr = nullptr;
}
///////////////////////////////////////////////
template <class T>
bool MAVector<T>::operator==(const MAVector<T> &other)
{
    if (sze != other.sze)
        return false;
    if (cap != other.cap)
        return false;

    for (int i = 0; i < sze; ++i)
    {
        if (arr[i] != other.arr[i])
            return false;
    }

    return true;
}
///////////////////////////////////////////////
template <class T>
int MAVector<T>::size()
{
    return sze;
}
///////////////////////////////////////////////
template <class T>
void MAVector<T>::resize(int num)
{
    if (num > cap)
        cap += (num + 5);

    T* newArr = new T[cap];

    if (num < sze)
    {
        for (int j = 0; j < num; ++j)
            newArr[j] = arr[j];
        delete[] arr;
        arr = newArr;
        sze = num;
        delete[] newArr;
        newArr = nullptr;
    }
    else if (num > sze)
    {
        for (int j = 0; j < sze; ++j)
            newArr[j] = arr[j];
        for (int k = sze; k < num; ++k)
            newArr[k] = '\0';

        delete[] arr;
        arr = newArr;
        sze = num;
        delete[] newArr;
        newArr = nullptr;
    }
}

#endif