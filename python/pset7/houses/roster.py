from cs50 import SQL
from sys import argv, exit

# list of houses name
houseName = ["slytherin", "gryffindor", "ravenclaw", "hufflepuff"]

#house = argv[1].
# chaking command line arguments
if len(argv) != 2 or (argv[1].lower() not in houseName):
    print("Invalid argument(s) or house name")
    exit(1)

#set up a database connection
db = SQL("sqlite:///students.db")

# to store data from table
studentData = db.execute("SELECT first, middle, last, birth FROM students WHERE house = (?) ORDER BY last, first", argv[1])
 # to access and print
for row in studentData:
    if row["middle"] == None:
        print(row["first"] + " " + row["last"] + ", born " + str(row["birth"]))
    else:
        print(row["first"] + " " + row["middle"] + " " + row["last"] + ", born " + str(row["birth"]))
