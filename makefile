mac:	main.cpp tat_math.cpp tat_graphics.cpp
	g++ main.cpp tat_graphics.cpp tat_math.cpp -o test -L/System/Library/Frameworks -framework GLUT -framework OpenGL -Wno-deprecated

macdbg:	main.cpp tat_math.cpp
	g++ -g main.cpp -o test -L/System/Library/Frameworks -framework GLUT -framework OpenGL -Wno-deprecated
linux:
	g++ main.cpp tat_utils.cpp tat_graphics.cpp tat_math.cpp -o test -lglut -lGL -lGLU -Wno-deprecated
linuxdbg:
	g++ -g tat_utils.cpp main.cpp tat_graphics.cpp tat_math.cpp -o test -lglut -lGL -lGLU -Wno-deprecated
clean:
	-rm test test_d
