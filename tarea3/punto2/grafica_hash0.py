from matplotlib import pyplot as pp

archivo1 = open("time_vs_load_hash0.dat")

eje_x1 = []
eje_y1 = []
error1 = []

for linea in archivo1:
	linea = linea.split(' ')
	eje_x1.append(float(linea[0]))
	eje_y1.append(float(linea[1]))
	error1.append(float(linea[2]))

pp.errorbar(eje_x1, eje_y1, yerr = error1, linestyle = '', marker = 'o', color = 'purple')
pp.title("Hash0: Lambda VS Time")
pp.xlabel("Lambda")
pp.ylabel("Time")

pp.show()
