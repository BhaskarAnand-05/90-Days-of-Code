num = int(input("Enter the number to be reversed:- \t"))

if num < 10:
    print(num)
else:
    while (num >= 10):
        n = num % 10
        print(n,end=" ")
        num = num // 10
    print(num)