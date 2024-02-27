CODEPATH = ../code/templates/containers
TESTPATH = templates/containers
OBJPATH = bin/objects
OUTPATH = bin/executables

COMPILER = g++ -std=c++11
FLAGS = -pedantic-errors -Wall -Wextra -g
VLG = valgrind --leak-check=yes --track-origins=yes

FILE =

do : $(OUTPATH)/$(FILE).out run

run :
	./$(OUTPATH)/$(FILE).out

$(OUTPATH)/$(FILE).out : $(OBJPATH)/$(FILE)_test.o
	$(COMPILER) $(FLAGS) $^ -o $@

$(OBJPATH)/$(FILE)_test.o : $(TESTPATH)/$(FILE)_test.cpp
	$(COMPILER) $(FLAGS) $^ -c -o $@

vlg :
	$(VLG) ./$(OUTPATH)/$(FILE).out

clean :
	rm $(OBJPATH)/$(FILE)_test.o
