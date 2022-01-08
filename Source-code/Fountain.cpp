#include "Fountain.h"
#include <iostream>
Fountain::Fountain():
	x(0.0f),y(0.0f), animationTime(1.0f)
{
	// variable initiation when instantiate the fountain object.
}

Fountain::Fountain(int ttype, const std::string& filename1, const std::string& filename2)
{
	float pi = 3.1415926535798;
	float theta = pi / 3.0;	//defining throwing angle as pi/3 in radius

	// cpoy to global parameters
	type = ttype;

	texID1 = Scene::GetTexture(filename1);
	texID2 = Scene::GetTexture(filename2);

	texName = filename1;
}

// update the object to its new position framewise
void Fountain::Update(const double& deltaTime)
{
	float g = 9.8;
	aT = fmod(aT + static_cast<float>(deltaTime) * 2.0, 3.5f);
	x = 2.5 * aT;	// motion with constant speed along X direction: Dx = vx * t
	//std::cout << "pos[0]: " << pos[0] << std::endl;
	y = 15.0 * aT - 0.5 * g * aT * aT;	// free falling motion along Y direction: Dy = vy * t + (1/2) * g * t^2
	//std::cout << "pos[1]: " << pos[1] << std::endl;
}

void Fountain::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glColor3f(0.5f, 0.5f, 0.5f);

	// outter adjustment of object size, rotation and position
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);

	// draw the object
	drawFountain();

	glPopAttrib();
	glPopMatrix();
}

void Fountain::drawFountain() 
{
	drawNozzle();
	// select through identifier
	if (type == 1) {
		drawBase1(); // draw round base
	}
	else {
		drawBase2(); // draw rectangle base
	}
	glTranslatef(0.0f, 4.0f, 0.0f);
	glPushMatrix();

	// loop for drawing water drops towards different directions 
	for (float degree = 0.0; degree <= 360.0; degree += 18.0) {
		glRotatef(degree, 0.0, 1.0, 0.0);
		drawWater();
		glPopMatrix();
		glPushMatrix();
	}
	glPopMatrix();

}

// draw nozzle
void Fountain::drawNozzle()
{
	
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* objNozzle = gluNewQuadric();
	gluQuadricTexture(objNozzle, GLU_TRUE);
	gluQuadricDrawStyle(objNozzle, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID1);
	
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(objNozzle, 1.0f, 1.0f, 2.0f, 8.0f, 32.0f);
	glTranslatef(0.0f, 0.0f, 2.0f);
	gluCylinder(objNozzle, 1.0f, 0.2f, 2.0f, 8.0f, 32.0f);
	glPopMatrix();
}

// draw a water drop
void Fountain::drawWater()
{
	glColor4f(1.0f, 1.0f, 1.0f, 0.4f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* objSphere = gluNewQuadric();
	gluQuadricTexture(objSphere, GLU_TRUE);
	gluQuadricDrawStyle(objSphere, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID2);

	glTranslatef(x, y, 0.0f);
	gluSphere(objSphere, 0.3f, 32.0f, 32.0f);
}

// helper function to draw a round base
void Fountain::drawBase1() {
	float pi = 3.1415926535897;
	float radius = 12.0;

	glColor3f(1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* obj = gluNewQuadric();
	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricDrawStyle(obj, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID1);

	glPushMatrix();
	for (float degree = 0.0; degree <= 360.0; degree += 18.0) {
		glTranslatef(radius * sin((degree / 180.0) * pi), 0.0, radius * cos((degree / 180.0) * pi));
		glPushMatrix();
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(obj, 2.0f, 2.0f, 2.0f, 32.0f, 32.0f);
		glTranslatef(0.0f, 0.0f, 2.0f);
		gluCylinder(obj, 2.0f, 0.0f, 0.0f, 32.0f, 32.0f);
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
	}
	glPopMatrix();
}

// helper function to draw a rectangle base
void Fountain::drawBase2() {
	Wall* front = new Wall(1, texName, texName);
	front->size(3.0f);
	front->position(0.0f, 0.0f, 43.5f);
	Wall* back = new Wall(1, texName, texName);
	back->size(3.0f);
	back->position(0.0f, 0.0f, -43.5f);
	Wall* left = new Wall(1, texName, texName);
	left->size(3.0f, 3.0f, 9.0f);
	left->orientation(0.0f, 90.0f, 0.0f);
	left->position(-13.5f, 0.0f, 0.0f);
	Wall* right = new Wall(1, texName, texName);
	right->size(3.0f, 3.0f, 9.0f);
	right->orientation(0.0f, 90.0f, 0.0f);
	right->position(13.5f, 0.0f, 0.0f);

	front->Display();
	back->Display();
	left->Display();
	right->Display();
}
