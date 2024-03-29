//
// Created by 赵丹 on 2024/3/27.
//

#ifndef LEETCODE_PRACTICE_DYNAMIC_MEMORY_TEST_H
#define LEETCODE_PRACTICE_DYNAMIC_MEMORY_TEST_H
#include "utils.h"

namespace DynamicMemoryTest {
class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and delete element
    void push_back(const std::string& t) { data->push_back(t); }
    void pop_back();

    // visit element
    std::string& front();
    std::string& back();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;
};
}// namespace DynamicMemoryTest

#endif//LEETCODE_PRACTICE_DYNAMIC_MEMORY_TEST_H
