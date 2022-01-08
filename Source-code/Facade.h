/* This class is a level 2 object class defining a facade of the building, which is basically an aggregation of hollow wall and some pillars.
* 
* category: instantiable object class
* 
* Interface implemented: DiaplayableObject, Animation
* Dependencies: Hat, Pillar, Wall, TextureCube
* Being depended by: MainBuilding, SideBuiliding
*/

#ifndef __Facade__
#define __Facade__

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include "Animation.h"

#include "Hat.h"
#include "Pillar.h"
#include "Wall.h"
#include "TexturedCube.h"

class Facade :
	public DisplayableObject,
	public Animation

{
public:
	//Constructor method
	//Inputs:
	//	filename1: path of the first texture required by {@Wall} instance
	//	filename2: path of the second texture required by {@Wall} instance
	Facade(const std::string& filename1, const std::string& filename2);

	//virtual constructor
	~Facade();

	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}, updating the construction to enable animation
	void Update(const double& deltaTime);

private:
	//private variable for texture paths
	std::string texName1;
	std::string texName2;
	//private funstion to draw the facade object.
	void drawFacade();
};

#endif