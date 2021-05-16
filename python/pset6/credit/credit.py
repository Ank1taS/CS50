# progrme to check the validity of a credit card in python
from cs50 import get_int

# to find the size
def check_size(cnum):
    count = 0
    while cnum != 0:
        count += 1
        cnum //= 10
    return count

# to check validity
def check_valid(cnum, csize):
    if cnum > 0:

        #checking the size of card numbers
        if csize >= 13 or csize <= 16:
            evensum = 0
            oddsum = 0

            while cnum != 0:
                # extracting odd position number
                rem = cnum % 10
                oddsum += rem

                # updating cnum
                cnum //= 10

                # extracing even position number
                rem = cnum % 10
                rem *= 2
                evensum += ((rem // 10) + (rem % 10))

                # updating cnum
                cnum //= 10

            # if remainder is not 0
            if ((evensum + oddsum) % 10):
                return False

            # if remainder is 0
            else:
                return True
        else:
            return False
    else:
        return False

# to find brand of card
def card_brand(cnum, csize):
    startingdigits = cnum // (pow(10, csize - 2))
   # print(startingdigits)
    # checks for American Express
    if (csize == 15) and (startingdigits == 34 or startingdigits == 37):
        print("AMEX")

    # checks for MASTERCARD
    elif (csize == 16) and (startingdigits >= 51 and startingdigits <= 55):
        print("MASTERCARD");

    # checks for VISA
    elif (csize == 16 or csize == 13) and ((startingdigits // 10) == 4):
        print("VISA")

    else:
        print("INVALID")

# main()
cardno = get_int("Number: ")

card_size = check_size(cardno)

# chaking validity
if check_valid(cardno, card_size):
    card_brand(cardno, card_size)
else:
    print("INVALID")
