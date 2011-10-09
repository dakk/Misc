clc
disp("Esercitazione n.1, Davide Gessa (45712)\n")


function f=fibonacci(n)
	% Vettore vuoto dove inserire i numeri di fibonacci
	f = zeros(n,1);
	
	% Casi base
	f(1) = 1;
	f(2) = 2;
	
	for k = 3:n
		f(k) = f(k-1) + f(k-2);
	end
end


disp("Parte 5")

disp("n numeri di fibonacci\n")
n = input("Inserisci il numero di numeri da generare: ")
fibonacci(n)
