if __name__ == "__main__":
    t = int(input())
    i = 0
    while i < t:
        a, b = input().split()
        a = int(a)
        b = int(b)
        result = a ** b
        result = str(result)
        print(result[len(result) - 1])
        i += 1
