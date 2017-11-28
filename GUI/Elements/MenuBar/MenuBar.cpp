#include "MenuBar.h"



MenuBar::MenuBar(RenderWindow* renderWindow_, float x, float y, float width,
	float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle,
	float leftBorder, float rightBorder, Color staticBarColor) :
	GUIBox(renderWindow_, x, y, width, height, text_, Ctstyle, Cgstyle),
	staticBar(new RectangleShape())
{
	
	iconT = nullptr;
	icon = nullptr;

	leftBord = leftBorder;
	rightBord = rightBorder;


	staticBar->setPosition(x, y);
	staticBar->setSize(Vector2f(width, height));
	staticBar->setFillColor(staticBarColor);


	
}
void MenuBar::buttonAction()
{
	std::cout << "Button on menu bar pressed!" << std::endl;
}

void MenuBar::addButton(std::string name)

{
	//пример создания стиля gui
	static GUIStyle gst;
	gst.mainTex.loadFromFile("backGUI.png");
	gst.pressTex.loadFromFile("pressGUI.png");
	gst.overTex.loadFromFile("overGUI.png");
	gst.frame.loadFromFile("frame.png");
	gst.frameWid = 5;

	//пример создания стиля текста
	static TextStyle tst;
	tst.font.loadFromFile("Robotic.ttf");
	tst.color.r = tst.color.g = tst.color.b = 255;
	tst.fontSize = 22;
	tst.align = 'c';


}