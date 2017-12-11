#include "Kolo.h"

int Kolo::wysokoscOkna;
int Kolo::szerokoscOkna;


int main(int argc, char** argv)
{

	Kolo punkt(786, 1024, 100, 100);
	punkt.stworzenieOkna(argc, argv);
	punkt.inicjalizacjaGlew();
	punkt.stworzenieVAO();
	punkt.stworzenieVBO();
	glutDisplayFunc(punkt.wyswietl);

	glClearColor(0.0f, 0.4f, 0.0f, 0.0f);

	glutMainLoop();

	return 0;
}

Kolo::Kolo(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Kolo::Kolo()
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

void Kolo::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //bufory
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("punkt");

}


void Kolo::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glPointSize(10);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glutSwapBuffers();

}

int Kolo::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK) {
		std::cerr << "Ne udalo sie zainicjalizowac GLEW.Blad:" << glewGetErrorString(wynik) << std::endl;

		//system("pause");
		return 1;
		//system("pause");
	}
}

void Kolo::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}

void Kolo::stworzenieVBO() {
	//Domyœlne, CounterClockWise
	GLfloat Wierzcholki[9] = {
		-0.8f, 0.8f, 0.0f,
		0.8f, -0.8f, 0.0f,
		0.0f, 0.8f, 0.0f,
	};

	//wierzcholki rysowane CounterClockWise
	GLfloat xCCW[3] = { -0.8, 0.8, 0.0 };
	GLfloat yCCW[3] = { -0.8, -0.8, 0.8 };

	//glFrontFace() - funkcja do zmieniania tego czy wyœwietlaæ CCW czy CW(clock wise)
	//glFrontFace(GL_CW) - w³aœnie prze³¹czenie na wyœwietlanie CW
	//glCullFace() - funkcja do wy³¹czania wyœwietlania przodu figury czy nie, by móc u¿yæ trzeba odpaliæ glEnable(GL_CULL_FACE)



	glGenBuffers(1, &VBO); //generuje bufor
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}
