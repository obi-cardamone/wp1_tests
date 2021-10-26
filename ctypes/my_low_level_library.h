/**
 * @file my_low_level_library.h
 */
#ifndef __MY_LOW_LEVEL_LIBRARY_H
#define __MY_LOW_LEVEL_LIBRARY_H

extern "C" {
    void my_low_level_function(
        float * p_in, float * p_out, uint64_t num_vals
    );
}
#endif /* #ifndef __MY_LOW_LEVEL_LIBRARY_H */

