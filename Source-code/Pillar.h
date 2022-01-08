/* This class is a level 1 object class defining pillars in the scene.
* This class follows factory design pattern in object orienting programming
* There are six kinds of fountain to be implemented:
*	1. combined pillar of type 1
*	2. combined pillar of type 2
*	3. combined pillar of type 3
*	4. cylinder pillar
*	5. prism pillar
*	6. cube pillar
*
* category: instantiable object class
* Interface implemented: DiaplayableObject, Animation
* Dependencies: Hat
* Being depended by: MyScene, Facade, MainBuiliding, SideBuilding
*/
#ifndef __Pillar__
#define __Pillar__

#define _USE_MATH_DEFINES
#include <math.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Hat.h"

class Pillar :
	public DisplayableObject,
	public Animation

{
public:
	//Constructor method
	//Inputs:
	//	type: integer identifier for specifying the pillar type
	//	filename: path of the texture required by pillar instance
	Pillar(int type, const std::string& filename);
	
	//virtual constructor
	~Pillar();
	
	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}
	//updating the construction to enable animation
	void Update(const double& deltaTime);

private:
	// integer identifier for specifying the pillar type
	int type;
	// a copy of texture id
	GLint texID;

	//private function to draw a combined pillar of type 1.
	void drawPillarCombined1();

	//private function to draw a combined pillar of type 2.
	void drawPillarCombined2();

	//private function to draw a combined pillar of type 3.
	void drawPillarCombined3();

	//private function to draw a cylinder pullar..
	void drawPillarCylinder();

	//private function to draw a prism pillar.
	void drawPillarPrism();

	//private function to draw a cube pillar.
	void drawBiasCube();
};

#endif