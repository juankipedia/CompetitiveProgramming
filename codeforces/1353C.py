t = int(input())

while t > 0:
    t = t - 1
    n = int(input())
    m = 0
    i = 3
    j = 1
    while i <= n:
        m += (i * 4 - 4) * j
        i += 2
        j += 1

    print(m)