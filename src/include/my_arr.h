#ifndef _MY_ARR_H_
#define _MY_ARR_H_
#include<iostream>
template <typename T>
class my_arr
{
    unsigned int m_size;
    T *arr;

public:
    my_arr();
    my_arr(unsigned int);
    unsigned int size();
    T &operator[](unsigned int);
    my_arr &operator=(const my_arr<T> &);
    bool operator==(const my_arr<T> &);
    ~my_arr();

    my_arr(const my_arr &) = delete;
    my_arr(my_arr &&) = delete;
    my_arr &operator=(my_arr &&) = delete;
};

template <typename T>
my_arr<T>::my_arr() : m_size{0}, arr{nullptr} {}

template <typename T>
my_arr<T>::my_arr(unsigned int size) : m_size{size}
{
    arr = new T[m_size]{0};
}

template <typename T>
unsigned int my_arr<T>::size()
{
    return m_size;
}
template <typename T>
T &my_arr<T>::operator[](unsigned int index)
{
    if(index < 0 || index >= m_size)
    {
        std::cerr<<"Warning: You have exceeded the size of the array."<<std::endl;
    }   
    return arr[index];
}
template <typename T>
my_arr<T> &my_arr<T>::operator=(const my_arr<T> &other)
{
    if (*this == other)
        return *this;
    delete[] arr;
    m_size = other.m_size;
    if (m_size != 0)
    {
        arr = new int[m_size];
        for (unsigned int i = 0; i < m_size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    else
        arr = nullptr;
    return *this;
}

template <typename T>
bool my_arr<T>::operator==(const my_arr<T> &other)
{
    if ((*this).arr == other.arr)
        return true;
    if (other.m_size != this->m_size)
        return false;
    for (unsigned int i = 0; i < m_size; ++i)
    {
        if (arr[i] != other.arr[i])
        {
            return false;
        }
    }
    return true;
}
template<typename T>
my_arr<T>::~my_arr()
{
    delete[] arr;
}

#endif //_MY_ARR_H_