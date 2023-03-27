#include "Emoji.h"

void Face::draw(AnimationWindow &win)
{
	win.draw_circle(centre, radius, Color::dark_salmon);
}

void EmptyFace::draw(AnimationWindow &win)
{
	Face::draw(win);
	win.draw_circle(Point{centre.x - radius/2, centre.y - radius/2}, radius/5, eyeColor);	// Left eye
	win.draw_circle(Point{centre.x + radius/2, centre.y - radius/2}, radius/5, eyeColor);	// Right eye
	win.draw_circle(Point{centre.x, centre.y + radius/2}, radius/5, Color::red);			// Mouth
}