#include "sovereign_engine.h"
#include <cstdint>
#include <algorithm>

namespace sse {
    void SovereignEngine::infer(const int16_t* input, const int16_t* weights, 
                               const int16_t* bias, int16_t* output, 
                               size_t in_size, size_t out_size) noexcept {
        // حلقة الاستدلال (Dense Layer Logic)
        for (size_t j = 0; j < out_size; ++j) {
            int32_t sum = static_cast<int32_t>(bias[j]);
            for (size_t i = 0; i < in_size; ++i) {
                // الوصول للمصفوفة بالترتيب row-major: index = i * out_size + j
                sum += static_cast<int32_t>(input[i]) * static_cast<int32_t>(weights[i * out_size + j]);
            }
            // ReLU Activation: ضروري لمنع القيم السالبة في الشبكات العصبية
            output[j] = static_cast<int16_t>(std::max(0, sum));
        }
    }
}