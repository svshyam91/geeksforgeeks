""""
    Decode the pattern- Geeks for Geeks
    Problem Link: https://practice.geeksforgeeks.org/problems/decode-the-pattern/0

    Author: Shyam Kumar (@svshyam91)
    Date: 31-10-2019

"""

def decodeThePattern(seq, n):
	count=1
	if n > 1:
		for _ in range(n-1):
			nxt_seq=""
			count=1
			for i in range(1, len(seq)):
				if seq[i] == seq[i-1]:
					count+=1
				else:
					nxt_seq+=str(count)+seq[i-1]
					count=1
			nxt_seq+=str(count)+seq[len(seq)-1]
			seq=nxt_seq
		print(nxt_seq)
	else:
		print("1")

if __name__ == '__main__':
	t=int(input())
	for _ in range(t):
		n=int(input())
		seq="1"
		decodeThePattern(seq, n)