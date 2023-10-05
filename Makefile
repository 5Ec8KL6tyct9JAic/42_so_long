# Nom du fichier cible
NAME = so_long

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -g3

# Commande pour supprimer des fichiers/dossiers
RM = rm -rf

# Répertoires
DIR_H = headers/
DIR_S = srcs/
DIR_O = objs/

# Crée le répertoire objs s'il n'existe pas
CREATE_DIR_O = @mkdir -p $(DIR_O)

# Listes des fichiers source
SRCS_LIST = main.c hook.c

# Chemins complets des fichiers source
SRCS = $(addprefix $(DIR_S), $(SRCS_LIST))

# Transformation des fichiers source en fichiers objet
OBJS = $(SRCS:$(DIR_S)%.c=$(DIR_O)%.o)

# Compilation et liaison avec la bibliothèque Libft
DIR_LIBFT = libs/libft/
LIBFT_INC = -I $(DIR_LIBFT)
LIBFT = $(DIR_LIBFT)libft.a
FT_LNK = -L $(DIR_LIBFT) -lft

# Compilation et liaison avec la bibliothèque MiniLibX
ifeq ($(shell uname), Linux)
    DIR_MLX = mlx_linux/
    MLX_LNK = -L $(DIR_MLX) -lmlx -lXext -lX11 -lbsd -lm
else
    DIR_MLX = mlx_macos/
    MLX_LNK = -L $(DIR_MLX) -l mlx -framework OpenGL -framework AppKit
endif
MLX_INC = -I $(DIR_MLX)
MLX = $(DIR_MLX)libmlx.a

LIBS = $(FT_LNK) $(MLX_LNK)

# Compilation de l'exécutable
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "[$(NAME)]: SO_LONG Objects were created"
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

# Création de la bibliothèque Libft
$(LIBFT):
	@echo "[$(NAME)]: Creating Libft..."
	$(MAKE) -C $(@D)
	@echo "[$(NAME)]: Libft Objects were created"

# Création de la bibliothèque MiniLibX
$(MLX):
	@echo "[$(NAME)]: Creating MLX..."
	$(MAKE) -C $(@D)
	@echo "[$(NAME)]: MLX Objects were created"

# Règle générique pour la compilation de fichiers source en fichiers objet
$(DIR_O)%.o: $(DIR_S)%.c
	@$(CREATE_DIR_O)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(MLX_INC) -I $(DIR_H) -o $@ -c $<

# Nettoyage des fichiers objets
clean:
	@echo "[$(NAME)]: Cleaning SO_LONG Objects..."
	$(RM) $(OBJS)
	$(RM) $(DIR_O)
	@echo "[$(NAME)]: SO_LONG Objects were cleaned"

# Nettoyage complet (fichiers objets et exécutable)
fclean: clean
	@echo "[$(NAME)]: Cleaning SO_LONG..."
	$(RM) $(NAME)
	@echo "[$(NAME)]: SO_LONG Executable was cleaned"

# Nettoyage des bibliothèques Libft et MiniLibX
libclean:
	@echo "[$(NAME)]: Cleaning Libft..."
	$(MAKE) -sC $(DIR_LIBFT) fclean
	@echo "[$(NAME)]: Libft Objects were cleaned"
	@echo "[$(NAME)]: Cleaning MLX..."
	$(MAKE) -sC $(DIR_MLX) clean
	@echo "[$(NAME)]: MLX Objects were cleaned"

# Règle pour tout nettoyer puis reconstruire
re: fclean all

.PHONY: all clean fclean re libclean
