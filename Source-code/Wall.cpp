#include "Wall.h"
#include <iostream>

Wall::Wall()
{

}

Wall::Wall(int ttype, const std::string& filename1, const std::string& filename2)
{
	type = ttype;
	texID1 = Scene::GetTexture(filename1);
	texID2 = Scene::GetTexture(filename2);
	texName = filename1;
}

void Wall::Update(const double& deltaTime)
{
	// static object will not be updated
}

void Wall::Display()
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

	// select through identifier for the type of wall to return
	if (Wall::type == 1) {
		drawWall();
	}
	else {
		drawHollowWall();
	}

	glPopAttrib();
	glPopMatrix();
}

// draw a plane wall
void Wall::drawWall()
{
	TexturedCube* tc = new TexturedCube(texName);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	glScalef(10.0f, 2.0f, 1.0f);
	tc->Display();
}

// draw a hollow wall
void Wall::drawHollowWall()
{
	GLint privateID = Scene::GetTexture("./texture/window.png"); // inner texture which could not be customized

	TexturedCube* tc = new TexturedCube(texName);


	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	glPushMatrix();
	glTranslatef(-1.8f, 0.0f, 0.0f);
	glPushMatrix();
	drawLeftHalf();
	glTranslatef(3.6f, 0.0f, 0.0f);
	drawRightHalf();
	glPopMatrix();
	glTranslatef(1.8f, 1.0f, 0.0f);
	glScalef(4.3f, 2.0f, (1.41/2.0));
	tc->Display();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, privateID);
	glBegin(GL_QUADS);	// back polygon
	glNormal3f(0.0f, 0.0f, 1.0f);
	// define texture coordinates for the 4 vertices
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2.2f, 2.0f, -0.3f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2.2f, -4.0f, -0.3f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.2f, -4.0f, -0.3f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.2f, 2.0f, -0.3f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, NULL);

	glBindTexture(GL_TEXTURE_2D, texID2);
	glBegin(GL_QUADS);	// front polygon
	glNormal3f(0.0f, 0.0f, 1.0f);
	// define texture coordinates for the 4 vertices
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2.2f, 2.0f, 0.4f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2.2f, -4.0f, 0.4f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.2f, -4.0f, 0.4f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.2f, 2.0f, 0.4f);
	glEnd();
}

// helper to draw left half of a hollow wall
void Wall::drawLeftHalf() {
	glPushMatrix();
	glScalef(1.0, 1.6, 1.0);
	drawLeftPloy();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.0, 0.9, 0.0);
	glRotatef(-60.0, 0.0, 0.0, 1.0);
	drawLeftPloy();
	glPopMatrix();
}

// helper to draw right half of a hollow wall
void Wall::drawRightHalf() {
	glPushMatrix();
	glScalef(1.0, 1.6, 1.0);
	drawRightPloy();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0, 0.9, 0.0);
	glRotatef(60.0, 0.0, 0.0, 1.0);
	drawRightPloy();
	glPopMatrix();
}

// sub helper for the left part
void Wall::drawLeftPloy() {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* wall = gluNewQuadric();
	gluQuadricTexture(wall, GLU_TRUE);
	gluQuadricDrawStyle(wall, GLU_FILL);
	gluQuadricNormals(wall, GLU_SMOOTH);
	glBindTexture(GL_TEXTURE_2D, texID1);

	glPushMatrix();
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(wall, 0.5f, 0.5f, 4.0f * (5.0 / 8.0), 4.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef((1.41 / 4.0), 0.0, -(1.41 / 12.0));
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(wall, (1.4 / 3.0), (1.4 / 3.0), 4.0f * (5.0 / 8.0), 3, 32.0f);
	glPopMatrix();
}

// sub helper for the right part
void Wall::drawRightPloy() {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* wall = gluNewQuadric();
	gluQuadricTexture(wall, GLU_TRUE);
	gluQuadricDrawStyle(wall, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID1);

	glPushMatrix();
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(wall, 0.5f, 0.5f, 4.0f * (5.0 / 8.0), 4.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-(1.41 / 4.0), 0.0, -(1.41 / 12.0));
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(wall, (1.4 / 3.0), (1.4 / 3.0), 4.0f * (5.0 / 8.0), 3, 32.0f);
	glPopMatrix();
}
