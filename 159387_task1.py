import numpy
import matplotlib.pyplot as plt
import requests


total_words = 0
total_chars = 0
n_of_lines = 0

with open ("Sulpicia.txt", "r") as fp:
    for line in fp.readlines():
        n_of_lines += 1
        line = line.replace("\n", "")
        num_of_words = len(line.split(" "))
        num_of_chars = len(line)
        total_words += num_of_words
        total_chars += num_of_chars
        print(line, "\nNumber of words: ", num_of_words, "\nNumber of chars: ", num_of_chars)
        print("--------------------------")

avarage_words = total_words/n_of_lines

avarage_chars = total_chars/n_of_lines

print("The avarage number of words per line: ", avarage_words)
print("The avarage number of chars per line: ", avarage_chars)

def caculate_formula(a, b, x):
    return a*x+b*x**3



x = []
for i in range(0, 200, 2):
    x.append(i/100)

column1 = []
for i in x:
    column1.append(caculate_formula(1, 2, i))

column2 = []
for i in x:
    column2.append(caculate_formula(5, 5, i))



y = numpy.column_stack((numpy.array(column1), numpy.array(column2)))



plt.figure()

plt.plot(x, y[:, 0], "green")
plt.plot(x, y[:, 1], "red")
plt.legend(["A = 1, B = 2", "A = 5, B = 5"])
plt.xlabel("x")
plt.ylabel("y")

plt.show()



students_number = "159387"

sum = 0
for i in students_number:
    sum += int(i)

print(requests.get(f"http://numbersapi.com/{sum}").text)
