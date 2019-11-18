from matplotlib import pyplot as pp

archivo = open("hash64.txt")
eje_y = [int(i) for i in archivo.read().split(",")[:-1]]
archivo.close()

eje_x = [n for n in range(101)]
pp.bar(eje_x, eje_y, color = 'blue')
pp.title("Hash64 - Distrubition")
pp.xlabel("Posición")
pp.ylabel("Número de elementos")

pp.show()
