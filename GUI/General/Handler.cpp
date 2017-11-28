#include "../Window/WindowTab.h"
#include <Windows.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void buttonAction()
{
	std::cout << "Button pressed!" << std::endl;
}
void buttonAction1()
{
	std::cout << "Button 1 pressed!" << std::endl;
}
void buttonAction2()
{
	std::cout << "Button 2  pressed!" << std::endl;
}
void buttonAction3()
{
	std::cout << "Button 3 pressed!" << std::endl;
}
void buttonAction4()
{
	std::cout << "Button 4 pressed!" << std::endl;
}

//функция, которая будет вызываться каждый кадр во время перемещения слайдера
void onSliderMove(float slider_value)
{
	std::cout << "slider value = " << slider_value << std::endl;
}

//окей. теперь fun part
void main()
{
	//пример создания стиля gui
	static GUIStyle gst;
	gst.mainTex.loadFromFile("backGUI.png");
	gst.pressTex.loadFromFile("pressGUI.png");
	gst.overTex.loadFromFile("overGUI.png");
	gst.frame.loadFromFile("frame.png");
	gst.frameWid = 5;
	static GUIStyle gst2;
	gst2.mainTex.loadFromFile("01.png");
	gst2.frame.loadFromFile("02.png");
	gst2.frameWid = 5;
	//пример создания стиля текста
	static TextStyle tst;
	tst.font.loadFromFile("Robotic.ttf");
	tst.color.r = tst.color.g = tst.color.b = 255;
	tst.fontSize = 22;
	tst.align = 'c';
	
	//создание окна и слоя гуи на нем (можете прям копировать, если лень разбираться, да оно и не сильно надо пока)
	WindowTab main(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "main");
	std::shared_ptr<GUILayer> layer = main.CreateGUILayer(Vector2f(0,0), Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	//вот досюда

	//пример создания просто "коробки" с созданными стилями, положением 0,0 и размером 300,400 на созданном выше слое
	std::shared_ptr<GUIBox> box = layer->CreateButton(20, 20, 100,100, "omegaLUL", &tst, &gst, &buttonAction);

	// создание label
	Texture icon, icon2;
	icon.loadFromFile("Danger.png");
	icon2.loadFromFile("Galaxy.png");
	// просто текст
	std::shared_ptr<GUILabel> label = layer->CreateLabel(0, 300, 0, 0, "Just text", &tst, &gst);
	// иконка
	std::shared_ptr<GUILabel> label1 = layer->CreateLabel(0, 330, 0, 0, "", &tst, &icon, &gst);
	// текст и иконка
	std::shared_ptr<GUILabel> label2 = layer->CreateLabel(0, 400, 0, 0, "text to the right of the icon", &tst, &icon2, &gst);

	//добавляем label1 уже существующий label2 как дочерний
	//НО
	//По скольку Даниил в label1.Draw() не вызывает метод Draw() базового класса, label2 не отрисовывается
	//Метод Draw базового класса рисует все дочерние элементы
	//поэтому если вам это надо, то в начале своей функции Draw вызовите родительский Draw
	label1->AddElement(label2);
	// Cоздание прогресс бара. 
	std::shared_ptr<GUIProgressBar> progressBar = layer->CreateProgressBar(SCREEN_WIDTH / 3 + 50, SCREEN_HEIGHT / 3, 200, 30, "Sorting...", &tst, &gst,
		0, 200, Color::White, Color::Green);

	std::shared_ptr<MenuBar> menuBar = layer->CreateMenuBar(0, 0,SCREEN_WIDTH-12,50,"", &tst, &gst2,
		0, 200, Color::White);
	menuBar->addButton("1",&buttonAction1);
	menuBar->addButton("2", &buttonAction2);
	menuBar->addButton("3", &buttonAction3);
	menuBar->addButton("4", &buttonAction4);
	std::shared_ptr<ScrollBar> scrollbarHor = layer->CreateScrollBar(0, 0, 0, 0, "test", &tst, &gst, Orientation::HORIZONTAL);

	std::shared_ptr<ScrollBar> scrollbarVert = layer->CreateScrollBar(0, 0, 0, 0, "test", &tst, &gst, Orientation::VERTICAL);

	//создаем слайдер
	std::shared_ptr<Slider> slider = layer->CreateSlider(225, 450, 350, 20, 35, 38, 0, 100, 20, &onSliderMove);
	slider.get()->SetTextures("slider_back_line.png", "slider_front_line.png", "slider_handler.png");

	while (1)
	{
		// Костыль для теста на время, пока нет Observer.
		// Потом будет передаваться ивент об изменении значения бара.
		//*****тест ProgressBar****
		progressBar->increase();
		Sleep(20);
		//*************************

		main.Redraw();
	}	
}
