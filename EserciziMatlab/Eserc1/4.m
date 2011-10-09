clc
disp("Esercitazione n.1, Davide Gessa (45712)\n")

disp("Parte 4")

disp("n numeri equidistanti nell'intervallo [a,b]\n")
a = input("Inserisci l'estremo a: ")
b = input("Inserisci l'estremo b: ")
n = input("Inserisci il numero di elementi: ")

dist = (b - a) / n
x = a:dist:b
