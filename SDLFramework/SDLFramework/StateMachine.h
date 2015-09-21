#pragma once
#include "State.h"
#include <assert.h>
template<class T>
class StateMachine
{
private:

	// A pointer to the agent that owns this instance
	T* owner;

	State<T>* currentState;

	// A record of the last state the agent was in
	State<T>* previousState;

	// This state logic is called every time the FSM is updated
	State<T>* globalState;

public:

	StateMachine(T* owner) : owner(owner),
							 currentState(nullptr),
							 previousState(nullptr),
							 globalState(nullptr){}


	// Use these methods to initialize the FSM
	void SetCurrentState(State<T>* s) { currentState = s; }
	void SetGlobalState(State<T>* s) { globalState = s; }
	void SetPreviousState(State<T>* s) { previousState = s; }

	// Call this to update the FSM
	void Update() const
	{
		// if a global state exists, call its execute method
		if (globalState) globalState->Execute(owner);

		// same for the current state
		if (currentState) currentState->Execute(owner);
	}

	// Change to a new state
	void ChangeState(State<T>* newState)
	{
		assert(newState && "<StateMachine::ChangeState>: trying to change to a null state");

		// keep a record of the previous state
		previousState = currentState;

		// call the exit method of the existing state
		currentState->Exit(owner);

		// change the state to the new state
		currentState = newState;

		// call the entry method of the new state
		currentState->Enter(owner);
	}

	// change state back to the previous state
	void RevertToPreviousState()
	{
		ChangeState(previousState);
	}

	// Accessors
	State<T>* CurrentState() const { return currentState; }
	State<T>* GlobalState() const { return globalState; }
	State<T>* PreviousState() const { return previousState; }

	// Return true if the current state's type is equal to the type of the
	// class passed as a parameter
	//bool isInState(const State<class T>& st) const;
};

