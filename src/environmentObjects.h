#ifndef ENVIRONMENTOBJECTS_H
#define ENVIRONMENTOBJECTS_H
#endif
#include <GLFW\glfw3.h>
#include <math.h>



class gameEnvironmentObject
{
	GLfloat xLocation;
	GLfloat yLocation;
	GLfloat const zLocation = 0;
	GLfloat xSpeed;
	GLfloat ySpeed;
	GLfloat totalspeed = sqrt(pow(xSpeed, 2) + pow(ySpeed, 2));
	GLfloat rDeg;
	GLfloat radius;
	bool move;
	int type;
	float mass;
	// type  1==asteroid  2==planet
public:
	gameEnvironmentObject(GLfloat x, GLfloat y, GLfloat speedx, GLfloat speedy, GLfloat degrees, float massIn, int typeIn, GLfloat radiusIn, bool staticID)
	{
		move = staticID;
		xLocation = x;
		yLocation = y;
		xSpeed = speedx;
		ySpeed = speedy;
		rDeg = degrees;
		mass = massIn;
		type = typeIn;
		radius = radiusIn;
	}
	~gameEnvironmentObject(){};
	void drawObject();
	void checkEnvironmentLoop();
	GLfloat getXLocation();
	GLfloat getYLocation();
	GLfloat getMass();
	GLfloat getRadius();
};





// random function declarations






