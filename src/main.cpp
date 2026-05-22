#include <iostream>
#include <vector>
#include <cpuid.h>
#include "src/engine/avx512_kernels.cpp" // هنا توجد دوال الـ Kernels

// تعريف دالة التحقق في البداية لتكون مرئية للجميع
bool check_avx512() {
    unsigned int eax, ebx, ecx, edx;
    if (__get_cpuid_count(7, 0, &eax, &ebx, &ecx, &edx)) {
        return (ebx & (1 << 16)); 
    }
    return false;
}

// دالة التشغيل التي تختار الـ Kernel المناسب
void run_vector_add(const float* a, const float* b, float* res, size_t n) {
    if (check_avx512()) {
        std::cout << "Running AVX-512 Kernel..." << std::endl;
        Sovereign::Engine::Kernels::vector_add_avx512(a, b, res, n);
    } else {
        std::cout << "Running Scalar (Fallback) Kernel..." << std::endl;
        for (size_t i = 0; i < n; i++) {
            res[i] = a[i] + b[i];
        }
    }
}

int main() {
    size_t n = 16;
    float a[16] = {1.0f}, b[16] = {2.0f}, res[16] = {0};
    
    run_vector_add(a, b, res, n);
    
    std::cout << "Engine status: Success. Result[0]: " << res[0] << std::endl;
    return 0;
}