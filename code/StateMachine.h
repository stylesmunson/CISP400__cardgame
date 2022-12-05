#pragma once

#include <memory>
#include <stack>
#include "State.h"

using std::stack;
using std::unique_ptr;

typedef unique_ptr<State> StateRef;

class StateMachine
{
public:
	StateMachine() {}

	void add_state(StateRef newState, bool isReplacing = true);
	void remove_state();
	
	void process_state_changes();

	StateRef& get_active_state();


private:
	stack<StateRef> stateStack;
	StateRef newState;

	bool isRemoving;
	bool isAdding;
	bool isReplacing;
};