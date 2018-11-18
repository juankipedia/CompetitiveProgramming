n = int(input())
r = 0
while n != 0:
	n -= 1
	r += int(input()) % 128
print(r % 128)