from tkinter import *
import os

main = Tk()

os.system("cd ../Calculator/ && g++ Main.cpp BinaryTree.cpp Parser.cpp -o ../src/Main")

button = Button(main, text="Press")
button.pack()

main.mainloop()