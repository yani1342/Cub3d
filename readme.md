# 🧊 cub3D

This project was created as part of the 42 curriculum by **ymsa** and **vhorta-s**.

cub3D is a 42 School project inspired by the Wolfenstein 3D engine. It is a small raycaster: you move on a 2D map while the program renders a first-person 3D view.

---

## 🎯 Project goals

- Learn the basics of **raycasting**
- Handle keyboard (and related) events
- Use **MiniLibX**
- Work with textures, collisions, map parsing, and related topics

---

This project was developed as part of the 42 curriculum:

- **ymsa** — 2D part  
- **vhorta-s** — 3D part  

---

## 📚 Resources used

### 🎥 Tutorials and videos

- **Raycasting Tutorial (Python)**  
  https://youtu.be/E18bSJezaUE?si=IcJuT75h1u3TAsvC  
  https://www.youtube.com/watch?v=rnWRs_BBgXc  
  https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCXqoZAc8-tyDSaO8jnabOEFhdTQfx77_&index=1  
  https://www.youtube.com/watch?v=-DX84gp7csM&list=PLpKIEFIlPlKbpTu78AqNnyozX2mZf3PF-&index=2

- **Raycasting PICO-8 #4 — Theory**  
  https://www.youtube.com/watch?v=ZAlMicFhHmM

### 📝 Articles and documentation

- **Cub3D | Nathan Rontey**  
  https://nathaan.me/projects/cub3d

### 🤖 AI-assisted tools (per 42 guidelines)

- Copilot (for vhorta-s)  
- Gemini (for ymsa)

---

## 🛠️ Build

✔️ Make MiniLibX scripts executable  
*(required on some Linux setups)*

```bash
cd minilibx-linux
chmod +x configure
make
cd ..
make
```

---

## 🚀 Run

```bash
./cub3D maps/map.cub
```

---

## 🗂️ Project layout

```text
cub3d/
├── srcs/
├── includes/
├── maps/
├── minilibx-linux/
├── libft/
├── Makefile
└── readme.md
```

---

## 🗺️ `.cub` map format

- `NO`, `SO`, `WE`, `EA` textures  
- Floor and ceiling colors  
- Map made of `1`, `0`, `N`, `S`, `E`, `W` (and spaces, as handled by the parser)

---

## 🎮 Controls

- **W / A / S / D** — move  
- **Left / Right arrows** — rotate  
- **ESC** — quit  

---

## 🧩 Personal notes (free section)

### 👩🏾‍💻 ymsa — personal notes  

*(To be filled as the project evolves: difficulties, wins, what you learned, ideas, improvements, etc.)*

### 👩🏾‍💻 vhorta-s — personal notes  

- Difficulty understanding raycasting and the DDA  
- Greater autonomy in coding after we split responsibilities  
- Reliable support, understanding, and listening from my teammate  
- Doing my best to respect the deadline for my partner  

---

## 🐞 Issues and solutions  

- Keep logic and structure clear so the project stays understandable  
- Accept different working paces between partners  
- Communicate often and work together; effective teamwork on-site and remotely  

---

## 📌 Closing thoughts  

This is not our first paired 42 project, but we keep improving how we collaborate while seeing how each of us progresses.
Our favorite part is still tailoring the visuals of the project.
