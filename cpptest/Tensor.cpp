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
void Tensor<T>::Fill(T value) {
    CHECK(!data_.empty()) << "The data area of the tensor is empty.";
    data_.fill(value);
}

template<typename T>
const std::vector<uint32_t>& Tensor<T>::GetRawShape() const {
    CHECK(!rawDims_.empty());
    CHECK_LE(rawDims_.size(), 3);
    CHECK_GE(rawDims_.size(), 1);
    return rawDims_;
}

template<typename T>
uint32_t Tensor<T>::GetChannels() const {
    CHECK(!data_.empty()) << "The data area of the tensor is empty.";
    return data_.n_slices;
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
}// namespace InferEngine