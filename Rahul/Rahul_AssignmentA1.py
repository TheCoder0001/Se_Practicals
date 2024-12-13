"""
Experiment No. 1 :
	In a second year computer engineering class, group A students play cricket, group B students play
	badminton and group C students play football.
	Write a python program using functions to compute following:
	a) List of students who play both cricket and badminton.
	b) List of students who play either cricket or badminton but not both.
	c) Number of students who play neither cricket nor badminton.
	d) Number of students who play cricket and football but not badminton.
(NOTE : While realising the group, duplicate entries should be avoided. Do not use SET built-in functions)
"""

"""
		Student Name: Rahul Mahendra Patil
		Class: FE-COMP-2
		Semester: 3
		Subject: Data Structures Laboratory	
"""


# Function to create sets/lists/groups.
def make_list(group, students):
	cricket = []
	badminton = []
	football = []
	if group == "A":
		for i in range(students):
			cricket.append(int(input("Enter roll number: ")))
		return cricket
	elif group == "B":
		for i in range(students):
			badminton.append(int(input("Enter roll number: ")))
		return badminton
	else:
		for i in range(students):
			football.append(int(input("Enter roll number: ")))
		return football


# Function to remove duplicate entries in set.
def remove_duplicate(st):
	lst = []
	for roll_no in st:
		if roll_no not in lst:
			lst.append(roll_no)

	return lst


# Function to find union of cricket and football or 1st output.
def both_cf(cricket, badminton):
	both_cf = []
	for roll_no in cricket:
		if roll_no in badminton:
			both_cf.append(roll_no)

	return both_cf


# Function to find 2nd output
def notboth_cf(cricket, badminton):
	notboth_cf = []

	for roll_no in cricket:
		if roll_no not in badminton:
			notboth_cf.append(roll_no)

	for roll_no in badminton:
		if roll_no not in cricket:
			notboth_cf.append(roll_no)

	return notboth_cf


# Function to find 3rd output.
def only_f(cricket, badminton, football):
	only_f = []

	for roll_no in football:
		if roll_no not in cricket:
			if roll_no not in badminton:
				only_f.append(roll_no)

	return only_f


# Function to find 4th output.
def only_cf(cricket, badminton, football):
	only_cf = []
	for roll_no in cricket:
		if roll_no not in badminton:
			only_cf.append(roll_no)

	for roll_no in football:
		if roll_no not in badminton:
			if roll_no not in cricket:
				only_cf.append(roll_no)

	return only_cf


# Function to show menu
def menu():
	print("\n--------------------MENU--------------------")
	print("1. List of students who play both cricket and football.")
	print("2. List of students who either play cricket or football but not both.")
	print("3. Number of students who play neither cricket nor badminton.")
	print("4. Number of students who play cricket and football but not badminton.")
	print("5. EXIT")


# Creating list for cricket
stud1 = int(input("Enter number of students for cricket: "))
cric = make_list("A", stud1)
cric = remove_duplicate(cric)
print("Your list of students in cricket is ", cric)

# Creating list for badminton
stud2 = int(input("Enter number of students for badminton: "))
badm = make_list("B", stud2)
badm = remove_duplicate(badm)
print("Your list of students in badminton is ", badm)

# Creating list for football
stud3 = int(input("Enter number of students for football: "))
footb = make_list("C", stud3)
footb = remove_duplicate(footb)
print("Your list of students in football is ", footb)

menu()
cont = 1

while cont == 1:

	ch = int(input("\nEnter your choice (from 1 to 5)\nPress 0 to see MENU: "))

	if ch == 1:
		print("\nStudents in cricket and badminton are: ", both_cf(cric, badm))

	elif ch == 2:
		print("Students in cricket and badminton but not in both are: ", notboth_cf(cric, badm))

	elif ch == 3:
		print("Students neither in cricket nor in badminton are: ", only_f(cric, badm, footb))

	elif ch == 4:
		print("Students in cricket and football but not badminton are: ", only_cf(cric, badm, footb))

	elif ch == 5:
		cont = 0
		print("You terminated the program.\nThank you for using the program.")

	elif ch == 0:
		menu()

	else:
		print("INVALID CHOICE!!!")

# <-------------------------------- END OF PROGRAM -------------------------------->
