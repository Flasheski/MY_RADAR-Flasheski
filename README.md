# 📡 MY_RADAR

## 🧭 DESCRIPTION DU PROJET

L'objectif de ce projet est de réaliser un panneau de contrôle de trafic aérien en 2D.
Il s'agit d'une simulation simulant les mouvements d'avions et les zones de contrôle de tours de contrôle dans un espace aérien.

Le programme doit gérer deux types d'entités:

- Les avions : Se déplacent en ligne droite de leur point de départ à leur point d'arrivée à une vitesse constante. Ils apparaissent au décollage et disparaissent à l'atterrissage.

- Les tours de contrôle : Entités statiques possédant une zone de protection circulaire.

> [!NOTE]
> ⚠️ Règle de collision : si deux avions entrent en collision, ils sont détruits, sauf s'ils se trouvent dans la zone de contrôle d'une tour.
---

## 🗓️ DATES

📅 **Du 22/11/2025 à 08h42 au 19/12/2025 à 19h42**

---

## 🚀 UTILISATION

### - Lancement :

#### Le programme prend exactement un paramètre : le chemin vers un fichier script de simulation.

```bash
./my_radar path_to_script
```

### ⚙️ - Options et interactions :

#### 💻​ - Commandes / touches :

- ./my_radar -h : affiche l'usage du programme et quitte.
- Touche 'L' : active ou désactive l'affichage des hitboxes et des zones de contrôle.
- Touche 'S' : active ou désactive l'affichage des sprites des entités.

> [!IMPORTANT]
> Bien générer un script.rdr avant de faire la commande ./my_radar

## 📜 FORMAT DU SCRIPT (.rdr) :

### Le fichier script définit les entités présentes dans la simulation.
- Avions (A) : A [départ_x] [départ_y] [arrivée_x] [arrivée_y] [vitesse] [délai]
- Tour (T) : T [pos_x] [pos_y] [rayon]

### Exemple :

```bash
A 1035 165 1125 190 84 0
A 1035 165 620 795 122 1
A 620 795 1125 190 116 2
A 1160 750 340 435 132 3
A 1160 750 340 435 138 4
A 1035 165 620 795 46 5
A 1160 750 1035 165 110 6
A 1160 750 1125 190 30 7
A 1125 190 1160 750 130 8
A 1125 190 620 795 117 9
A 1035 165 1125 190 56 10
A 1125 190 340 435 100 11
A 1125 190 620 795 26 12
A 620 795 1160 750 135 13
A 620 795 1160 750 56 14
A 1125 190 1160 750 83 15
A 620 795 1125 190 23 16
A 1160 750 340 435 65 17
A 1125 190 340 435 21 18
A 1035 165 1160 750 124 19
A 620 795 1160 750 69 20
A 1125 190 620 795 130 21
A 1125 190 1160 750 48 22
A 1125 190 1035 165 98 23
A 620 795 1035 165 114 24
A 1035 165 340 435 116 25
A 1125 190 340 435 150 26
A 1035 165 1125 190 72 27
A 620 795 1035 165 80 28
A 1160 750 1035 165 81 29
T 1160 750 10
T 620 795 5
T 340 435 7
T 1125 190 7
T 1035 165 8
```

## 📁 FICHIERS && STRUCTURE DU PROJET :

###  - Projet dispersé en plusieurs sous-dossiers et fichiers pour avoir plus de clarté sur celui-ci.

```bash
├── 500_map.rdr // script test
├── assets
│   ├── font
│   │   └── timer.ttf
│   └── sprites
│       ├── plane.png
│       ├── tower.png
│       └── world_map.png
├── generator.py // pour générer les maps -> 500_map.rdr, test_map.rdr
├── include
│   ├── my.h
│   └── radar.h
├── lib
│   ├── libmy.a
│   └── my
├── Makefile
├── my_radar
├── src
│   ├── data
│   │   ├── extract_data.c
│   │   ├── parse_entities.c
│   │   └── parse_script.c
│   ├── destroy
│   │   ├── destroy_planes.c
│   │   ├── destroy_radar.c
│   │   ├── destroy_sprites_and_textures.c
│   │   └── destroy_towers.c
│   ├── events
│   │   ├── analyse_events.c
│   │   ├── calculate_angle.c
│   │   └── get_timer.c
│   ├── main.c
│   ├── planes
│   │   ├── check_planes.c
│   │   ├── init_planes.c
│   │   ├── move_planes.c
│   │   ├── parse_planes.c
│   │   ├── planes_collision.c
│   │   └── update_planes.c
│   ├── sprites
│   │   ├── display_all.c
│   │   ├── init_all.c
│   │   └── sprites.c
│   ├── towers
│   │   ├── init_towers.c
│   │   └── parse_towers.c
│   └── window
│       ├── loop_window.c
│       └── open_window.c
└── test_map.rdr // script test
```
