#include "main.h"
#include <Windows.h>

/// <summary>
/// U Properties, Linker -> Advanced -> Entry Point (default je main iako nije upisan)
/// ako se upiše neki naziv, onda compiler i linker stavljaju taj naziv metode kao entry point
/// </summary>
/// <returns>broj / int -> kao završni kod</returns>
// int MojMejn()
int main()
{
	POINT p; p.x = 11; p.y = 55;
	std::vector <POINT> * items = new std::vector<POINT> (128);
	items->push_back(p);
	items->clear();
	items->push_back(p);

	TEngine app;
    return	app.Run();	
}