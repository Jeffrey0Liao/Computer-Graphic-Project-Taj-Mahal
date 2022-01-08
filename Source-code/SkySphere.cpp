#include "SkySphere.h"

SkySphere::SkySphere():
	state(0), nKey(0)
{
	// initial state as false
}

void SkySphere::Update(const double& deltaTime)
{
	if (nKey)
		state += 1; // if corresponding keyboard input is detected, state value increases one
}

void SkySphere::Display()
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

	// draw the object
	drawSkySphere();

	glPopAttrib();
	glPopMatrix();
}

// draw the sky shpere
void SkySphere::drawSkySphere()
{
	GLint privateID1 = Scene::GetTexture("./texture/skySphere.bmp");
	GLint privateID2 = Scene::GetTexture("./texture/3.bmp");

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* objSphere = gluNewQuadric();
	gluQuadricTexture(objSphere, GLU_TRUE);
	gluQuadricDrawStyle(objSphere, GLU_FILL);

	// the texture varies along with the state
	if (state % 2 == 0) {
		glBindTexture(GL_TEXTURE_2D, privateID1);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, privateID2);
	}
	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glScalef(-1.0f, -1.0f, -1.0f);
	gluSphere(objSphere, 1.0f, 100.0f, 100.0f);
	glPopMatrix();
}

void SkySphere::HandleKey(unsigned char key, int state, int x, int y) {
	// key handler for the keyboard input
	switch (key)
	{
	case 'N':
	case 'n':
		nKey = state;
		break;
	}
}
