
graphicus-2: graphicus-2.o canevas.o couche.o forme.o rectangle.o Cercle.o tests.o
	g++ -o graphicus graphicus-2.o canevas.o couche.o forme.o rectangle.o Cercle.o tests.o

graphicus-2.o: graphicus-2.cpp tests.h forme.o rectangle.o Cercle.o
	g++ graphicus-2.cpp -g -c
	
tests.o: tests.cpp
	g++ tests.cpp -g -c 
	
forme.o: forme.cpp coordonnee.h
	g++ forme.cpp -g -c 
	
rectangle.o: rectangle.cpp forme.h
	g++ rectangle.cpp -g -c
	
Cercle.o: Cercle.cpp forme.h
	g++ Cercle.cpp -g -c
	
couche.o: couche.cpp 
	g++ couche.cpp -g -c
	
canevas.o: canevas.cpp 
	g++ canevas.cpp -g -c
	
clean:
	rm  -f *.o		
#
# fin du makefile
#
