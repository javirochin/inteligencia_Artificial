#! /usr/bin/env python
# -*- coding: utf-8 -*-
import random

def generalista():
	lista = []
	for i in xrange(1,1000):
		lista.append(random.randint(0, 100000))
	return lista