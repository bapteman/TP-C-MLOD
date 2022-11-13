# Description du projet
- Modification de arkanoid (casse briques).
- ajout de bonus dans les briques initialisée aléatoirement.
# Comment compiler
aprés le tutoriel envoyé pour installer raylib : 
gcc -o arkanoid arkanoid.c -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -s -O1 -D_DEFAULT_SOURCE -I. -I/home/bot/Raylib.git/src -I/home/bot/Raylib.git/src/external -I/usr/local/include -L. -L/home/bot/Raylib.git/src -L/home/bot/Raylib.git/src -L/usr/local/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -latomic -DPLATFORM_DESKTOP

# Comment exécuter
./arkanoid

# Comment utiliser le projet

![screenshot_arkanoid](https://user-images.githubusercontent.com/111047280/201524847-117a46ae-adc3-473b-b0d4-0cbd8e0b31e9.png)

les régles et les touches sont les mêmes que la arkanoid basique juste certaines briques contiennent maintenant un bonus ou un malus qui peut soit rajouter une balle ne faisant pas perdre de points de vie(vert), agrandir(bleu) ou rétrecir(rouge) la barre.
# URL vidéo de démo
# Quelques détails sur votre implémentation
principalement de l'ajout de champ dans une structure, des booléens sur les briques pour les bonus. Plus un tableau de balles pour les balles à ajouter. Pour finir un ajout de variables globales avec un #define pour pouvoir facilement changer le nombre de bonus

# Extensions / améliorations possibles
utilisation de l'aléatoire pour génerer les briques avce les bonus, simplification du code en intégrant la balle principale dans un même tableau avec les balles additionelles
