// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <gl/glew.h>
#include <math.h>
#include <timeapi.h>
#include <stdio.h>

#define PI 3.141592653589793238

struct double3 {
	double x, y, z;
};

struct float3 {
	float x, y, z;
};

struct ubyte4 {
	unsigned char x, y, z, w;
};

struct float2 {
	float s,t;
};

struct onland {
	int isonland;
	double x1, z1, x2, z2, y;
};

struct blockandsurface {
	int ispoint;
	int blockx, blocky, blockz;
	int surx, sury, surz;
};

struct movestate {
	onland onlandstate;
	double3 pos, v;
	double ang1, ang2;
	double3 at;
	int flying, up, left, forward;
	blockandsurface point;
	int inhand;
};

struct elementtypes {
	int opaque, red;
};

const double r = 0.3, dr = 0.2, rm = 0.4, bot = -1.62, top = 0.18;
int const tr[256] = { 1,0,0,0,1,1,1 };
extern int upbs;

int initview(GLuint *tex, GLuint *vbo, GLuint *tbo, int(*block)[256][256], HBITMAP teximg);
int draw(movestate *pe, GLuint *vbo, GLuint *tbo);
int initblocks(int(**block)[256][256], double3 pos);
int move(movestate *pe, unsigned int dt, int(*block)[256][256]);
void updatepoint(movestate *pe, int(*block)[256][256]);
void upregionsurface(int(*block)[256][256], int rx, int rz, int t, GLuint *vbo, GLuint *tbo);
void upb(int x, int y, int z, int type, int(*block)[256][256], elementtypes *regionsupdate);
void removeblock(movestate *pe, int(*block)[256][256], elementtypes *regionsupdate);
void rightbutton(movestate *pe, int(*block)[256][256], elementtypes *regionsupdate);
void updateintick(int(*block)[256][256], elementtypes *regionsupdate);

// TODO: reference additional headers your program requires here
