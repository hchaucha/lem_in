# ** ---- LIBFT ----** #

*La libft est une librairie statique comprenant des fonctions qui permettent de manipuler des chaines de caractères, des liste chainées, retourner des longueur, manipuler des zones mémoires etc.*

## Contenu de la libft: ##
* Fonctions (void)
* Fonctions (int)
* Fonctions (char*)
* Fonctions (char**)
* Fonctions (void*)
* fonctions (Liste chainée)

### Fonctions (void) ###

* ft_putchar /      *affiche un caractère*
* ft_putchar_fd /   *affiche un caractère sur le filedescriptor*
* ft_putstr /       *affiche une chaine de caractère*
* ft_putstr_fd /    *affiche une chaine de caractère sur le filedescriptor*
* ft_putendl /      *affiche une chaine de caractère + 1 saut de ligne*
* ft_putendl_fd /   *affiche (ft_putendl) sur le filedescriptor*
* ft_putnbr /       *affiche un nombre*
* ft_putnbr_fd /    *affiche un nombre sur le filedescriptor*
* ft_strdel /       *libère une chaine de caractère et remet le pointeur à NULL*
* ft_strclr /       *ré-initialise une chaine de caractère à \0*
* ft_iter /         *applique la fonction f à tous les caractère de la chaine*
* ft_iteri /        *applique (ft_iter) mais ajoute l'index du caractère*
* ft_memdel /       *libère la mémoire de la variable passée en paramètre*
* ft_bzero /        *JE SAIS PLUS CE QUE CA FAIT*

### Fonctions (int) ###

* ft_isalpha /      *retourne 1 si le caractère est une lettre*
* ft_isdigit /      *retourne 1 si le caractère est un chiffre*
* ft_isascii /      *retourne 1 si le caractère est dans la table ASCII*
* ft_isalnum /      *retourne 1 si le caractère est un chiffre ou une lettre*
* ft_isprint /      *retourne 1 si le caractère peut être affiché*
* ft_tolower /      *met la lettre en minuscule si elle ne l'est pas déjà*
* ft_toupper /      *met la lettre en majuscule si elle ne l'est pas déjà*
* ft_strcmp /       *compare deux chaines de caractères et renvoie un entier*
* ft_strncmp /      *applique (ft_strcmp) sur les n premiers caractères*
* ft_memcmp /       *compare deux mémoires et renvoie un entier*
* ft_strequ /       *compare lexicographiquement deux chaînes de caractères*
* ft_strnequ /      *applique (ft_strequ) sur les n premiers caractères*
* ft_strlen /       *retourne la longueur de la chaine de caractère*
* ft_strlcat /      *concatene deux chaines de caractères en précisant la taille de la chaine finale*
* ft_atoi /         *convertit la chaine de caractère en un int*

### Fonctions (char*) ###

* ft_strcat /       *concatene deux chaines de caractères*
* ft_strncat /      *ajoute a s1 les n premiers caractère de s2*
* ft_strchr /       *cherche la première occurrence d'un caractère dans une chaine de caractère*
* ft_strrchr /      *cherche la dernière occurrence d'un caractère dans une chaine de caractère*
* ft_strstr /       *cherche la première occurrence d'un mot dans une chaine de caractère*
* ft_strrstr /      *cherche la dernière occurrence d'un mot dans une chaine de caractère*
* ft_strrev /       *inverse la chaine de caractère*
* ft_strcpy /       *copie une chaine de caractère dans une nouvelle chaine de caractère*
* ft_strncpy /      *copie les n premiers caractère d'une chaine de caractère dans une autre*
* ft_strnew /       *crée une nouvelle chaine de caractère et l'initialise à \0*
* ft_strsub /       *renvoi la copie d'un tronçon de chaine de caractère (index to len)*
* ft_strtrim /      *copie une chaine de caractère en supprimant les espaces de debut et de fin*
* ft_strmap /       *applique la fonction (*f) sur chaque caractère pour créer une nouvelle chaine*
* ft_strmapi /      *applique (ft_strmap) en passant l'index du caractère en paramètre*
* ft_strjoin /      *concatene deux chaines de caractères et termine la chaine de retour par \0*
* ft_strdup /       *duplique une chaine de caractère et renvoie un pointeur sur la nouvelle chaine*
* ft_itoa /         *convertit un int en une chaine de caractère*

### Fonctions (char**) ###

* ft_strsplit /     *copie les mots d'une chaine de caractère dans un tableau de chaine de caractère*

### Fonctions (void*) ###

* ft_memalloc /     *alloue une zone mémoire pour une variable*
* ft_memcpy /       *copie n octet d'une zone mémoire vers une autre*
* ft_memccpy /      *applique (ft_memcpy) et s'arrête si le caractère c à été rencontré*
* ft_memchr /       *cherche parmi les n premiers octets, la première occurrence de c*
* ft_memset /       *remplis les n premiers octet de la zone mémoire avec l'octet c*
* ft_memmove /      *copie les n premiers octets d'une zone mémoire vers une autre*

### Fonctions (Liste chainée) ###

* ft_lstnew /       *crée une nouvelle liste*
* ft_lstadd /       *ajoute un nouveau maillon à la liste*
* ft_lstdelone /    *efface un maillon de la liste*
* ft_lstdel /       *efface tout une liste*
* ft_lstiter /      *applique la fonction ($f) à tout les maillons de la liste*
* ft_lstmap /       *crée une nouvelle liste grace à l'application de (*f) sur chaque maillon*