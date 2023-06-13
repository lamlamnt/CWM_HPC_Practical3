barley: barley.c Makefile
	icc barley.c -o barley $(INC) $(LIB)
clean:
	rm -f barley

