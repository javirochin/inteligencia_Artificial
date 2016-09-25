#! /usr/bin/env python
# -*- coding: utf-8 -*-
import lista

def quicksort(lista,izq,der):
    i=izq
    j=der
    x=lista[(izq + der)/2]
 
    while( i <= j ):
        while lista[i]<x and j<=der:
            i=i+1
        while x<lista[j] and j>izq:
            j=j-1
        if i<=j:
            aux = lista[i]; lista[i] = lista[j]; lista[j] = aux;
            i=i+1;  j=j-1;
 
        if izq < j:
            quicksort( lista, izq, j )
    if i < der:
        quicksort( lista, i, der )
 
def imprimeLista(lista,tam):
    for i in range(0,tam):
        print lista[i]
 

 
A=lista.generalista()
quicksort(A,0,len(A)-1)
imprimeLista(A,len(A))