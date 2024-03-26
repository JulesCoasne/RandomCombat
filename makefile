EXEC_NAME = RandomCombat
OBJ_FILES = obj/Jeu.o obj/Consommable.o obj/Combat.o obj/Niveau.o obj/Partie.o obj/Personnage.o obj/Competence.o obj/Ennemi.o obj/Equipement.o obj/Inventaire.o obj/affichageText.o obj/Affichage.o

# Commande par défaut
all: $(EXEC_NAME)

# Compilation de l'exécutable
$(EXEC_NAME): $(OBJ_FILES)
	g++ $(OBJ_FILES) -o $(EXEC_NAME) -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
	mv $(EXEC_NAME) bin/

# Règle générique pour la compilation des fichiers source
obj/%.o: src/%.cpp src/%.h
	g++ -c $< -o $@

obj/Jeu.o: src/Jeu.cpp
	g++ -c src/Jeu.cpp -o obj/Jeu.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

obj/SDLSprite.o: src/SDLSprite.cpp src/SDLSprite.h
	g++ -c src/SDLSprite.cpp -o obj/SDLSprite.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

affichage: src/Affichage.cpp src/Affichage.h
	g++ src/Affichage.cpp -o Affichage -lSDL2
	mv Affichage bin/

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -rf obj/*.o
	rm -f bin/$(EXEC_NAME)

# Exécution de la version graphique
run: $(EXEC_NAME)
	bin/$(EXEC_NAME)
