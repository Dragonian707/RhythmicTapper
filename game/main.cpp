#include "raylib.h"

#include "framework/resourcemanager.h"
#include "framework/core.h"
#include "settings.h"

#include "scenemanager.h"

int main()
{
	SetConfigFlags(FLAG_FULLSCREEN_MODE);
	InitWindow(SCRWIDTH, SCRHEIGHT, WINDOWNAME);

	ResourceManager* rs = ResourceManager::Instance();
	SceneManager* s = SceneManager::Instance();
	Core core;

    while (core.running) //while (core.Run(game)) { ; }
    {
		core.Run(s->GetActiveScene(), BACKGROUND);
    }

	rs->Cleanup();
    
	CloseWindow();
    
	return 0;
}
