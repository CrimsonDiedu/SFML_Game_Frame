#include "stdafx.h"
#include "Timer.h"


Timer::Timer()
{
	notifying = false;
}

Timer::Timer(Observer* observer, float tDuration, bool repeating, float tHold)
{
	timeRemaining = duration = tDuration;
	hold = tHold;
	this->repeating = repeating;
	AddObserver(observer);
	notifying = false;
}


Timer::~Timer()
{
}

void Timer::AddObserver(Observer * observer)
{
	observers.push_back(observer);
}

void Timer::Update()
{
	
		timeRemaining -= Game::GetInstance()->GetDeltaTime();
	
		if (timeRemaining < 0){
		if (!hold)
		{
			if (repeating) {
				timeRemaining = duration;
			}

			BeginNotification();
			NotifyObservers();
		}
		else {
			if (!notifying){
				BeginNotification();
			}
			if (-timeRemaining < hold) {
				NotifyObservers();
			}
			else {
				if (repeating) {
					timeRemaining = duration;
				}
			}
		}
	}
	else {
		if (notifying) {
			EndNotification();
			notifying = false;
		}
	}
}


void Timer::Render(sf::RenderWindow * window)
{
}

void Timer::OnStart()
{
}

void Timer::OnDisable()
{
}

void Timer::NotifyObservers()
{
	for (unsigned int i = 0; i < observers.size(); i++) {
		observers[i]->Notify();
	}
}

void Timer::BeginNotification()
{
	for (unsigned int i = 0; i < observers.size(); i++) {
		observers[i]->NotifyBegin();
	}
	notifying = true;
}

void Timer::EndNotification()
{
	for (unsigned int i = 0; i < observers.size(); i++) {
		observers[i]->NotifyEnd();
	}
	notifying = false;
}
