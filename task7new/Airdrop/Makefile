#makefile

GCFLAGS=-O3 -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format -msse

all: $(patsubst a.cpp, a.out,$(wildcard a.cpp))
a.out: a.o student.o
	g++ $(GCFLAGS) $^ -o $@ -lm
a.o: a.cpp student.o
	g++ -c $(GCFLAGS) $<
student.o: student.cpp student.h
	g++ -c $(GCFLAGS) $<
clean:
	rm -f *.out *.o *.bak
