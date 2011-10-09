clc
disp("Esercitazione n.1, Davide Gessa (45712)\n")

disp("Parte 2")

eye(2,2)
eye(4,4)
eye(6,6)
eye(8,8)


disp("Matrice casuale tra 0 e 10 compresi")
A=(rand(4,4)*10)
det(A)
inv(A)

disp("Matrici casuali tra -2 e 2 compresi")
A=rand(4,4)*4-2
B=rand(4,4)*4-2

C=A.*B

