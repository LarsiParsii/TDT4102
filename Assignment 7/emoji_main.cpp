#include "AnimationWindow.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;
constexpr int spacing = 10;

void draw_emojis(std::vector<std::unique_ptr<Emoji>> &emojiVector, AnimationWindow &win)
{
	for (auto &emoji : emojiVector)
	{
		emoji->draw(win);
	}
}

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	/* TODO:
	 *  - initialiser emojiene
	 *  - Tegn emojiene til vinduet
	 */

	std::vector<std::unique_ptr<Emoji>> emojis;

	emojis.emplace_back(new SmilingFace{Point{xmax / 2 - 2 * emojiRadius - 2 * spacing, ymax / 2 - spacing - emojiRadius}, emojiRadius});
	emojis.emplace_back(new SurprisedFace{Point{xmax / 2, ymax / 2 - spacing - emojiRadius}, emojiRadius});
	emojis.emplace_back(new GrimacingFace{Point{xmax / 2 + 2 * emojiRadius + 2 * spacing, ymax / 2 - spacing - emojiRadius}, emojiRadius});
	emojis.emplace_back(new AngryFace{Point{xmax / 2 - 2 * emojiRadius - 2 * spacing, ymax / 2 + spacing + emojiRadius}, emojiRadius});
	emojis.emplace_back(new WinkingFace{Point{xmax / 2, ymax / 2 + spacing + emojiRadius}, emojiRadius});

	draw_emojis(emojis, win);
	win.wait_for_close();

	return 0;
}
