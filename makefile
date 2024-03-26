EXEC_NAME = RandomCombat
OBJ_FILES = obj/Jeu.o obj/Consommable.o obj/Combat.o obj/Niveau.o obj/Partie.o obj/Personnage.o obj/Competence.o obj/Ennemi.o obj/Equipement.o obj/Inventaire.o obj/affichageText.o

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILES)
	g++ $(OBJ_FILES) -o $(EXEC_NAME)
	mv $(EXEC_NAME) bin/

obj/%.o: src/%.cpp src/%.h
	g++ -c $< -o $@

obj/Jeu.o: src/Jeu.cpp
	g++ -c src/Jeu.cpp -o obj/Jeu.o

affichage: src/Affichage.cpp src/Affichage.h
	g++ src/Affichage.cpp -o Affichage -lSDL2
	mv Affichage bin/

clean:
	rm -rf obj/*.o
	rm -f bin/$(EXEC_NAME)
