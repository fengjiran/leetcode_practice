//
// Created by richard on 4/18/24.
//

#include "Tensor.h"

namespace InferEngine {
template<typename T>
Tensor<T>::Tensor(uint32_t size) {
    data_ = arma::Cube<T>(1, size, 1);
    rawDims_ = std::vector<uint32_t>{size};
}

template<typename T>
Tensor<T>::Tensor(uint32_t rows, uint32_t cols) {
    data_ = arma::Cube<T>(rows, cols, 1);
    if (rows == 1) {
        rawDims_ = std::vector<uint32_t>{cols};
    } else {
        rawDims_ = std::vector<uint32_t>{rows, cols};
    }
}

template<typename T>
Tensor<T>::Tensor(uint32_t channels, uint32_t rows, uint32_t cols) {
    data_ = arma::Cube<T>(rows, cols, channels);
    if (channels == 1 && rows == 1) {
        rawDims_ = std::vector<uint32_t>{cols};
    } else if (channels == 1) {
        rawDims_ = std::vector<uint32_t>{rows, cols};
    } else {
        rawDims_ = std::vector<uint32_t>{channels, rows, cols};
    }
}

template<typename T>
Tensor<T>::Tensor(const std::vector<uint32_t>& shape) {
    CHECK(!shape.empty() && shape.size() <= 3);
}

template class Tensor<float>;
}// namespace InferEngine