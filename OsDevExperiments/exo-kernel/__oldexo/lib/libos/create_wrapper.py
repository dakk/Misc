import os

os.system("objdump -x kernel/arch/x86/kernel > dump.txt")

f = open("dump.txt", "r")
data = f.read()
f.close()

data = data.split("\n")

symbols = []

for x in data:
	x = x.split("\t")
	if len(x) == 2:
		a = x[0].split(" ")[0]

		d = x[1]
		d = d.split(" ")

		if len(d) == 2:
			if d[1].find(".") == -1:
				if d[0] != '00000000':
					symbols.append([d[1], a])

f = open("address.h", "w")
f.write("#ifndef ADR_H\n#define ADR_H\n\n")
f.write("#define START 0x100000\n");
for x in symbols:
	f.write("#define _"+x[0].upper()+" (0x"+x[1]+")\n")
f.write("\n\n#endif\n")
f.close()

os.system("rm dump.txt")

"""
f = open("fun_def.iface", "r")
data = f.read()
f.close()
data = data.split("\n")

for x in data:
	print x
"""
#print data
