#ifndef _CHUNK
#define _CHUNK

#include "mathlibrary/maths.h"
#include "block.h"

struct Chunk
{
	vec3 topLeftPosition;
	Block* blocks;
	int blockCount;
	int width;
	int height;
	int depth;
};
typedef struct Chunk Chunk;

void initChunk(Chunk* chunk, vec3 topLeftPosition, int width, int height, int depth);
void destroyChunk(Chunk* chunk);

#endif
