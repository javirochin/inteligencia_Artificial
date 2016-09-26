#! /usr/bin/env python
# -*- coding: utf-8 -*-
import lista

lista = lista.generalista()

for i in range(1,len(lista)):
	temp = lista[i]
	j = i -1
	while j >= 0:
		if temp < lista[j]:
			lista[j+1] = lista[j]
			lista[j] = temp
			j = j-1
		else:
			break
print lista