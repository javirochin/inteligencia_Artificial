#!/usr/bin/python
#!python
import lista
lista = lista.generalista()

for i in range(1,len(lista)):
	for j in range(len(lista) - i):
		if lista[j] > lista[j + 1]:
			temp = lista[j]
			lista[j] = lista[j + 1]
			lista[j + 1] = temp		
print (lista)
