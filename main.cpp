#include "gtest/gtest.h"
#include "glog/logging.h"

int main() {
    testing::InitGoogleTest();
    google::InitGoogleLogging("test");
    FLAGS_logtostderr = true;
    return RUN_ALL_TESTS();
}
