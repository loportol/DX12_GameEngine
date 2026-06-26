#include "Application.h"

using namespace std;
int main() {

	using namespace Engine;

	Application engineApp;

	if (engineApp.Initialize()) {
		//Run it

		while (engineApp.isRunning()) {
			
			//While the application is running, update it
			engineApp.Update();
		}

		//Application is turned off by setting isRunning flag to false
	}
}