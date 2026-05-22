cmake_minimum_required(VERSION 3.14)
project(SovereignVault CXX)
set(CMAKE_CXX_STANDARD 20)

# تحسين الأداء عبر الـ Compiler Flags
add_compile_options(-O3 -march=native -Wall -Wextra)

add_library(sse_core STATIC sovereign_engine.cpp kernels_scalar.cpp)
add_executable(ai_inference main.cpp)
target_link_libraries(ai_inference PRIVATE sse_core)