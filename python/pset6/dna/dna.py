from sys import argv, exit
from csv import reader, DictReader


# chaking command line arguments
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# to open txt files
with open(argv[2], "r") as txtFile:
    dna = txtFile.read()

# to open csv file
with open (argv[1], "r") as csvFile:
    dnaList = list(reader(csvFile))
# to extract only the str sequence
    for row in dnaList:
        dnaList = row
        dnaList.pop(0)
        break

# dictionary to store str as key and count as value
dnaSequence = {}

for item in dnaList:
    dnaSequence[item] = 1

# to compare key with dna sequences
dnaSize = len(dna)

for key in dnaSequence:
    # to get size of each key it sequence
    keySize = len(key)
    count = 0
    temp = 0

    for i in range(dnaSize):
        temp = 0
        if (dna[i:i + keySize] == key):
            while dna[i + keySize: i + 2 * keySize] == key:
                temp += 1
                i += keySize

        # if the sequence repeatation is greater than previous time
        if count < temp:
            count = temp

    # to store repetation (count) as value to the corresponding key(str sequence)
    dnaSequence[key] += count

# to open csv file
with open(argv[1], newline='') as csv_file:
    people = DictReader(csv_file)

    # to print
    for person in people :
        # to count matched sequence number
        match = 0

        for dna in dnaSequence:
            if dnaSequence[dna] == int(person[dna]):
                match += 1
        # if match found
        if match == len(dnaSequence):
            print(person['name'])
            exit(0)

    # if no match found
    print("No match")
    exit(1)