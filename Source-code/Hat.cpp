#include "Hat.h"

Hat::Hat()
{

}

Hat::Hat(int ttype, const std::string& filename)
{
	type = ttype;
	texID = Scene::GetTexture(filename);
}

void Hat::Update(const double& deltaTime)
{
	// static object will not be updated
}

void Hat::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glColor3f(1.0f, 1.0f, 0.94f);

	// outter adjustment of object size, rotation and position
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);

	// select through identifier for the type of roof to return
	if (Hat::type == 1) {
		drawHat90();
	}
	else if (Hat::type == 2) {
		drawHat120();
	}
	else {
		drawHat0();
	}

	glPopAttrib();
	glPopMatrix();
}

// draw a hat with a base stone
void Hat::drawHat90()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* obj = gluNewQuadric();
	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricDrawStyle(obj, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID);

	glPushMatrix();
	glRotatef(-90.0f, 1, 0, 0);
	gluSphere(obj, 2.0f, 100.0f, 100.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, ((1.414 / 2.0) * 2.0), 0.0f);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj,((1.414 / 2.0) * 2.0), 0.0f, ((1.414 / 2.0) * 2.0), 100.0f, 100.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, -0.43 * 2.0 - 1.0f, 0.0f);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, (0.9 * 2.0), (0.9 * 2.0), 1.0, 100.0f, 100.0f);
	glPopMatrix();

	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);
}

// draw a hat without a base stone
void Hat::drawHat120()
{
	float pi = 3.1415926535798;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* obj = gluNewQuadric();
	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricDrawStyle(obj, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID);

	glPushMatrix();
	glRotatef(-90.0f, 1, 0, 0);
	gluSphere(obj, 2.0f, 100.0f, 100.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, ((1.732 / 2.0) * 2.0), 0.0f);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 1.0f, 0.0f, ((1.732 / 6.0) * 2.0), 100.0f, 100.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, -2.0f, 0.0f);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 2.0f, 2.0f, 2.0f, 100.0f, 100.0f);
	gluCylinder(obj, 2.5f, 0.0f, 0.0f, 8.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, -2.0 - 0.1, 0.0f);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 2.5f, 3.0f, 0.1f, 8.0f, 32.0f);
	gluCylinder(obj, 2.5f, 0.0f, 0.0f, 8.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, -2.0 - 0.1 - 0.5f, 0.0f);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 2.0f, 2.0f, 0.5f, 8.0f, 32.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((2.0 - 0.2) * sin(0), -2.0 - 0.1 - 0.5f - 2.0f, (2.0 - 0.2) * cos(0));
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 0.2f, 0.2f, 2.0f, 32.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef((2.0 - 0.2) * sin(pi / 4), -2.0 - 0.1 - 0.5f - 2.0f, (2.0 - 0.2) * cos(pi / 4));
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 0.2f, 0.2f, 2.0f, 32.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef((2.0 - 0.2) * sin((pi / 4) * 2), -2.0 - 0.1 - 0.5f - 2.0f, (2.0 - 0.2) * cos((pi / 4) * 2));
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 0.2f, 0.2f, 2.0f, 32.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef((2.0 - 0.2) * sin((pi / 4) * 3), -2.0 - 0.1 - 0.5f - 2.0f, (2.0 - 0.2) * cos((pi / 4) * 3));
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 0.2f, 0.2f, 2.0f, 32.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef((2.0 - 0.2) * sin((pi / 4) * 4), -2.0 - 0.1 - 0.5f - 2.0f, (2.0 - 0.2) * cos((pi / 4) * 4));
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 0.2f, 0.2f, 2.0f, 32.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef((2.0 - 0.2) * sin((pi / 4) * 5), -2.0 - 0.1 - 0.5f - 2.0f, (2.0 - 0.2) * cos((pi / 4) * 5));
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 0.2f, 0.2f, 2.0f, 32.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef((2.0 - 0.2) * sin((pi / 4) * 6), -2.0 - 0.1 - 0.5f - 2.0f, (2.0 - 0.2) * cos((pi / 4) * 6));
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 0.2f, 0.2f, 2.0f, 32.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef((2.0 - 0.2) * sin((pi / 4) * 7), -2.0 - 0.1 - 0.5f - 2.0f, (2.0 - 0.2) * cos((pi / 4) * 7));
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(obj, 0.2f, 0.2f, 2.0f, 32.0f, 32.0f);
	glPopMatrix();

	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);
}

// draw decorative round roof
void Hat::drawHat0() {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* obj = gluNewQuadric();
	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricDrawStyle(obj, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID);

	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glScalef(1.0f, 1.0f, 1.4f);
	gluSphere(obj, 1.0f, 32.0f, 32.0f);
	gluCylinder(obj, 0.0f, 1.4f, 0.0f, 8.0f, 32.0f);
	gluCylinder(obj, 1.4f, 1.4f, 0.1f, 8.0f, 32.0f);
	glTranslatef(0.0f, 0.0f, 0.1f);
	gluCylinder(obj, 1.4f, 0.0f, 0.1f, 8.0f, 32.0f);

	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);
}
