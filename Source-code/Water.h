#pragma once
/* This class is a level 1 object class defining a water surface.
* Animations of water waves will be implemented in this class.
*
* category: instantiable object class, updateable animation class
* Interface implemented: DiaplayableObject, Animation, Input
* Dependencies: None
* Being depended by: MyScene
*/

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

#include <string>

class Water :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	//Constructor method 
	//Inputs:
	//	gridX: number of splits along X axis
	//	gridZ: number of splits along Z axis
	//	filename: path of the texture required by water surface
	Water(const int& gridX, const int& gridZ, const std::string& filename);
	//virtual constructor
	~Water();

	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}
	//updating the construction to enable animation
	void Update(const double& delteTime);

	// override from {@Input}
	// handle keyboard input
	void HandleKey(unsigned char key, int state, int x, int y);

private:
	//a copy of texture id
	int texID;
	//a copy of splits
	int xGridDims, zGridDims;
	// indicator for animation intensity
	float radius;
	// pointer points to the texture coordinates
	float* texCoords;
	// a copy of time
	double time;
	// state boolean indicator 
	bool frozen;

	// matrial properties of the grid
	float matAmbient[4];      
	float matDiffuse[4];
	int   matShininess;
	float matSpecular[4];
};

