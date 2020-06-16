# Cahier des charges : Projet Black Jack

## Contexte et définition du problème 

<p>L'ojectif de ce projet est de parvenir à réaliser une ineligence artificielle capable de gagner un maximum d'argent au jeu du black jack. Le jeu du black jack est un jeu très simple mais les stratégie permetant de gagner sont complexes c'est pourquoi il est compliqué pour un joueur humain de gagner de l'argent lors d'un grand nombre de partie. Cela s'expique par le fait que le joueur ne peut pas mémoriser les meuilleur choix à faire dans chaque situation car les différents cas de figures sont beaucoup trop nombreux. De plus, l'humain aura du mal à ce souvenir de toutes les carte qui sont deja sorties et il ne poura pas exploiter ces informations. Au contraire un programme informatique n'auras aucun mal a faire un très grand nombre de fois et sans faire d'érreur.
Acuellement grâce à l'augmentation de la puissance de calcul des ordinateurs il est envisagable de conaitre en un temps raisonable les meuilleurs coups à jouer et quelle somme d'argent miser afin de maximiser les profits réalisés</p> 

## Objetifs du projet

### Objectif long terme 

<p>L'objectif final de ce projet est d'optenir un programme qui nous permetrais d'aller dans un casino, de rentrer des paramètres lié aux règles de ce casinon et à la sommme de base que l'on possède. Une fois ces donnée aqcuises et compilées on attent du programme qu'il sugère à l'utilisateur combien miser et quelles actions faire durant la partie.</p>

### Objetctifs cour terme 

<p>Réaliser un jeu de black jack dans la console en C et créer une inteligence ariticielle qui permet de jouer à ce jeu. L'ia devra être capable de faire les choix les plus optimaux dans chacunes des situations de jeu. On dévelopera une autre partie du programme peremetant de détermier en jouant un grand nombre de partie et en utilisant des technique lié au machine learning quelle est le choix optitmal dans chaque situation de jeu.</p>

## Périmètre du projet 

<p>Le projet devra tenter dans la meusure du possible de s'adapter aux règles qui peuvent varier d'un casion à l'autre, notament le nombre de paquets de carte dans le sabot ou les mises minimums ou la somme de départ que l'utilisateur possède ou certaines règles qui diffèrent entre les casino européen et nord américain. Le projet devrat s'exécuter en un temps aceptable (5s maximum entre l'acquisition des cartes la réponse de l'action à faire). On peut envisager que une fois que les paramètres du casino ont été sélectioné, le programme nécessite un temps d'exécution plus conséquent (1h) afin de déterminer la manière de jouer</p>

## Description fonctionnelle des besoins

* Fonction principale : avoir une fontion qui détermine la meilleure manière de joueur 
* Sous fonctions :
  * Faire un jeu de black jack
  * Faire en sorte que le jeu se déroule sans aucune interaction humaine 
  * Déterminer une méthode pour déterminer de manière expérimentale le meuilleur choix à faire selon la situation et les paramètres 
  * Stocker les données de tel sorte qu'elles soient accèssibles rapidement
  * Optimiser le programme pour qu'il s'exécute en un temps raisonable
  * Faire un menu de sélection pour choisir les paramètres rapidement 
  * Calculer avant le lancement le temps estimé d'exécution pour avoir une idée globale (et faire une barre d'affichement)
* Produire un rapport détaillant ce qui a été fait dans le projet et la manière de le faire

## Enveloppe budgétaire

<p>0000,00€€ c'est un projet uniquement logiciel, les ide pour le c sont gratuit. On peut envisager d'optenir de la puissance de calcul alouée si le programme est trop long à l'exécution, en utilisant les autres ordinateurs disponible et en les faisant tourner à distance la nuit.</p>

## Délais

Même si ce projet se déroule au rythme que je choisi et en fonction du temps que j'ai envie d'y passer les dead lines sont les suivantes :

* fin juin : mise en place de l'environement de dévelopement(vs code apérationel) et fin de la phase de documentation active
* mi juillet : avoir un programme qui penmet de joueur avec un utilisataeur humain au jeu
* fin juillet : avoir une ébauche d'inteligence artificielle et avoir trouver la méthode lui permétant d'apprendre pour faire les meilleur coup
* fin aout : sortir une première version complète du programme en faisant en prioritée les règles pour les casino français 

## Contrainte / Normalitation et Documentation du code

* Comenter le code au maximum
* Tout mettre en place pour une future exportation avec doxygen
* Utiliser la norme Camel Case
* Produire un code le plus clair et optimisé possible pour réduire le temps d'éxecution et faciliter l'améliration du projet même après plusieurs mois de pause


