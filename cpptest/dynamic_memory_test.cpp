//
// Created by richard on 1/26/24.
//
#include "dynamic_memory_test.h"
namespace DynamicMemoryTest {
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}


}// namespace DynamicMemoryTest