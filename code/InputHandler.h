#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Screen.h"
#include "ScreenManagerRemoteControl.h"

using namespace sf;
using namespace std;

class Screen;

class InputHandler
{
public:
	void initialize_input_handler(ScreenManagerRemoteControl* _sw, vector<shared_ptr<Button>> _buttons, View* _ptrToUIView, Screen* _parentScreen);
	
	void handle_input(RenderWindow& _window, Event& _event);
	virtual void handle_leftClick(string& _buttonInteractedWith, RenderWindow& _window);

	View* get_ptr_to_UI_view();

	ScreenManagerRemoteControl* get_ptr_to_ScreenManagerToRemoteControl();

	Screen* get_m_parentScreen();

private:
	Screen* m_parentScreen;
	vector<shared_ptr<Button>> m_ptrButtons;
	View* m_ptrToUIPanelView;
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
};