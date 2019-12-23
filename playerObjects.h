#ifndef PLAYEROBJECTS_H
#define PLAYEROBJECTS_H
#endif
#include <GLFW\glfw3.h>
#include <math.h>




// used to create player objects such as the main player of ship, might use this class for another game object, idk

class gamePlayerObject
{
	GLfloat xLocation;
	GLfloat yLocation;
	GLfloat const zLocation = 0;
	float xSpeed;
	float ySpeed;
	GLfloat totalspeed = sqrt(pow(xSpeed, 2) + pow(ySpeed, 2));
	GLfloat rDeg;
	float mass;

public:

	gamePlayerObject(GLfloat x, GLfloat y, GLfloat speedx, GLfloat speedy, GLfloat degrees, float massIn = 1)    
	{
		xLocation = x;
		yLocation = y;
		xSpeed = speedx;
		ySpeed = speedy;
		rDeg = degrees;
		mass = massIn;
	}
	~gamePlayerObject() {};
	void drawObject();
	void addSpeed();
	void minusSpeed();
	void addGravSpeed(float xS, float yS);
	void clockWiseRot();
	void counterclockWiseRot();
	void checkEnvironmentLoop();
	GLfloat getXLocation();
	GLfloat getYLocation();
	GLfloat getMass();
	GLfloat getXSpeed();
	GLfloat getYSpeed();
	GLfloat getRotation();


};


