EXEC_NAME = RandomCombat
OBJ_FILES = obj/Jeu.o obj/Consommable.o obj/Niveau.o obj/Partie.o obj/Personnage.o obj/Competence.o obj/Ennemi.o obj/Equipement.o obj/Inventaire.o

all: Jeu

Jeu: $(OBJ_FILES)
	g++ $(OBJ_FILES) -o Jeu
	
	mv Jeu bin/

obj/%.o: src/%.cpp src/%.h 
	
	g++ -c  $< -o $@

clean:
	rm -rf obj/*.o
	rm -f bin/Jeu