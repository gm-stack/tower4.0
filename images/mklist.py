#!/usr/bin/env python
import os
for i in os.listdir("."):
	if i[-3:] == "bmp":
		j = i[:-4]
		print """textures["%s"] = new zImage(system_filepath "images/%s.bmp");""" % (j,j)