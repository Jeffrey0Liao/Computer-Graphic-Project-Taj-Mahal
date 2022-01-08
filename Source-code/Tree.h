#pragma once
/* This class is a level 1 object class defining pillars in the scene.
* This class follows factory design pattern in object orienting programming
* There are two kinds of fountain to be implemented:
*	1. a single tree
*	2. a strip of trees
*
* category: instantiable object class
* Interface implemented: DiaplayableObject, Animation
* Dependencies: TexturedCube
* Being depended by: MyScene
*/

#include "DisplayableObject.h"
#include "Animation.h"
#include "TexturedCube.h"

#include <string>

class Tree :
	public DisplayableObject,
	public Animation
{
public:
	//Constructor method
	//Inputs:
	//	filename1: path of the first texture required by leaf
	//	filename2: path of the first texture required by wood
	Tree(const std::string& filename1, const std::string& filename2);
	//Constructor method (overload)
	//Inputs:
	//	filename1: path of the first texture required by leaf
	//	filename2: path of the first texture required by wood
	//	numOfTree: how many trees in the tree strip
	Tree(const std::string& filename3, const std::string& filename4, int numOfTree);

	//override from {@DisplayableObject}
	//display the object in OpenGL scene
	void Display();

	//override from {@Aniamtion}
	// updating the construction to enable animation
	void Update(const double& deltaTime);

private:
	// private function to draw a single tree
	void drawTree();
	// private function to draw a tree strip
	void drawTreeStrip();

	// integer identifier for specifying the pillar type
	int indicator;
	// number of trees in a tree strip
	int num;
	// cpoies of texture ids
	GLint texID1;
	GLint texID2;
};

