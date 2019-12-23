#ifndef ENVIRONMENTFUNCTIONS_H
#define ENVIRONMENTFUNCTIONS_H
#endif
#include <GLFW\glfw3.h>
#include <math.h>
#include <vector>





class projectile
{

public:
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
	static void getGravityPlayer(gameEnvironmentObject& env1, gamePlayerObject& player);
	static void addProjectile(gamePlayerObject& player, environmentFunctions& projectiles);
	static void drawProjectiles(environmentFunctions& projectiles);
	static void addProjectileTick(environmentFunctions& projectiles);
	static void resetProjectileTick(environmentFunctions& projectiles);
	static int getProjectileTicks(environmentFunctions& projectiles);
	static bool projectileCheckAndClear(environmentFunctions& projectiles, int index);
	static void printProSize(environmentFunctions& projectiles);

};


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);


const float pi = 3.1415926;
const float screen_edgeLower = -1;
const float screen_edgeUpper = 1;
const float screen_edgeRight = 1;
const float screen_edgeLeft = -1;
