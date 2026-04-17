
-Test compilation OK 
     MAJ des droits d'autorisation de la MinilibX 
     " cd minilibx-linux / chmod +x configure / make / cd ..make (général) " 
Attention!!! Nom du Projet "cube3D" avec D majuscule (cf fiche subject)

-Finir les textures 
     Mise à jour de la structure, 
     l'initialisation des données texture(4) (add, bpp, line_ten, endian) 
     et free
     
-Pose de la caméra
     Vecteur plan de caméra (plane_x, plane_y)
     plan caméra = “écartement” géométrique des rayons
     FOV = champ de vision, ouverture totale couverte par ces rayons
     classiquement mis à 0.66 = paramètre géométrique ( sans unité) qui fixe le FOV (2 * atan(0.66) = angle (radians) et angle converti ≈ ~66° degrés)
     
- raycasting 
     draw_floor_ceiling() remplit le sol et plafonds
     Une colonne = est une position horizontale x de l’écran. pour chaque colonne, on lances un rayon (un trait vertical de pixels). Ce rayon dit quoi dessiner dans cette colonne, la boucle colonnes “construis l’image de gauche à droite”. 
     Voici ces calculs :
     (C’est exactement la formule du tuto raycasting DDA)
     camera_x = 2 * x / WIN_WIDTH - 1 
     (camera_x dit “où je suis dans le plan caméra”, de gauche à droite.)
     ray_dir_x = dir_x + plane_x * camera_x
     ray_dir_y = dir_y + plane_y * camera_x
     (crée le rayon)
     le rayon est un outil “collision/mesure”, mais si on le répète pour chaque colonne, il permet de fabriquer l’image, c'est ce qu'on appel un "RAYCASTER"

- DDA ( le raycasting qui crée le rayon mais c'est le processus DDA qui contruit réllement 
     le rayons case par case et non comme un segment continue jusqu'a collision)
     DDA = Digital Differential Analyzer — algorithme qui avance pas à pas sur une grille le long d'un segment (ici le rayon), en passant d'une case à la voisine sans tester chaque pixel.
      ✅ Mathématiquement, on peut imaginer un segment continu. Mais en pratique dans une map grille, on fait avancer le rayon case par case (plus précisément frontière de case par frontière). Ce parcours discret, optimisé pour les grilles, c’est justement le DDA (Digital Differential Analyzer). Donc DDA = algorithme qui décide à chaque étape:
     est-ce qu’on franchit la prochaine ligne verticale de grille ou horizontale, on met à jour map_x/map_y, on teste la case, on stop dès qu’un mur est rencontré.
     C’est pour ça que c’est rapide et très adapté à cub3d.
     Et “cast a ray” signifie lancer/tracer un rayon depuis le joueur dans une direction donnée pour trouver ce qu’il touche. ( via dda_loop & dda_compute_perp_dist permet de corriger la bonne projection de l'image pour pas que les murs se courbent)

Couleur unie selon face :
     - `side == 0` (mur vertical) vs `side == 1` (mur horizontal)
     - variante N/S/E/W via signe de `step_x/step_y`
     si side == 0 et step_x > 0 -> west /gauche 
     si side == 0 et step_x < 0 -> east / droite
     si side == 1 et step_y > 0 -> North/haut
     si side == 1 et step_y < 0 -> south/ bas
     En raycasting classique cub3d, le “cube” est rendu avec 6 faces, en 4 murs ( les 4 directions) “face latérale N/S/E/W”  au sens du DDA mais le plafond et le sol sont traités à part (draw_floor_ceiling, couleurs / textures sol-plafond)

Frame et image
     Dessin = écriture dans data->img (via draw_pixel).
     Affichage = avec mlx_put_image_to_window une fois la frame prête.
     L’image MLX (data->img) = C’est toute la fenêtre : une seule image de WIN_WIDTH × WIN_HEIGHT (dans le header, typiquement 1280 × 720). C’est là qu’on dessine sol, plafond, murs, minimap, avec mlx_put_image_to_window. Ce n’est pas une case de la map.
     Frame = c’est un instantané montrer à l’écran à un moment donné, et à chaque séquence (déplacement, rotation, etc.) un nouveau frame est créé.
     la fc° render_frame est le point unique qui construit une image complète pour la fenêtre, puis l’affiche

     




