#include "Tree.h"
#include "Texture.h"

// constructor for initiating a single tree
Tree::Tree(const std::string& filename1, const std::string& filename2)
{
	texID1 = Scene::GetTexture(filename1);
	texID2 = Scene::GetTexture(filename2);
	indicator = 1;
}

// constructor for initiating a tree strip
Tree::Tree(const std::string& filename3, const std::string& filename4, int numOfTree)
{
	texID1 = Scene::GetTexture(filename3);
	texID2 = Scene::GetTexture(filename4);
	num = numOfTree;
	indicator = 2;
}

void Tree::Update(const double& deltaTime)
{
	// static object will not be updated
}

void Tree::Display()
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

	// select through identifier for the type to return
	if (indicator == 1) {
		drawTree();
	}
	else
	{
		drawTreeStrip();
	}

	glPopAttrib();
	glPopMatrix();
}

// helper to draw a single tree
void Tree::drawTree()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	GLUquadricObj* wood = gluNewQuadric();
	gluQuadricTexture(wood, GLU_TRUE);
	gluQuadricDrawStyle(wood, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID1);

	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(wood, 0.6f, 0.3f, 2.0f, 32.0f, 32.0f);

	GLUquadricObj* leaf = gluNewQuadric();
	gluQuadricTexture(leaf, GLU_TRUE);
	gluQuadricDrawStyle(leaf, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texID2);

	glTranslatef(0.0f, 0.0f, 1.5f + 1.0f);
	gluSphere(leaf, 1.0f, 32.0f, 32.0f);
	gluCylinder(leaf, 1.0f, 1.0f, 4.0f, 32.0f, 32.0f);
	glTranslatef(0.0f, 0.0f, 1.5f + 1.0f + 1.0f);
	gluSphere(leaf, 1.0f, 32.0f, 32.0f);
	glPopMatrix();
}

// helper to draw a tree strip
void Tree::drawTreeStrip()
{
	for (int i = 0; i < num; i++) {
		glTranslatef(0.0f, 0.0f, 8.0f);
		drawTree();
	}
}


