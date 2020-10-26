# a = bq + r
import math
num1, num2 = [int(x) for x in input(
    "\n\nEnter 2 numbers where the first one is bigger: ").split()]

print("\nWe have to represent it in the following form: \n\n a = bq + r where \n a -> dividend \n b -> divisor \n q -> quotient and \n r -> remainder\n\n")


print(f"{num1} = {num2}q + r\n\n")

original1 = num1
original2 = num2

r = -1
while r != 0:
    r = num1 % num2
    q = math.floor(num1/num2)
    print("Inputting the values: ")
    print(f"{num1} = {num2} x ({q}) + ({r})\n")
    num1 = num2
    num2 = r

print(
    f"Thus, GCD of ({original1}, {original2}) is equal to GCD of ({num1}, {num2}) which is {num1}")
