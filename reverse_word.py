t = int(input())

while t: 
    str = input()

    # Convert the string into list 
    lst = list(str.split('.'))

    # Reverse the list
    lst.reverse()

    # Join the list with . seperator
    str = ".".join(lst)

    # Printing the string
    print(str)
    t = t-1