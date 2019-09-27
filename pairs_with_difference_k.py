""" 
    Pairs with difference K - GeeksForGeeks
    Problem Link: https://practice.geeksforgeeks.org/problems/pairs-with-difference-k/0

    Author: Shyam Kumar
    Date: 15-09-2019

"""


from itertools import combinations

def pairs_with_difference(n,k,arr):
    'This function uses combinations method to find all the combinations'

    comb=combinations(arr,2)
    count=0
    for t in list(comb):
        if( abs(t[0]-t[1]) == k ):
            count+=1
    return count

def main():
    t=int(input())
    while(t>0):
        n,k=input().split()
        k=int(k)
        arr=list(map(int,input().split()))
        ans = pairs_with_difference(n,k,arr)
        print(ans)
        t-=1

if __name__ == "__main__":
    main()