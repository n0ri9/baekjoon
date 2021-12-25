h, m, s = input().split()

h = int(h) * 3600
m = int(m) * 60
s = int(s)

add = int(input()) 
result = h + m + s + add
hour = int(result / 3600);
hour %= 24;
result %= 3600;
minute = int(result / 60);
result %= 60;
second = result;
print (hour, minute, second, sep=' ')
