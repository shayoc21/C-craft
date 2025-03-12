#ifndef _SCENE
#define _SCENE

#include "chunk.h"
#include "skybox.h"

struct Scene
{
	Skybox skybox;
	Chunk** worldChunks;
	int worldChunkCounter;
};
typedef struct Scene Scene;

void initScene(Scene* scene);
void drawScene(Scene* scene);
void destroyScene(Scene* scene);

#endif

