/* This class is a level 3 object class defining the main building in the scene.
*
* category: instantiable object class
* Interface implemented: DiaplayableObject, Animation
* Dependencies: Hat, Facade, TextureCube, Pillar, Wall
* Being depended by: MyScene
*/

#ifndef __MainBuilding__
#define __MainBuilding__

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include "Animation.h"

#include "Hat.h"
#include "Pillar.h"
#include "Wall.h"
#include "Facade.h"
#include "TexturedCube.h"

class MainBuilding:
	public DisplayableObject,
	public Animation

{
public:
	//Constructor method
	MainBuilding();
	//virtual constructor
	~MainBuilding();

	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}, updating the construction to enable animation
	void Update(const double& deltaTime);

private:
	//private function to draw the main building object.
	void drawMainBuilding();
};

#endif