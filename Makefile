##
## Makefile for  in /home/munoz_d/test
##
## Made by David Munoz
## Login   <munoz_d@epitech.net>
##
## Started on  Thu May 19 09:43:57 2016 David Munoz
## Last update Tue Jun 21 13:23:18 2016 David Munoz
##

TARGET   = FASTAtools

CC       = gcc

SRC	 = check_args.c	\
	   part1.c	\
	   part2.c	\
	   part3.c	\
	   part4.c	\
	   part5.c	\
	   part6.c	\
	   utils.c	\
	   datafile.c	\
	   parsfile.c	\
	   tri_tab.c	\
	   main.c

CFLAGS   = -W -Wall -Werror -ansi -pedantic -Iinclude

SRCDIR   = src
OBJDIR   = obj

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

rm	 = rm -rf
mkdir	 = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) -L./lib/my -lmy
	@echo ""$(TARGET)" compiled !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "  [OK]  "$<""

all	: $(OBJECTS) $(TARGET)

clean	:
	@$(rm) $(OBJDIR)
	@echo "Binary files deleted"

fclean	: clean
	@$(rm) $(TARGET)
	@echo "Binary and executable files are deleted"

re	: fclean all

.PHONY: all clean fclean re
