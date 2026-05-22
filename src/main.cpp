#include "sovereign_engine.h"
#include <iostream>
#include <vector>
#include <cassert>

int main() {
    sse::SovereignEngine engine;
    
    // تعريف مصفوفة المدخلات والأوزان بدقة هندسية
    std::vector<int16_t> input = {2, 2, 2};
    std::vector<int16_t> weights = {3, 1, 3, 1, 3, 1}; // 3x2 Matrix
    std::vector<int16_t> bias = {0, 0};
    std::vector<int16_t> output = {0, 0};

    engine.infer(input.data(), weights.data(), bias.data(), output.data(), 3, 2);

    // التحقق من صحة النتائج (Assertion)
    if(output[0] == 18 && output[1] == 6) {
        std::cout << "[SUCCESS] Inference Verified: " << output[0] << ", " << output[1] << std::endl;
    } else {
        std::cerr << "[ERROR] Logic Mismatch! Expected 18, 6 but got " << output[0] << ", " << output[1] << std::endl;
    }
    
    return 0;
}