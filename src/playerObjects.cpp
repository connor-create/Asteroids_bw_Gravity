#include "playerObjects.h"
#include "environmentObjects.h"
#include "environmentFunctions.h"


void gamePlayerObject::drawObject()
{
	glColor3f(255, 255, 255);
	glTranslatef(xLocation, yLocation, zLocation);
	GLfloat inDeg;
	if (rDeg <= 90)
	{
		GLfloat ph = rDeg - 90;
		inDeg = 360 + ph;
	}
	else 
		inDeg = rDeg - 90;
	glScalef(1, 1, 1);
	glRotatef(inDeg, 0, 0, 1);
	glTranslatef(-xLocation, -yLocation, -zLocation);
	glBegin(GL_LINE_LOOP);
		glVertex3f(xLocation + xSpeed, yLocation + .05 + ySpeed, zLocation);
		glVertex3f(xLocation - .02 +xSpeed, yLocation - .025 + ySpeed, zLocation);
		glVertex3f(xLocation + xSpeed, yLocation - .01 + ySpeed, zLocation);
		glVertex3f(xLocation + .02 + xSpeed, yLocation - .025  + ySpeed, zLocation);
	glEnd(); 
	glPopMatrix();
	glLoadIdentity();
	xLocation = xLocation + xSpeed;
	yLocation = yLocation + ySpeed;
	glScalef(1, 1, 1);

	
}
void gamePlayerObject::addSpeed()
{
	float radAmount = rDeg * pi / 180;
	xSpeed = xSpeed + cos(radAmount) * .0002;
	ySpeed = ySpeed + sin(radAmount) * .0002;
};
void gamePlayerObject::minusSpeed()
{
	float radAmount = rDeg * pi / 180;
	xSpeed = xSpeed - cos(radAmount) * .0002;
	ySpeed = ySpeed - sin(radAmount) * .0002;
}


void gamePlayerObject::addGravSpeed(float xS, float yS)
{
	xSpeed = xSpeed + xS;
	ySpeed = ySpeed + yS;
}


void gamePlayerObject::clockWiseRot()
{
	if (rDeg == 0)
	{
		rDeg = 357;
	}
	else
	{
		rDeg = rDeg - 3;
	}
	
}


void gamePlayerObject::counterclockWiseRot()
{
	if (rDeg == 360)
	{
		rDeg = 3;
	}
	else
	{
		rDeg = rDeg + 3;
	}
}

void gamePlayerObject::checkEnvironmentLoop()
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



GLfloat gamePlayerObject::getXLocation()
{
	return xLocation;
}

GLfloat gamePlayerObject::getYLocation()
{
	return yLocation;
}


GLfloat gamePlayerObject::getMass()
{
	return mass;
}

GLfloat gamePlayerObject::getXSpeed()
{
	return xSpeed;
}

GLfloat gamePlayerObject::getYSpeed()
{
	return ySpeed;
}

GLfloat gamePlayerObject::getRotation()
{
	return rDeg;
}





//other 


