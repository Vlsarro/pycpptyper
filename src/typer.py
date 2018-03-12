#! /usr/bin/env python

class Typer(object):

	def identify(self, var):
		print('The var is {}, <{}>'.format(var, type(var)))
		return var


if __name__ == "__main__":
	ins = Typer()
	var = ins.identify(5)
