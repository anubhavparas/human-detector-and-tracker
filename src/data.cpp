/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */


#include <data.hpp>
#include <type_traits>
#include <types.hpp>


template <typename T>
Data<T>::Data() {
}

template <typename T>
Data<T>::Data(T data) {
    this->_data = data;
}

template <typename T>
Data<T>::~Data() {
}

template <typename T>
void Data<T>::setData(T data) {
    this->_data = data;
}

template <typename T>
T Data<T>::getData() const {
    return this->_data;
}

template class Data<int>;
template class Data<RectanglesAndScores>;
