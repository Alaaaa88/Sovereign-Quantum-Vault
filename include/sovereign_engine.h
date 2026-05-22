#pragma once
#include <cstddef>
#include <cstdint>

namespace sse {
    class SovereignEngine {
    public:
        void infer(const int16_t* input, const int16_t* weights, 
                   const int16_t* bias, int16_t* output, 
                   size_t in_size, size_t out_size) noexcept;
    };
    void compute_dot_product(const int16_t* input, const int16_t* weights, int16_t* output, size_t in_size);
}