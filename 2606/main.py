pc_num = input()
pc_ssang = input()
pc_num = int(pc_num)
pc_ssang = int(pc_ssang)

virus = 0
array = [[0 for col in range(100)] for row in range(100)]
visited = [0 for row in range(100)]

def dfs (pc_num, now):
    global virus
    for i in range(pc_num):
        if visited[i] == 0 and array[now][i]:
            visited[i] = 1
            dfs(pc_num, i)
            virus += 1

i = 0
while i < pc_ssang:
    a, b = input().split(' ')
    a = int(a)
    b = int(b)
    array[a - 1][b - 1] = 1;
    array[b - 1][a - 1] = 1;
    i += 1

visited[0] = 1
dfs(pc_num, 0)
print(virus)
