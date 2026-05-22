#include <immintrin.h>

namespace Sovereign::Engine::Kernels {

    // نستخدم __attribute__ للتأكد أن هذه الدالة تُجمع فقط للـ AVX-512
    // وهذا يمنع المترجم من محاولة استدعائها في المعالجات غير الداعمة
    __attribute__((target("avx512f")))
    void vector_add_avx512(const float* a, const float* b, float* result, size_t n) {
        for (size_t i = 0; i < n; i += 16) {
            __m512 va = _mm512_loadu_ps(&a[i]); // نستخدم loadu لتجنب مشاكل المحاذاة مؤقتاً
            __m512 vb = _mm512_loadu_ps(&b[i]);
            __m512 vr = _mm512_add_ps(va, vb);
            _mm512_storeu_ps(&result[i], vr);
        }
    }
}