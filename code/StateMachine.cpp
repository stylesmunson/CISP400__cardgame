#include "StateMachine.h"

void StateMachine::add_state(StateRef _newState, bool _isReplacing)
{
	isAdding = true;
	isReplacing = _isReplacing;

	newState = std::move(newState);
}

void StateMachine::remove_state()
{
	isRemoving = true;
}

void StateMachine::process_state_changes()
{
	if (isRemoving && !stateStack.empty())
	{
		stateStack.pop();

		if (!stateStack.empty())
			stateStack.top()->resume();

		isRemoving = false;
	}
	if (isAdding)
	{
		if (!stateStack.empty())
		{
			if (isReplacing)
				stateStack.pop();
			else
				stateStack.top()->pause();
		}
		stateStack.push(std::move(newState));
		stateStack.top()->init();
	}
	StateRef& StateMachine::get_active_state()
	{
		return stateStack.top
	}
}