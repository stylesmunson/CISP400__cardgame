#include <sstream>
#include "InputHandler.h"

using namespace sf;
using namespace std;

void InputHandler::initialize_input_handler(ScreenManagerRemoteControl* _sw, vector<shared_ptr<Button>> _buttons, View* _ptrToUIView, Screen* _parentScreen)
{
	m_ScreenManagerRemoteControl = _sw;
	m_ptrButtons = _buttons;
	m_ptrToUIPanelView = _ptrToUIView;
	m_parentScreen = _parentScreen;
}

void InputHandler::handle_input(RenderWindow& _window, Event& _event)
{
	//handle key presses here

	//handle mouse clicks
	if (_event.type == Event::MouseButtonReleased)
	{
		auto end = m_ptrButtons.end();							//iterator

		for (auto i = m_ptrButtons.begin(); i != m_ptrButtons.end(); ++i)		//runs thru all Buttons
		{
			if ((*i)->m_collider.contains(_window.mapPixelToCoords(Mouse::getPosition(), (*get_ptr_to_UI_view()))))
			{
				handle_leftClick((i*)->, _window);
			}
		}
	}
}
