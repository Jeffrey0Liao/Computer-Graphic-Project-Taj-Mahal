#pragma once
/* This class is defines the scene.
*
* category: framework class, functional class
* Interface implemented: None
* Dependencies: Scene
* Being depended by: None
*/

#include "Scene.h"

class MyScene :
	public Scene
{
public:
	//Constructor method
	//Inputs:
	//	argc: number of command line arguments
	// **argv: pointer of the pointer of the command line argument list
	// *title: window title
	// *windowWidth: window width
	// *windowHeight: window height
	MyScene(int argc, char** argv, const char* title, const int& windowWidth, const int& windowHeight);
	//virtual constructor
	~MyScene() {};

private:
	// Initialization function to set up the whole environment
	void Initialise();
	// function required by OpengGL to specify the projection in the scene
	void Projection();

};