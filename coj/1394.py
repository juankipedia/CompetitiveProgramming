
def f(n):
	if n == 1:
		return 1
	elif n % 2 == 0:
		return n / 2
	else:
		return f((n - 1)/2) + f((n - 1)/2 + 1)

n = int(input())
while n != -1:
	print("f(" + str(n) + ") = " + str(f(n)))
	n = int(input())
	if n != -1 :
		print("");