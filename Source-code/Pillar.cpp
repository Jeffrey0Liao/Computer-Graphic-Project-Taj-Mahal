#include "Pillar.h"
#include "Texture.h"

Pillar::Pillar(int ttype, const std::string& filename)
{
	type = ttype;
	texID = Scene::GetTexture(filename);
}

void Pillar::Update(const double& deltaTime)
{
	// static object will not be updated
}

void Pillar::Display()
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

	// select through identifier for the type of pillar to return
	if (Pillar::type == 1) {
		drawPillarCombined1();
	}
	else if (Pillar::type == 2) {
		drawPillarCombined2();
	}
	else if (Pillar::type == 3){
		drawPillarCombined3();
	}
	else if (Pillar::type == 4) {
		drawPillarCylinder();
	}
	else if (Pillar::type == 5) {
		drawPillarPrism();
	}
	else
	{
		drawBiasCube();
	}

	glPopAttrib();
	glPopMatrix();
}

// draw a cylinder pillar
void Pillar::drawPillarCylinder()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	
	GLUquadricObj* objCylinder1 = gluNewQuadric();
	gluQuadricTexture(objCylinder1, GLU_TRUE);
	gluQuadricDrawStyle(objCylinder1, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID);

	glPushMatrix();
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(objCylinder1, 0.40f, 0.34f, 2.0f, 32, 32);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 2.0f, 0.0f);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(objCylinder1, 0.34f, 0.40f, 0.1f, 32, 32);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 2.1f, 0.0f);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(objCylinder1, 0.40f, 0.40f, 0.1f, 32, 32);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 2.2f, 0.0f);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(objCylinder1, 0.40f, 0.0f, 0.0f, 32.0f, 32.0f);
	glPopMatrix();
}

// draw a prism pillar
void Pillar::drawPillarPrism()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* objCylinder1 = gluNewQuadric();
	gluQuadricTexture(objCylinder1, GLU_TRUE);
	gluQuadricDrawStyle(objCylinder1, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID);

	glPushMatrix();
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(objCylinder1, 1.0, 1.0, 1.0f, 8, 32);
	glTranslatef(0.0f,0.0f,1.0f);
	gluCylinder(objCylinder1, 1.0, 0.0, 0.0, 8.0, 32.0);
	glPopMatrix();
}

// draw a cube pillar
void Pillar::drawBiasCube() {
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, sinf(67.76f) * 1.73 * 1.0);
	glScalef(1.0f, 3.0f, 1.0f);
	glutSolidCube(1.0f);
	glPopMatrix();
}

// draw the first kind of combined pillar
void Pillar::drawPillarCombined1() {
	Hat* hat = new Hat(2, "C:/Users/41713/Desktop/Academic/Year4_Autumn/computer_graphics/project/texture/stoneWall3.bmp");
	hat->size(0.2f);
	
	glPushMatrix();
	drawPillarCylinder();
	glTranslatef(0.0f, 2.2f, 0.0f);
	glScalef(0.9f, 1.0f, 0.9f);
	drawPillarCylinder();
	glTranslatef(0.0f, 2.2f, 0.0f);
	glScalef(0.9f, 1.0f, 0.9f);
	drawPillarCylinder();
	glTranslatef(0.0f, 2.2f + 0.8f, 0.0f);
	hat->Display();
	glPopMatrix();
}

// draw the second kind of combined pillar
void Pillar::drawPillarCombined2() {
	Hat* hat = new Hat(3, "C:/Users/41713/Desktop/Academic/Year4_Autumn/computer_graphics/project/texture/stoneWall3.bmp");
	hat->size(0.12f);

	glPushMatrix();
	glScalef(0.1f, 5.8f, 0.1f);
	drawPillarPrism();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 5.8f, 0.0f);
	hat->Display();
	glPopMatrix();
}

// draw the third kind of combined pillar
void Pillar::drawPillarCombined3() {
	Hat* hat = new Hat(2, "C:/Users/41713/Desktop/Academic/Year4_Autumn/computer_graphics/project/texture/stoneWall3.bmp");
	hat->size(0.2f);

	GLUquadricObj* objCylinder1 = gluNewQuadric();
	gluQuadricTexture(objCylinder1, GLU_TRUE);
	gluQuadricDrawStyle(objCylinder1, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID);

	glPushMatrix();
	glScalef(0.4f, 4.0f, 0.4f);
	drawPillarPrism();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 4.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(objCylinder1, 0.4f, 0.7f, 0.1f, 8.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 4.1f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(objCylinder1, 0.7f, 0.0f, 0.0f, 8.0f, 32.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 5.0f, 0.0f);
	hat->Display();
	glPopMatrix();
}

Pillar::~Pillar()
{
}
