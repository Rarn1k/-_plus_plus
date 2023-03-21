#include <SFML/Graphics.hpp>
#pragma once
using namespace sf;

class LifeBar
{
public:
	Image image;
	Texture t;
	Sprite s, b;
	int max;
	bool min = false;
	RectangleShape bar, bl;

	LifeBar()
	{
		image.loadFromFile("Images/life.png");
		t.loadFromImage(image);
		s.setTexture(t);
		s.setTextureRect(IntRect(0, 0, 201, 55));

		bar.setFillColor(Color(255, 0, 0));
		bar.setSize(Vector2f(156, 36));
		bl.setFillColor(Color(0, 0, 0));
		max = 156;
	}

	void update(int k)// k-текущее здоровье
	{
		if (k > 0 && k < 100)
			bl.setSize(Vector2f(-(max - (max * k / 100)), 36));
		if (k < 0 && !min)
		{
			bl.setSize(Vector2f(-(max - (max * k / 100)), 36));
			min = true;
		}

	}

	void draw(RenderWindow& window)
	{
		Vector2f center = window.getView().getCenter();
		Vector2f size = window.getView().getSize();

		s.setPosition(center.x - size.x / 2 + 10, center.y - size.y / 2 + 10);//позиция на экране
		bar.setPosition(center.x - size.x / 2 + 51, center.y - size.y / 2 + 20);
		bl.setPosition(center.x - size.x / 2 + 207, center.y - size.y / 2 + 20);
		window.draw(bar);//сначала рисуем иконку сердца и рамку уровня здоровья
		window.draw(s);//поверх неё уже красный прямоугольник, который заполняет эту рамку
		window.draw(bl);//поверх красного уже черный прямоугольник, он как бы покрывает его
	}

};