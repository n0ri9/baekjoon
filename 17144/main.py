from math import floor

COUNTERCLOCKWISE = 0
CLOCKWISE = 1
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def get_result(arr, R, C):
    result = 0
    i = 0
    while i < C:
        j = 0
        while j < R:
            result += arr[j][i]
            j += 1
        i += 1
    return result

def diffusion(arr, R, C, x, y):
    fine_dust = arr[x][y]
    arr[x][y] = 0
    fine_dust /= 5
    fine_dust = floor(fine_dust)
    can_diffusion_cnt = 0
    i = 0
    while i < 4:
        tmp_x = int(dx[i]) + int(x)
        tmp_y = int(dy[i]) + int(y)
        if (tmp_x >= 0 and tmp_y >= 0) and (tmp_x < C and tmp_y < R) and arr[x][y] != -1:
            tmp = int(arr[tmp_x][tmp_y]) + fine_dust
            arr[tmp_x][tmp_y] = tmp
            can_diffusion_cnt += 1
        i += 1
    arr[x][y] = (5 - can_diffusion_cnt) * fine_dust

def check_fine_dust(arr, R, C):
    fine_dust_list = []
    i = 0
    while i < C:
        j = 0
        while j < R:
            if arr[j][i] > 0:
                fine_dust_list.append([j, i])
            j += 1
        i += 1
    return (fine_dust_list)

def fine_dust_diffusion(arr, R, C, fine_dust_list):
    for fine_dust in fine_dust_list:
        x = fine_dust[0]
        y = fine_dust[1]
        diffusion(arr, R, C, x, y)

def apply_left(arr, R, C, x, y, location_list):
    i = 0
    while x + i < C:
        arr[x - i, y] = location_list.pop()
        i += 1

def apply_right(arr, R, C, x, y, location_list):
    i = 0
    while x + i < C:
        arr[x + i, y] = location_list.pop()
        i += 1

def apply_up(arr, R, C, x, y, location_list):
    i = 0
    while y + i < R - 1:
        arr[x, y + i] = location_list.pop()
        i += 1

def apply_down(arr, R, C, x, y, location_list):
    i = 0
    while y + i < R - 1:
        arr[x, y + i] = location_list.pop()
        i += 1

def left(arr, R, C, x, y):
    i = 0
    list = []
    while x + i < C:
        list.append([x - i, y])
        i += 1

    return list

def right(arr, R, C, x, y):
    i = 0
    list = []
    while x + i < C:
        list.append([x + i, y])
        i += 1

    return list

def up(arr, R, C, x, y):
    i = 0
    list = []
    while y + i < R - 1:
        list.append([x, y + i])
        i += 1

    return list

def down(arr, R, C, x, y):
    i = 0
    list = []
    while y + i < R - 1:
        list.append([x, y + i])
        i += 1

    return list

def apply_clearner(arr, R, C, x, y, location_list, dir):
    if dir == COUNTERCLOCKWISE:
        apply_right(arr, R, C, x + 1, y, location_list)
        apply_up(arr, R, C, 0, R - 1, location_list)
        apply_left(arr, R, C, C - 1, R - 1, location_list)
        apply_down(arr, R, C, C - 1, y, location_list)
    elif dir == CLOCKWISE:
        apply_right(arr, R, C, x + 1, y)
        apply_down(arr, R, C, C - 1, y)
        apply_left(arr, R, C, C - 1, R - 1)
        apply_up(arr, R, C, 0, R - 1)
    

def clearner(arr, R, C, x, y, dir):
    location_list = []
    #location.append([x + 1, y, 0] )
    if dir == COUNTERCLOCKWISE:
        location_list.append(right(arr, R, C, x + 1, y))
        location_list.append(up(arr, R, C, 0, R - 1))
        location_list.append(left(arr, R, C, C - 1, R - 1))
        location_list.append(down(arr, R, C, C - 1, y))
        location_list.insert(0, 0)
        apply_clearner(arr, R, C, x, y, location_list, dir)

    elif dir == CLOCKWISE:
        location_list.append(right(arr, R, C, x + 1, y))
        location_list.append(down(arr, R, C, C - 1, y))
        location_list.append(left(arr, R, C, C - 1, R - 1))
        location_list.append(up(arr, R, C, 0, R - 1))
        location_list.insert(0, 0)
        apply_clearner(arr, R, C, x, y, location_list, dir)
        

def air_cleaner(arr, R, C):
    i = 0
    cnt = 0
    while i < C:
        j = 0
        while j < R:
            if arr[j][i] == -1:
                clearner(arr, R, C, j, i, cnt)
                cnt += 1
            j += 1
        i += 1

R, C, T = map(int, input().split())
arr = [0 for _ in range(C)]
for i in range(R):
    arr[i] = list(map(int, input().split(' ')))
i = 0
while i < T:
    fine_dust_list = check_fine_dust(arr, R, C)
    fine_dust_diffusion(arr, R, C, fine_dust_list)
    air_cleaner(arr, R, C)
    i += 1
result = get_result(arr, R, C)
print(result)
