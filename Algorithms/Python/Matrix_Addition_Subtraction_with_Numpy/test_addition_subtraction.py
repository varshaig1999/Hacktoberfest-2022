from add_matrices import two_matrices_addition
from subtract_matrices import two_matrices_subtraction
# Tests
test_matrix_A = [5, 6]
test_matrix_B = [7, 6]

print(f"First matrix {test_matrix_A}")
print(f"Second matrix {test_matrix_B}")
print("Matrix Addition")
print(two_matrices_addition(test_matrix_A, test_matrix_B))
print("Matrix Subtraction")
print(two_matrices_subtraction(test_matrix_A, test_matrix_B))
