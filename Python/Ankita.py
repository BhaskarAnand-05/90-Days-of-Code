# a = 1
# b = 1
# print(a,end=", ")
# print(b,end=", ")

# for x in range(10):
#     sum = a+b
#     print(sum,end=", ")
#     a = b
#     b = sum



# num = int(input("Enter the number to be reversed:- \t"))

# if num < 10:
#     print(num)
# else:
#     while (num >= 10):
#         n = num % 10
#         print(n,end=" ")
#         num = num // 10
#     print(num)

# fno = int(input("First no in range"))
# sno = int(input("Second no in range"))
for n in range (10):
    if (n % 2 == 1):
        continue
    print(n)
