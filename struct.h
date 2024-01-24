#pragma once

typedef struct vector
{
	float x;
	float y;
}vector;

typedef struct Object
{
	vector position;
	vector speed;
	int radius;
};
