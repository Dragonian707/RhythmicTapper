#ifndef CORE_H
#define CORE_H

#include "scene.h"

class Core
{
public:
	/// @brief Constructor
	Core();
	/// @brief Destructor
	virtual ~Core();

	void Run(Scene* scene);

	bool running = true;

private:
	void SetDeltatime();
	double deltaTime;
	double lastTime;

};

#endif
