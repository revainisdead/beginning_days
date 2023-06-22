# Author: 	Christian Hall
# Date:		September 28, 2015
# Abstract:	This program's purpose is to read from a file containing
#		any ASCII characters and write to a new file (and print),
#		the corresponding hexadecimal value.

file = open('hexdump.txt', 'w')

line = 1
with open('sample') as f:
	lines = f.readlines()
	file.write("ASCII, Hex\n")
	file.write("----------\n")
	
	
	
	for l in lines:
		words = l.split()
		
		file.write("Line #")
		file.write("" + str(line))
		file.write('\n')
		
		line += 1
		for w in words:
			word = w
			
			p = word.encode("hex")
			
			file.write(word)
			file.write(", ")
			file.write(p)
			file.write('\n')
			
			print "%s -> %s" % (word, p)
		
		file.write('\n')
