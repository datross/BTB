.PHONY : clean,mrproper
CXX = g++ 
CXXFLAGS = 
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
EXEC = Programme

all : $(EXEC)

$(EXEC) : main.o
	$(CXX) $^ -o $(EXEC) $(CXXFKAGS) $(LDFLAGS)

%.o : src/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)
clean : 
	rm -rf *.o
mrproper : clean
	rm -rf $(EXEC)
