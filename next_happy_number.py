"""
	Next Happy Number
	Problem Link: https://practice.geeksforgeeks.org/problems/next-happy-number/0

	Author: Shyam Kumar
	Date: 12-09-2019

"""


def digit_square_sum(n):
	sum = 0
	while n > 0:
		rem = n % 10
		sum += rem*rem
		n = n // 10
	return sum


def next_happy_number(n):

	"""Max 100 times the value of sum is calculated and 
	checked, if the value of sum is not found to be 1
	then it is considered as NOT HAPPY VALUE """ 
	for _ in range(100):
		dss = digit_square_sum(n)
		if dss == 1:
			return True
		n = dss

	""" If after 100 times, the value of sum is never found
		to be 1, so we considering this as limit and hence 
		the number is not happy number """
	return False
 
def main():
    t = int(input())
    while(t>0): 
        n = int(input())
        n+=1
        while True:
        	ans=next_happy_number(n)
        	if ans == True:
        		break
        	n+=1
        print(n)
        t-=1

if __name__ == "__main__":
    main()
