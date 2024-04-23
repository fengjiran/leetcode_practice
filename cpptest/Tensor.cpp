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
    //
}
}// namespace InferEngine