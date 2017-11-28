#pragma once
#include "../../GUI/GUIBox.h"
#include <vector>
#include <string.h>


class MenuBar : public GUIBox
{
private:
	std::vector<GUIBox> buttonVect;
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;



	friend class GUILayer;
	TextStyle *tstyle;
	Text text;
	Texture *iconT;
	Sprite *icon;

	RectangleShape * staticBar;


	float leftBord;
	float rightBord;

	float point;

protected:
	MenuBar(RenderWindow* renderWindow_, float x, float y, float width, float height,
		std::string text, TextStyle *tstyle, GUIStyle *gstyle,
		float leftBorder, float rightBorder, Color staticBarColor);

	//virtual void Draw() override;

public:
	void buttonAction();

	void addButton(std::string name);
};

