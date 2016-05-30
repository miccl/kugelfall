class Controller {

private:
	int FALL_DURATION;

public:
	Controller();

	int getReleaseTime();

	int getHoleDelay();

	void release(int releaseTime);
};
