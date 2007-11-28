#ifndef TETRISDATA_H
#define TETRISDATA_H
#include <string>
const int GRID_MAX_WIDTH =		10;
const int GRID_MAX_HEIGHT =		20;
const int BLOCK_SIZE = 12;

typedef enum statustype{TETRIS_STARTUP,TETRIS_PLAYING,TETRIS_PAUSE,TETRIS_GAME_OVER} ;
typedef enum blocktype{STICK, SQUARE, LETTERT, LETTERS, NUMBER2, GAMMA, GAMMAINV};
struct SubBlock
{
	int Xpos;
	int Ypos;
	
};
class TetrisBlock
{
	public:
		
		TetrisBlock();
		TetrisBlock(blocktype theType,int xPos, int yPos);
		void RotateClockwise();
		void RotateCounterClockwise();
		int GetXPos(void);
		int GetYPos(void);
		int GetOrientation(void);
		char GetColor(void);
		void RecalcBlockOrientation(void);
		struct SubBlock subblocks_[4];
		blocktype btype_;
		int orientation_;
		int XPos_;
		int YPos_;
		int Height_;
		char color_;

};

class Tetris
{
	public:
		Tetris(void);
		~Tetris(void);
		void ClearGrid(void);
		void DrawIntroGrid(void);
		void InitGame(int StartingLevel);
		void SetStatus(statustype status){this->status_ = status;};
		statustype GetStatus(void){return this->status_;};
		char GetGridValue(int x, int y){return grid_[x][y];};
		void GameLoop(void);
		void MoveBlockLeft(void);
		void MoveBlockRight(void);
		bool MoveBlockDown(void);
		char grid_[GRID_MAX_WIDTH][GRID_MAX_HEIGHT];
		char cleared_lines[GRID_MAX_HEIGHT];
		statustype status_;
		int score_;
		int lines_;
		int level_;
		int timer_;
		TetrisBlock CurrentBlock_;
		TetrisBlock NextBlock_;
		bool TimerEnabled_;
		void ClearCompleteLines(void);
		void FlagCompletedLines(void);
		int GetClearedLineCount();
		void RotateCurrentBlockClockwise(void);
		int NewLevel_;
		int StartingLevel_;
		

};

#endif

