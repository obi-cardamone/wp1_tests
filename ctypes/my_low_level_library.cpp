/**
 * @file my_low_level_library.cpp
 */
#include <thread>

static void thread_func(float * p_in, float * p_out, uint64_t num_vals) {
    for (auto idx=0; idx<num_vals; ++idx)
    {
        p_out[idx] = p_in[idx] * p_in[idx];
    }  
}

extern "C" {

void my_low_level_function(
    float * p_in, float * p_out, uint64_t num_vals
) {
    std::thread thread_a(thread_func, p_in, p_out, num_vals/2);
    std::thread thread_b(
        thread_func, p_in + num_vals/2, p_out + num_vals/2, num_vals/2
    );

    thread_a.join(); thread_b.join();
}

}
