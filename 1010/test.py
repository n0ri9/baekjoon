import math
n = int(input())
r = int(input())

result = math.factorial(n) / (math.factorial(n - r) * math.factorial(r))
print(int(result))
