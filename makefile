release:	main.cpp tat_math.cpp tat_graphics.cpp
	g++ main.cpp tat_graphics.cpp tat_math.cpp -o test -L/System/Library/Frameworks -framework GLUT -framework OpenGL -Wno-deprecated

debug:	main.cpp tat_math.cpp
	g++ -g main.cpp -o test -L/System/Library/Frameworks -framework GLUT -framework OpenGL -Wno-deprecated

clean:
	-rm test test_d
