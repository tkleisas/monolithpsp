#include <vector>
#include "tetrisdata.h"
#include "cube.h"
#include "tickcounter.h"
using namespace std;


class TetrisGame
{

public:
	static const float PI=3.141592653589793238;
	TetrisGame();
	~TetrisGame();
	void InitGraphics();
	void GameLoop();
private:
	TickCounter tickcounter;

	Tetris tetris;
	float xzAngle;
	float yzAngle;
	float xyAngle;

	float xzOffset;
	float RotateAngle;
	float yAngle;
	float xAngle;
	float xzOffsetDefault;
	Position rotationVertexDefaults;
	Position rotationVertex;
	bool isPaused;
	int xpos;
	int ypos;
	bool explosionComplete;
	bool explosion;
	vector<Position> explosion_cubes;
	vector<Position> explosion_velocities;
	vector<unsigned int> explosion_colors;
	float acceleration;
	int explosionFrames;
	int explosionCurrentFrame;

	void* fbp0;
	void* fbp1;
	void* zbp;
	void DrawCube(float x,float y, float z,float xrot,float yrot,float zrot,int colorindex);
	void DrawPlayfield(void);
	void DrawBoard(void);
	void DrawSquare(float x,float y, float z,float xrot,float yrot,float zrot,int colorindex);
	void Draw3DText(string text,unsigned int color, float x, float y, float z, float scale,float thickness);
	void DrawNextPiece(float x, float y, float z);
	void DrawFallingPiece();
	void DrawExplosion();
	
	unsigned int GetColor(char color);
	void CreateCubeExplosion(int x, int y, unsigned int color);
	void CreateLineExplosion(int line);
	bool CheckExplosions();
	void ClearExplosion();
	
	int HandleInput();
};
