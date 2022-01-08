/* This class is a level 3 object class defining the side building in the scene.
*
* category: instantiable object class
* Interface implemented: DiaplayableObject, Animation
* Dependencies: Hat, Facade, TextureCube, Pillar, Wall
* Being depended by: MyScene
*/

#ifndef __SideBuilding__
#define __SideBuilding__

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include "Animation.h"

#include "Hat.h"
#include "Pillar.h"
#include "Wall.h"
#include "Facade.h"
#include "TexturedCube.h"

class SideBuilding :
	public DisplayableObject,
	public Animation

{
public:
	//Constructor method
	SideBuilding();
	//virtual constructor
	~SideBuilding();

	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}, updating the construction to enable animation
	void Update(const double& deltaTime);

private:
	//private function to draw the side building object.
	void drawSideBuilding();
};

#endif