function f=fun4(x)
	f = zeros(size(x), 1)
	
	for k=1:size(x)
		f(k) = 1/(k^2 + 1)
	end
end
