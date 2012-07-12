x = -1.01:.001:1.01;
y = 4/5*(sqrt(1-x.^2) + sqrt(abs(x)));
z = 4/5*(-sqrt(1-x.^2) + sqrt(abs(x)));
plot(x,y,'r'); 
plot(x,z,'r'); 

	
