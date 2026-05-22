#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

namespace sse {
    template <typename T>
    class Tensor {
    public:
        // محاذاة الذاكرة (Memory Alignment) ضرورية لـ AVX
        Tensor(size_t rows, size_t cols) : rows_(rows), cols_(cols), data_(rows * cols) {}

        T& operator()(size_t r, size_t c) { return data_[r * cols_ + c]; }
        
        size_t rows() const { return rows_; }
        size_t cols() const { return cols_; }
        T* data() { return data_.data(); }

    private:
        size_t rows_, cols_;
        std::vector<T> data_;
    };
}