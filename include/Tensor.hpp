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

    /**
     * @brief Fills tensor with value
     *
     * @param value Fill value
     */
    void Fill(T value);

    /**
     * @brief Get raw tensor shape
     *
     *@return Raw tensor dimensions
     */
    const std::vector<uint32_t>& GetRawShape() const;

    /**
     *@brief Print tensor
     */
    void Show();

    /**
     * @brief Get number of tensor channels
     *
     * @return Number of tensor channels
     */
    uint32_t GetChannels() const;

    /**
     * @brief Get number of rows
     *
     * @return Number of tensor rows
     */
    uint32_t GetRows() const;

    /**
     * @brief Get number of cols
     *
     * @return Number of tensor cols
     */
    uint32_t GetCols() const;

    /**
     * @brief Gets total number of elements
     *
     * @return Total number of elements
     */
    size_t GetSize() const;

    /**
     * @brief Gets actually total number of elements
     *
     * @return Total actually number of elements
     */
    size_t GetPlaneSize() const;

private:
    /// Raw tensor dimensions
    std::vector<uint32_t> rawDims_;
    /// Tensor data
    arma::Cube<T> data_;
};

}// namespace InferEngine

#endif//LEETCODE_PRACTICE_TENSOR_HPP
