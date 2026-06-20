.PHONY:	run compile clean

obj = main.c perso.c perso.h
file = main 

run: compile
	@./$(file)

clean:
	rm -f $(file)


compile:
	@echo "compile...."
	cc $(obj) -o $(file)
	

