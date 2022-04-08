# TODO: WRITE ME! (and submit me)
# Harshavardhan Reddipalli
#CS 198C
#Project 12b
#Make Makefile

# On "make", the makefile should
#   Compile "src/copysome.c" to the executable (at this level) "copysome"
#   For each "input/[xyz].in", use "copysome" and the -n flag (with NUMLINES) to make
#    the corresponding "output/[xyz].out"
NUMLINES = 10
IN = $(wildcard input/*.in)
OUT = $(patsubst input/%.in,output/%.out,$(IN))

all:$(OUT)

output/%.out: input/%.in copysome /output
	./copysome -n $(NUMLINES) $< $@

obj/copysome.o: src/copysome.c
	gcc -c src/copysome.c -o obj/copysome.o


/output: copysome clean
	mkdir -p output

copysome: obj/copysome.o
	gcc obj/copysome.o -o copysome


clean:
	rm -rf output
	
	



