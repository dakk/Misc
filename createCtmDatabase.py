import urllib2
import sys;

link = "http://www.ctmcagliari.it/linee_percorso.php?linea=" + sys.argv[1]
data = urllib2.urlopen(link).read().split("<div class='verso' class='clearfix'>")

verso = []

for x in data:
	fermate = []
	u = x.split("<a href='linee_orari.php?linea=")
	for y in u:
		y = y.split("</li>")[0]
		
		try:
			codice = y.split("palina=")[1].split("'")[0]
			nome = y.split("alla fermata \"")[1].split("\"")[0]
		
			fermate.append([nome, codice])
		except:
			pass
		
	verso.append(fermate)
	
verso = verso[1:]

for x in verso:
	for y in x:
		print "new Fermata(\""+y[0]+"\", \""+y[1]+"\"), "
	print "\n\n\n"


"""
linee = []

data = urllib2.urlopen("http://www.ctmcagliari.it/linee.php").read()
data = data.split("<ul id='elenco_linee' class='clearfix una_colonna testo'>")[1].split("</ul>")[0].split("</li>")

for x in data:
	days = [False, False, False, False, False, False, False]
	try:
		color = x.split("<div class='colore_linea' style='background-color: ")[1].split("' >")[0]
	except:
		color = "#000"
	try:
		link = x.split("<a class='link' href='")[1]
	except:
		link = ""
		
	try:
		name = link.split(">")[1].split("<")[0]
	except:
		name = ""
		
	try:
		link = link.split("'>")[0]
	except:
		link = ""

	if x.find("Linea attiva nel giorno di luned") != -1:
		days[0] = True
	if x.find("Linea attiva nel giorno di marted") != -1:
		days[1] = True
	if x.find("Linea attiva nel giorno di mercoled") != -1:
		days[2] = True
	if x.find("Linea attiva nel giorno di gioved") != -1:
		days[3] = True
	if x.find("Linea attiva nel giorno di venerd") != -1:
		days[4] = True
	if x.find("Linea attiva nel giorno di sabat") != -1:
		days[5] = True
	if x.find("Linea attiva nel giorno di domenic") != -1:
		days[6] = True
	
	
	linea = [name, color, link, days]
	
	if name != "":
		linee.append(linea)

print linee
"""
