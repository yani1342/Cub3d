
Je laisse un max de commentaire dans mes codes, si jamais t'as besoin de plus d'info, et pour moi même quand je reviens sur le code.

Dans le fichier .cub, quand tu vois une ligne comme F 220,100,0, ces trois chiffres correspondent au système RGB (Red, Green, Blue), ce qui donne en français Rouge, Vert, Bleu.

L'ordre est toujours strictement celui-ci :
Le premier chiffre (220) : La quantité de lumière Rouge.
Le deuxième chiffre (100) : La quantité de lumière Verte.
Le troisième chiffre (0) : La quantité de lumière Bleue.

**Parse_rgb**
Quand tu voudra peindre le sol, tu prendra juste ce grand nombre 14443520 et le donnera à la MiniLibX.

**Makefile**
*.c est interdit, find aussi est interdit a 42.
Je viens de voir qu'on a utiliser *.c pour minishell mais on aurait pas du ptdrrr c'est pas grave.
Du coup j'ai lister tout les .c comme avant, et j'ai fais le chemin pour la libft. Mais j'ai bien garder ta structure du makefile
- Important : retirer -g3 avant de push c'est interdit.
Ps : j'aime trop le truc ou ca creer un fichier avec les .o !
J'ai ajouté -lm a la compilation pour compiler la biblithèque math.h

06/03/2026

Le parsing ressemble beau coup a celui de so_long, sauf pour les vecteurs la x y et pour les couleurssinon c'est similaires.

**MLX**
MLX ne dessine pas pixel par pixel directement dans la fenêtre — c'est trop lent. À la place on dessine dans une image en mémoire (addr)
puis on envoie toute l'image d'un coup à la fenêtre avec mlx_put_image_to_window

**Minimap**
- Parcourir grid case par case
- Si c'est un '1' → dessiner un carré de couleur foncée (mur)
- Si c'est un '0' → dessiner un carré clair (sol)
- Dessiner un petit carré pour le joueur à sa position
Pour dessiner on a besoin d'une fonction put_pixel qui écrit directement dans img.addr
*put_pixel* — écrire un pixel dans l'image
*draw_tile* — dessiner un carré de TILE_SIZE x TILE_SIZE pixels
*draw_minimap* — parcourir la grille et appeler draw_tile

Alors a partir de là, la vérité je comprends rien au calcul, avec tout les efforts du monde je comprend pas la logique donc je vais écrire des faits histoire de retenir.
Dans put pixel on a : addr + (y * line_len) + (x * bpp / 8)
- y * line_len → descend jusqu'à la bonne ligne
- x * bpp / 8 → avance jusqu'à la bonne colonne
- bpp / 8 → convertit les bits en octets (32 bits = 4 octets par pixel)
     **`draw_minimap` — tout assembler**
Pour chaque case de la grille :
  - Si c'est un '1' → dessine un carré gris foncé (mur)
  - Si c'est un '0' → dessine un carré gris clair (sol)

dir_x et dir_y c'est quoi ?
C'est la direction vers laquelle regarde le joueur, exprimée comme une flèche :
dir_x = 0, dir_y = -1  →  regarde vers le HAUT (Nord)
dir_x = 0, dir_y =  1  →  regarde vers le BAS (Sud)
dir_x =  1, dir_y = 0  →  regarde vers la DROITE (Est)
dir_x = -1, dir_y = 0  →  regarde vers la GAUCHE (Ouest)

movement.c
Pour avancer, tu ajoutes simplement la direction à la position :
player.x += dir_x * vitesse
player.y += dir_y * vitesse
Si le joueur regarde vers l'Est (dir_x = 1) et avance → x augmente → il va à droite
Pour tourner, c'est là qu'on utilise cos et sin — ils permettent de faire pivoter la flèche de direction d'un certain angle.

SPEED = 0.1 → c'est des cases (sur la grille de la carte)
ROT_SPEED = 0.05 → c'est des radians (une unité d'angle)