#include "DemoWindow.h"

DemoWindow::DemoWindow(int width, int height)
: Window(width,height)
{
	set_title("OpenGL Demo Window");
}

void DemoWindow::setup_gl() {
	glClearColor(0.2f, 0.4f, 0.7f, 1.0);
	glMatrixMode(GL_PROJECTION); // ������������� ������� ��������
	gluPerspective (45.0, double(width()) / double(height()), 0.1, 20.0);

	glMatrixMode(GL_MODELVIEW);
	// glPointSize(16.0f); ������ �����
	// glLineWidth(10.0f); ������ �����
	glEnable(GL_DEPTH_TEST); //��������� ����� �������
}

void CRender(){
	//��������� ����
		glBegin(GL_QUADS);
		glColor3d(1.0, 0.0, 0.0); // ������ ����� (�������)
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, -1.0);

		glColor3d(0.0, 1.0, 1.0); // ������� ����� (���������)
		glVertex3d(-1.0, -1.0, 1.0);
		glVertex3d(1.0, -1.0, 1.0);
		glVertex3d(1.0, 1.0, 1.0);
		glVertex3d(-1.0, 1.0, 1.0);

		glColor3d(0.0, 1.0, 0.0); // ������� ����� (�������)
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(1.0, -1.0, 1.0);
		glVertex3d(1.0, 1.0, 1.0);

		glColor3d(1.0, 1.0, 0.0); // ������� ����� (������)
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, 1.0);
		glVertex3d(1.0, -1.0, 1.0);

		glColor3d(0.7, 0.5, 0.0); // ������� ����� (����������)
		glVertex3d(-1.0, -1.0, -1.0);
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(-1.0, 1.0, 1.0);
		glVertex3d(-1.0, -1.0, 1.0);

		glColor3d(0.0, 0.5, 0.2); // ������� ����� (�����-�������)
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, 1.0);
		glVertex3d(-1.0, 1.0, 1.0);
		glEnd();
}

void DemoWindow::render() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // �������

	glLoadIdentity(); // ������� ������ ���� = ���������

	gluLookAt(3.0, 4.0, 2.0,  // ���������� ������
			  0.0, 0.0, 0.0,  // ���������� ������
			  0.0, 0.0, 1.0); // ����������� �����, ����������=������
	glRotated(_cube_angle, 0.0, 0.0, 1.0);
	glPushMatrix (); //������������ ^ ������� � ����

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
	_cube_angle += 0.01; //������� ����
	if (_cube_angle >= 360.0) // ���� ��� �������� ����� 360 ��������
		_cube_angle -= 360.0; // ������� �������� � 0 ��������
}
