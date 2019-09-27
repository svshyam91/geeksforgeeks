"""
    The Even Array
    Problem Link: https://practice.geeksforgeeks.org/problems/the-even-array/0

    Author: Shyam Kumar
    Date: 13-09-2019

"""


def the_even_array(s):
    auto_next = 0
    l = len(s)
    count=0
    for i in range(l):
        if s[i] == 'O' and auto_next == 0:
            s=s.replace('O','E',1)
            auto_next=1
            count+=1
        elif s[i] == 'O' and auto_next == 1:
            s=s.replace('O','E',1)
            auto_next=1
        else:
            auto_next=0
    return count

def main():
    t=int(input())
    while(t>0):
        
        # Try-except block is only used to remove EOF error 
        # that comes on online compiler
        try:
            s=input()
        except:
            pass
        ans = the_even_array(s)
        print(ans)
        t-=1

if __name__ == "__main__":
    main()