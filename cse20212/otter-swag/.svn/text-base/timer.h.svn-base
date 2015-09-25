// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// timer.h header file

/*
	The timer class handles the game clock and allows us to alter the framerate in order to achieve the best performance
*/

#ifndef TIMER_H
#define TIMER_H

class Timer{
    public:
        Timer(); //constructor
        void start(); //begins timer
        void stop(); //stops timer
        void pause(); //pauses timer
        void unpause(); //resumes timer
        int get_ticks(); //returns number of ticks
        bool is_started(); //checks if timer has been started
        bool is_paused(); //checks if timer is paused
    private:
        int startTicks; 
        int pausedTicks;
        bool paused;
        bool started;
};

#endif
