clc
disp("Esercitazione n.1, Davide Gessa (45712)\n")

disp("Parte 3")

disp("Uso dell'help ed utilizzo funzioni builtin")
A=rand(5,5) * 20 - 10

rand(6)
eye(4)
zeros(6)
ones(3)
inv(A)




disp("\nSoluzione sistema")
A=floor(rand(4,4) * 20)
B=rand(4,1)

sol = A \ B


disp("\nVettori equidistanti -pi/pi")

dist = 2 * pi / 20
x1 = -pi:dist:pi


disp("\nVettori equidistanti -4/4")
dist = 2 * 4 / 12
x2 = -4:dist:4
