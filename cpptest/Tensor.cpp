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
}// namespace InferEngine