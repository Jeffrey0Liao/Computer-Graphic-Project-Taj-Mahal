#pragma once
/* This class is a level 1 object class defining a cube.
* 
* category: instantiable object class
* Interface implemented: DiaplayableObject, Animation
* Dependencies: None
* Being depended by: Facade, MainBuiliding, SideBuilding, MyScene
*/

#include "DisplayableObject.h"
#include "Animation.h"

#include <string>

class TexturedCube :
	public DisplayableObject,
	public Animation
{
public:
	//Constructor method
	TexturedCube();
	//Constructor method (overload)
	//Inputs:
	//	filename: path of the cube texture
	TexturedCube(const std::string& filename);
	//virtual constructor
	~TexturedCube() {}

	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}
	// updating the construction to enable animation
	void Update(const double& deltaTime);

private:
	// private function to draw a cube
	void DrawCube();

	// Rate of rotation in x and y (degrees per second) 
	float _xrot, _yrot;
	//a copy of texture id
	GLint texID;
};

