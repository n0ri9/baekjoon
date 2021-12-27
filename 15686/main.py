from itertools import combinations

def get_chicken_distance(chicken_list, house_list):
    h_x = 0
    h_y = 0
    c_x = 0
    c_y = 0
    result = 0
    for house in house_list:
        min = -1
        for chicken in chicken_list:
            h_x = house[0]
            h_y = house[1]
            c_x = chicken[0]
            c_y = chicken[1]
            distance = abs(h_x - c_x) + abs(h_y - c_y)
            if min == -1:
                min = distance
            elif min > distance:
                min = distance 
        result += min
    return result 

n, m = map(int, input().split())
arr = [0 for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int, input().split(' ')))
house_list = []
chicken_list = []

i = 0
while i < n:
    j = 0
    while j < n:
        if arr[i][j] == 1:
            house_list.append([j,i])
        elif arr[i][j] == 2:
            chicken_list.append([j,i])
            arr[i][j] == 0
        j += 1
    i += 1
comb = combinations(chicken_list, m)

result = []
for c in comb:
    tmp = get_chicken_distance(c, house_list)
    result.append(tmp)

print(min(result))

#queue = []
#def bfs(arr, y, x):
#    arr[y][x] = 8
#    print('queue_len : {}'.format(len(queue)))
#    print(queue)
#    cnt = 0
#    tmp_x = [1, 0, -1, 0]
#    tmp_y = [0, 1, 0, -1]
#    i = 0
#    while i < 4:
#        next_x = x + tmp_x[i]
#        next_y = y + tmp_y[i]
#        if next_x >= 0 and next_y >= 0 and next_x < n and next_y < n:
#            if arr[next_y][next_x] == 4:
#                arr[y][x] = 0
#                return (1);
#            else:
#                queue.append([next_y, next_x])
#        i += 1
#    if len(queue) != 0:
#        remove_el = queue.pop(0)
#        next_x = remove_el[0]
#        next_y = remove_el[1]
#        cnt = bfs(arr, next_y, next_x)
#        cnt += 1
#    arr[y][x] = 0
#    return cnt
#
#def print_arr(arr):
#    i = 0
#    j = 0
#    while i < 5:
#        print(arr[i])
#        i += 1
#
#def bfs_init(comb):
#    print('comb {}'.format(comb))
#    print('bfs_init')
#    print_arr(arr)
#    result = 0
#    for tmp in comb:
#        arr[tmp[1]][tmp[0]] = 4
#    i = 0
#    while i < n:
#        j = 0
#        while j < n:
#            if arr[i][j] == 1:
#                print('bfs_start')
#                arr[i][j] = 8
#                result = bfs(arr, i, j)
#                queue.clear()
#                arr[i][j] = 1
#            j += 1
#        i += 1
#    for tmp in comb:
#        arr[tmp[1]][tmp[0]] = 0
#    return result
