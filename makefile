EXEC_NAME = RandomCombat
OBJ_FILES = obj/Jeu.o obj/Consommable.o

all: Jeu

Jeu: $(OBJ_FILES)
	g++ obj/Consommable.o obj/Jeu.o -o Jeu
	mv Jeu bin/

obj/%.o: src/%.cpp src/%.h 
	g++ -c  $< -o $@

clean:
	rm -rf obj/*.o
	rm Jeu