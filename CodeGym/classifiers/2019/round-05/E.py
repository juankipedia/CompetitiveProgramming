from __future__ import division
 
def main():
	n = input() 
	sum = 0
	for x in range(2, n + 1):
		sum += x * (x-1)
 
	result = sum/n
	print('%.10f'%result)
 
if __name__ == "__main__":
	main()