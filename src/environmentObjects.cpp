#include "environmentObjects.h"
#include "playerObjects.h"
#include "environmentFunctions.h"
#include <iostream>

void gameEnvironmentObject::drawObject()
{

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float deginRad = i * (pi / 180);
		GLfloat xIn = radius*cos(deginRad) + xLocation;
		GLfloat yIn = radius*sin(deginRad) + yLocation;
		glVertex2f(xIn, yIn);
	}
	glEnd();


}


void gameEnvironmentObject::checkEnvironmentLoop()
{
	if (xLocation > 1.025)
	{
		xLocation = xLocation - 2.055;
	}
	else if (xLocation < -1.025)
	{
		xLocation = xLocation + 2.055;
	}
	else if (yLocation > 1.025)
	{
		yLocation = yLocation - 2.055;
	}
	else if (yLocation < -1.025)
	{
		yLocation = yLocation + 2.055;
	}
}



GLfloat gameEnvironmentObject::getXLocation()
{
	return xLocation;
}



GLfloat gameEnvironmentObject::getYLocation()
{
	return yLocation;
}

GLfloat gameEnvironmentObject::getMass()
{
	return mass;
}

GLfloat gameEnvironmentObject::getRadius()
{
	return radius;
}




void getGravityEnvironment(gameEnvironmentObject &env1, gameEnvironmentObject &env2)  // used for calculation gravitational force between two environment objects
{

}


bool gameEnvironmentObject::getActive() {
	return active;
}




//other 

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}


