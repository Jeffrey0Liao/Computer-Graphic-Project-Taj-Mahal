#pragma once
/* This class is a level 1 object class defining a wall in a facade.
* This class follows factory design pattern in object orienting programming
* There are two kinds of fountain to be implemented:
*	1. plane wall
*	2. hollow wall
* 
* category: instantiable object class
* Interface implemented: DiaplayableObject, Animation
* Dependencies: TexturedCube
* Being depended by: Facade, MainBuiliding
*/

#include "DisplayableObject.h"
#include "Animation.h"
#include "TexturedCube.h"

#include <string>

class Wall :
	public DisplayableObject,
	public Animation
{
public:
	//Constructor method
	Wall();
	//Constructor method (overload)
	//Inputs:
	//	ttype: integer identifier for specifying the wall type
	//	filename1: path of the first texture required by the wall
	//	filename2: path of the second texture required by the wall surface
	Wall(int ttype, const std::string& filename1, const std::string& filename2);
	//virtual constructor
	~Wall() {}

	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}
	//updating the construction to enable animation
	void Update(const double& deltaTime);

private:
	//private function to draw a plane wall
	void drawWall();
	// private function to draw a hollowed wall
	void drawHollowWall();
	// helper function to draw the left part of a hollow wall
	void drawLeftHalf();
	// helper function to draw the right part of a hollow wall
	void drawRightHalf();
	// helper function to draw a left orienting object
	void drawLeftPloy();
	// helper function to draw a right orienting object
	void drawRightPloy();

	// Rate of rotation in x and y (degrees per second) 
	float _xrot, _yrot;

	// integer identifier for specifying the wall type
	int type;
	//copies of texture ids
	GLint texID1;
	GLint texID2;
	// a copy of texture name
	std::string texName;
};

