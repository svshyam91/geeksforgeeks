"""
    Print Pattern - GeeksForGeeks
    Problem Link: https://practice.geeksforgeeks.org/problems/print-pattern/0

    Author: Shyam Kumar
    Date: 10-06-2019

"""

def print_pattern(n, a):
    global flag
    if a != n:
        print(a,end=" ")
        if a < 0 or a == 0:
            flag=1
        if flag == 0:
            a=a-5
        else:
            a=a+5
        print_pattern(n,a)

t=int(input())
for _ in range(t):
    n=int(input())
    if n > 0:
        a=n-5
    else:
        a=n+5
    flag=0
    print(n,end=" ")
    print_pattern(n,a)
    print(n)

