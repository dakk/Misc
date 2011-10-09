clc
disp("Esercitazione n.1, Davide Gessa (45712)\n")

disp("Parte 7")

n = input("Inserisci il numero di punti: ")
a = input("Inserisci l'estremo a: ")
b = input("Inserisci l'estremo b: ")

dist = (b - a) / n
x = a:dist:b

g1 = fun1(x)

g2 = fun2(x)

g3 = fun3(x)

g4 = fun4(x)

plot(x, g1, "b", x, g2, "r")
legend("fun1", "fun2");


pause()
