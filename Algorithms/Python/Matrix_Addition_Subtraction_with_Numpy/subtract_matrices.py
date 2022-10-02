import numpy as np

def two_matrices_subtraction(matrix_one, matrix_two):
    # return the subtraction of matrix matrix_two from matrix matrix_one

    # cast to numpy arrays
    matrix_one = np.array(matrix_one)
    matrix_two = np.array(matrix_two)

    return np.subtract(matrix_one, matrix_two)

