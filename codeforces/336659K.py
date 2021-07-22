import decimal
N, k = map(int, input().split())
D = decimal.Decimal
n = D(N)

with decimal.localcontext() as ctx:
    ctx.prec = 20000
    x = n.sqrt()
    s  = str(x)
    res = ""
    cuenta = 0
    flag = False
    for i, c in enumerate(s):
        if flag: cuenta += 1
        if c == '.': 
            flag = True
        res += c
        if flag and cuenta == k:
            break
    if not flag:
        res += '.'
        for i in range(0, k):
            res += '0' 
    print(res)