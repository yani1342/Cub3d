//Ps: dit moi si tu veux qu'on fasse le readme en anglais !!!

# 🧊 cub3D
This project has been created as part of the 42 curriculum by **vhorta-s** & **ymsa***
cub3D est un projet de l'école 42 inspiré du moteur de jeu de Wolfenstein 3D.  
Il s'agit d'un mini‑raycaster permettant de se déplacer dans une carte en 2D et d'afficher une vue 3D.

---

## 🎯 Objectifs du projet

- Comprendre les bases du **raycasting**
- Manipuler les événements clavier/souris
- Utiliser la **MiniLibX**
- Gérer textures, collisions, parsing de carte, etc.

---

This project has been created as part of the 42 curriculum :  
- **ymsa** — partie 2D 
- **vhorta-s** — partie 3D  

## 📚 Ressources utilisées

### 🎥 Tutoriels & vidéos
- **Raycasting Tutorial (Python)**  
  https://youtu.be/E18bSJezaUE?si=IcJuT75h1u3TAsvC

- **Raycasting PICO‑8 #4 — Théorie**  
  https://www.youtube.com/watch?v=ZAlMicFhHmM

### 📝 Articles & documentation
- **Cub3D | Nathan Rontey**  
  https://nathaan.me/projects/cub3d

### 🤖 Outils d’aide IA (selon les conventions 42)
- Copilot (pour vhorta-s)  
- Gemini (pour ymsa)

---

## 🛠️ Compilation

✔️ Mise à jour des droits d’exécution de la MiniLibX  
*(nécessaire sur certaines installations Linux)*
cd minilibx-linux
chmod +x configure
make
cd ..
make

## 🚀 Lancement  
./cub3D maps/map.cub

## 🗂️ Structure du projet 
cub3d/
│── src/
│── include/
│── maps/
│── minilibx-linux/
│── Makefile
│── README.md

🗺️ Format des cartes .cub
Texture NO, SO, WE, EA
Couleurs du sol et plafond
Carte composée de 1, 0, N, S, E, W

🎮 Contrôles
W / A / S / D : déplacement
Flèches gauche/droite : rotation
ESC : quitter

---

## 🧩 Partie libre : Développement personnel  

### 👩🏾‍💻 ymsa — Notes personnelles  
*(À remplir au fil du projet : difficultés, réussites, apprentissages, idées, améliorations…)*

### 👩🏾‍💻 vhorta-s — Notes personnelles  
*(Même principe : espace libre pour documenter ton évolution.)*

---

## 🐞 Problèmes rencontrés & solutions  
*(à remplir en commun)*

---

## 📌 Conclusion & analyses finales  
*(Bilan du projet, ce que vous avez appris, ce que vous amélioreriez,
 perspectives pour la suite…)*
