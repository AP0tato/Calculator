from tkinter import *
import math as m

main = Tk()

main.geometry('600x700')
#main.config(background='#FFFFFF')

numButtons = [ Button(main, text=i, width=10, height=5) for i in range(10) ]

for i in range(10):
    numButtons[i].grid(column=(i-1)%3, row=int((9-i)/3))
numButtons[0].grid(column=0, row=3)

functions = ['=', '-', '+', '*', '/', ".", "%"]
funcButtons = [ Button(main, text=x, width=10, height=5) for x in functions ]

funcButtons[1].grid(column=4, row=1)
funcButtons[2].grid(column=4, row=0)
funcButtons[3].grid(column=4, row=2)
funcButtons[4].grid(column=4, row=3)
funcButtons[5].grid(column=1, row=3)
funcButtons[6].grid(column=2, row=3)
funcButtons[0].grid(column=0, row=4, columnspan=5, sticky='ew')

main.mainloop()