#include "MainBuilding.h"

MainBuilding::MainBuilding()
{
}

void MainBuilding::Update(const double& deltaTime)
{
}

void MainBuilding::Display()
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
	drawMainBuilding();
	glPopAttrib();
	glPopMatrix();
}

void MainBuilding::drawMainBuilding()
{
	// draw main body of the building
	TexturedCube* body = new TexturedCube("./texture/stoneWall3.bmp");
	body->size(23.0f, 13.0f, 23.0f);
	body->position(0.0f, -14.0f, 0.0f);

	// draw five roofs of the building
	Hat* mainHat = new Hat(1, "./texture/stoneWall3.bmp");
	mainHat->size(4.0f, 4.0f, 4.0f);
	Hat* hat1 = new Hat(2, "./texture/stoneWall3.bmp");
	hat1->size(1.1f, 0.8f, 1.1f);
	hat1->position(9.0, -3.5, -9.0);
	Hat* hat2 = new Hat(2, "./texture/stoneWall3.bmp");
	hat2->size(1.1f, 0.8f, 1.1f);
	hat2->position(9.0, -3.5, 9.0);
	Hat* hat3 = new Hat(2, "./texture/stoneWall3.bmp");
	hat3->size(1.1f, 0.8f, 1.1f);
	hat3->position(-9.0, -3.5, 9.0);
	Hat* hat4 = new Hat(2, "./texture/stoneWall3.bmp");
	hat4->size(1.1f, 0.8f, 1.1f);
	hat4->position(-9.0, -3.5, -9.0);

	// draw the two facades of the buildng
	Facade* faceFront = new Facade("./texture/stoneWall3.bmp", 
		"./texture/carvings.png");
	Facade* faceBack = new Facade("./texture/stoneWall3.bmp", 
		"./texture/carvings.png");
	faceBack->orientation(0.0f, 180.0f, 0.0f);
	faceBack->position(0.0f, 0.0f, 0.0f);
	/*Facade* faceLeft = new Facade("./texture/stoneWall3.bmp", 
		"./texture/redWall.jpeg");
	Facade* faceRight = new Facade("./texture/stoneWall3.bmp", 
		"./texture/redWall.jpeg");*/


	// draw base and its towers
	TexturedCube* base = new TexturedCube("./texture/stoneWall3.bmp");
	base->size(46.0f, 4.0f, 46.0f);
	base->position(0.0f, -22.0f, 0.0f);

	Pillar* basePillar1 = new Pillar(5, "./texture/stoneWall3.bmp");
	basePillar1->size(3.0f, 4.0f, 3.0f);
	basePillar1->position(23.0f, -24.0f, 23.0f);
	Pillar* basePillar2 = new Pillar(5, "./texture/stoneWall3.bmp");
	basePillar2->size(3.0f, 4.0f, 3.0f);
	basePillar2->position(-23.0f, -24.0f, 23.0f);
	Pillar* basePillar3 = new Pillar(5, "./texture/stoneWall3.bmp");
	basePillar3->size(3.0f, 4.0f, 3.0f);
	basePillar3->position(23.0f, -24.0f, -23.0f);
	Pillar* basePillar4 = new Pillar(5, "./texture/stoneWall3.bmp");
	basePillar4->size(3.0f, 4.0f, 3.0f);
	basePillar4->position(-23.0f, -24.0f, -23.0f);
	Pillar* tower1 = new Pillar(1, "./texture/stoneWall3.bmp");
	tower1->size(3.0f, 3.0f, 3.0f);
	tower1->position(23.0f, -21.0f, 23.0f);
	Pillar* tower2 = new Pillar(1, "./texture/stoneWall3.bmp");
	tower2->size(3.0f, 3.0f, 3.0f);
	tower2->position(-23.0f, -21.0f, 23.0f);
	Pillar* tower3 = new Pillar(1, "./texture/stoneWall3.bmp");
	tower3->size(3.0f, 3.0f, 3.0f);
	tower3->position(23.0f, -21.0f, -23.0f);
	Pillar* tower4 = new Pillar(1, "./texture/stoneWall3.bmp");
	tower4->size(3.0f, 3.0f, 3.0f);
	tower4->position(-23.0f, -21.0f, -23.0f);
	


	body->Display();
	mainHat->Display();
	hat1->Display();
	hat2->Display();
	hat3->Display();
	hat4->Display();
	base->Display();
	basePillar1->Display();
	basePillar2->Display();
	basePillar3->Display();
	basePillar4->Display();
	tower1->Display();
	tower2->Display();
	tower3->Display();
	tower4->Display();
	faceFront->Display();
	faceBack->Display();
}

MainBuilding::~MainBuilding()
{
}
