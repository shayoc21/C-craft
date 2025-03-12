#include "scene.h"

void addChunkToScene(Scene* scene, Chunk* chunk)
{
	Chunk* copiedChunk = (Chunk*)malloc(sizeof(Chunk));
	*copiedChunk = *chunk;

	scene->worldChunkCounter++;
	scene->worldChunks = (Chunk**)realloc(scene->worldChunks, scene->worldChunkCounter * sizeof(Chunk*));
	scene->worldChunks[scene->worldChunkCounter-1] = copiedChunk;
}

void initWorld(Scene* scene)
{
	//proper chunk generation to come...
	Chunk chunk;
	initChunk(&chunk, vector(0.0f, 0.0f, 0.0f), 1, 1, 1);
	addChunkToScene(&chunk);
}

void initScene(Scene* scene)
{
	scene->worldChunks = (Chunk**)malloc(sizeof(Chunk*));
	scene->worldChunkCounter = 0;

	initWorld(scene);
	initSkybox(&scene->skybox);
}

void getFacesToDraw(Scene* scene, BlockFace** faceBuffer)
{
	//for now it just gets every face, soon will cull faces not seen.
	//this is also really slow because this runs every frame, will add some caching later
	int blockCounter = 0;
	for (int i = 0; i < scene->worldChunkCounter; i++)
	{
		Chunk* chunk = scene->worldChunks[i];
		for (int j = 0; j < chunk->blockCount; j++)
		{
			Block* block = chunk->blocks[j];
			for (int k = 0; k < 6; k++)
			{
				blockCounter++;
				*faceBuffer = (BlockFace*)realloc(*faceBuffer, blockCounter * sizeof(BlockFace));
				(*faceBuffer)[blockCounter-1] = block->faces[k];
			}
		}
	}
}

void drawScene(Scene* scene)
{
	BlockFace* facesToDraw = (BlockFace*)malloc(sizeof(BlockFace));	
	getFacesToDraw(scene, &facesToDraw);

	drawBlockFaces(facesToDraw);
}

void destroyScene(Scene* scene)
{
	for (int i = 0; i < scene->worldChunkCounter; i++)
	{
		destroyChunk(scene->worldChunks[i]);
	}
}
