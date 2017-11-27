#ifndef PUNKT_H
#define PUNKT_H

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

GLuint VAO;
GLuint VBO;

class punkt
{
private:
	static int wysokoscOkna;
	static int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;

public:
	punkt();
	punkt(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);

	~punkt(void);
	void inicjalizacjaGlew();

	void stworzenieOkna(int argc, char** argv);
	void stworzenieVAO();
	void stworzenieVBO();
	static void wyswietl();
};

#endif /* PUNKT_H */