//
// Created by richard on 4/28/24.
//
#include "Tensor.hpp"
#include "utils.h"

namespace InferEngine {
TEST(TensorTest, init1D) {
    Tensor<float> f1(4);
    f1.Fill(1.f);

    LOG(INFO) << "--------------------Tensor1D--------------------";
    LOG(INFO) << "raw shape size: " << f1.GetRawShape().size();
    LOG(INFO) << "data numbers: " << f1.GetRawShape()[0];
    f1.Show();
}

TEST(TensorTest, init2D) {
    Tensor<float> f1(5, 5);
    f1.Fill(1.0);
    LOG(INFO) << "--------------------Tensor2D--------------------";
    LOG(INFO) << "raw shape size: " << f1.GetRawShape().size();
    uint32_t rows = f1.GetRawShape()[0];
    uint32_t cols = f1.GetRawShape()[1];
    LOG(INFO) << "data rows: " << rows;
    LOG(INFO) << "data cols: " << cols;
    LOG(INFO) << "data size: " << f1.GetSize();
    LOG(INFO) << "data plane size: " << f1.GetPlaneSize();
    f1.Show();
}
}// namespace InferEngine