
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

06/03/2026

Le parsing ressemble beau coup a celui de so_long, sauf pour les vecteurs la x y et pour les couleurssinon c'est similaires.