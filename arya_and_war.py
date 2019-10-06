"""
    Arya and the Great War - GeeksForGeeks
    Problem Link: https://practice.geeksforgeeks.org/problems/arya-and-the-great-war/0

    Author: Shyam Kumar
    Date: 09-06-2019

"""

def binary(n):
	global s
	if n > 1:
		binary(n//2)
	s+=str(n%2)
	return s

def main():
	global s
	t=int(input())
	for _ in range(t):
	    n=int(input())
	    count=0
	    s=""
	    st=binary(n)
	    for c in st:
	    	if c=='1':
	    		count+=1
	    print(count)

if __name__ == '__main__':
	s=""
	main()