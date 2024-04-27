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
}// namespace InferEngine