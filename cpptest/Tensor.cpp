//
// Created by richard on 4/18/24.
//

#include "Tensor.hpp"

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

    uint32_t remain = 3 - shape.size();
    std::vector<uint32_t> shape_(3, 1);
    std::copy(shape.begin(), shape.end(), shape_.begin() + remain);

    uint32_t channels = shape_[0];
    uint32_t rows = shape_[1];
    uint32_t cols = shape_[2];

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
Tensor<T>::Tensor(T* rawPtr, uint32_t size) {
    CHECK_NE(rawPtr, nullptr);
    rawDims_ = std::vector<uint32_t>{size};
    data_ = arma::Cube<T>(rawPtr, 1, size, 1, false, true);
}

template<typename T>
Tensor<T>::Tensor(T* rawPtr, uint32_t rows, uint32_t cols) {
    CHECK_NE(rawPtr, nullptr);
    data_ = arma::Cube<T>(rawPtr, rows, cols, 1, false, true);
    if (rows == 1) {
        rawDims_ = std::vector<uint32_t>{cols};
    } else {
        rawDims_ = std::vector<uint32_t>{rows, cols};
    }
}

template<typename T>
Tensor<T>::Tensor(T* rawPtr, uint32_t channels, uint32_t rows, uint32_t cols) {
    CHECK_NE(rawPtr, nullptr);
    data_ = arma::Cube<T>(rawPtr, rows, cols, channels, false, true);
    if (channels == 1 && rows == 1) {
        rawDims_ = std::vector<uint32_t>{cols};
    } else if (channels == 1) {
        rawDims_ = std::vector<uint32_t>{rows, cols};
    } else {
        rawDims_ = std::vector<uint32_t>{channels, rows, cols};
    }
}

template<typename T>
Tensor<T>::Tensor(T* rawPtr, const std::vector<uint32_t>& shape) {
    CHECK_NE(rawPtr, nullptr);
    CHECK(!shape.empty() && shape.size() <= 3);

    uint32_t remain = 3 - shape.size();
    std::vector<uint32_t> shape_(3, 1);
    std::copy(shape.begin(), shape.end(), shape_.begin() + remain);

    uint32_t channels = shape_[0];
    uint32_t rows = shape_[1];
    uint32_t cols = shape_[2];

    data_ = arma::Cube<T>(rawPtr, rows, cols, channels, false, true);
    if (channels == 1 && rows == 1) {
        rawDims_ = std::vector<uint32_t>{cols};
    } else if (channels == 1) {
        rawDims_ = std::vector<uint32_t>{rows, cols};
    } else {
        rawDims_ = std::vector<uint32_t>{channels, rows, cols};
    }
}

template<typename T>
Tensor<T>::Tensor(const Tensor<T>& rhs) : data_(rhs.data_), rawDims_(rhs.rawDims_) {}

template<typename T>
Tensor<T>& Tensor<T>::operator=(const Tensor<T>& rhs) {
    if (this != &rhs) {
        data_ = rhs.data_;
        rawDims_ = rhs.rawDims_;
    }
    return *this;
}

template<typename T>
Tensor<T>::Tensor(Tensor<T>&& rhs) noexcept : rawDims_(std::move(rhs.rawDims_)), data_(std::move(rhs.data_)) {}

template<typename T>
Tensor<T>& Tensor<T>::operator=(Tensor<T>&& rhs) noexcept {
    if (this != &rhs) {
        data_ = std::move(rhs.data_);
        rawDims_ = std::move(rhs.rawDims_);
    }
    return *this;
}

template<typename T>
void Tensor<T>::Fill(T value) {
    CHECK(!data_.empty()) << "The data area of the tensor is empty.";
    data_.fill(value);
}

template<typename T>
void Tensor<T>::Fill(const std::vector<T>& values, bool rowMajor) {
    CHECK(!data_.empty()) << "The data area of the tensor is empty.";
    CHECK_EQ(values.size(), data_.size());
    if (rowMajor) {
        //
    }
}

template<typename T>
const std::vector<uint32_t>& Tensor<T>::GetRawShape() const {
    CHECK(!rawDims_.empty());
    CHECK_LE(rawDims_.size(), 3);
    CHECK_GE(rawDims_.size(), 1);
    return rawDims_;
}

template<typename T>
std::vector<uint32_t> Tensor<T>::GetShape() const {
    CHECK(!data_.empty()) << "The data area of the tensor is empty.";
    return {GetChannels(), GetRows(), GetCols()};
}

template<typename T>
uint32_t Tensor<T>::GetChannels() const {
    CHECK(!data_.empty()) << "The data area of the tensor is empty.";
    return data_.n_slices;
}

template<typename T>
uint32_t Tensor<T>::GetRows() const {
    CHECK(!data_.empty()) << "The data area of the tensor is empty.";
    return data_.n_rows;
}

template<typename T>
uint32_t Tensor<T>::GetCols() const {
    CHECK(!data_.empty()) << "The data area of the tensor is empty.";
    return data_.n_cols;
}

template<typename T>
size_t Tensor<T>::GetSize() const {
    CHECK(!data_.empty()) << "The data area of the tensor is empty.";
    return data_.size();
}

template<typename T>
size_t Tensor<T>::GetPlaneSize() const {
    CHECK(!data_.empty()) << "The data area of the tensor is empty.";
    return GetCols() * GetCols();
}

template<typename T>
bool Tensor<T>::empty() const {
    return data_.empty();
}

template<typename T>
void Tensor<T>::SetData(const arma::Cube<T>& data) {
    CHECK(data.n_rows == data_.n_rows) << data.n_rows << " != " << data_.n_rows;
    CHECK(data.n_cols == data_.n_cols) << data.n_cols << " != " << data_.n_cols;
    CHECK(data.n_slices == data_.n_slices) << data.n_slices << " != " << data_.n_slices;
    data_ = data;
}

template<typename T>
T& Tensor<T>::index(uint32_t offset) {
    CHECK(offset < data_.size()) << "Tensor index out of bound";
    return data_.at(offset);
}

template<typename T>
const T& Tensor<T>::index(uint32_t offset) const {
    CHECK(offset < data_.size()) << "Tensor index out of bound";
    return data_.at(offset);
}

template<typename T>
arma::Cube<T>& Tensor<T>::data() {
    return data_;
}

template<typename T>
const arma::Cube<T>& Tensor<T>::data() const {
    return data_;
}

template<typename T>
arma::Mat<T>& Tensor<T>::slice(uint32_t channel) {
    CHECK_LT(channel, GetChannels());
    return data_.slice(channel);
}

template<typename T>
const arma::Mat<T>& Tensor<T>::slice(uint32_t channel) const {
    CHECK_LT(channel, GetChannels());
    return data_.slice(channel);
}

template<typename T>
T& Tensor<T>::at(uint32_t channel, uint32_t row, uint32_t col) {
    CHECK_LT(channel, GetChannels());
    CHECK_LT(row, GetRows());
    CHECK_LT(col, GetCols());
    return data_.at(row, col, channel);
}

template<typename T>
const T& Tensor<T>::at(uint32_t channel, uint32_t row, uint32_t col) const {
    CHECK_LT(channel, GetChannels());
    CHECK_LT(row, GetRows());
    CHECK_LT(col, GetCols());
    return data_.at(row, col, channel);
}

template<typename T>
void Tensor<T>::Show() {
    for (uint32_t i = 0; i < GetChannels(); ++i) {
        LOG(INFO) << "Channel: " << i
                  << "\n"
                  << data_.slice(i);
    }
}

template class Tensor<float>;
template class Tensor<uint32_t>;
template class Tensor<uint8_t>;
}// namespace InferEngine