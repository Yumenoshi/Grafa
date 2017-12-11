#ifndef KOLO_H
#define KOLO_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>


GLuint VAO;
GLuint VBO;

class Kolo
{
private:

	static int wysokoscOkna;
	static int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;

public:
	Kolo(void);
	Kolo(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);
	//~Punkt(void);
	void stworzenieOkna(int argc, char** argv);
	int inicjalizacjaGlew();
	static void wyswietl();
	void stworzenieVAO();
	void stworzenieVBO();
};

#endif/*KOLO_H*/