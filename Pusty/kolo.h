#ifndef KOLO_H
#define KOLO_H
#define _USE_MATH_DEFINES

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <math.h>

GLuint VAO;
GLuint VBO;

class Kolo
{
private:

	static int wysokoscOkna;
	static int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;
	const static GLuint ILOSC_BOKOW = 100;
	GLfloat promien;

public:
	Kolo(void);
	Kolo(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY, GLfloat promien);
	//~Punkt(void);
	void stworzenieOkna(int argc, char** argv);
	int inicjalizacjaGlew();
	static void wyswietl();
	void stworzenieVAO();
	void stworzenieVBO();
};

#endif/*KOLO_H*/