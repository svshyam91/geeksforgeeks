"""
    Maximize Toys
    Problem Link: https://practice.geeksforgeeks.org/problems/maximize-toys/0

    Author: Shyam Kumar
    Date: 13-11-2019

"""

def maximizeToys(s, totalAmt, costToys):
    costToys.sort()
    count=0
    for ct in costToys:
        if ct > totalAmt:
            break;
        else:
            totalAmt-=ct
            count+=1
    return count

if __name__ == "__main__":
    t=int(input())
    for _ in range(t):
        s,totalAmt=map(int, input().split())
        costToys=list(map(int, input().split()))
        ans=maximizeToys(s, totalAmt, costToys)
        print(ans)
    