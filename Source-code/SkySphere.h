#pragma once
/* This class is a level 1 object class defining the background in the scene.
*
* category: instantiable object class, updateable object, controlable object
* Interface implemented: DiaplayableObject, Animation, Input
* Dependencies: None
* Being depended by: MyScene
*/

#include "Input.h"
#include "DisplayableObject.h"
#include "Animation.h"

#include <string>

class SkySphere :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	//Constructor method
	SkySphere();
	//virtual constructor
	~SkySphere() {}


	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}
	// updating the construction to enable animation
	void Update(const double& deltaTime);

	// override from {@Input}
	// handle keyboard input
	void HandleKey(unsigned char key, int state, int x, int y);

private:
	//private function to draw the main building object.
	void drawSkySphere();
	
	// variable indicating the state of the keyboard input.
	int nKey, state;
};

