#include <SFML/Graphics.hpp>
using namespace sf;

View view;

void setPlayerCoordinateForView(float x, float y)//не даёт камере заходить за края карты
{ 
	float tempX = x; float tempY = y;

	if (x > 1730) tempX = 1730;
	if (x < 640) tempX = 640;
	if (y < 380) tempY = 380;
	if (y > 500) tempY = 500;

	view.setCenter(tempX, tempY); 
}