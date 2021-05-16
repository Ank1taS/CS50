from cs50 import get_string
import sys

def gradeCalculaion(arr):
    # storing the length of the string
    length = len(arr)
    countLetter = 0
    countWord = 0
    countSentence = 0

    for i in range(0, length):
        # counting numbers of letters
        if (arr[i].isalpha()):
            countLetter += 1

        # counting numbers of sentence
        if (arr[i] == "!" or arr[i] == "?" or arr[i] == "."):
            countSentence += 1

        # counting numbers of words
        if i == 0 and arr[i].isalpha():
            #for the 0th index of string
            countWord += 1

        elif i != (length - 1) and arr[i] == " " and arr[i + 1] != " ":
            countWord += 1

    # average number of letters per 100 words in the text
    l = (countLetter / countWord) * 100

    # average number of sentences per 100 words in the text
    s = (countSentence / countWord) * 100

    # grade level computed by the Coleman-Liau formula
    index = 0.0588 * l - 0.296 * s - 15.8

    # returning grade
    # ie round the resulting index number to the nearest whole number
    return round(index)

# main()

#taling input using get_string()
text = get_string("Text: ")

# checking whether a null string
if(len(text) == 0):
    sys.exit(1)

#calling gradeCalculation to calculate grade level
grade = gradeCalculaion(text)

# checking cases of possible grade
if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print("Grade ", grade)
