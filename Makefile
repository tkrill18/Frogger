## Names: Chris Giuffrida and Thomas Krill
## Class: Fundamentals of Computing
## Final Project
## File:  Makefile

CMP = g++ -std=c++14
CLASS = game
CLASS2 = frog
CLASS3 = obstacle
MAIN = final
EXEC = frogger
FLAGX = -lX11

$(EXEC): $(MAIN).o $(CLASS).o $(CLASS2).o $(CLASS3).o 
	$(CMP) $(MAIN).o $(CLASS).o $(CLASS2).o $(CLASS3).o gfxnew.o $(FLAGX) -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp $(FLAGX) -o $(CLASS).o

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) -c $(CLASS2).cpp $(FLAGX) -o $(CLASS2).o

$(CLASS3).o: $(CLASS3).cpp $(CLASS3).h
	$(CMP) -c $(CLASS3).cpp $(FLAGX) -o $(CLASS3).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h $(CLASS2).h $(CLASS3).h
	$(CMP) -c $(MAIN).cpp $(FLAGX) -o $(MAIN).o

clean:
	rm *.o
	rm $(EXEC)


