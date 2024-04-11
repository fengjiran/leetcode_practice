//
// Created by richard on 1/26/24.
//
#include "dynamic_memory_test.h"
namespace DynamicMemoryTest {

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending) {
    return ctr > 1 ? word + ending : word;
}

std::ostream& print(std::ostream& os, const QueryResult& qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << std::endl;

    for (auto num: *qr.lines) {
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << std::endl;
    }
    return os;
}

void runQueries(std::ifstream& infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "Enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(StrBlob::size_type i, const std::string& msg) const {
    if (data->size() <= i) {
        throw std::out_of_range(msg);
    }
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

TextQuery::TextQuery(std::ifstream& is) : file(new std::vector<std::string>) {
    std::string text;
    while (getline(is, text)) {
        file->push_back(text);
        size_type n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            auto& lines = wm[word];
            if (!lines) {
                lines.reset(new std::set<size_type>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string& sought) const {
    static std::shared_ptr<std::set<size_type>> nodata(new std::set<size_type>);
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return {sought, file, nodata};
    } else {
        return {sought, file, loc->second};
    }
}


TEST(DynamicMemoryTest, test1) {
    std::cout << "\ndynamic memory test1:\n";
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        std::cout << b2.size() << std::endl;
    }
    std::cout << b1.size() << std::endl;
    std::cout << b1.front() << " " << b1.back() << std::endl;
    const StrBlob b3 = b1;
    std::cout << b3.front() << " " << b3.back() << std::endl;
}

TEST(DynamicMemoryTest, test2) {
    //
}

}// namespace DynamicMemoryTest
