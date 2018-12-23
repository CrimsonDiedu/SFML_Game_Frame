#include "stdafx.h"
#include "Timer.h"


Timer::Timer()
{
}

Timer::Timer(Observer* observer, float tDuration, bool repeating, float tHold)
{
	timeRemaining = duration = tDuration;
	hold = tHold;
	this->repeating = repeating;
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
			for (unsigned int i = 0; i < observers.size(); i++) {
				observers[i]->Notify();
			}
		}
		else {
			if (-timeRemaining < hold) {

			}
			else {
				if (repeating) {
					timeRemaining = duration;
				}
			}
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
