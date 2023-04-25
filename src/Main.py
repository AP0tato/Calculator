import os
os.system("cd ../Calculator/ && g++ Main.cpp BinaryTree.cpp Parser.cpp -o ../src/Main")

from tkinter import *

main = Tk()

numButtons = [ Button(main, text=i) for i in range(10) ]

for i in range(10):
    numButtons[i].pack()

functions = ['=', '-', '+', '*', '/', ".", "%"]
funcButtons = [ Button(main, text=x) for x in functions ]

for i in range(len(funcButtons)):
    funcButtons[i].pack()

main.mainloop()