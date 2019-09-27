"""
    Two numbers with sum closest to zero - GeeksForGeeks
    Problem Link: https://practice.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero/0

    Note: This solution is based on Dynamic Programming( Memoization )

    Author: Shyam Kumar
    Date: 15-09-2019

"""

# INCOMPLETE

from itertools import combinations

def sum_closest_to_zero(size, arr):
    
    closest_number=arr[0]+arr[1]
    
    for i in range(0,size-1):
        for j in range(i+1,size):
            
            add=arr[i]+arr[j]
            if abs(add) < abs(closest_number):
                closest_number=add
            elif abs(add) == abs(closest_number):
                if(add < 0):
                    closest_number=add
                
    return closest_number
    
    # comb_lst=list(combinations(arr,2))
    # closest_number=sum(comb_lst[0])
    # i=1
    # l=len(comb_lst)
    # while i < l:
    #     n=sum(comb_lst[i])
    #     if( abs(n) < abs(closest_number) ):
    #         closest_number=n
            
    #     i+=1
    # return closest_number

def main():
    t=int(input())
    while t > 0:
        size=int(input())
        arr=list(map(int,input().split()))
        ans=sum_closest_to_zero(size, arr)
        print(ans)
        t-=1
    
    
if __name__ == "__main__":
    main()