#pragma once
/* This class is a level 1 object class defining roofs for a building.
* This class follows factory design pattern in object orienting programming
* There are three kinds of roofs to be implemented:
*	1. main roof with a base
*	2. side roofs with pillars
*	3. small round decorative roof
*
* category: instantiable object class
* Interface implemented: DiaplayableObject, Animation
* Dependencies: None
* Being depended by: Facade, MainBuiliding, SideBuilding
*/

#include "DisplayableObject.h"
#include "Animation.h"

#include <string>

class Hat :
	public DisplayableObject,
	public Animation
{
public:
	//Constructor method
	Hat();
	//Constructor method (overload)
	//Inputs:
	//	type: integer identifier for specifying the fountain type
	//	filename: path of the roof texture
	Hat(int ttype, const std::string& filename);
	//virtual constructor
	~Hat() {}

	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}
	// updating the construction to enable animation
	void Update(const double& deltaTime);

private:
	// private function to draw the main roof with a base 
	void drawHat90();
	// private function to draw the side rood with pillars
	void drawHat120();
	// private function to draw the round decorative roof
	void drawHat0();
	
	// identifier for the factory to specify the type of the roof
	int type;
	//a copy of texture id
	GLint texID;
};

