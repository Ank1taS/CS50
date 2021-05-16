from cs50 import SQL
from sys import argv, exit
from csv import DictReader

# chaking command line arguments along with file type(.csv)
if len(argv) != 2 or not(argv[1].endswith('.csv')):
    print("Usage: Invalid argument(s) number or file type")
    exit(1)

#set up a database connection
db = SQL("sqlite:///students.db")

# to update student id
count = 1

# to open csv file
with open(argv[1], newline='') as csv_file:
    studentDic = DictReader(csv_file)

    for row in studentDic:
        # to store splited list of name
        namelist = str.split(row["name"])

        #inserting into student.db
        if len(namelist) == 2:
            #to perform insert query
            db.execute("INSERT INTO students(id, first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?, ?)"
            ,count, namelist[0], None, namelist[1], row["house"], row["birth"])
        elif len(namelist) == 3:
            db.execute("INSERT INTO students(id, first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?, ?)"
            ,count, namelist[0], namelist[1], namelist[2],  row["house"], row["birth"])

        #to update count (id)
        count += 1
