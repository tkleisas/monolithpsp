struct Vertex
{
	float u, v;
	unsigned int color;
	float x,y,z;
};

struct Position
{
	float x,y,z;
};
unsigned int ColorFromRGBA(unsigned char r,unsigned char g,unsigned char b,unsigned char a)
{
	unsigned int retval=0;
	retval = a<<24 | b<<16 | g<<8 | r;
	return retval;
};
unsigned char GetAlpha(unsigned int color)
{
	return (unsigned char)((color & 0xff000000)>>24)&0xff;
};
unsigned char GetBlue(unsigned int color)
{
	return (unsigned char)((color & 0xff0000)>>16)&0xff;
};
unsigned char GetGreen(unsigned int color)
{
	return (unsigned char)((color & 0xff00)>>8)&0xff;
};
unsigned char GetRed(unsigned int color)
{
	return (unsigned char)(color & 0xff)&0xff;
};
struct Vertex __attribute__((aligned(16))) vertices[12*3] =
{

	{0, 0, 0xffffffff,-0.5,-0.5, 0.5}, // 0-1
	{1, 0, 0xffffffff,-0.5, 0.5, 0.5}, // 4-2
	{1, 1, 0xffffffff, 0.5, 0.5, 0.5}, // 5-3

	{0, 0, 0xffffffff,-0.5,-0.5, 0.5}, // 0-4
	{1, 1, 0xffffffff, 0.5, 0.5, 0.5}, // 5-5
	{0, 1, 0xffffffff, 0.5,-0.5, 0.5}, // 1-6

	{0, 0, 0xffffffff,-0.5,-0.5,-0.5}, // 3-7
	{1, 0, 0xffffffff, 0.5,-0.5,-0.5}, // 2-8
	{1, 1, 0xffffffff, 0.5, 0.5,-0.5}, // 6-9

	{0, 0, 0xffffffff,-0.5,-0.5,-0.5}, // 3-10
	{1, 1, 0xffffffff, 0.5, 0.5,-0.5}, // 6-11
	{0, 1, 0xffffffff,-0.5, 0.5,-0.5}, // 7-12

	{0, 0, 0xffffffff, 0.5,-0.5,-0.5}, // 0-13
	{1, 0, 0xffffffff, 0.5,-0.5, 0.5}, // 3-14
	{1, 1, 0xffffffff, 0.5, 0.5, 0.5}, // 7-15

	{0, 0, 0xffffffff, 0.5,-0.5,-0.5}, // 0-16
	{1, 1, 0xffffffff, 0.5, 0.5, 0.5}, // 7-17
	{0, 1, 0xffffffff, 0.5, 0.5,-0.5}, // 4-18

	{0, 0, 0xffffffff,-0.5,-0.5,-0.5}, // 0-19
	{1, 0, 0xffffffff,-0.5, 0.5,-0.5}, // 3-20
	{1, 1, 0xffffffff,-0.5, 0.5, 0.5}, // 7-21

	{0, 0, 0xffffffff,-0.5,-0.5,-0.5}, // 0-22
	{1, 1, 0xffffffff,-0.5, 0.5, 0.5}, // 7-23
	{0, 1, 0xffffffff,-0.5,-0.5, 0.5}, // 4-24

	{0, 0, 0xffffffff,-0.5, 0.5,-0.5}, // 0-25
	{1, 0, 0xffffffff, 0.5, 0.5,-0.5}, // 1-26
	{1, 1, 0xffffffff, 0.5, 0.5, 0.5}, // 2-27

	{0, 0, 0xffffffff,-0.5, 0.5,-0.5}, // 0-28
	{1, 1, 0xffffffff, 0.5, 0.5, 0.5}, // 2-29
	{0, 1, 0xffffffff,-0.5, 0.5, 0.5}, // 3-30

	{0, 0, 0xffffffff,-0.5,-0.5,-0.5}, // 4-31
	{1, 0, 0xffffffff,-0.5,-0.5, 0.5}, // 7-32
	{1, 1, 0xffffffff, 0.5,-0.5, 0.5}, // 6-33

	{0, 0, 0xffffffff,-0.5,-0.5,-0.5}, // 4-34
	{1, 1, 0xffffffff, 0.5,-0.5, 0.5}, // 6-35
	{0, 1, 0xffffffff, 0.5,-0.5,-0.5}, // 5-36
/*
	{0, 0, 0xff7f0000,-1,-1, 1}, // 0-1
	{1, 0, 0xff7f0000,-1, 1, 1}, // 4-2
	{1, 1, 0xff7f0000, 1, 1, 1}, // 5-3

	{0, 0, 0xff7f0000,-1,-1, 1}, // 0-4
	{1, 1, 0xff7f0000, 1, 1, 1}, // 5-5
	{0, 1, 0xff7f0000, 1,-1, 1}, // 1-6

	{0, 0, 0xff7f0000,-1,-1,-1}, // 3-7
	{1, 0, 0xff7f0000, 1,-1,-1}, // 2-8
	{1, 1, 0xff7f0000, 1, 1,-1}, // 6-9

	{0, 0, 0xff7f0000,-1,-1,-1}, // 3-10
	{1, 1, 0xff7f0000, 1, 1,-1}, // 6-11
	{0, 1, 0xff7f0000,-1, 1,-1}, // 7-12

	{0, 0, 0xff007f00, 1,-1,-1}, // 0-13
	{1, 0, 0xff007f00, 1,-1, 1}, // 3-14
	{1, 1, 0xff007f00, 1, 1, 1}, // 7-15

	{0, 0, 0xff007f00, 1,-1,-1}, // 0-16
	{1, 1, 0xff007f00, 1, 1, 1}, // 7-17
	{0, 1, 0xff007f00, 1, 1,-1}, // 4-18

	{0, 0, 0xff007f00,-1,-1,-1}, // 0-19
	{1, 0, 0xff007f00,-1, 1,-1}, // 3-20
	{1, 1, 0xff007f00,-1, 1, 1}, // 7-21

	{0, 0, 0xff007f00,-1,-1,-1}, // 0-22
	{1, 1, 0xff007f00,-1, 1, 1}, // 7-23
	{0, 1, 0xff007f00,-1,-1, 1}, // 4-24

	{0, 0, 0xff00007f,-1, 1,-1}, // 0-25
	{1, 0, 0xff00007f, 1, 1,-1}, // 1-26
	{1, 1, 0xff00007f, 1, 1, 1}, // 2-27

	{0, 0, 0xff00007f,-1, 1,-1}, // 0-28
	{1, 1, 0xff00007f, 1, 1, 1}, // 2-29
	{0, 1, 0xff00007f,-1, 1, 1}, // 3-30

	{0, 0, 0xff00007f,-1,-1,-1}, // 4-31
	{1, 0, 0xff00007f,-1,-1, 1}, // 7-32
	{1, 1, 0xff00007f, 1,-1, 1}, // 6-33

	{0, 0, 0xff00007f,-1,-1,-1}, // 4-34
	{1, 1, 0xff00007f, 1,-1, 1}, // 6-35
	{0, 1, 0xff00007f, 1,-1,-1}, // 5-36
*/	
};
template <int length> struct Entity
{
	Vertex& operator[] (int index){return v[index];};
	__attribute__((aligned(16))) Vertex v[length];
	Position position;
	Position rotationPosition;
	Entity()
	{
		for(int i=0;i<length;i++)
		{
			v[i].x = 0;
			v[i].y = 0;
			v[i].z = 0;
			v[i].color = 0;
			v[i].u = 0;
			v[i].v = 0;
		position.x=0;
		position.y=0;
		position.z=0;
		rotationPosition.x=0;
		rotationPosition.y=0;
		rotationPosition.z=0;
		
		}
		
	};
	Entity(unsigned int color)
	{
		Entity();
		SetColor(color);

		
	};
	void SetColor(unsigned int thecolor)
	{
		for(int i=0;i<36;i++)
		{
			switch(i/6)
			{
				case 0:
				v[i].color = thecolor; 
				break;
				case 1:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*7)/8,(GetGreen(thecolor)*7)/8,(GetBlue(thecolor)*7)/8,GetAlpha(thecolor));
				break;
				case 2:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*6)/8,(GetGreen(thecolor)*6)/8,(GetBlue(thecolor)*6)/8,GetAlpha(thecolor));
				break;
				case 3:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*5)/8,(GetGreen(thecolor)*5)/8,(GetBlue(thecolor)*5)/8,GetAlpha(thecolor));
				break;
				case 4:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*4)/8,(GetGreen(thecolor)*4)/8,(GetBlue(thecolor)*5)/8,GetAlpha(thecolor));
				break;
				case 5:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*3)/8,(GetGreen(thecolor)*3)/8,(GetBlue(thecolor)*4)/8,GetAlpha(thecolor));
				break;
				case 6:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*2)/8,(GetGreen(thecolor)*2)/8,(GetBlue(thecolor)*3)/8,GetAlpha(thecolor));
				break;
				default:
				v[i].color = thecolor;
				break;

				
			}		
		}
	};
	void SetPosition(float x1, float y1, float z1)
	{
		this->position.x=x1;
		this->position.y=y1;
		this->position.z=z1;
	};
	void SetRotation(float x1, float y1, float z1)
	{	
		
		this->rotationPosition.x = x1;
		this->rotationPosition.y = y1;
		this->rotationPosition.z = z1;
	};
	void SetVertex(int index,float eu,float ev,unsigned int ecolor,float ex,float ey,float ez)
	{
		if(index<length)
		{
			v[index].u = eu;
			v[index].v = ev;
			v[index].color = ecolor;
			v[index].x=ex;
			v[index].y=ey;
			v[index].z=ez;
		}
	};	
};
struct Cube
{

	Vertex& operator[] (int index){return v[index];};
	__attribute__((aligned(16))) Vertex v[36];
	Position position;
	Position rotationPosition;
	Cube()
	{
		
		for(int i=0;i<36;i++)
		{
			v[i].x = vertices[i].x;
			v[i].y = vertices[i].y;
			v[i].z = vertices[i].z;
			v[i].color = vertices[i].color;
			v[i].u = vertices[i].u;
			v[i].v = vertices[i].v;
		}
		position.x=0;
		position.y=0;
		position.z=0;
		rotationPosition.x=0;
		rotationPosition.y=0;
		rotationPosition.z=0;
		
	};
	Cube(unsigned int theColor)
	{
		for(int i=0;i<36;i++)
		{
			v[i].x = vertices[i].x;
			v[i].y = vertices[i].y;
			v[i].z = vertices[i].z;
			v[i].color = theColor;
			v[i].u = vertices[i].u;
			v[i].v = vertices[i].v;
		}
		position.x=0;
		position.y=0;
		position.z=0;
		rotationPosition.x=0;
		rotationPosition.y=0;
		rotationPosition.z=0;
		this->SetColor(theColor);
		
	};
	Cube(struct vertices[12*3],unsigned int thecolor)
	{
		
		for(int i=0;i<36;i++)
		{
			
			v[i].x = vertices[i].x;
			v[i].y = vertices[i].y;
			v[i].z = vertices[i].z;
			v[i].u = vertices[i].u;
			v[i].v = vertices[i].v;
			switch(i/6)
			{
				case 0:
				v[i].color = thecolor; 
				break;
				case 1:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*7)/8,(GetGreen(thecolor)*7)/8,(GetBlue(thecolor)*7)/8,GetAlpha(thecolor));
				break;
				case 2:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*6)/8,(GetGreen(thecolor)*6)/8,(GetBlue(thecolor)*6)/8,GetAlpha(thecolor));
				break;
				case 3:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*5)/8,(GetGreen(thecolor)*5)/8,(GetBlue(thecolor)*5)/8,GetAlpha(thecolor));
				break;
				case 4:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*4)/8,(GetGreen(thecolor)*4)/8,(GetBlue(thecolor)*5)/8,GetAlpha(thecolor));
				break;
				case 5:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*3)/8,(GetGreen(thecolor)*3)/8,(GetBlue(thecolor)*4)/8,GetAlpha(thecolor));
				break;
				case 6:
				v[i].color = ColorFromRGBA((GetRed(thecolor)*2)/8,(GetGreen(thecolor)*2)/8,(GetBlue(thecolor)*3)/8,GetAlpha(thecolor));
				break;
				default:
				v[i].color = thecolor;
				break;

				
			}
			
			
			
			
		}
	};
	void SetPosition(float x1, float y1, float z1)
	{
		this->position.x=x1;
		this->position.y=y1;
		this->position.z=z1;
	};
	void SetRotation(float x1, float y1, float z1)
	{	
		
		this->rotationPosition.x = x1;
		this->rotationPosition.y = y1;
		this->rotationPosition.z = z1;
	};
	void SetColor(unsigned int thecolor)
	{
		for(int i=0;i<36;i++)
		{
			switch(i/6)
			{
				case 0:
				v[i].color = thecolor; 
				break;
				case 1:
				v[i].color = ColorFromRGBA(GetRed(thecolor)>>1,GetGreen(thecolor)>>1,GetBlue(thecolor)>>1,GetAlpha(thecolor));
				break;
				case 2:
				v[i].color = ColorFromRGBA(GetRed(thecolor),GetGreen(thecolor),GetBlue(thecolor),GetAlpha(thecolor));
				break;
				case 3:
				v[i].color = ColorFromRGBA(GetRed(thecolor)>>2,GetGreen(thecolor)>>2,GetBlue(thecolor)>>2,GetAlpha(thecolor));
				break;
				case 4:
				v[i].color = ColorFromRGBA(GetRed(thecolor),GetGreen(thecolor),GetBlue(thecolor),GetAlpha(thecolor));
				break;
				case 5:
				v[i].color = ColorFromRGBA(GetRed(thecolor)>>1,GetGreen(thecolor)>>1,GetBlue(thecolor)>>1,GetAlpha(thecolor));
				break;
				default:
				v[i].color = thecolor;
				break;

				
			}		
		}
	};
	void SetVertex(int index,float eu,float ev,unsigned int ecolor,float ex,float ey,float ez)
	{
		if(index<36)
		{
			v[index].u = eu;
			v[index].v = ev;
			v[index].color = ecolor;
			v[index].x=ex;
			v[index].y=ey;
			v[index].z=ez;
		}
	};	
	

};

