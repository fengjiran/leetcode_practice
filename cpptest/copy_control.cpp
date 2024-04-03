//
// Created by 赵丹 on 2024/4/1.
//
#include "copy_control.h"

namespace CopyControlTest {
HasPtrLikePointer& HasPtrLikePointer::operator=(const CopyControlTest::HasPtrLikePointer& rhs) {
    if (this != &rhs) {
        ++*rhs.cnt;
        if (--*cnt == 0) {
            delete ps;
            delete cnt;
        }
        ps = rhs.ps;
        i = rhs.i;
        cnt = rhs.cnt;
    }
    return *this;
}

HasPtrLikePointer::~HasPtrLikePointer() {
    if (--*cnt == 0) {
        delete ps;
        delete cnt;
    }
}
}// namespace CopyControlTest