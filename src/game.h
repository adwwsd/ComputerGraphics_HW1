#pragma once
#include <tuple>
#include <vector>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "ballObject.h"
#include "movableCubeObject.h"
#include "renderer.h"

enum GameState {
	GAME_MENU,
	GAME_READY,
	GAME_PLAYING,
	GAME_SCORE,
	GAME_SET,
};

enum Direction {
	POSITIVE_X,
	POSITIVE_Y,
	NEGATIVE_X,
	NEGATIVE_Y
};

typedef std::tuple<bool, Direction, glm::vec2> Collision;

class Game {
private:
	MovableCubeObject player1;
	MovableCubeObject player2;
	BallObject ball;
	GameState gamestate;
	bool is2player;
	int delayTime;
	int score1;
	int score2;
	int winningScore;
	bool player1Scored;
	bool exiting;
	Renderer renderer;
	ViewMode viewmode;

	void resetPosition();
	void restartGame();
	void updateBall(int delta);
	void updatePlayer(int delta);
public:
	Game();
	~Game();
	void init(int argc, char* argv[], int width, int height, bool isFullScreen);
	void exit();
	bool isExiting();
	void handleInput(unsigned char key);
	void handleInputUp(unsigned char key);
	void handleSpecialInput(int key);
	void handleSpecialInputUp(int key);
	void setScreenSize(int width, int height);
	void update(int delta);
	void render();
};
