#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Prototype
void draw_teeth(AnimationWindow &win, const Point &mouthPos, int mouthW, int mouthH,
				int numTeeth, int toothHeight);

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
	virtual void draw(AnimationWindow &) = 0;
	virtual ~Emoji(){}; // destruktør
};

class Face : public Emoji
{
public:
	Face(Point centre, int radius)
		: centre{centre}, radius{radius} {}
	virtual void draw(AnimationWindow &win) override = 0;

protected:
	Point centre;
	int radius;
};

class EmptyFace : public Face
{
public:
	EmptyFace(Point centre, int faceRadius, Color eyeColor = Color::blue)
		: Face{centre, faceRadius}, eyeColor{eyeColor} {}
	void draw(AnimationWindow &win);

protected:
	Color eyeColor;
};

class SmilingFace : public EmptyFace
{
public:
	SmilingFace(Point centre, int faceRadius);
	void draw(AnimationWindow &win);

private:
	Point mouthPos{0, 0};
	int mouthW{0}, mouthH{0}, mouthStartAngle{0}, mouthEndAngle{0};
};

class SurprisedFace : public EmptyFace
{
public:
	SurprisedFace(Point centre, int faceRadius);
	void draw(AnimationWindow &win);

private:
	Point mouthPos{0, 0};
	int mouthRadius{0};
};

class GrimacingFace : public EmptyFace
{
public:
	GrimacingFace(Point centre, int faceRadius);
	void draw(AnimationWindow &win);

private:
	Point mouthPos{0, 0};
	int mouthW{0}, mouthH{0};
};

class AngryFace : public GrimacingFace
{
public:
	AngryFace(Point centre, int faceRadius);
	void draw(AnimationWindow &win);
};

class WinkingFace : public Face
{
public:
	WinkingFace(Point centre, int faceRadius, Color eyeColor = Color::blue);
	void draw(AnimationWindow &win);

private:
	Point mouthPos{0, 0};
	int mouthW{0}, mouthH{0}, mouthStartAngle{0}, mouthEndAngle{0};
	Color eyeColor;
};