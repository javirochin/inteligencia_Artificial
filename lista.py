#! /usr/bin/env python
# -*- coding: utf-8 -*-
import random

def generalista():
	lista = []
	for i in xrange(1,10000):
		lista.append(random.randint(0, 10))
	return lista