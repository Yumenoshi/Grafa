#include "Okno.h"

int main(int argc, _TCHAR* argv[])
{
	Okno okno(786, 1024, 100, 100);
	okno.stworzenieOkna(argc, argv);
	glutDisplayFunc(okno.wyswietl);

	glClearColor(1.0f, 0.8f, 0.9f, 0.0f);

	glutMainLoop();

	return 0;
}

Okno::Okno(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Okno::Okno()
{
		 wysokoscOkna = 768;
		 szerokoscOkna = 1024;
		 polozenieOknaX = 100;
		 polozenieOknaY = 100;
}

void Okno::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
}