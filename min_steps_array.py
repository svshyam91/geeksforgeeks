""" 
    Minimum steps to get desired array - GeeksForGeeks
    Problem Link: https://practice.geeksforgeeks.org/problems/minimum-steps-to-get-desired-array/0
    
    Author: Shyam Kumar 

"""

def min_steps(arr, n):
    count=0
    while True:

        # To check all elements are zero
        all_zeros=True      

        # To check if all elements are even
        even=True
        
        for i,value in enumerate(arr):
            if value != 0:
                all_zeros=False

            # If an element is off, decrease it and increase the count
            if value%2 != 0:        # Check for odd
                arr[i]-=1
                count+=1
                even=False

        # If all the elements are even
        if even == True:
            for i,value in enumerate(arr):
                arr[i]=arr[i]//2
            count+=1

        # If all the elements are 0
        if all_zeros == True: 
            break
    return count-1
        
        


t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(map(int, input().split()))
    ans=min_steps(arr, n)
    print(ans)