//
// Created by richard on 4/18/24.
//

#ifndef LEETCODE_PRACTICE_TENSOR_HPP
#define LEETCODE_PRACTICE_TENSOR_HPP

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

    /**
     * @brief Construct a 1D tensor
     *
     * @param size vector size
     */
    explicit Tensor(uint32_t size);

    /**
     * @brief Construct a 2D tensor
     *
     * @param rows number of rows
     * @param cols number of cols
     */
    Tensor(uint32_t rows, uint32_t cols);

    /**
     * @brief Construct a 3D tensor
     *
     * @param channels number of channels
     * @param rows number of rows
     * @param cols number of cols
     */
    Tensor(uint32_t channels, uint32_t rows, uint32_t cols);

    /**
     * @brief Construct a tensor with shape
     *
     * @param shape tensor dimension
     */
    explicit Tensor(const std::vector<uint32_t>& shape);

    /**
     * @brief Construct a 1D tensor with raw ptr
     *
     * @param rawPtr raw pointer of data
     * @param size vector size
     */
    Tensor(T* rawPtr, uint32_t size);

    /**
     * @brief Construct a 2D tensor with raw ptr
     *
     * @param rawPtr raw pointer of data
     * @param rows number of rows
     * @param cols number of cols
     */
    Tensor(T* rawPtr, uint32_t rows, uint32_t cols);

    /**
     * @brief Construct a 3D tensor with raw ptr
     *
     * @param rawPtr raw pointer of data
     * @param channels number of channels
     * @param rows number of rows
     * @param cols number of cols
     */
    Tensor(T* rawPtr, uint32_t channels, uint32_t rows, uint32_t cols);

    /**
     * @brief Construct a tensor with raw ptr and shape
     *
     * @param rawPtr raw pointer of data
     * @param shape tensor dimension
     */
    Tensor(T* rawPtr, const std::vector<uint32_t>& shape);

private:
    /// Raw tensor dimensions
    std::vector<uint32_t> rawDims_;
    /// Tensor data
    arma::Cube<T> data_;
};

}// namespace InferEngine

#endif//LEETCODE_PRACTICE_TENSOR_HPP
