#-------------VARIABLES---------------------
#-Wshadow : flag que te avisa si tienes variables con el mismo nombre aunque no se afecten unas a otras.
#-Wno-shadow : flag que te quita los avisos de Wshadow.

NAME		=	Mommy,_when_I_grow_up,_I_want_to_be_a_bureaucrat!
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
OBJ_DIR		=	obj/
SRC_DIR		= 	src/
INC_DIR		=	inc
DEP_FLAGS	=	-MMD
RM			=	rm -f
	

SRC_FILES 	=	main Bureaucrat 
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

#--------------RULES------------------------

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
				mkdir -p $(OBJ_DIR)
				$(CC) -c $(CFLAGS) -I $(INC_DIR) $(DEP_FLAGS) $< -o $@

$(NAME): $(OBJ) Makefile
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
-include $(DEPS)

all: 
	 			@$(MAKE) $(NAME)

clean:
				$(RM) -r $(OBJ_DIR) $(DEPS)

fclean: clean
				$(RM) $(NAME)

re: fclean all

.PHONY : all clean re fclean 