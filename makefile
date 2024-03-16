EXEC_NAME = RandomCombat
OBJ_FILES = obj/Jeu.o obj/Consommable.o obj/Niveau.o obj/Partie.o obj/Personnage.o obj/Competence.o obj/Ennemi.o obj/Equipement.o obj/Inventaire.o obj/txtCombat.o obj/winTxt.o obj/main_txtCombat.o

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILES)
	g++ $(OBJ_FILES) -o $(EXEC_NAME)
	mv $(EXEC_NAME) bin/

obj/%.o: src/%.cpp src/%.h
	g++ -c $< -o $@

obj/main_txtCombat.o: src/main_txtCombat.cpp
	g++ -c src/main_txtCombat.cpp -o obj/main_txtCombat.o

clean:
	rm -rf obj/*.o
	rm -f bin/$(EXEC_NAME)
