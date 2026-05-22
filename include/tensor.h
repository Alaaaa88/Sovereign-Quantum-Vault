#pragma once
#include <vector>
#include <memory>
#include <iostream>

namespace sse {
    template <typename T>
    class Tensor {
    public:
        Tensor(size_t rows, size_t cols) : rows_(rows), cols_(cols), data_(rows * cols) {}

        T& operator()(size_t r, size_t c) { return data_[r * cols_ + c]; }
        size_t size() const { return rows_ * cols_; }
        T* data() { return data_.data(); }

    private:
        size_t rows_, cols_;
        std::vector<T> data_;
    };
}