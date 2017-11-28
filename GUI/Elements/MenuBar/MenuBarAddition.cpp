#include "../../GUI/GUILayer.h"
#include "MenuBar.h"



void MenuBar::addButton(std::string name, void(*action)())

{
	//������ �������� ����� gui
	static GUIStyle gst;
	gst.mainTex.loadFromFile("03.png");
	gst.pressTex.loadFromFile("04.png");
	gst.overTex.loadFromFile("05.png");

	gst.frameWid = 3;

	//������ �������� ����� ������
	static TextStyle tst;
	tst.font.loadFromFile("Robotic.ttf");
	tst.color.r = tst.color.g = tst.color.b = 255;
	tst.fontSize = 30;
	tst.align = 'c';

	//������ �������� ������ "�������" � ���������� �������, ���������� 0,0 � �������� 300,400 �� ��������� ���� ����
	std::shared_ptr<GUIBox> box;
	buttonVect.push_back(box);
	
	box = layer->CreateButton(buttonPosHelp, 5, 200, 40, name, &tst, &gst, action);
	buttonPosHelp = buttonPosHelp + 200;

}