
#include "MyScene.h"

#include "SkySphere.h"
#include "Pillar.h"
#include "MainBuilding.h"
#include "SideBuilding.h"
#include "Hat.h"
#include "Wall.h"
#include "Fountain.h"
#include "Water.h"
#include "Tree.h"
#include "TexturedCube.h"

MyScene::MyScene(int argc, char** argv, const char* title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // original background color is set to black
#ifdef __APPLE__
	TexturedCube* tc = new TexturedCube("./water.bmp");
	//do nothing
#else
	SideBuilding* test = new SideBuilding();

	// initiate sky shpere and ground
	SkySphere* sky = new SkySphere();
	TexturedCube* ground = new TexturedCube("./texture/floor.png");

	// initiate main building and two side buildings
	MainBuilding* mb = new MainBuilding();
	SideBuilding* sbLeft = new SideBuilding();
	SideBuilding* sbRight = new SideBuilding();

	// initiate four towers along with the closure wall
	Pillar* wallTower1 = new Pillar(3, "./texture/redWall.jpeg");
	Pillar* wallTower2 = new Pillar(3, "./texture/redWall.jpeg");
	Pillar* wallTower3 = new Pillar(3, "./texture/redWall.jpeg");
	Pillar* wallTower4 = new Pillar(3, "./texture/redWall.jpeg");
	Wall* wallLeft = new Wall(1, "./texture/redWall.jpeg", 
		"./texture/redWall.jpeg");
	Wall* wallRight = new Wall(1, "./texture/redWall.jpeg", 
		"./texture/redWall.jpeg");
	Wall* wallFL = new Wall(1, "./texture/redWall.jpeg", 
		"./texture/redWall.jpeg");
	Wall* wallRL = new Wall(1, "./texture/redWall.jpeg", 
		"./texture/redWall.jpeg");

	// initiate two fountains
	Fountain* ft1 = new Fountain(1, "./texture/stoneWall3.bmp", 
		"./texture/water.jpg");
	Fountain* ft2 = new Fountain(2, "./texture/stoneWall3.bmp",
		"./texture/water.jpg");
	Water* water1 = new Water(20, 20, "./texture/water.png");
	Water* water2 = new Water(20, 20, "./texture/water.jpg");

	// initiate two tree strips
	Tree* ts1 = new Tree("./texture/wood.jpg",
		"./texture/leaf.jpg", 6);
	Tree* ts2 = new Tree("./texture/wood.jpg",
		"./texture/leaf.jpg", 6);
#endif

	// settings
	sky->size(600.0f);
	sky->orientation(0.0f, 0.0f, 180.0f);
	
	ground->size(180.0f, 0.1f, 180.0f);
	ground->orientation(0.0f, 180.0f, 0.0f);
	ground->position(0.0f, -23.0f, 41.0f);

	mb->size(1.0f);

	sbLeft->size(0.8f);
	sbLeft->position(-75.0f, -8.0f, 0.0f);

	sbRight->size(0.8f);
	sbRight->orientation(0.0f, 180.0f, 0.0f);
	sbRight->position(75.0f, -8.0f, 0.0f);

	wallLeft->size(1.0f, 3.0f, 10.0f);
	wallLeft->orientation(0.0f, 90.0f, 0.0f);
	wallLeft->position(-75.0f, -20.0f, 57.0f);
	wallRight->size(1.0f, 3.0f, 10.0f);
	wallRight->orientation(0.0f, 90.0f, 0.0f);
	wallRight->position(75.0f, -20.0f, 57.0f);
	wallFL->size(5.0f, 3.0f, 1.0f);
	wallFL->position(-51.0f, -20.0f, 107.0f);
	wallRL->size(5.0f, 3.0f, 1.0f);
	wallRL->position(51.0f, -20.0f, 107.0f);

	wallTower1->size(4.0f, 2.6f, 4.0f);
	wallTower1->position(-75.0f, -24.0f, 107.0f);
	wallTower2->size(4.0f, 2.6f, 4.0f);
	wallTower2->position(75.0f, -24.0f, 107.0f);
	wallTower3->size(4.0f, 2.6f, 4.0f);
	wallTower3->position(-25.0f, -24.0f, 107.0f);
	wallTower4->size(4.0f, 2.6f, 4.0f);
	wallTower4->position(25.0f, -24.0f, 107.0f);

	ft1->size(1.2f);
	ft1->position(0.0f, -23.0f, 100.0f);
	water1->position(0.0f, -21.5f, 100.0f);
	water1->size(35.0f, 20.0f, 30.0f);

	ft2->size(0.6f);
	ft2->position(0.0f, -23.0f, 55.0f);
	water2->position(0.0f, -21.5f, 55.0f);
	water2->size(15.0f, 20.0f, 50.0f);

	ts1->size(1.0f);
	ts1->position(10.0f, -23.0f, 26.0f);
	ts2->size(1.0f);
	ts2->position(-10.0f, -23.0f, 26.0f);

	
	
	// push objects into the object list
	//AddObjectToScene(test);
	AddObjectToScene(sky);
	AddObjectToScene(ground);
	AddObjectToScene(ft1);
	AddObjectToScene(water1);
	AddObjectToScene(ft2);
	AddObjectToScene(water2);
	AddObjectToScene(sbLeft);
	AddObjectToScene(sbRight);
	AddObjectToScene(wallLeft);
	AddObjectToScene(wallRight);
	AddObjectToScene(wallFL);
	AddObjectToScene(wallRL);
	AddObjectToScene(wallTower1);
	AddObjectToScene(wallTower2);
	AddObjectToScene(wallTower3);
	AddObjectToScene(wallTower4);
	AddObjectToScene(ts1);
	AddObjectToScene(ts2);
	AddObjectToScene(mb);
	AddObjectToScene(sbLeft);
	AddObjectToScene(sbRight);
}

void MyScene::Projection()
{
	// projection and perspective
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
