#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include <time.h>
#include "AStar.h"
#include "Graph.h"
#include "Dashboard.h"


int main(int args[])
{
	srand(static_cast<unsigned int>(time(nullptr)));						// initialize random seed 

	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);

	auto graph = new Graph(application);									// Create a graph
	auto dashboard = new Dashboard();										// To show some statistics such as shortestPath, Cow state and rabbit state

	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					application->Quit();
					break;
				case SDL_KEYDOWN:

				switch (event.key.keysym.sym){

					case SDLK_0:

					break;

					default:

						break;
				}
				break;
				case SDL_MOUSEBUTTONDOWN:				
					graph->cow->OnClick(event);								// Handle mouse clicks for the cow
					break;
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));							// White color
		dashboard->Update();
		// For the background
		application->SetColor(Color(255, 255, 255, 255));					// Black color
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}



