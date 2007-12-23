
#include "tetrisdata.h"
TetrisBlock::TetrisBlock()
{
	

	this->XPos_ = 3;
	this->YPos_ = 0;
	int blocktype = rand()%7;
	this->orientation_ = 0;
	switch(blocktype)
	{
	case 0:
		this->btype_ = STICK;
		this->color_ = '1';
		break;
	case 1:
		this->btype_ = SQUARE;
		this->color_ = '2';
		break;
	case 2:
		this->btype_ = LETTERT;
		this->color_ = '3';
		break;
	case 3:
		this->btype_ = LETTERS;
		this->color_ = '4';

		break;
	case 4:
		this->btype_ = NUMBER2;
		this->color_ = '5';
		break;
	case 5:
		this->btype_ = GAMMA;
		this->color_ = '6';
		break;
	case 6:
		this->btype_ = GAMMAINV;
		this->color_ = '7';
		break;

	}
	this->RecalcBlockOrientation();

}
TetrisBlock::TetrisBlock(blocktype theType,int xPos, int yPos)
{
	this->btype_ = theType;
	this->orientation_ = 0;
	switch(this->btype_)
	{
		case STICK:
			this->color_='1';
			
		break;
		case SQUARE:
			this->color_ = '2';
		break;
		case LETTERT:
			this->color_ = '3';
		break;
		case LETTERS:
			this->color_ = '4';
		break;
		case NUMBER2:
			this->color_ = '5';
			
		break;
		case GAMMA:
			this->color_ = '6';
			
		break;
		case GAMMAINV:
			this->color_ = '7';
			
		break;


	}
	this->RecalcBlockOrientation();

}

char TetrisBlock::GetColor(void)
{
	return this->color_;
}


void TetrisBlock::RecalcBlockOrientation(void)
{
	switch(this->btype_)
	{
		case STICK:
			if (this->GetOrientation()==0 || this->GetOrientation()==2)
			{
			
				this->subblocks_[0].Xpos =0;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =1; 
				this->subblocks_[1].Ypos =0; 
				this->subblocks_[2].Xpos =2; 
				this->subblocks_[2].Ypos =0; 
				this->subblocks_[3].Xpos =3; 
				this->subblocks_[3].Ypos =0;
				this->Height_ = 1;
			}
			else
			{
				this->subblocks_[0].Xpos =0;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =0; 
				this->subblocks_[1].Ypos =1; 
				this->subblocks_[2].Xpos =0; 
				this->subblocks_[2].Ypos =2; 
				this->subblocks_[3].Xpos =0; 
				this->subblocks_[3].Ypos =3;
				this->Height_ = 4;
			}
			
		break;
		case SQUARE:
			this->subblocks_[0].Xpos =0;
			this->subblocks_[0].Ypos =0;
			this->subblocks_[1].Xpos =1; 
			this->subblocks_[1].Ypos =0; 
			this->subblocks_[2].Xpos =0; 
			this->subblocks_[2].Ypos =1; 
			this->subblocks_[3].Xpos =1; 
			this->subblocks_[3].Ypos =1;
			this->Height_ = 2;

		break;
		case LETTERT:
			switch (this->GetOrientation())
			{
				case 0:
					this->subblocks_[0].Xpos =0;
					this->subblocks_[0].Ypos =0;
					this->subblocks_[1].Xpos =1; 
					this->subblocks_[1].Ypos =0; 
					this->subblocks_[2].Xpos =2; 
					this->subblocks_[2].Ypos =0; 
					this->subblocks_[3].Xpos =1; 
					this->subblocks_[3].Ypos =1;
					this->Height_ = 2;
				break;
				case 1:
					this->subblocks_[0].Xpos =1;
					this->subblocks_[0].Ypos =0;
					this->subblocks_[1].Xpos =0; 
					this->subblocks_[1].Ypos =1; 
					this->subblocks_[2].Xpos =1; 
					this->subblocks_[2].Ypos =1; 
					this->subblocks_[3].Xpos =1; 
					this->subblocks_[3].Ypos =2;
					this->Height_ = 3;
				break;
				case 2:
					this->subblocks_[0].Xpos =1;
					this->subblocks_[0].Ypos =0;
					this->subblocks_[1].Xpos =0; 
					this->subblocks_[1].Ypos =1; 
					this->subblocks_[2].Xpos =1; 
					this->subblocks_[2].Ypos =1; 
					this->subblocks_[3].Xpos =2; 
					this->subblocks_[3].Ypos =1;
					this->Height_ = 2;
				break;
				case 3:
					this->subblocks_[0].Xpos =0;
					this->subblocks_[0].Ypos =0;
					this->subblocks_[1].Xpos =0; 
					this->subblocks_[1].Ypos =1; 
					this->subblocks_[2].Xpos =1; 
					this->subblocks_[2].Ypos =1; 
					this->subblocks_[3].Xpos =0; 
					this->subblocks_[3].Ypos =2;
					this->Height_ = 3;
				break;


			}
			
		break;
		case LETTERS:

			if (this->GetOrientation()==0 || this->GetOrientation()==2)
			{
			
				this->subblocks_[0].Xpos =1;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =2; 
				this->subblocks_[1].Ypos =0; 
				this->subblocks_[2].Xpos =0; 
				this->subblocks_[2].Ypos =1; 
				this->subblocks_[3].Xpos =1; 
				this->subblocks_[3].Ypos =1;
				this->Height_ = 2;
			}
			else
			{
				this->subblocks_[0].Xpos =0;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =0; 
				this->subblocks_[1].Ypos =1; 
				this->subblocks_[2].Xpos =1; 
				this->subblocks_[2].Ypos =1; 
				this->subblocks_[3].Xpos =1; 
				this->subblocks_[3].Ypos =2;
				this->Height_ = 3;
			}

			
		break;
		case NUMBER2:
			if (this->GetOrientation()==0 || this->GetOrientation()==2)
			{
			
				this->subblocks_[0].Xpos =0;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =1; 
				this->subblocks_[1].Ypos =0; 
				this->subblocks_[2].Xpos =1; 
				this->subblocks_[2].Ypos =1; 
				this->subblocks_[3].Xpos =2; 
				this->subblocks_[3].Ypos =1;
				this->Height_ = 2;
			}
			else
			{
				this->subblocks_[0].Xpos =1;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =0; 
				this->subblocks_[1].Ypos =1; 
				this->subblocks_[2].Xpos =1; 
				this->subblocks_[2].Ypos =1; 
				this->subblocks_[3].Xpos =0; 
				this->subblocks_[3].Ypos =2;
				this->Height_ = 3;
			}


		break;
		case GAMMA:
			switch(this->GetOrientation())
			{
			case 0:
				this->subblocks_[0].Xpos =0;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =0; 
				this->subblocks_[1].Ypos =1; 
				this->subblocks_[2].Xpos =1; 
				this->subblocks_[2].Ypos =1; 
				this->subblocks_[3].Xpos =2; 
				this->subblocks_[3].Ypos =1;
				this->Height_ = 2;

				break;
			case 1:
				this->subblocks_[0].Xpos =0;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =1; 
				this->subblocks_[1].Ypos =0; 
				this->subblocks_[2].Xpos =0; 
				this->subblocks_[2].Ypos =1; 
				this->subblocks_[3].Xpos =0; 
				this->subblocks_[3].Ypos =2;
				this->Height_ = 3;

				break;
			case 2:
				this->subblocks_[0].Xpos =0;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =1; 
				this->subblocks_[1].Ypos =0; 
				this->subblocks_[2].Xpos =2; 
				this->subblocks_[2].Ypos =0; 
				this->subblocks_[3].Xpos =2; 
				this->subblocks_[3].Ypos =1;
				this->Height_ = 2;

				break;
			case 3:
				this->subblocks_[0].Xpos =1;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =1; 
				this->subblocks_[1].Ypos =1; 
				this->subblocks_[2].Xpos =0; 
				this->subblocks_[2].Ypos =2; 
				this->subblocks_[3].Xpos =1; 
				this->subblocks_[3].Ypos =2;
				this->Height_ = 3;

				break;

			}



		break;
		case GAMMAINV:
			switch(this->GetOrientation())
			{
			case 0:
				this->subblocks_[0].Xpos =2;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =0; 
				this->subblocks_[1].Ypos =1; 
				this->subblocks_[2].Xpos =1; 
				this->subblocks_[2].Ypos =1; 
				this->subblocks_[3].Xpos =2; 
				this->subblocks_[3].Ypos =1;
				this->Height_ = 2;

				break;
			case 1:
				this->subblocks_[0].Xpos =0;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =0; 
				this->subblocks_[1].Ypos =1; 
				this->subblocks_[2].Xpos =0; 
				this->subblocks_[2].Ypos =2; 
				this->subblocks_[3].Xpos =1; 
				this->subblocks_[3].Ypos =2;
				this->Height_ = 3;

				break;
			case 2:
				this->subblocks_[0].Xpos =0;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =1; 
				this->subblocks_[1].Ypos =0; 
				this->subblocks_[2].Xpos =2; 
				this->subblocks_[2].Ypos =0; 
				this->subblocks_[3].Xpos =0; 
				this->subblocks_[3].Ypos =1;
				this->Height_ = 2;

				break;
			case 3:
				this->subblocks_[0].Xpos =0;
				this->subblocks_[0].Ypos =0;
				this->subblocks_[1].Xpos =1; 
				this->subblocks_[1].Ypos =0; 
				this->subblocks_[2].Xpos =1; 
				this->subblocks_[2].Ypos =1; 
				this->subblocks_[3].Xpos =1; 
				this->subblocks_[3].Ypos =2;
				this->Height_ = 3;

				break;

			}



		break;
	}
	
}
void TetrisBlock::RotateClockwise()
{
	
	if (this->orientation_ <3)
	{
		this->orientation_++;
	}
	else
	{
		this->orientation_ = 0;
	}
	RecalcBlockOrientation();
	
}

void TetrisBlock::RotateCounterClockwise()
{
	if (this->orientation_ >0)
	{
		this->orientation_--;
	}
	else
	{
		this->orientation_ = 3;
	}
	RecalcBlockOrientation();

}


int TetrisBlock::GetXPos(void)
{
	return this->XPos_;
}

int TetrisBlock::GetYPos(void)
{
	return this->YPos_;
}
		
int TetrisBlock::GetOrientation()
{
	return this->orientation_;
}



Tetris::Tetris(void):status_(TETRIS_STARTUP),score_(0),lines_(0),level_(1),timer_(1000),TimerEnabled_(false),NewLevel_(1),StartingLevel_(1)
{
	
}

Tetris::~Tetris(void)
{
}

void Tetris::ClearGrid(void)
{
	for(int x=0;x<GRID_MAX_WIDTH;x++)
	{
		for(int y=0;y<GRID_MAX_HEIGHT;y++)
		{
			this->grid_[x][y]=' ';
		}
	}
	for(int y=0;y<GRID_MAX_HEIGHT;y++)
	{
		this->cleared_lines[y]=0;
	}
	
}

void Tetris::DrawIntroGrid(void)
{
	this->ClearGrid();
	std::string strgrid =  
	"111 22 111"
	" 1  2   1 "
	" 1  22  1 "
	" 1  2   1 "
	" 1  22  1 "
	"          "
	"33  4 555 "
	"3 3 4 5   "
	"33  4 555 "
	"3 3 4   5 "
	"3 3 4 555 "
	"          "
	"1  22  44 "
	"1 22 33 44"
	"1    33   "
	"1  5      "
	"  555     ";
	for (unsigned int currchar=0;currchar < strgrid.length();currchar++)
	{
		int x = currchar%GRID_MAX_WIDTH;
		int y = currchar/GRID_MAX_WIDTH;
			
			
				
		this->grid_[x][y] = strgrid[currchar];
			
	}
}
void Tetris::MoveBlockLeft(void)
{
	if(
		(this->CurrentBlock_.subblocks_[0].Xpos+this->CurrentBlock_.XPos_>0) &&
		(this->CurrentBlock_.subblocks_[1].Xpos+this->CurrentBlock_.XPos_>0) &&
		(this->CurrentBlock_.subblocks_[2].Xpos+this->CurrentBlock_.XPos_>0) &&
		(this->CurrentBlock_.subblocks_[3].Xpos+this->CurrentBlock_.XPos_>0)
	)
	{
		if(
			(this->grid_[this->CurrentBlock_.subblocks_[0].Xpos+this->CurrentBlock_.XPos_-1][this->CurrentBlock_.subblocks_[0].Ypos+this->CurrentBlock_.YPos_]==' ') &&
			(this->grid_[this->CurrentBlock_.subblocks_[1].Xpos+this->CurrentBlock_.XPos_-1][this->CurrentBlock_.subblocks_[1].Ypos+this->CurrentBlock_.YPos_]==' ') &&
			(this->grid_[this->CurrentBlock_.subblocks_[2].Xpos+this->CurrentBlock_.XPos_-1][this->CurrentBlock_.subblocks_[2].Ypos+this->CurrentBlock_.YPos_]==' ') &&
			(this->grid_[this->CurrentBlock_.subblocks_[3].Xpos+this->CurrentBlock_.XPos_-1][this->CurrentBlock_.subblocks_[3].Ypos+this->CurrentBlock_.YPos_]==' ') 
		)
		{
			this->CurrentBlock_.XPos_--;
		}
	}


}
void Tetris::MoveBlockRight(void)
{
	if(
		(this->CurrentBlock_.subblocks_[0].Xpos+this->CurrentBlock_.XPos_<GRID_MAX_WIDTH-1) &&
		(this->CurrentBlock_.subblocks_[1].Xpos+this->CurrentBlock_.XPos_<GRID_MAX_WIDTH-1) &&
		(this->CurrentBlock_.subblocks_[2].Xpos+this->CurrentBlock_.XPos_<GRID_MAX_WIDTH-1) &&
		(this->CurrentBlock_.subblocks_[3].Xpos+this->CurrentBlock_.XPos_<GRID_MAX_WIDTH-1)
	)
	{
		if(
			(this->grid_[this->CurrentBlock_.subblocks_[0].Xpos+this->CurrentBlock_.XPos_+1][this->CurrentBlock_.subblocks_[0].Ypos+this->CurrentBlock_.YPos_]==' ') &&
			(this->grid_[this->CurrentBlock_.subblocks_[1].Xpos+this->CurrentBlock_.XPos_+1][this->CurrentBlock_.subblocks_[1].Ypos+this->CurrentBlock_.YPos_]==' ') &&
			(this->grid_[this->CurrentBlock_.subblocks_[2].Xpos+this->CurrentBlock_.XPos_+1][this->CurrentBlock_.subblocks_[2].Ypos+this->CurrentBlock_.YPos_]==' ') &&
			(this->grid_[this->CurrentBlock_.subblocks_[3].Xpos+this->CurrentBlock_.XPos_+1][this->CurrentBlock_.subblocks_[3].Ypos+this->CurrentBlock_.YPos_]==' ') 
		)
		{
			this->CurrentBlock_.XPos_++;
		}
	}


}
bool Tetris::MoveBlockDown(void)
{
	for(int i=0;i<4;i++)
	{
		if (this->CurrentBlock_.subblocks_[i].Ypos+this->CurrentBlock_.YPos_>GRID_MAX_HEIGHT+2)
		{
			this->grid_[this->CurrentBlock_.subblocks_[0].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[0].Ypos+this->CurrentBlock_.YPos_]=this->CurrentBlock_.GetColor();
			this->grid_[this->CurrentBlock_.subblocks_[1].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[1].Ypos+this->CurrentBlock_.YPos_]=this->CurrentBlock_.GetColor();
			this->grid_[this->CurrentBlock_.subblocks_[2].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[2].Ypos+this->CurrentBlock_.YPos_]=this->CurrentBlock_.GetColor();
			this->grid_[this->CurrentBlock_.subblocks_[3].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[3].Ypos+this->CurrentBlock_.YPos_]=this->CurrentBlock_.GetColor();
	
	

			return false;

		}
	}
	if(this->CurrentBlock_.Height_+this->CurrentBlock_.YPos_<GRID_MAX_HEIGHT)
	{
		if(
			(this->grid_[this->CurrentBlock_.subblocks_[0].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[0].Ypos+this->CurrentBlock_.YPos_+1]==' ') &&
			(this->grid_[this->CurrentBlock_.subblocks_[1].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[1].Ypos+this->CurrentBlock_.YPos_+1]==' ') &&
			(this->grid_[this->CurrentBlock_.subblocks_[2].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[2].Ypos+this->CurrentBlock_.YPos_+1]==' ') &&
			(this->grid_[this->CurrentBlock_.subblocks_[3].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[3].Ypos+this->CurrentBlock_.YPos_+1]==' ') 
		)
		{
			this->CurrentBlock_.YPos_++;
			
			return true;
		}
	}
	score_++;
	this->grid_[this->CurrentBlock_.subblocks_[0].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[0].Ypos+this->CurrentBlock_.YPos_]=this->CurrentBlock_.GetColor();
	this->grid_[this->CurrentBlock_.subblocks_[1].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[1].Ypos+this->CurrentBlock_.YPos_]=this->CurrentBlock_.GetColor();
	this->grid_[this->CurrentBlock_.subblocks_[2].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[2].Ypos+this->CurrentBlock_.YPos_]=this->CurrentBlock_.GetColor();
	this->grid_[this->CurrentBlock_.subblocks_[3].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[3].Ypos+this->CurrentBlock_.YPos_]=this->CurrentBlock_.GetColor();
	
	

	return false;

	


}

int Tetris::GetClearedLineCount()
{
	int cleared=0;
	for(int line=0;line<GRID_MAX_HEIGHT;line++)
	{
		if(this->cleared_lines[line]!=0)
		{
			cleared++;
		}
	}
	return cleared;
}

void Tetris::FlagCompletedLines(void)
{
	
	for(int y=0;y<GRID_MAX_HEIGHT;y++)
	{

		bool linecleared=true;
		for(int x=0;x<GRID_MAX_WIDTH;x++)
		{
			if(this->grid_[x][y]==' ')
			{
				linecleared = false;
				break;
			}
		}
		if(linecleared)
		{
			this->cleared_lines[y]=1;
		}
		else
		{
			this->cleared_lines[y]=0;
		}
	}
}
void Tetris::ClearCompleteLines(void)
{
	int currentline =GRID_MAX_HEIGHT-1;
	int linescleared = 0;
	this->NewLevel_=this->level_;
	while(currentline>0)
	{
		bool linecomplete=true;
		for (int x=0;x<GRID_MAX_WIDTH;x++)
		{
			if(grid_[x][currentline]==' ')
			{
				linecomplete = false;
			}
		}
		if (linecomplete)
		{
			for (int y=currentline;y>0;y--)
			{
				for (int x=0;x<GRID_MAX_WIDTH;x++)
				{
					if (y>0)
					{
						grid_[x][y]=grid_[x][y-1];
					}
					else
					{
						grid_[x][y]=' ';
					}
				}
			}
			linescleared++;
		}
		else
		{
			currentline--;
		}
	}
	switch(linescleared)
	{
	case 0:
		break;
	case 1:
		score_ = score_ + 25;
		break;
	case 2:
		score_ = score_ + 75;
		break;

	case 3:
		score_ = score_ + 100;
		break;
	case 4:
		score_ = score_ + 200;
		break;
	default:
		break;

	}
	lines_ = lines_+linescleared;
	if (lines_>20 && lines_<=40)
	{
		NewLevel_ = 2;
		timer_ = 900;
		return;
	}
	if (lines_>40 && lines_<=60)
	{
		NewLevel_ = 2;
		timer_ = 800;
		return;
	}
	if (lines_>60 && lines_<=80)
	{
		NewLevel_ = 3;
		timer_ = 700;
		return;
	}
	if (lines_>80 && lines_<=100)
	{
		NewLevel_ = 4;
		timer_ = 600;
		return;
	}
	if (lines_>100 && lines_<=120)
	{
		NewLevel_ = 5;
		timer_ = 500;
		return;
	}
	if (lines_>120 && lines_<=140)
	{
		NewLevel_ = 6;
		timer_ = 400;
		return;
	}
	if (lines_>140 && lines_<=160)
	{
		NewLevel_ = 7;
		timer_ = 300;
		return;
	}
	if (lines_>160 && lines_<=180)
	{
		NewLevel_ = 8;
		timer_ = 200;
		return;
	}
	if (lines_>180 && lines_<=200)
	{
		NewLevel_ = 9;
		timer_ = 100;
		return;
	}
	if (lines_>200)
	{
		NewLevel_ = 10;
		timer_ = 50;
		return;
	}



	
}

void Tetris::GameLoop(void)
{
	if(this->MoveBlockDown())
	{
		ClearCompleteLines();
		if(this->NewLevel_!=this->level_)
		{
			level_=NewLevel_;
		}
	}
	else
	{
		
		for (int i=0;i<4;i++)
		{
			if (this->grid_[this->NextBlock_.subblocks_[0].Xpos+this->NextBlock_.XPos_][this->CurrentBlock_.subblocks_[0].Ypos+this->NextBlock_.YPos_]!=' ')
			{
				this->SetStatus(TETRIS_GAME_OVER);
				
				return;
			}
		}
		this->CurrentBlock_=this->NextBlock_;
		TetrisBlock(bl);
		
		this->NextBlock_ = bl;

	}
	

}

void Tetris::RotateCurrentBlockClockwise(void)
{
	int currentorientation = this->CurrentBlock_.orientation_;
	this->CurrentBlock_.RotateClockwise();
	this->CurrentBlock_.RecalcBlockOrientation();
	for(int i=0;i<4;i++)
	{
		if (this->CurrentBlock_.XPos_+this->CurrentBlock_.subblocks_[i].Xpos>=GRID_MAX_WIDTH)
		{
			this->CurrentBlock_.orientation_ = currentorientation;
			this->CurrentBlock_.RecalcBlockOrientation();
			return;
		}
		if (this->CurrentBlock_.YPos_+this->CurrentBlock_.subblocks_[i].Ypos>=GRID_MAX_HEIGHT)
		{
			this->CurrentBlock_.orientation_ = currentorientation;
			this->CurrentBlock_.RecalcBlockOrientation();
			return;

		}
		if (grid_[this->CurrentBlock_.subblocks_[i].Xpos+this->CurrentBlock_.XPos_][this->CurrentBlock_.subblocks_[i].Ypos+this->CurrentBlock_.YPos_]!=' ')
		{
			this->CurrentBlock_.orientation_ = currentorientation;
			this->CurrentBlock_.RecalcBlockOrientation();
			return;

		}
	}
}

void Tetris::InitGame(int StartingLevel)
{
	this->score_ = 0;
	this->lines_ = 0;
	this->level_ = StartingLevel;
	this->NewLevel_ = StartingLevel;
	this->StartingLevel_ = StartingLevel;
	TetrisBlock newblock;
	this->CurrentBlock_ = newblock;
	TetrisBlock newnextblock;
	this->NextBlock_ = newnextblock;
	switch(StartingLevel_)
	{
	case 1:
		this->timer_ = 1000;
		break;
	case 2:
		this->timer_ = 900;
		break;
	case 3:
		this->timer_ = 800;
		break;
	case 4:
		this->timer_ = 700;
		break;
	case 5:
		this->timer_ = 600;
		break;
	case 6:
		this->timer_ = 500;
		break;
	case 7:
		this->timer_ = 400;
		break;
	case 8:
		this->timer_ = 300;
		break;
	case 9:
		this->timer_ = 200;
		break;
	case 10:
		this->timer_ = 100;
		break;




	}
	
}

