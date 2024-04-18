//
// Created by richard on 4/18/24.
//

#ifndef LEETCODE_PRACTICE_TENSOR_H
#define LEETCODE_PRACTICE_TENSOR_H

#include <armadillo>
#include <glog/logging.h>
#include <vector>

namespace InferEngine {

template<typename T>
class Tensor {
public:
    /**
     * @brief Construct a new empty Tensor.
     */
    Tensor() = default;

    /*
     * @brief Construct a 1D Tensor.
     *
     * @param size vector size
     */
    explicit Tensor(uint32_t size);

private:
    /// Raw tensor dimensions
    std::vector<uint32_t> rawDims_;
    /// Tensor data
    arma::Cube<T> data_;
};

}// namespace InferEngine

#endif//LEETCODE_PRACTICE_TENSOR_H
