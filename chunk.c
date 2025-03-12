#include "chunk.h"

void fillChunk(Chunk* chunk)
{
	for (int w = 0; w < chunk->width; w++)
	{
		for (int h = 0; h < chunk->height; h++)
		{
			for (int d = 0; d < chunk->depth; d++)
			{
				Block block;
				initBlock(&block, w, h, d);
				chunk->blocks[w+h+d] = block;
			}
		}
	}
}

void transformChunk(chunk)
{
	for (int i = 0; i < chunk->blockCount; i++)
	{
		transformBlock(chunk->blocks[i]);
	}
}

void initChunk(Chunk* chunk, vec3 topLeftPosition, int width, int height, int depth)
{
	chunk->topLeftPosition = topLeftPosition;
	
	chunk->width = width;
	chunk->height = height;
	chunk->depth = depth;
	int totalBlocks = width*height*depth;
	chunk->blocks = (Block*)malloc(totalBlocks*sizeof(Block));
	chunk->blockCount = totalBlocks;
	
	fillChunk(chunk);
	transformChunk(chunk);
}
