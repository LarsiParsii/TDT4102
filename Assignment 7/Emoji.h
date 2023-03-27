#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};


class Face : public Emoji
{
public:
	virtual ~Face(){}; // Destructor
	virtual void draw(AnimationWindow &win) override = 0;
	Face(Point c, int r) : centre{c}, radius{r} {}

protected:
	Point centre;
	int radius;
};


class EmptyFace : public Face
{
public:
	EmptyFace(Point centre, int faceRadius, Color eyeColor) :
		Face{centre, faceRadius}, eyeColor{eyeColor} {}
	void draw(AnimationWindow &win);

protected:
	Color eyeColor;
};