#ifndef ENVIRONMENTFUNCTIONS_H
#define ENVIRONMENTFUNCTIONS_H
#endif
#include <GLFW\glfw3.h>
#include <math.h>
#include <vector>

struct projectile
{


	GLfloat xSpeed;
	GLfloat ySpeed;
	GLfloat xLocation;
	GLfloat yLocation;

};

class environmentFunctions
{
	std::vector<projectile> projectileContainer;
	int projectileTicks = 0;

public:
	static void keyStrokes(GLFWwindow* window, gamePlayerObject& ship, environmentFunctions& projectiles);
	static void addProjectile(gamePlayerObject& player, environmentFunctions& projectiles);
	static void drawProjectiles(environmentFunctions& projectiles);
	static void addProjectileTick(environmentFunctions& projectiles);
	static void resetProjectileTick(environmentFunctions& projectiles);
	static int getProjectileTicks(environmentFunctions& projectiles);
	static void projectileCheckAndClear(environmentFunctions& projectiles);
	static void printProSize(environmentFunctions& projectiles);
	static void gravityAdjust(environmentFunctions& projectiles, gamePlayerObject& player, gameEnvironmentObject& env1, gameEnvironmentObject& env2, environmentFunctions& asteroids);
	static void checkAllCollision(environmentFunctions& projectiles, gamePlayerObject& player, gameEnvironmentObject& planet1, gameEnvironmentObject& planet2, gameEnvironmentObject& asteroids);

};


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);


const float pi = 3.1415926;
const float screen_edgeLower = -1;
const float screen_edgeUpper = 1;
const float screen_edgeRight = 1;
const float screen_edgeLeft = -1;
