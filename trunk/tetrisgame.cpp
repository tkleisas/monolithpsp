#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspdebug.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <pspgu.h>
#include <pspgum.h>
#include <pspctrl.h>
#include <psprtc.h>
#include "callbacks.h"
#include "vram.h"
#include "controller.h"
#include "text.h"
#include "tetrisgame.h"


#define BUF_WIDTH (512)
#define SCR_WIDTH (480)
#define SCR_HEIGHT (272)
PSP_MODULE_INFO("psptetris", 0, 1, 1);
PSP_HEAP_SIZE_KB(4096);
//PSP_HEAP_SIZE_MAX();
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER| THREAD_ATTR_VFPU);
PSP_MAIN_THREAD_STACK_SIZE_KB(1024);
int defaultminkeytime=75;
TickCounter counter;
Cube c0(0xff0000ff);
Cube c1(0xff00ff00);
Cube c2(0xffff0000);
Cube c3(0xffff00ff);
Cube c4(0xff00ffff);
Cube c5(0xffffff00);
Cube c6(0xffff9933);
Cube c7(0xffffffff);
Entity<6> textpixel;
Entity<6> leftField;
Entity<6> rightField;
Entity<6> bottomField;

Cube cubes[8];
static unsigned int __attribute__((aligned(16))) list[262144];



void CreateSquare(Entity<6>& square,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3,float x4,float y4,float z4,unsigned int color)
{
	/*
	square.SetVertex(0,-1.0,-1.0,color,x1,y1,z1);
	square.SetVertex(1,-1.0,1.0,color,x3,y3,z3);
	square.SetVertex(2,1.0,1.0,color,x2,y2,z2);
	square.SetVertex(3,1.0,-1.0,color,x1,y1,z1);
	square.SetVertex(4,-1.0,-1.0,color,x4,y4,z4);
	square.SetVertex(5,1.0,1.0,color,x3,y3,z3);
	*/
	square.SetVertex(0,0.0,0.0,color,x1,y1,z1);
	square.SetVertex(1,0.0,0.0,color,x3,y3,z3);
	square.SetVertex(2,0.0,0.0,color,x2,y2,z2);
	square.SetVertex(3,0.0,0.0,color,x1,y1,z1);
	square.SetVertex(4,0.0,0.0,color,x4,y4,z4);
	square.SetVertex(5,0.0,0.0,color,x3,y3,z3);
	
}



TetrisGame::TetrisGame()
{
	setupCallbacks();
	SetupController();
	xzAngle=0.0;
	yzAngle=0.0;
	xyAngle=0.0;

	xzOffset=15;
	RotateAngle=0;
	yAngle=0;
	xAngle=0;

	xzOffsetDefault = xzOffset;
	rotationVertexDefaults.x=1.0;
	rotationVertexDefaults.y=1.0;
	rotationVertexDefaults.z=0;
	rotationVertex=rotationVertexDefaults;
	
	xpos=0;
	ypos=0;
	explosionComplete=true;
	acceleration = 0.001;
	explosionFrames=60;
	explosionCurrentFrame=0;
	explosion=false;	
	isPaused=false;



	
}
TetrisGame::~TetrisGame()
{
	sceGuTerm();
	sceKernelExitGame();
}

int TetrisGame::HandleInput()
{
	int done;

	done = 0;
	int xpad = GetJoystickX()-128;
	int ypad = GetJoystickY()-128;
	float anglestep = 2.0*GU_PI/720.0f;
	if(xpad>15 || xpad<-15)
	{
		xzAngle = xzAngle+(((float)xpad)/15)*anglestep;
	}
	if(ypad>15 || ypad<-15)
	{
		yzAngle = yzAngle+(((float)ypad)/15)*anglestep;
	}
	
	

	unsigned int buttons = GetButtonsPressed();
	
	if(buttons & PSP_CTRL_SELECT)
	{
		xyAngle=0.0;
		xzAngle=0.0;
		yzAngle=0.0;
	}
	if(buttons & PSP_CTRL_START)
	{
		return -16;
	}
	if(buttons & PSP_CTRL_UP)
	{
		return -4;
	}
	if(buttons & PSP_CTRL_RIGHT)
	{
		return -2;
	}
	if(buttons & PSP_CTRL_DOWN)
	{
		return -8;
	}
	if(buttons & PSP_CTRL_LEFT)
	{
		return -1;
	}
	if(buttons & PSP_CTRL_LTRIGGER)
	{
	}
	if(buttons & PSP_CTRL_RTRIGGER)
	{
	}
	if(buttons & PSP_CTRL_TRIANGLE)
	{
	}
	if(buttons & PSP_CTRL_CIRCLE)
	{
	}
	if(buttons & PSP_CTRL_CROSS)
	{
		return -4;
	}
	if(buttons & PSP_CTRL_SQUARE)
	{
		isPaused=!isPaused;
	}

	return done;
}
unsigned int TetrisGame::GetColor(char color)
{

	switch(color)
	{
		case '1':
			return 0;
		break;
		case '2':
			return 1;
		break;
		case '3':
			return 2;
		break;
		case '4':
			return 3;
		break;
		case '5':
			return 4;
		break;
		case '6':
			return 5;
		break;
		case '7':
			return 6;
		break;
		default:
			return 7;
		break;

	}
}

void TetrisGame::InitGraphics()
{
	void* fbp0 = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);
	void* fbp1 = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);
	void* zbp = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_4444);

	sceGuInit();
	
	sceGuStart(GU_DIRECT,list);
	sceGuDrawBuffer(GU_PSM_8888,fbp0,BUF_WIDTH);
	sceGuDispBuffer(SCR_WIDTH,SCR_HEIGHT,fbp1,BUF_WIDTH);
	sceGuDepthBuffer(zbp,BUF_WIDTH);
	sceGuOffset(2048 - (SCR_WIDTH/2),2048 - (SCR_HEIGHT/2));
	sceGuViewport(2048,2048,SCR_WIDTH,SCR_HEIGHT);
	sceGuDepthRange(65535,0);
	sceGuScissor(0,0,SCR_WIDTH,SCR_HEIGHT);
	sceGuEnable(GU_SCISSOR_TEST);
	sceGuDepthFunc(GU_GEQUAL);
	sceGuEnable(GU_DEPTH_TEST);
	//sceGuDepthRange(65535,0);
	//sceGuFrontFace(GU_CW);
	sceGuShadeModel(GU_SMOOTH);
	//sceGuShadeModel(GU_FLAT);
	//sceGuEnable(GU_CULL_FACE);
	//sceGuEnable(GU_TEXTURE_2D);
	sceGuEnable(GU_CLIP_PLANES);/////
	sceGuFinish();
	sceGuSync(0,0);

	sceDisplayWaitVblankStart();
	sceGuDisplay(GU_TRUE);

}
void TetrisGame::DrawCube(float x,float y, float z,float xrot,float yrot,float zrot,int colorindex)
{
			//sceGumPushMatrix();
			sceGumLoadIdentity();
			ScePspFVector3 pos = { x, y, z };
			ScePspFVector3 rot = { xrot, yrot, zrot};
			sceGumTranslate(&pos);
			sceGumRotateXYZ(&rot);
			
			
			sceGumDrawArray(GU_TRIANGLES,GU_TEXTURE_32BITF|GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,12*3,0,cubes[colorindex].v);
			//sceGumPopMatrix();		
	
}
void TetrisGame::DrawPlayfield()
{
	//sceGumPushMatrix();
	sceGumLoadIdentity();
		
	sceGumDrawArray(GU_TRIANGLES,GU_TEXTURE_32BITF|GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,6*3,0,leftField.v);
	//sceGumPopMatrix();
	//sceGumPushMatrix();
	
	sceGumLoadIdentity();
	sceGumDrawArray(GU_TRIANGLES,GU_TEXTURE_32BITF|GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,6*3,0,rightField.v);
	//sceGumPopMatrix();
	//sceGumPushMatrix();
	
	sceGumLoadIdentity();
	sceGumDrawArray(GU_TRIANGLES,GU_TEXTURE_32BITF|GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,6*3,0,bottomField.v);
	//sceGumPopMatrix();
	
}

void TetrisGame::Draw3DText(string text,unsigned int color, float offx, float offy, float offz, float scale,float thickness)


{
	Text<128> theText(text);
	
	for(int y=0;y<8;y++)
	{
		for(int x=0;x<128;x++)
		{
			if(theText.billboard[x][y]==1)
			{
				//sceGumPushMatrix();
				sceGumLoadIdentity();
				ScePspFVector3 pos = { offx+(((float)x)*scale),offy+(-((float)y)*scale) , offz };
				ScePspFVector3 rot = { 0, 0, 0};
				sceGumTranslate(&pos);
				sceGumRotateXYZ(&rot);
				sceGumDrawArray(GU_TRIANGLES,GU_TEXTURE_32BITF|GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,6*3,0,textpixel.v);
				//sceGumPopMatrix();					
				
			}
		}
	}
}
void TetrisGame::DrawNextPiece( float x, float y, float z)
{
	unsigned int color = GetColor(tetris.NextBlock_.GetColor());
	sceGumLoadIdentity();
	ScePspFVector3 pos = { x, y, z };
	ScePspFVector3 pos2 = { -1.0f, 1.0f, 0.0f };
	ScePspFVector3 rot = { 0.0f, 0.0f, RotateAngle};
	sceGumTranslate(&pos);
	sceGumRotateXYZ(&rot);
	sceGumTranslate(&pos2);
	
	for(int i=0;i<4;i++)
	{
		int x1 = tetris.NextBlock_.subblocks_[i].Xpos+tetris.NextBlock_.GetXPos();
		int y1 = tetris.NextBlock_.subblocks_[i].Ypos+tetris.NextBlock_.GetYPos();
		
		sceGumPushMatrix();

		ScePspFVector3 pos = { x1*1.0f, -y1*1.0f, 0 };
		ScePspFVector3 rot = { 0.0f, 0.0f, 0.0f};
		sceGumTranslate(&pos);
		sceGumRotateXYZ(&rot);
		sceGumDrawArray(GU_TRIANGLES,GU_TEXTURE_32BITF|GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,12*3,0,cubes[color].v);
		sceGumPopMatrix();
	

	}

	
}

void TetrisGame::DrawBoard()
{
	for(int y=0;y<20;y++)
	{
		for(int x=0;x<10;x++)
		{
			char result = tetris.GetGridValue(x,y);
			int color;
			switch(result)
			{
				case '1':
					color=0;
					break;
				case '2':
					color=1;
					break;
				case '3':
					color=2;
					break;
				case '4':
					color=3;
					break;
				case '5':
					color=4;
					break;
				case '6':
					color=5;
					break;
				case '7':
					color=6;
					break;
				default:
					color=-1;
					break;
			}

			if(color!=-1)
			{
				if(!(tetris.cleared_lines[y]==1))
				{

					sceGumLoadIdentity();
					ScePspFVector3 pos = { -5.0f+x*1.0f, 9.0f-y*1.0f, -2.5f };
					ScePspFVector3 rot = { 0, 0, 0};
					sceGumTranslate(&pos);
					sceGumRotateXYZ(&rot);
					
					sceGumDrawArray(GU_TRIANGLES,GU_TEXTURE_32BITF|GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,12*3,0,cubes[color].v);

				}
			}

		}
	}
}

void TetrisGame::DrawFallingPiece()
{
	unsigned int color = GetColor(tetris.CurrentBlock_.GetColor());
	for(int i=0;i<4;i++)
	{
		int x1 = tetris.CurrentBlock_.subblocks_[i].Xpos+tetris.CurrentBlock_.GetXPos();
		int y1 = tetris.CurrentBlock_.subblocks_[i].Ypos+tetris.CurrentBlock_.GetYPos();
		

		sceGumLoadIdentity();
		ScePspFVector3 pos = { -5.0f+x1*1.0f, 9.0f-y1*1.0f, -2.5f };
		ScePspFVector3 rot = { 0.0f, 0.0f, 0.0f};
		sceGumTranslate(&pos);
		sceGumRotateXYZ(&rot);
		sceGumDrawArray(GU_TRIANGLES,GU_TEXTURE_32BITF|GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,12*3,0,cubes[color].v);

	

	}

}
void TetrisGame::DrawExplosion()
{
	vector<Explosion>::iterator iter=explosions.end();
	while(iter!=explosions.begin())
	{
		Explosion e=*iter;
		
		if(e.frame>explosionFrames)
		{
			
			explosions.erase(iter);
		}
		else
		{
			DrawCube(e.x,e.y,e.z,0.0,0.0,0.0,e.color);
			e.x=e.x+e.velx*e.frame;
			e.y=e.y+e.vely*e.frame;
			e.z=e.z+e.velz*e.frame;
			e.vely=e.vely-acceleration*e.frame;
			e.frame++;
			*iter=e;
		}
		iter--;
	}


}
void TetrisGame::ClearExplosion()
{
	explosions.clear();	
	
}
void TetrisGame::CreateCubeExplosion(int x, int y, unsigned int color)
{
	


	float velx = (((rand()%2)?-1:1))*(rand()%100/2000.0);
	float vely = (((rand()%2)?-1:1))*(rand()%100/2000.0);
	float velz = (((rand()%2)?-1:1))*(rand()%100/2000.0);
	Explosion e(-5.0f+x*1.0f,9.0f-y*1.0f,-2.5f,velx,vely,velz,0,color);
	explosions.push_back(e);
}
void TetrisGame::CreateLineExplosion(int line)
{
	for(int x=0;x<GRID_MAX_WIDTH;x++)
	{
		unsigned int color = GetColor(tetris.GetGridValue(x,line));
		CreateCubeExplosion(x,line,color);
	}
	
}



bool TetrisGame::CheckExplosions()
{
	int clearedLines=tetris.GetClearedLineCount();
	
	if(clearedLines>0)
	{
		
		
		for(int i=0;i<GRID_MAX_HEIGHT;i++)
		{
			if(tetris.cleared_lines[i]==1)
			{
				CreateLineExplosion(i);
			}
		}
		explosion = true;
	}
	else
	{
		explosion = false;
		return false;
	}
	return explosion;
}

void TetrisGame::GameLoop()
{
	
	tetris.InitGame(1);
	tetris.SetStatus(TETRIS_PLAYING);
	tetris.ClearGrid();
	tetris.TimerEnabled_ = true;

	unsigned int gameoversize=255;
	unsigned char gameoverstep=1;
	unsigned int now=tickcounter.GetTicks();
    unsigned int lastKeyPress = tickcounter.GetTicks();
	unsigned int minKeyTime = defaultminkeytime;	
	float g_valyz=0;
	float g_valxz=0;
	sceKernelDcacheWritebackAll();
	ClearExplosion();
	while(running())
	{

		sceKernelDelayThread(1000);

		sceGuStart(GU_DIRECT,list);



		sceGuClearColor(0x00000000);
		sceGuClearDepth(0);
		sceGuClear(GU_COLOR_BUFFER_BIT|GU_DEPTH_BUFFER_BIT);



		sceGumMatrixMode(GU_PROJECTION);
		sceGumLoadIdentity();
		sceGumPerspective(75.0f,16.0f/9.0f,0.5f,1000.0f);

		sceGumMatrixMode(GU_VIEW);
		sceGumLoadIdentity();
		ScePspFVector3 pos1 = { 0, 0, -16.0f };

		ScePspFVector3 rot = { yzAngle, xzAngle,  0};
		ScePspFVector3 pos2 = { 0, 0, 2.5f };
		sceGumTranslate(&pos1);
		sceGumRotateXYZ(&rot);		
		sceGumTranslate(&pos2);
		sceGumMatrixMode(GU_MODEL);
		DrawPlayfield();
		DrawFallingPiece();
		char str[255];
		char level[255];
		char lines[255];
		char tick[255];
		char sxpos[255];
		char sypos[255];
		sprintf(sxpos,"%f",yzAngle);
		sprintf(sypos,"%f",xzAngle);
		//sprintf(tick,"%u",tickcounter.GetTicks());
		sprintf(lines,"%d",tetris.lines_);
		sprintf(str,"%d",tetris.score_);
		string s(str);
		while(s.length()<8)
		{
			s = "0"+s;
		}
		Draw3DText("SCORE",8,-18.0f,10.0f,0,0.2,0.2);
		Draw3DText(s,8,-18.0f,8.0f,0,0.2,0.2);
		//Draw3DText(string(sxpos),8,-15.0,10.0,0,0.2,0.2);
		//Draw3DText(string(sypos),8,-15.0,8.0,0,0.2,0.2);
		
		sprintf(level,"%d",tetris.level_);		
		Draw3DText(string("LEVEL"),8,-18.0f,6.0f,0.0f,0.22f,0.22f);
		Draw3DText(string(level),8,-18.0f,4.0f,0.0f,0.22f,0.22f);
		Draw3DText(string("LINES"),8,-18.0f,2.0f,0.0f,0.22f,0.22f);
		Draw3DText(string(lines),8,-18.0f,0.0f,0.0f,0.22f,0.22f);
		Draw3DText(string("(C)TEACAKE"),8,4.2f,-8.0f,0.0f,0.18f,0.18f);
		DrawNextPiece(14.0f,-0.0f,-2.5f);
		
		if(isPaused && (tetris.GetStatus()==TETRIS_PLAYING))
		{
			Draw3DText(string("PAUSED"),8,-5,2,3,0.4,0.4);
		}
		
		if(tetris.GetStatus()==TETRIS_GAME_OVER)
		{
			Draw3DText(string("GAME OVER"),8,-10.0f,1.0f,2.0f,0.3,0.3);
			gameoversize = gameoversize+gameoverstep;
			if (gameoversize>255)
			{
				gameoverstep=-gameoverstep;
			}
			if(gameoversize<30)
			{
				gameoverstep=-gameoverstep;
			}

		}		

		DrawExplosion();
			


		tetris.FlagCompletedLines();
		if(tetris.GetClearedLineCount()>0)
		{
			CheckExplosions();
				
		
		}
		DrawBoard();
		RotateAngle = RotateAngle+0.01f;
		if(RotateAngle>360.0f)
		{
			RotateAngle=0.0f;
		}
		unsigned int timenow = tickcounter.GetTicks();

		int done= HandleInput();
		if(done==-16)
		{
			tetris.InitGame(1);
			tetris.SetStatus(TETRIS_PLAYING);
			tetris.ClearGrid();
			ClearExplosion();
			tetris.TimerEnabled_ = true;
			now=tickcounter.GetTicks();
			lastKeyPress = tickcounter.GetTicks();
			minKeyTime = defaultminkeytime;			

		}
		if(isPaused)
		{
			//unsigned char message[255];

			
			
			
		}
		else if(tetris.GetStatus()!=TETRIS_PLAYING)
		{
		}
		else if(timenow>now+tetris.timer_)
		{

			
			
			tetris.GameLoop();

			now = tickcounter.GetTicks();
			
			
		}
		else
		{
		
			if(done==-1)
			{
				if(tickcounter.GetTicks()-lastKeyPress>minKeyTime)
				{
					tetris.MoveBlockLeft();
				}
				lastKeyPress = tickcounter.GetTicks();
				
			}
			if(done==-2)
			{
				if(tickcounter.GetTicks()-lastKeyPress>minKeyTime)
				{
					tetris.MoveBlockRight();
				}
				lastKeyPress = tickcounter.GetTicks();
				
			}

			if(done==-4)
			{
				if(tickcounter.GetTicks()-lastKeyPress>minKeyTime*2)
				{
					tetris.RotateCurrentBlockClockwise();
				}
				lastKeyPress = tickcounter.GetTicks();

			}
			if(done==-8 )
			{

				tetris.GameLoop();
				
			}		
		
		
		
		
		}
		//sceGumPopMatrix();
		
		sceGuFinish();
		sceGuSync(0,0);

		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
	}
}
int main(int argc, char* argv[])
{
	cubes[0] = c0;
	cubes[1] = c1;
	cubes[2] = c2;
	cubes[3] = c3;
	cubes[4] = c4;
	cubes[5] = c5;
	cubes[6] = c6;
	cubes[7] = c7;
	CreateSquare(textpixel,0.05,0.05,0.0,-0.05,0.05,0,-0.05,-0.05,0,0.05,-0.05,0,0xffffffff);
	CreateSquare(leftField,-5.6,-10.6,-2.0,-5.6,-10.6,-3.5f,-5.6,12.1,-3.5f,-5.6,12.1,-2.0,0xfff0f0f0);
	CreateSquare(rightField,4.6,-10.6,-2.0,4.6,-10.6,-3.5f,4.6,12.1,-3.5f,4.6,12.1,-2.0,0xfff0f0f0);
	CreateSquare(bottomField,-5.6,-10.6,-2.0,4.6,-10.6,-2.0,4.6,-10.6,-3.5,-5.6,-10.6,-3.5,0xfff0f0f0);		
	TetrisGame game;
	game.InitGraphics();
	game.GameLoop();
	return 0;

	
}

