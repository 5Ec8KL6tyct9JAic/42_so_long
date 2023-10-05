# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalerio <dvalerio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 13:16:56 by dvalerio          #+#    #+#              #
#    Updated: 2022/10/21 11:38:31 by dvalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Nom du fichier cible
NAME = libft.a

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Utilitaire d'archivage
AR = ar rcs

# Commande pour supprimer des fichiers/dossiers
RM = rm -rf

# Répertoires des sources
SRCDIR = sources
CONVDIR = $(SRCDIR)/conversions
FDDIR = $(SRCDIR)/file_descriptor
CHARDIR = $(SRCDIR)/manipulate_characters
MEMDIR = $(SRCDIR)/manipulate_memory
STRDIR = $(SRCDIR)/manipulate_strings
GNLDIR = $(SRCDIR)/get_next_line
PRINTFDIR = $(SRCDIR)/ft_printf

# Liste des fichiers source
SOURCES = \
	$(CONVDIR)/ft_atoi.c \
	$(CONVDIR)/ft_itoa.c \
	$(FDDIR)/ft_putchar_fd.c \
	$(FDDIR)/ft_putendl_fd.c \
	$(FDDIR)/ft_putnbr_fd.c \
	$(FDDIR)/ft_putstr_fd.c \
	$(CHARDIR)/ft_isalnum.c \
	$(CHARDIR)/ft_isalpha.c \
	$(CHARDIR)/ft_isascii.c \
	$(CHARDIR)/ft_isdigit.c \
	$(CHARDIR)/ft_isprint.c \
	$(CHARDIR)/ft_tolower.c \
	$(CHARDIR)/ft_toupper.c \
	$(CHARDIR)/ft_putchar.c \
	$(CHARDIR)/ft_putnbr.c \
	$(MEMDIR)/ft_bzero.c \
	$(MEMDIR)/ft_calloc.c \
	$(MEMDIR)/ft_memchr.c \
	$(MEMDIR)/ft_memcmp.c \
	$(MEMDIR)/ft_memcpy.c \
	$(MEMDIR)/ft_memmove.c \
	$(MEMDIR)/ft_memset.c \
	$(MEMDIR)/ft_strdup.c \
	$(STRDIR)/ft_split.c \
	$(STRDIR)/ft_strchr.c \
	$(STRDIR)/ft_striteri.c \
	$(STRDIR)/ft_strjoin.c \
	$(STRDIR)/ft_strlcat.c \
	$(STRDIR)/ft_strlcpy.c \
	$(STRDIR)/ft_strlen.c \
	$(STRDIR)/ft_strmapi.c \
	$(STRDIR)/ft_strncmp.c \
	$(STRDIR)/ft_strnstr.c \
	$(STRDIR)/ft_strrchr.c \
	$(STRDIR)/ft_strtrim.c \
	$(STRDIR)/ft_substr.c \
	$(STRDIR)/ft_putstr.c \
	$(STRDIR)/ft_printptr.c \
	$(STRDIR)/ft_printhex.c \
	$(STRDIR)/ft_printnbr.c \
	$(GNLDIR)/get_next_line.c \
	$(PRINTFDIR)/ft_printf.c

# Transformation des fichiers source en fichiers objet
OBJECTS = $(SOURCES:.c=.o)

# Couleurs
DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m

# Compilation et création de la bibliothèque
all: $(NAME)

$(NAME): $(OBJECTS)
	@ARCHFLAGS="-arch arm64" $(AR) $@ $(OBJECTS)
	@echo "$(GREEN)◞( ､ᐛ)､＿/ Le Makefile de [LIBFT] a été compilé avec succès!$(DEF_COLOR)"

# Règle générique pour la compilation de fichiers source en fichiers objet
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@$(RM) $(OBJECTS)
	@echo "$(BLUE) [LIBFT] Fichiers objets nettoyés!$(DEF_COLOR)"

# Nettoyage complet (fichiers objets et bibliothèque)
fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE) [LIBFT] Bibliothèque nettoyée!$(DEF_COLOR)"

# Recompile tout
re: fclean all
	@echo "$(BLUE) [LIBFT] Tout a été nettoyé et reconstruit!$(DEF_COLOR)"

.PHONY: all clean fclean re
