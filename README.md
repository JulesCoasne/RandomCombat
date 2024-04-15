# RandomCombat

Projet de l'UE LIFAPCD par COASNE Jules and ALOUI Chahd

- [Description du projet](#description-du-projet)

- [Compilation du projet](#compilation-du-projet)
  
  - [Les librairies](#les-librairies)

- [Lancer le projet](#lancer-le-projet)

- [Déroulement d'une partie](#déroulement-dune-partie)
  
  - [Lancement du jeu](#lancement-du-jeu)
  
  - [Les combats](#les-combats)

# Description du projet

RandomCombat est un proejt de jeu de type RPG tour par tour avec des enchaînements de combat ce voulant de plus en plus difficile.

# Compilation du projet

Il est important de ce mettre à la racine du projet.

```bash
cd RandomCombat
make
```

## Les librairies

La librairie [SDL2](https://www.libsdl.org/) est nécessaire pour compiler le projet.

La librairie d'ouverture des `.json`, [GitHub - nlohmann/json: JSON for Modern C++](https://github.com/nlohmann/json), est fournis dans le dossier `lib`

# Lancer le projet

Lancer le projet depuis la racine

```bash
cd RandomCombat
bin/RandomCombat
```

# Déroulement d'une partie

Certain dialogue sont à passer en appuyant sur `RETURN`, d'autre après entre 3 et 5 secondes.

## Lancement du jeu

Appuyer sur `RETURN` pour sortir de l'écran titre.

Choisissez votre personnage entre *MAGE* et *GUERRIER*

## Les combats

Les combats s'enchaine tous seuls jusqu'à la mort du joueur. Il n'y a pas de victoire, seulement votre meilleur score.

A chaque combat vous pourrez choisir entre :

- Attaquer

- Utiliser un consommable

- Consulter les PV des ennemis

- Consulter vos statistiques

A noter que une fois une option choisi, il n'est pas possible de revenir en arrière. Cependant, les consultations de l'état de la partie ne passe pas votre tour et vous ramène simplement au choix initiale.
