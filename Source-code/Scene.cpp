#include "Animation.h"
#include "Input.h"
#include "Scene.h"
#include "DisplayableObject.h"
#include <cstdlib>
#include <iostream>

Texture Scene::texture = Texture();		// Initialise Texture handler
Camera Scene::camera = Camera();        // Initialise Camera object

Scene::Scene(int argc, char** argv, const char* title, const int& windowWidth, const int& windowHeight)
	: Engine(argc, argv, title, windowWidth, windowHeight), state(0)
{
	camera.Reset(); // Set Camera to default properties
}
/**
 * Destructor: deletes all {@link DisplayableObject}s in the Scene
 */
Scene::~Scene()
{
	for (DisplayableObject* obj : objects)
	{
		if (obj != NULL)
			delete obj;
		obj = NULL;
	}
}

int Scene::GetWindowWidth()
{
	return Engine::windowWidth;
}

int Scene::GetWindowHeight()
{
	return Engine::windowHeight;
}

int Scene::GetTexture(std::string filename)
{
	return texture.GetTexture(filename);
}

void Scene::Initialise()
{
	// Override in your class
}

void Scene::Draw()
{
	// Clear colour and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Update based on window details (also sets initial projection properties)
	Reshape(windowWidth, windowHeight);
	// Reset MODELVIEW matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Setup viewing properties
	camera.SetupCamera();

	// set the ambient light model
	GLfloat global_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	// enable directional light lighting
	// (x, y, z, 0.0) -> directional lighting
	// (x, y, z, 1.0) -> positional lighting
	glEnable(GL_LIGHTING);
	GLfloat ambienceDay[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	GLfloat diffuseDay[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat specularDay[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat positionDay[] = { 1.0f, 1.0f, 1.0f, 0.0f };

	GLfloat ambienceNight[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat diffuseNight[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat specularNight[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat positionNight[] = { 1.0f, 1.0f, 1.0f, 0.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambienceDay);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseDay);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularDay);
	glLightfv(GL_LIGHT0, GL_POSITION, positionDay);

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambienceNight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseNight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularNight);
	glLightfv(GL_LIGHT1, GL_POSITION, positionNight);

	glEnable(GL_LIGHT1);
	if (state % 2 == 1) {
		glEnable(GL_LIGHT0);
	}
	else {
		glDisable(GL_LIGHT0);
	}
	// Enable fog effect
	glEnable(GL_FOG);
	GLfloat fogColor[] = { 0.8f, 0.8f, 0.8f };
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_DENSITY, 0.5f);
	glFogf(GL_FOG_START, 0.0f);
	glFogf(GL_FOG_END, 800.0f);
	glHint(GL_FOG_HINT, GL_NICEST);

	// Display all objects in the Scene
	for (DisplayableObject* obj : objects)
		obj->Display();

	// Zealous reset of MODELVIEW matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Dump silent GL errors into console output
	CheckGLError();
}

void Scene::Reshape(int w, int h)
{
	// update window properties
	windowWidth = w;
	windowHeight = h;
	// Reset projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Generate new projection transform based on updated window properties
	Projection();
	// Revert to MODELVIEW (for viewing)
	glMatrixMode(GL_MODELVIEW);
	// Update viewport for new window dimensions
	camera.SetViewport();
}

void Scene::Projection() {
	// Default orthographic projection
	glOrtho(static_cast<GLdouble>(-windowWidth) / static_cast<GLdouble>(2.0), static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(2.0),
		static_cast<GLdouble>(-windowHeight) / static_cast<GLdouble>(2.0), static_cast<GLdouble>(windowHeight) / static_cast<GLdouble>(2.0),
		static_cast<GLdouble>(1.0), static_cast<GLdouble>(1000.0));
}

void Scene::Update(const double& deltaTime)
{
	Animation* animated_obj;
	// Update camera/view
	camera.Update(deltaTime);
	// Iterate through objects to update animations
	for (DisplayableObject* obj : objects)
	{
		animated_obj = dynamic_cast<Animation*>(obj); // Cast to animation
		if (animated_obj != NULL) // If cast successful
			animated_obj->Update(deltaTime); // Call update sequence for obj
	}
	// Scene update
	if (nKey)
		state += 1;
}

void Scene::AddObjectToScene(DisplayableObject* obj) {
	objects.push_back(obj); // Object added to list (vector) of those to display in Scene
}

void Scene::HandleKey(unsigned char key, int state, int x, int y)
{
	// Handle Keyboard input (ASCII) and pass to objects.
	// State is 1 for key press, 0 for key release

	switch (key)
	{
	case 'N':
	case 'n':
		nKey = state;
		break;
	}

	if (key == 27 && state) // Check for escape key pressed
	{
		exit(0); // EXIT ON ESCAPE PRESS
	}

	Input* input_obj;
	camera.HandleKey(key, state, x, y);
	for (DisplayableObject* obj : objects)
	{
		input_obj = dynamic_cast<Input*>(obj);
		if (input_obj != NULL)
			input_obj->HandleKey(key, state, x, y);
	}
}

void Scene::HandleSpecialKey(int key, int state, int x, int y)
{
	// Handle Special Keyboard input (non-ASCII) and pass to objects.
	// State is 1 for key press, 0 for key release
	Input* input_obj;
	camera.HandleSpecialKey(key, state, x, y);
	for (DisplayableObject* obj : objects)
	{
		input_obj = dynamic_cast<Input*>(obj);
		if (input_obj != NULL)
			input_obj->HandleSpecialKey(key, state, x, y);
	}
}

void Scene::HandleMouse(int button, int state, int x, int y)
{
	// Handle mouse input and pass to objects.
	// State is 1 for button press, 0 for key release
	Input* input_obj;
	camera.HandleMouse(button, state, x, y);
	for (DisplayableObject* obj : objects)
	{
		input_obj = dynamic_cast<Input*>(obj);
		if (input_obj != NULL)
			input_obj->HandleMouse(button, state, x, y);
	}
}

void Scene::HandleMouseDrag(int x, int y)
{
	// Handle mouse movement while button is pressed (active motion)
	Input* input_obj;
	camera.HandleMouseDrag(x, y);
	for (DisplayableObject* obj : objects)
	{
		input_obj = dynamic_cast<Input*>(obj);
		if (input_obj != NULL)
			input_obj->HandleMouseDrag(x, y);
	}
}

void Scene::HandleMouseMove(int x, int y)
{
	// Handle passive mouse movement, called whether button is pressed or not
	Input* input_obj;
	camera.HandleMouseMove(x, y);
	for (DisplayableObject* obj : objects)
	{
		input_obj = dynamic_cast<Input*>(obj);
		if (input_obj != NULL)
			input_obj->HandleMouseMove(x, y);
	}
}
