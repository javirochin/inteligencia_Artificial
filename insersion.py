#! /usr/bin/env python
# -*- coding: utf-8 -*-
import lista

lista= lista.generalista()
l=len(lista)
for i in range(0, l-1):
	min=i
	temp=lista[i]
	for j in range(i,l):
		if lista[j] < temp:
			min=j
			temp = lista[j]
			lista[min] = lista[i]
			lista[i] = temp

			