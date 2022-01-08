#pragma once
/* This class is a level 2 object class defining a fountain in the scene.
* This class follows factory design pattern in object orienting programming
* There are two kinds of fountain to be implemented:
*	1. Round base fountain
*	2. Rectangle baed fountain
* Animations of the spraying water will be implemented in this class.
*
* category: instantiable object class, updateable animation class
* Interface implemented: DiaplayableObject, Animation
* Dependencies: Wall
* Being depended by: MyScene
*/

#include "DisplayableObject.h"
#include "Animation.h"

#include "Water.h"
#include "Wall.h"

#include <string>

class Fountain :
	public DisplayableObject,
	public Animation
{
public:
	//Constructor method
	Fountain();

	//Constructor method (overload)
	//Inputs:
	//	type: integer identifier for specifying the fountain type
	//	filename1: path of the first texture required by {@Wall} instance
	//	filename2: path of the second texture required by {@Water} instance
	Fountain(int type, const std::string& filename1, const std::string& filename2);
	
	//virtual constructor
	~Fountain() {}

	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}
	//updating the construction to enable animation
	void Update(const double& deltaTime);

private:

	//private function to draw the fountain object.
	void drawFountain();
	//private funstion to draw its nozzle.
	void drawNozzle();
	//private funstion to draw its water drops.
	void drawWater();	
	//private funstion to draw its round base.
	void drawBase1();
	//private funstion to draw its rectangle base.
	void drawBase2();

	// identifier for the factory to specify the type of the fountain
	int type;
	// a copy of texture name for the wall
	std::string texName;

	// position for the water drop
	float x, y;
	// time slot for animations
	float animationTime, aT, slot;

	//a copy of texture ids
	GLint texID1;
	GLint texID2;
};

