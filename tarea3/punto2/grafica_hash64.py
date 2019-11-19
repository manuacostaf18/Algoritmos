from matplotlib import pyplot as pp

archivo2 = open("time_vs_load_hash64.dat")
eje_x2 = []
eje_y2 = []
error2 = []

for linea in archivo2:
	linea = linea.split(' ')
	eje_x2.append(float(linea[0]))
	eje_y2.append(float(linea[1]))
	error2.append(float(linea[2]))

pp.errorbar(eje_x2, eje_y2, yerr = error2, linestyle = '', marker = 'o', color = 'blue')
pp.title("Hash0: Lambda VS Time")
pp.xlabel("Lambda")
pp.ylabel("Time")

pp.show()
