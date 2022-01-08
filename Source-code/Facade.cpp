#include "Facade.h"

Facade::Facade(const std::string& filename1, const std::string& filename2)
{
	// save two texture ids
	texName1 = filename1;
	texName2 = filename2;
}

void Facade::Update(const double& deltaTime)
{
	// static object will not be updated
}

void Facade::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glColor3f(0.5, 0.5f, 0.5f);

	// outter adjustment of object size, rotation and position
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);

	// draw the object
	drawFacade();
	glPopAttrib();
	glPopMatrix();
}

void Facade::drawFacade()
{
	// wall objects contributing to the facade is initiated here
	Wall* mainWall = new Wall(2, texName1, texName2);
	mainWall->size(2.7f, 2.5f, 1.5f);
	mainWall->position(0.0f, -11.0f, 12.0f);
	Wall* subWall1 = new Wall(2, texName1, texName2);
	subWall1->size(1.3f, 1.1f, 1.5f);
	subWall1->position(-8.7f, -9.5f, 12.0f);
	Wall* subWall2 = new Wall(2, texName1, texName2);
	subWall2->size(1.3f, 1.1f, 1.5f);
	subWall2->position(8.7f, -16.5f, 12.0f);
	Wall* subWall3 = new Wall(2, texName1, texName2);
	subWall3->size(1.3f, 1.1f, 1.5f);
	subWall3->position(8.7f, -9.5f, 12.0f);
	Wall* subWall4 = new Wall(2, texName1, texName2);
	subWall4->size(1.3f, 1.1f, 1.5f);
	subWall4->position(-8.7f, -16.5f, 12.0f);

	// decorative towers are initiated here
	Pillar* tower5 = new Pillar(2, texName1);
	tower5->size(3.0f);
	tower5->position(6.0f, -21.0f, 12.5f);
	Pillar* tower6 = new Pillar(2, texName1);
	tower6->size(3.0f);
	tower6->position(-6.0f, -21.0f, 12.5f);
	Pillar* tower7 = new Pillar(2, texName1);
	tower7->size(3.0f, 2.8f, 3.0f);
	tower7->position(11.5f, -21.0f, 12.5f);
	Pillar* tower8 = new Pillar(2, texName1);
	tower8->size(3.0f, 2.8f, 3.0f);
	tower8->position(-11.5f, -21.0f, 12.5f);

	tower5->Display();
	tower6->Display();
	tower7->Display();
	tower8->Display();

	mainWall->Display();
	subWall1->Display();
	subWall2->Display();
	subWall3->Display();
	subWall4->Display();
}

Facade::~Facade()
{
}
