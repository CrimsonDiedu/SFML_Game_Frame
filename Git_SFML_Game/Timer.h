#pragma once
#include "BaseObject.h"
class Timer :
	public BaseObject
{
	//will the timer stop after completion, or reset
	bool repeating,notifying;
	//timeRemaining: the time left in the timer
	//duration: the total amount of time the timer will run
	//hold: the amount of time the timer will be "complete" before looping or stopping.
	float timeRemaining,duration, hold;
	std::vector<Observer*> observers;
public:
	Timer();
	Timer(Observer* observer,float tDuration,bool repeating = false,float tHold = 0.f);
	~Timer();
	void AddObserver(Observer* observer);
	void Update();
	void Render(sf::RenderWindow *window);
	void OnStart();
	void OnDisable();
	void NotifyObservers();
	void BeginNotification();
	void EndNotification();
};

