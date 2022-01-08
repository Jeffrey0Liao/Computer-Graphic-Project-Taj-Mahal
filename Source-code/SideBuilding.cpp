#include "SideBuilding.h"

SideBuilding::SideBuilding()
{
}

void SideBuilding::Update(const double& deltaTime)
{
}

void SideBuilding::Display()
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
	drawSideBuilding();
	glPopAttrib();
	glPopMatrix();
}

void SideBuilding::drawSideBuilding()
{
	// initiate main body of the side building
	TexturedCube* body = new TexturedCube("./texture/redWall.jpeg");
	body->size(13.0f, 15.0f, 39.0f);
	body->position(0.0f, -15.0f, 0.0f);
	TexturedCube* bodyLeft = new TexturedCube("./texture/redWall.jpeg");
	bodyLeft->size(3.0f, 15.0f, 9.0f);
	bodyLeft->position(0.0f, -15.0f, 23.0f);
	TexturedCube* bodyRight = new TexturedCube("./texture/redWall.jpeg");
	bodyRight->size(3.0f, 15.0f, 9.0f);
	bodyRight->position(0.0f, -15.0f, -23.0f);

	// initiate three roofs
	Hat* mainHat = new Hat(1, "./texture/stoneWall3.bmp");
	mainHat->size(3.2f, 2.7f, 3.2f);
	mainHat->position(0.0f, -3.6f, 0.0f);
	Hat* hatLeft = new Hat(1, "./texture/stoneWall3.bmp");
	hatLeft->size(2.8f, 2.3f, 2.8f);
	hatLeft->position(0.0f, -3.6f, -14.0f);
	Hat* hatRight = new Hat(1, "./texture/stoneWall3.bmp");
	hatRight->size(2.8f, 2.3f, 2.8f);
	hatRight->position(0.0f, -3.6f, 14.0f);

	// initiate two facades and four individual hollow walls
	Facade* faceFront = new Facade("./texture/redWall.jpeg", 
		"./texture/redWall.jpeg");
	faceFront->size(1.0f, 1.1f, 1.0f);
	faceFront->orientation(0.0f, -90.0f, 0.0f);
	faceFront->position(19.0f, 1.0f, 0.0f);
	Facade* faceBack = new Facade("./texture/redWall.jpeg", 
		"./texture/redWall.jpeg");
	faceBack->size(1.0f, 1.1f, 1.0f);
	faceBack->orientation(0.0f, 90.0f, 0.0f);
	faceBack->position(-19.0f, 1.0f, 0.0f);
	Wall* hw1 = new Wall(2, "./texture/redWall.jpeg", 
		"./texture/redWall.jpeg");
	hw1->size(2.0f, 2.45f, 1.9f);
	hw1->orientation(0.0f, 90.0f, 0.0f);
	hw1->position(-6.5f, -12.5f, 15.5f);
	Wall* hw2 = new Wall(2, "./texture/redWall.jpeg", 
		"./texture/redWall.jpeg");
	hw2->size(2.0f, 2.45f, 1.9f);
	hw2->orientation(0.0f, 90.0f, 0.0f);
	hw2->position(-6.5f, -12.5f, -15.5f);
	Wall* hw3 = new Wall(2, "./texture/redWall.jpeg", 
		"./texture/redWall.jpeg");
	hw3->size(2.0f, 2.45f, 1.9f);
	hw3->orientation(0.0f, -90.0f, 0.0f);
	hw3->position(6.5f, -12.5f, 15.5f);
	Wall* hw4 = new Wall(2, "./texture/redWall.jpeg", 
		"./texture/redWall.jpeg");
	hw4->size(2.0f, 2.45f, 1.9f);
	hw4->orientation(0.0f, -90.0f, 0.0f);
	hw4->position(6.5f, -12.5f, -15.5f);

	// initiate two pillars
	Pillar* tower1 = new Pillar(3, "./texture/redWall.jpeg");
	tower1->size(5.0f, 4.2f, 5.0f);
	tower1->position(0.0f, -23.0f, 28.0f);
	Pillar* tower2 = new Pillar(3, "./texture/redWall.jpeg");
	tower2->size(5.0f, 4.2f, 5.0f);
	tower2->position(0.0f, -23.0f, -28.0f);



	body->Display();
	bodyLeft->Display();
	bodyRight->Display();
	mainHat->Display();
	hatLeft->Display();
	hatRight->Display();
	faceFront->Display();
	hw1->Display();
	hw2->Display();
	faceBack->Display();
	hw3->Display();
	hw4->Display();
	tower1->Display();
	tower2->Display();
}

SideBuilding::~SideBuilding()
{
}
