''' 
    Count Occurences of Anagrams- GeeksForGeeks
    Problem Link: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams/0

    Author: Shyam Kumar
    Date: 27th Sep, 2019

'''


def check_anagram(count_s, count_w):
    """ This function returns True if the two list are identical """

    str1="".join(map(str,count_s))
    str2="".join(map(str,count_w))
    if str1 == str2:
        return True


def count_occurances_of_anagrams(S,w):
    """ This function counts the number of occurences of anagrams in S """

    # List of size 26 and initialized to 0 for counting chars in w
    count_w=[0]*26  i
    count=0         # count anagrams

    # Count the characters in word w
    for c in w:
        count_w[ord(c)-97]+=1
    l1=len(w)
    l2=len(S)

    # List of size 26 and initialized to 0 for counting chars in S
    count_s=[0]*26
    
    # Count the starting l1 chars in S
    for i in range(l1):
        count_s[ord(S[i])-97]+=1

    if(check_anagram(count_s, count_w)):
        count+=1

    r=l2-l1+1

    # Move and check for anagram at each iteration
    for i in range(1,r):
        count_s[ord(S[i-1])-97]-=1
        count_s[ord(S[l1+i-1])-97]+=1
        if(check_anagram(count_s,count_w)):
            count+=1

    return count

def main():
    t=int(input())
    for _ in range(t):
        S=input()
        w=input()
        ans = count_occurances_of_anagrams(S,w);
        print("Total no. of Anagrams: ",ans)
        

if __name__=="__main__":
    main()