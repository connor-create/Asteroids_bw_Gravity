#include "playerObjects.h"
#include "environmentObjects.h"
#include "environmentFunctions.h"
#include <stdlib.h>
#include <iostream>


int main(void)
{
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(1080, 1080, "Asteroids: But With Gravity", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	GLfloat r = 0;
	GLfloat g = 0;
	GLfloat b = 0;
	int key;
	gamePlayerObject ship(0, 0, 0, 0, 90);
	gameEnvironmentObject planet1(-.40, .40, 0, 0, 0, 100, 2, .1, true);
	gameEnvironmentObject planet2(.40, .40, 0, 0, 0, 100, 2, .1, false);
	environmentFunctions asteroids;
	environmentFunctions projectiles;
	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		environmentFunctions::gravityAdjust(projectiles, ship, planet1, planet2, asteroids);
		environmentFunctions::keyStrokes(window, ship, projectiles);
		ship.checkEnvironmentLoop();
		r = 0;
		g = 0;
		b = .90;
		glColor3f(r, g, b);
		planet1.drawObject();
		r = 0;
		g = 0;
		b = 0;
		glColor3f(r, g, b);
		ship.drawObject();
		projectiles.drawProjectiles(projectiles);
		glfwSwapBuffers(window);
		glfwPollEvents();
		environmentFunctions::addProjectileTick(projectiles);
		environmentFunctions::printProSize(projectiles);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

