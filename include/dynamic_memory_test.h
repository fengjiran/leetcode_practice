//
// Created by 赵丹 on 2024/3/27.
//

#ifndef LEETCODE_PRACTICE_DYNAMIC_MEMORY_TEST_H
#define LEETCODE_PRACTICE_DYNAMIC_MEMORY_TEST_H
#include <utility>

#include "utils.h"

namespace DynamicMemoryTest {
class StrBlob {
public:
    //    typedef std::vector<std::string>::size_type size_type;
    using size_type = std::vector<std::string>::size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and delete element
    void push_back(const std::string& t) { data->push_back(t); }
    void push_back(std::string&& t) { data->push_back(t); }
    void pop_back();

    // visit element
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;
};

class QueryResult {
public:
    using size_type = std::vector<std::string>::size_type;
    QueryResult(std::string s,
                std::shared_ptr<std::vector<std::string>> f,
                std::shared_ptr<std::set<size_type>> p)
        : sought(std::move(s)), file(std::move(f)), lines(std::move(p)) {}

private:
    std::string sought;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<size_type>> lines;
    friend std::ostream& print(std::ostream& os, const QueryResult& qr);
};

class TextQuery {
public:
    using size_type = std::vector<std::string>::size_type;
    TextQuery() = delete;
    explicit TextQuery(std::ifstream& is);
    QueryResult query(const std::string& sought) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<size_type>>> wm;
};

}// namespace DynamicMemoryTest

#endif//LEETCODE_PRACTICE_DYNAMIC_MEMORY_TEST_H
