CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Liste des fichiers source
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Liste des fichiers objet correspondants
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Nom de l'exécutable
TARGET = $(BIN_DIR)/jeu

# Commande de compilation des fichiers objet
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Commande de création de l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Cible par défaut
all: $(TARGET)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
