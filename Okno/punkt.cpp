#include "punkt.h"

int main(int argc, CHAR* argv[])
{
	punkt okno(786, 1024, 100, 100);
	glutDisplayFunc(okno.wyswietl);

	glClearColor(1.0f, 0.8f, 0.9f, 0.0f);

	glutMainLoop();

	return 0;
}

int punkt::wysokoscOkna;
int punkt::szerokoscOkna;

punkt::punkt(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

punkt::punkt(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

void punkt::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void punkt::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	glutCreateWindow("punkt");
}

void punkt::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK){
		std::cerr << "Nie uda³o siê zaicianizowaæ GLEW blad:" << glewGetErrorString(wynik) << std::endl;

		system("pause");
		exit(1);
	}
}

void punkt::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}