CC=g++
CCFLAGS=-std=c++2a
SOURCES=driver.cpp
OBJECTS=driver.o

#build rules
myprog: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o myprog.exe $(LIBS)

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

depend:
	$(CC) -M $(SOURCES) > incl.defs

clean:
	rm -f *.o
	rm -f *.exe
	rm myprog.exe

run:
	./myprog.exe 2D.txt 10
	
