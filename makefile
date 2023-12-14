cc = gcc -Wall -Wextra -Werror
.o-file = datetime.o tools.o menu.o main.o calendar.o database.o 
.c-file = datetime.c tools.c menu.c main.c calendar.c database.c
exe = main

all: clean comp obj run

comp:
	@$(cc) -c $(.c-file) 
obj:
	@$(cc) -o $(exe)  $(.o-file)
run: 
	./$(exe)
clean:
	@rm -f $(exe) $(.o-file)
