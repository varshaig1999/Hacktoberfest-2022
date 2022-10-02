import numpy as np

def two_matrices_addition(matrix_one, matrix_two):
    # return the sum of matrix one with matrix two

    # cast to numpy array
    matrix_one = np.array(matrix_one)
    matrix_two = np.array(matrix_two)

    return np.add(matrix_one, matrix_two)
