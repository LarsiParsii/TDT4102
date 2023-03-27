#include "Emoji.h"

void draw_teeth(AnimationWindow &win, const Point &mouthPos, int mouthW, int mouthH, int numTeeth, int toothHeight)
{
	// Calculate the spacing of the teeth
	const int spacing = mouthW / numTeeth;

	// Calculate the position of the first tooth
	const int toothX = mouthPos.x + spacing - 1;

	// Draw the teeth
	for (int i = 0; i < numTeeth; i++)
	{
		// Draw upper teeth
		const Point toothUpperStart{toothX + i * spacing, mouthPos.y};
		const Point toothUpperEnd{toothX + i * spacing, mouthPos.y + toothHeight};
		win.draw_line(toothUpperStart, toothUpperEnd, Color::black);

		// Draw lower teeth
		const Point toothLowerStart{toothX + i * spacing, mouthPos.y + mouthH - toothHeight};
		const Point toothLowerEnd{toothX + i * spacing, mouthPos.y + mouthH - 1};
		win.draw_line(toothLowerStart, toothLowerEnd, Color::black);
	}

	// Draw the edge of the upper teeth
	const Point lineUpperStart{mouthPos.x, mouthPos.y + toothHeight};
	const Point lineUpperEnd{mouthPos.x + mouthW - 1, mouthPos.y + toothHeight};
	win.draw_line(lineUpperStart, lineUpperEnd, Color::black);

	// Draw the edge of the lower teeth
	const Point lineLowerStart{mouthPos.x, mouthPos.y + mouthH - toothHeight};
	const Point lineLowerEnd{mouthPos.x + mouthW - 1, mouthPos.y + mouthH - toothHeight};
	win.draw_line(lineLowerStart, lineLowerEnd, Color::black);
}

void Face::draw(AnimationWindow &win)
{
	win.draw_circle(centre, radius, Color::dark_salmon);
}

void EmptyFace::draw(AnimationWindow &win)
{
	Face::draw(win);
	win.draw_circle(Point{centre.x - radius / 2, static_cast<int>(centre.y - radius * 0.4)}, radius / 5, eyeColor); // Left eye
	win.draw_circle(Point{centre.x + radius / 2, static_cast<int>(centre.y - radius * 0.4)}, radius / 5, eyeColor); // Right eye
}

SmilingFace::SmilingFace(Point centre, int radius)
	: EmptyFace{centre, radius}
{
	mouthPos = {centre.x, static_cast<int>(centre.y + radius * 0.2)};
	mouthW = static_cast<int>(radius * 0.75);
	mouthH = static_cast<int>(radius * 0.6);
	mouthStartAngle = 180;
	mouthEndAngle = 360;
}
void SmilingFace::draw(AnimationWindow &win)
{
	// Print variables mouthW and mouthH for debugging
	EmptyFace::draw(win);
	win.draw_arc(mouthPos, mouthW, mouthH, mouthStartAngle, mouthEndAngle, Color::black);
}

SurprisedFace::SurprisedFace(Point centre, int radius)
	: EmptyFace{centre, radius}
{
	mouthPos = {centre.x, static_cast<int>(centre.y + radius * 0.4)};
	mouthRadius = static_cast<int>(radius * 0.3);
}
void SurprisedFace::draw(AnimationWindow &win)
{
	EmptyFace::draw(win);
	win.draw_circle(mouthPos, mouthRadius, Color::brown);
}

GrimacingFace::GrimacingFace(Point centre, int radius)
	: EmptyFace{centre, radius}
{
	mouthW = static_cast<int>(radius * 1.2);
	mouthH = static_cast<int>(radius * 0.3);
	mouthPos = {static_cast<int>(centre.x - mouthW / 2),
				static_cast<int>(centre.y + radius * 0.2)};
}
void GrimacingFace::draw(AnimationWindow &win)
{
	EmptyFace::draw(win);
	win.draw_rectangle(mouthPos, mouthW, mouthH, Color::white, Color::black);

	// Draw the teeth
	const int numTeeth = 8;
	const int toothHeight = mouthH / 2;
	draw_teeth(win, mouthPos, mouthW, mouthH, numTeeth, toothHeight);
}

AngryFace::AngryFace(Point centre, int radius)
	: GrimacingFace{centre, radius} {}

void AngryFace::draw(AnimationWindow &win)
{
	GrimacingFace::draw(win);
	// Use win.draw_line to draw the angry eyebrows
	const int eyebrowWidth = static_cast<int>(radius * 0.4);
	const int eyebrowHeight = static_cast<int>(radius * 0.1);
	const int eyebrowDistance = static_cast<int>(radius * 0.35);
	const int eyebrowStartX = static_cast<int>(eyebrowDistance / 2 + eyebrowWidth);
	const int eyebrowStartY = static_cast<int>(radius * 0.7);

	// Draw the left eyebrow
	const Point leftEyebrowStart{centre.x - eyebrowStartX, centre.y - eyebrowStartY};
	const Point leftEyebrowEnd{centre.x - eyebrowDistance / 2, centre.y - eyebrowStartY + eyebrowHeight};
	win.draw_line(leftEyebrowStart, leftEyebrowEnd, Color::black);

	// Draw the right eyebrow
	const Point rightEyebrowStart{centre.x + eyebrowDistance / 2, centre.y - eyebrowStartY + eyebrowHeight};
	const Point rightEyebrowEnd{centre.x + eyebrowStartX, centre.y - eyebrowStartY};
	win.draw_line(rightEyebrowStart, rightEyebrowEnd, Color::black);
}

WinkingFace::WinkingFace(Point centre, int radius, Color eyeColor)
	: Face{centre, radius}
{
	mouthPos = {centre.x, static_cast<int>(centre.y + radius * 0.2)};
	mouthW = static_cast<int>(radius * 0.75);
	mouthH = static_cast<int>(radius * 0.6);
	mouthStartAngle = 180;
	mouthEndAngle = 360;
	this->eyeColor = eyeColor;
}
void WinkingFace::draw(AnimationWindow &win)
{
	Face::draw(win);
	win.draw_circle(Point{static_cast<int>(centre.x - radius / 2),
						  static_cast<int>(centre.y - radius * 0.4)},
					radius / 5, eyeColor); // Left eye
	
	// Winking right eye
	win.draw_arc(Point{static_cast<int>(centre.x + radius * 0.4),
					   static_cast<int>(centre.y - radius * 0.35)},
				 radius / 5, radius / 5, 10, 170, Color::black);

	win.draw_arc(mouthPos, mouthW, mouthH, mouthStartAngle, mouthEndAngle, Color::black); // Mouth
}