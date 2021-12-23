#include "DemoWindow.h"

DemoWindow::DemoWindow(int width, int height)
: Window(width,height)
{
	set_title("OpenGL Demo Window");
}

void DemoWindow::setup_gl() {
	glClearColor(0.2f, 0.4f, 0.7f, 1.0);
	glMatrixMode(GL_PROJECTION); // использование матрицы проекции
	gluPerspective (45.0, double(width()) / double(height()), 0.1, 20.0);

	glMatrixMode(GL_MODELVIEW);
	// glPointSize(16.0f); размер точки
	// glLineWidth(10.0f); ширина линии
	glEnable(GL_DEPTH_TEST); //включение теста глубины
}

void CRender(){
	//Рисование куба
		glBegin(GL_QUADS);
		glColor3d(1.0, 0.0, 0.0); // Нижняя грань (красная)
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, -1.0);

		glColor3d(0.0, 1.0, 1.0); // Верхняя грань (бирюзовая)
		glVertex3d(-1.0, -1.0, 1.0);
		glVertex3d(1.0, -1.0, 1.0);
		glVertex3d(1.0, 1.0, 1.0);
		glVertex3d(-1.0, 1.0, 1.0);

		glColor3d(0.0, 1.0, 0.0); // Боковая грань (зеленая)
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(1.0, -1.0, 1.0);
		glVertex3d(1.0, 1.0, 1.0);

		glColor3d(1.0, 1.0, 0.0); // Боковая грань (желтая)
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, 1.0);
		glVertex3d(1.0, -1.0, 1.0);

		glColor3d(0.7, 0.5, 0.0); // Боковая грань (коричневая)
		glVertex3d(-1.0, -1.0, -1.0);
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(-1.0, 1.0, 1.0);
		glVertex3d(-1.0, -1.0, 1.0);

		glColor3d(0.0, 0.5, 0.2); // Боковая грань (темно-зеленая)
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, 1.0);
		glVertex3d(-1.0, 1.0, 1.0);
		glEnd();
}

void DemoWindow::render() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // Очистка

	glLoadIdentity(); // Матрица модель вида = единичная

	gluLookAt(3.0, 4.0, 2.0,  // Координаты камеры
			  0.0, 0.0, 0.0,  // Координаты центра
			  0.0, 0.0, 1.0); // Направление вверх, МодельВида=Камера
	glRotated(_cube_angle, 0.0, 0.0, 1.0);
	glPushMatrix (); //сохраненение ^ матрицы в стек

	glScaled(0.2, 0.2, 0.2);
	CRender();

	glPopMatrix ();
	glScaled(0.2, 0.2, 0.2);
	glTranslated (2.0, 0, 2.0);
	CRender();

	glTranslated (2.0, 0, -2.0);
	CRender();

	glTranslated (-2.0, 0, -2.0);
	CRender();

	glTranslated (4.0, 0, 0);
	CRender();

	glTranslated (-8.0, 0, 0);
	CRender();

}

void DemoWindow::update() {
	_cube_angle += 0.01; //поворот куба
	if (_cube_angle >= 360.0) // если угл поворота равен 360 градусов
		_cube_angle -= 360.0; // вернуть значение в 0 градусов
}
