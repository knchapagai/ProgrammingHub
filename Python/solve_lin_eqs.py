# -*- coding: utf-8 -*-
"""
@author: Naufal Hisyam
"""

def solve_lin_eqs(a,b,e,c,d,f):
	"""
	A function to solve a system of linear equations consisted of two linear equation.
	The input assume the equations to be in the following forms:
	ax + by = e (1)
	cx + dy = f (2)

	Parameters
	----------
	a, b, e : first equation coefficients
	c, d, f : second equation coefficients

	Returns
	-------
	x, y : solutions of the system

	"""
	m = c/a
	y = (f - (m*e))/(d - (m*b))
	x = (e-b*y)/a

	return x, y
