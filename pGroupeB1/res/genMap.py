# Définition de la taille de la map
nb_rows = int(1080/48)
nb_cols = int(1920/48)

# Initialisation de la map
map_data = []

# Ajout des 1 lignes en bas avec la texture 3 1
for y in range(nb_rows - 1, nb_rows):
    for x in range(nb_cols):
        map_data.append((x, y, 3, 1, 1))  # Ici, 1 représente la collision

# Ajout des 2 lignes de texture 0 0 au-dessus
for y in range(nb_rows - 3, nb_rows - 1):
    for x in range(nb_cols):
        map_data.append((x, y, 0, 0, 0))  # Ici, 0 représente l'absence de collision

# Ajout des 1 lignes de texture 3 0 au-dessus
for y in range(nb_rows - 4, nb_rows - 3):
    for x in range(nb_cols):
        map_data.append((x, y, 3, 0, 0))  # Ici, 0 représente l'absence de collision

# Ajout du quadrillage avec couloirs verticaux et colonnes de texture 0 0
for y in range(nb_rows - 4):
    for x in range(nb_cols):
        #if x % 6 == 0: #and (x < 12 or x > 24):
            # Couloirs de 4 cases de large de texture 2 0
         #   for k in range(4):
          #      x+=4
           #     map_data.append((x, y, 2, 0, 1))  # Ici, 1 représente la collision
        #else:
            # Colonnes de textures 0 0
         #   map_data.append((x, y, 0, 0, 0))  # Ici, 0 représente l'absence de collision
        if x < 3 or x > nb_cols-4:
            map_data.append((x, y, 0, 0, 0))
        else:
            if (x - 3) % 6 < 4:
                map_data.append((x, y, 2, 0, 1))
            else:
                map_data.append((x, y, 0, 0, 0))

# Affichage de la map générée
for y in range(nb_rows):
    for x in range(nb_cols):
        found = False
        for entry in map_data:
            if entry[0] == x and entry[1] == y:
                print(f"{entry[0]} {entry[1]} {entry[2]} {entry[3]} {entry[4]}", end="  ")  # Espacement entre chaque élément
                found = True
                break
        #if not found:
            #print(" 0 0 0", end="   ")  # Si aucune entrée trouvée à cette position, affichage de valeurs par défaut (0 0 0)
    print("\n" + " " * 1 * nb_cols)  # Nouvelle ligne pour chaque ligne de la map et espace pour l'alignement

with open('res/map.txt', 'w') as file:
    for y in range(nb_rows):
        for x in range(nb_cols):
            found = False
            for entry in map_data:
                if entry[0] == x and entry[1] == y:
                    file.write(f"{entry[0]} {entry[1]} {entry[2]} {entry[3]} {entry[4]}  ")  # Espacement entre chaque élément
                    found = True
                    break
            #if not found:
                #print(" 0 0 0", end="   ")  # Si aucune entrée trouvée à cette position, affichage de valeurs par défaut (0 0 0)
        file.write("\n")  # Nouvelle ligne pour chaque ligne de la map et espace pour l'alignement


# 1 1 16 0 0       16 1 16 0 0          32 1 16 0 0
# 1 16 0 0 0      16 16 48 0 0         32 16 0 16 0

