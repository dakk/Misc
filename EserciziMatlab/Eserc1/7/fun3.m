function f=fun3(x)
	f = zeros(size(x), 1)
	
	for k=1:size(x)
		f(k) = k^2 + k^3 + 5
	end
end
