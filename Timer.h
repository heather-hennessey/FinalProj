#pragma once
class Timer
{
public:
	Timer();
	void           start();
	void           stop();
	void           reset();
	bool           isRunning();
	unsigned long  getTime();

private:
	bool           resetted;
	bool           running;
	unsigned long  beg;
	unsigned long  end;
};

