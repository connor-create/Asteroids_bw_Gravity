#include "environmentObjects.h"
#include "playerObjects.h"
#include "environmentFunctions.h"
#include <iostream>
#include <vector>



void environmentFunctions::keyStrokes(GLFWwindow* window, gamePlayerObject& ship, environmentFunctions& projectiles)
{
	glfwSetKeyCallback(window, keyCallback);
	int wstate = glfwGetKey(window, GLFW_KEY_W);
	if (wstate == GLFW_PRESS)
	{
		ship.addSpeed();
	}
	int sstate = glfwGetKey(window, GLFW_KEY_S);
	if (sstate == GLFW_PRESS)
	{
		ship.minusSpeed();
	}
	int dstate = glfwGetKey(window, GLFW_KEY_D);
	if (dstate == GLFW_PRESS)
	{
		ship.clockWiseRot();
	}
	int astate = glfwGetKey(window, GLFW_KEY_A);
	if (astate == GLFW_PRESS)
	{
		ship.counterclockWiseRot();
	}
	int spacestate = glfwGetKey(window, GLFW_KEY_SPACE);
	if (spacestate == GLFW_PRESS)
	{
		projectiles.addProjectile(ship, projectiles);
	}
}
 

void environmentFunctions::getGravityPlayer(gameEnvironmentObject &env1, gamePlayerObject &player)  // used for calculation gravitational force between player and environment object
{
	// force calculations
	gameEnvironmentObject envPH = env1;     
	gamePlayerObject plaPH = player;
	float distanceX = abs(plaPH.getXLocation() - envPH.getXLocation());
	float distanceY = abs(plaPH.getYLocation() - envPH.getYLocation());
	float distanceAngleX = envPH.getXLocation() - plaPH.getXLocation();
	float distanceAngleY = envPH.getYLocation() - plaPH.getYLocation();
	float distanceVector = pow(distanceX, 2) + pow(distanceY, 2);
	float forceOfGrav = (.0000001 * envPH.getMass() * plaPH.getMass()) / pow(distanceVector, .6);
	// angle calculations
	float angleBefore = (atan((envPH.getYLocation() - plaPH.getYLocation()) / (envPH.getXLocation() - plaPH.getXLocation()))) * (180/pi);
	float angle = 0;
	if (distanceAngleX > 0 && distanceAngleY < 0)
	{
		angle = angleBefore + 360;
	}
	else if (distanceAngleX > 0 && distanceAngleY > 0 )
	{
		angle = angleBefore;
	}
	else if (distanceAngleX < 0 && distanceAngleY > 0)
	{
		angle = angleBefore + 180;
	}
	else if (distanceAngleX < 0 && distanceAngleY < 0)
	{
		angle = angleBefore + 180;
	}

	float xSpeed = cos(angle*(pi/180)) * forceOfGrav;
	float ySpeed = sin(angle*(pi/180)) * forceOfGrav;
	player.addGravSpeed(xSpeed, ySpeed);
}
 

void environmentFunctions::addProjectile(gamePlayerObject& player, environmentFunctions& projectiles)
{
	
	if (environmentFunctions::getProjectileTicks(projectiles) > 30)
	{
		projectile pro;
		GLfloat direction = player.getRotation();
		float radAmount = direction * pi / 180;
		pro.xSpeed = cos(radAmount)*.0225;
		pro.ySpeed = sin(radAmount)*.0225;
		pro.xLocation = player.getXLocation() + .07 * cos(radAmount);
		pro.yLocation = player.getYLocation() + .07 * sin(radAmount);
		projectiles.projectileContainer.push_back(pro);
		environmentFunctions::resetProjectileTick(projectiles);
	}


}


void environmentFunctions::drawProjectiles(environmentFunctions& projectiles)
{ 
	bool clear = false;
	int vectSize = projectiles.projectileContainer.size();
	for (int i = 0; i < vectSize; i++)
	{
		clear = false;
		glBegin(GL_POLYGON);
		projectile tempPro = projectiles.projectileContainer[i];
		GLfloat radius = .003;
		GLfloat deginRad;
		for (int j = 0; j < 360; j++)
		{
			deginRad = j * (pi / 180);
			GLfloat xIn = radius * cos(deginRad) + tempPro.xLocation;
			GLfloat yIn = radius * sin(deginRad) + tempPro.yLocation;
			glVertex2f(xIn, yIn);
		}

		tempPro.xLocation = tempPro.xLocation + tempPro.xSpeed;
		tempPro.yLocation = tempPro.yLocation + tempPro.ySpeed;
		projectiles.projectileContainer[i] = tempPro;
		glEnd();
		clear = environmentFunctions::projectileCheckAndClear(projectiles, i);
		if (clear == true)
		{

		}
	}

}


void environmentFunctions::addProjectileTick(environmentFunctions& projectiles)
{
	int tickTemp = projectiles.projectileTicks;
	tickTemp++;
	if (tickTemp > 10000)
	{
		tickTemp = 0;
	}
	projectiles.projectileTicks = tickTemp;
}


int environmentFunctions::getProjectileTicks(environmentFunctions& projectiles)
{
	return projectiles.projectileTicks;
}


void environmentFunctions::resetProjectileTick(environmentFunctions& projectiles)
{

	projectiles.projectileTicks = 0;
}


bool environmentFunctions::projectileCheckAndClear(environmentFunctions& projectiles, int index)
{
	if (projectiles.projectileContainer[index].xLocation > 1.025)
	{
		projectiles.projectileContainer.erase(projectiles.projectileContainer.begin()+index);
		return true;
	}
	else if (projectiles.projectileContainer[index].xLocation < -1.025)
	{
		projectiles.projectileContainer.erase(projectiles.projectileContainer.begin() + index);
		return true;
	}
	else if (projectiles.projectileContainer[index].yLocation > 1.025)
	{
		projectiles.projectileContainer.erase(projectiles.projectileContainer.begin() + index);
		return true;
	}
	else if (projectiles.projectileContainer[index].yLocation < -1.025)
	{
		projectiles.projectileContainer.erase(projectiles.projectileContainer.begin() + index);
		return true;
	}
}

void environmentFunctions::printProSize(environmentFunctions& projectiles)
{
	std::cout << projectiles.projectileContainer.size() << std::endl;
}