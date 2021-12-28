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
    while i < 4:
        tmp_x = dx[i] + x
        tmp_y = dy[i] + y
        if (tmp_x >= 0 and tmp_y >= 0) and (tmp_x < C and tmp_y < R) and arr[x][y] != -1:
            arr[tmp_x][tmp_y] += fine_dust
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

def left(arr, R, C, location):
    list = []
    tmp = 0
    return list

def right(arr, R, C, x, y):
    recent_tmp = 0
    last_tmp = 0
    i = 0
    while x + i < C:
        
#        if i == 0:
#            last_tmp = arr[y][x + i]
#            recent_tmp = arr[y][x + i + 1]
#            arr[y][i + i] = 0
#        else:
#            arr[y][i + i] = last_tmp
#            last_tmp = recent_tmp
#            recent_tmp = arr[y][x + i + 1]
        i += 1

    location.append()
    return location 

def up(arr, R, C, location):
    tmp = 0

def down(arr, R, C, location):
    tmp = 0

def clearner(arr, R, C, x, y, dir):
    location_list = []
    #location.append([x + 1, y, 0] )
    if dir == COUNTERCLOCKWISE:
        right(arr, R, C, x + 1, y)
#        right(arr, R, C, location)
#        location = right(arr, R, C, location)
#        location = up(arr, R, C, location)
#        location = left(arr, R, C, location)
#        down(arr, R, C, location)
    elif dir == CLOCKWISE:
        location = right(arr, R, C, location)
        location = down(arr, R, C, location)
        location = left(arr, R, C, location)
        up(arr, R, C, location)

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
    fine_dust_diffusion(arr, R, C)
    #air_cleaner(arr, R, C)
    i += 1
result = get_result(arr, R, C)
print(result)
