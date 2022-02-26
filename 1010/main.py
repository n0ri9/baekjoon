import math

i = 0
t = int(input())

while i < t:
    m, n = input().split()
    m = int(m)
    n = int(n)
    result = math.factorial(n) / (math.factorial(n - m) * math.factorial(m))
    result = int(result)
    print(result)
    i += 1
