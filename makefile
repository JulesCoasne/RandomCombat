all: Jeu

Jeu: Jeu.o Consommable.o
	g++ obj/Consommable.o obj/Jeu.o -o Jeu

Jeu.o: src/Consommable.h src/Jeu.cpp
	g++ -c src/Jeu.cpp
	mv Jeu.o obj/

Consommable.o: src/Consommable.h src/Consommable.cpp
	g++ -c src/Consommable.cpp
	mv Consommable.o obj/

clean:
	rm -rf obj/*.o