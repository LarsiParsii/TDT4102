#include "AnimationWindow.h"
#include "Emoji.h"


// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 250;

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	/* TODO:
	 *  - initialiser emojiene
	 *  - Tegn emojiene til vinduet
	 **/
	
	EmptyFace emoji1{Point{500, 300}, emojiRadius, Color::cyan};
	emoji1.draw(win);
	win.wait_for_close();

	return 0;
}
