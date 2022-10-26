#makefile

GCFLAGS=-O3 -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out

%.o: %.cpp
	g++ -DM=10 -c $(GCFLAGS) $<

%.out: %.o
	g++ $^ -o $@

clean:
	rm *.o*

errors.o: errors.cpp errors.h

data.o: data.cpp data.h errors.h

data_array.o: data_array.cpp data_array.h

sort.o: sort.cpp sort.h

a01.o: a01.cpp data.h data_array.h sort.h errors.h
a01.out: a01.o data.o data_array.o sort.o errors.o

a02.o: a02.cpp data.h data_array.h sort.h errors.h
a02.out: a02.o data.o data_array.o sort.o errors.o

a03.o: a03.cpp data.h data_array.h sort.h errors.h
a03.out: a03.o data.o data_array.o sort.o errors.o

a04.o: a04.cpp data.h data_array.h sort.h errors.h
a04.out: a04.o data.o data_array.o sort.o errors.o

a05.o: a05.cpp data.h data_array.h sort.h errors.h
a05.out: a05.o data.o data_array.o sort.o errors.o

a06.o: a06.cpp data.h data_array.h sort.h errors.h
a06.out: a06.o data.o data_array.o sort.o errors.o

a07.o: a07.cpp data.h data_array.h sort.h errors.h
a07.out: a07.o data.o data_array.o sort.o errors.o

a08.o: a08.cpp data.h data_array.h sort.h errors.h
a08.out: a08.o data.o data_array.o sort.o errors.o

a09.o: a09.cpp data.h data_array.h sort.h errors.h
a09.out: a09.o data.o data_array.o sort.o errors.o