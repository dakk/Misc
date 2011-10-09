clc
disp("Esercitazione n.1, Davide Gessa (45712)\n")

disp("Parte 1")

A=[10.1 -3.7 0 7.8; 2 3 4 5; -3 -2 -1 0; 10 20 30 40]
B=[0.89 -0.4 3 -5; 1 -5 10.7 0.123]


disp("\n\nC = A*B'")
C=A*B'

disp("\n\nSize of Matrix A:")
size(A)
disp("\n\nSize of Matrix B:")
size(B)
disp("\n\nSize of Matrix C:")
size(C)


D=[A(1:4, 1:4); B(1:2, 1:4)]
E=[A(1:4, 1:4) B'(1:4, 1:2)]
F=[A(1:4, 1:2)]
F=[A(2:3, 2:3)]

