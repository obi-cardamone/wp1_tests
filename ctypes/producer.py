import sys
import ctypes
import numpy as np

func = ctypes.CDLL('./my_low_level_library.so').my_low_level_function
func.restype = None
func.argtypes = [
    np.ctypeslib.ndpointer(ctypes.c_float, flags="C_CONTIGUOUS"),
    np.ctypeslib.ndpointer(ctypes.c_float, flags="C_CONTIGUOUS"),
    ctypes.c_size_t
]

def run(run_type: str):
    num_iterations = 32; len_data = int(2 ** 30)
    # Generate some data
    input_data = np.linspace(
        start=0, stop=len_data-1, num=len_data, dtype=np.single
    )
    output_data = np.zeros((len_data,), dtype=np.single)
    # Process a number of consecutive segments of data
    for _ in range(num_iterations):
        if run_type == "np":
            output_data = input_data * input_data
        elif run_type == "cpp":
            # Call the low-level library and await the output
            func(input_data, output_data, len_data)
        else:
            raise ValueError("Unrecognised run type: {}".format(run_type))
            
run(sys.argv[1])
