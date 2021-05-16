# to create a pyramid in py

from cs50 import get_int

# checking input
height = 0
while (height > 8 or height < 1):
    height = get_int("Height:\n")

#pyramid building
for i in range(1, height + 1):
    print(" " * (height - i), end="")
    print("#" * i, end="  ")
    print("#" * i)