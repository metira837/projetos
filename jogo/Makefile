.PHONY:	run compile clean

obj = main.c perso.c perso.h shop.c shop.h
file = main 
CC ?= cc
run: compile
	@./$(file)

compile:
	@echo "compile...."
	$(CC) $(obj) -o $(file) -Wall -Wextra
clean:
	rm -f $(file)

