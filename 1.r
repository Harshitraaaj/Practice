# Create two 3x3 matrixes.
m1 = matrix(c(1, 2, 3, 4, 5, 6,7,8,9), nrow = 3)
print("Matrix-1:")
print(m1)
m2 = matrix(c(0, 1, 2, 3, 0, 2,2,2,2), nrow = 3)
print("Matrix-2:")
print(m2)

result = m1 + m2
print("Result of addition")
print(result)

result = m1 - m2
print("Result of subtraction")
print(result)

result = m1 * m2
print("Result of multiplication")
print(result)

result = t(m1)
print("Transpose is:")
print(result)
