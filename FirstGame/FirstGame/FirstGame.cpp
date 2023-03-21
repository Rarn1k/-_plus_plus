#include <SFML/Graphics.hpp>
#include "view.h"
#include <iostream>
#include <sstream>
#include "iostream"
#include "level.h"
#include <vector>
#include <list>
#include "LifeBar.h"
using namespace sf;
////////////////////////////////////Общий класс-родитель//////////////////////////
class Entity {
public:
	std::vector<Object> obj;
	float dx, dy, x, y, speed, moveTimer;
	int w, h, health;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	String name;
	Entity(Image& image, String Name, float X, float Y, int W, int H)
	{
		x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0; health = 100;
		life = true; onGround = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}
	FloatRect getRect() 
	{
		return FloatRect(x, y, w, h);
	}
	virtual void update(float time) = 0;//все потомки переопределяют эту ф-цию
};

////////////////////////////////////////////////////КЛАСС ИГРОКА////////////////////////
class Player :public Entity
{
public:
	enum { left, right, up, down, jump, stay } state;
	int playerScore, healthP = 100;
	bool isMove = false;
	float currentP = 0;
	Player(Image& image, String Name, Level& lev, float X, float Y, int W, int H) :Entity(image, Name, X, Y, W, H)
	{
		playerScore = 0; state = stay; obj = lev.GetAllObjects();
	}
	void control(float time)
	{
		if (Keyboard::isKeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right))
			{
				state = left; speed = 0.2;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::Left))
			{
				state = right; speed = 0.2;
			}
			if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround))
			{
				state = jump; dy = -0.7; onGround = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				state = down;
			}
		}
	}
	void checkCollisionWithMap(float Dx, float Dy)
	{
		for (int i = 0; i < obj.size(); i++)
			if (getRect().intersects(obj[i].rect))
			{
				if (obj[i].name == "Solid")
				{
					if (Dy > 0) { y = obj[i].rect.top - h;  dy = 0; onGround = true; }
					if (Dy < 0) { y = obj[i].rect.top + obj[i].rect.height;   dy = 0; }
					if (Dx > 0) { x = obj[i].rect.left - w; }
					if (Dx < 0) { x = obj[i].rect.left + obj[i].rect.width; }
				}
			}
	}
	void update(float time)
	{
		if (healthP <= 0) 
		  life = false;
		setPlayerCoordinateForView(x, y);
		if (life)
		{
			control(time);
			switch (state)
			{
			case right:	dx = speed; break;
			case left:dx = -speed; break;
			case up: break;
			case down: dx = 0; break;
			case stay: break;
			}
			if (dx < 0)
			{
				currentP += 0.01 * time;
				if (currentP > 8) currentP -= 7;
				if (currentP > 1 || currentP < 0)
					sprite.setTextureRect(IntRect(136 * int(currentP) - 40, 12, -100, 77));
				else
					sprite.setTextureRect(IntRect(235, 12, -100, 77));
			}
			if (dx > 0)
			{
				currentP += 0.01 * time;
				if (currentP > 8) currentP -= 8;
				sprite.setTextureRect(IntRect(136 * int(currentP) + 40, 12, 100, 77));
			}
			if (dx == 0)
			{
				currentP += 0.01 * time;
				if (currentP > 6) currentP -= 6;
				sprite.setTextureRect(IntRect(136 * int(currentP) + 40, 108 , 100, 180));
			}
			x += dx * time;
			checkCollisionWithMap(dx, 0);
			y += dy * time;
			checkCollisionWithMap(0, dy);
			sprite.setPosition(x + w / 2, y + h / 2);

		}
		else
		{
			currentP += 0.005 * time;
			if (currentP > 6) currentP = 5;
			texture.loadFromFile("Images/Knight7.png");
			sprite.setTextureRect(IntRect(136 * int(currentP) + 40, 12, 100, 77));
		}
		dy = dy + 0.0015 * time;
		if (!isMove)
			speed = 0;
	}
};
////////////////////////////////////////////////////КЛАСС ВРАГА////////////////////////
class Enemy : public Entity
{
public:
	Enemy(Image& image, String Name, Level& lvl, float X, float Y, int W, int H) :Entity(image, Name, X, Y, W, H)
	{
		obj = lvl.GetObjects("Solid");//инициализируем, получаем нужные объекты для взаимодействия врага с картой
		if (name == "EasyEnemy") {
			sprite.setTextureRect(IntRect(0, 0, w, h));
			sprite.scale(-1, 1);
			dx = 0.1;
		}
	}
	float currentP = 0;
	float currentE = 0;
	void checkCollisionWithMap(float Dx, float Dy)
	{
		for (int i = 0; i < obj.size(); i++)
			if (getRect().intersects(obj[i].rect))
			{
				if (obj[i].name == "Solid")//если встретили препятствие
				{
					if (Dy > 0) { y = obj[i].rect.top - h;  dy = 0; onGround = true; }
					if (Dy < 0) { y = obj[i].rect.top + obj[i].rect.height;   dy = 0; }
					if (Dx > 0) { x = obj[i].rect.left - w;  dx = -0.1; sprite.scale(-1, 1); }
					if (Dx < 0) { x = obj[i].rect.left + obj[i].rect.width; dx = 0.1; sprite.scale(-1, 1); }
				}
			}
	}
	void update(float time)
	{
		if (name == "EasyEnemy")
		{
			currentP += 0.01 * time;
			currentE += 0.01 * time;
			if (currentP > 5) currentP -= 5;
			if (currentE > 3) currentE -= 3;
			sprite.setTextureRect(IntRect(84 * int(currentP), 75 * int(currentE), 84, 75));

			checkCollisionWithMap(dx, 0);
			x += dx * time;
			sprite.setPosition(x + w / 2, y + h / 2);
			if (health <= 0)
				life = false;
		}
	}
};
////////////////////////////////////////////////////КЛАСС КАМНЯ////////////////////////
class Stone : public Entity
{
public:
	Stone(Image& image, String Name, Level& lvl, float X, float Y, int W, int H) :Entity(image, Name, X, Y, W, H)
	{
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	void update(float time)
	{
		sprite.setPosition(x + w / 2, y + h / 2);
		if (health <= 0)
			life = false;
	}
};
bool game()
{
	RenderWindow window(VideoMode(1280, 720), "Knight");
	view.reset(FloatRect(0, 0, 1280, 720));

	Font font;//шрифт 
	font.loadFromFile("20016.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 40);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях)
	Text textWin("", font, 100);
	Text textLose("", font, 100);

	Level lvl;
	lvl.LoadFromFile("map.tmx");
	Image heroImage;
	heroImage.loadFromFile("Images/Knight6.png");
	Image easyEnemyImage;
	easyEnemyImage.loadFromFile("Images/em.png");
	Image stoneImage;
	stoneImage.loadFromFile("Images/Stone.png");
	Sprite sprite;
	std::list<Entity*>  entities;
	std::list<Entity*>::iterator it;
	std::vector<Object> e = lvl.GetObjects("EasyEnemy");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new Enemy(easyEnemyImage, "EasyEnemy", lvl, e[i].rect.left, e[i].rect.top, 84, 75));
	std::vector<Object> sto = lvl.GetObjects("Stone");
	for (int i = 0; i < sto.size(); i++)
		entities.push_back(new Stone(stoneImage, "Stone", lvl, sto[i].rect.left, sto[i].rect.top, 33, 33));
	Object player = lvl.GetObject("Player");
	Player p(heroImage, "Player1", lvl, player.rect.left, player.rect.top, 60, 65);
	Clock clock;
	LifeBar lifeBarPlayer;//экземпляр класса полоски здоровья
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		for (it = entities.begin(); it != entities.end();)//говорим что проходимся от начала до конца
		{
			Entity* b = *it;//для удобства, чтобы не писать (*it)->
			if (p.playerScore <= 2 || b->name == "Stone")
			b->update(time);//вызываем ф-цию update для всех объектов (по сути для тех, кто жив)
			if (b->life == false) { it = entities.erase(it); delete b; }// если этот объект мертв, то удаляем его
			else it++;//и идем итератором к следующему объекту, так делаем со всеми объектами списка
		}
		if (p.playerScore <= 2)
		{
			p.update(time);
			bool damage = false;
			if (p.life)
			{
				for (it = entities.begin(); it != entities.end(); it++)//проходимся по эл-там списка
				{
					if ((*it)->getRect().intersects(p.getRect()))//если прямоугольник спрайта объекта пересекается с игроком
					{
						if ((*it)->name == "EasyEnemy") //и при этом имя объекта EasyEnemy,то..
						{
							if ((p.dy > 0) && (p.onGround == false))//если прыгнули на врага,то даем врагу скорость 0, отпрыгиваем от него чуть вверх, даем ему здоровье 0
							{
								(*it)->dx = 0;
								p.dy = -0.4;
								(*it)->health = 0;
							}
							else
							{
								if ((*it)->dx > 0 && p.dx > 0)//если враг идет вправо и мы идём вправо
								{
									(*it)->x = p.x + (*it)->w; //отталкиваем его от игрока вправо (впритык)
								}
								if ((*it)->dx > 0 && (p.dx < 0 || p.dx == 0))//если враг идет вправо и мы идём ему навстречу или стоим
								{
									(*it)->x = p.x - (*it)->w; //отталкиваем его от игрока влево (впритык)
									(*it)->dx = -(*it)->dx;
									(*it)->sprite.scale(-1, 1);
								}
								if ((*it)->dx < 0 && p.dx < 0)//если враг идет влево и мы идём влево
								{
									(*it)->x = p.x - p.w; //аналогично - отталкиваем влево
								}
								if ((*it)->dx < 0 && (p.dx > 0 || p.dx == 0))//если враг идет влево и мы идём ему навстречу или стоим
								{
									(*it)->x = p.x + p.w; //аналогично - отталкиваем вправо
									(*it)->dx = -(*it)->dx;
									(*it)->sprite.scale(-1, 1);
								}
								damage = true;	//иначе враг подошел к нам сбоку и нанес урон
							}
						}
						if ((*it)->name == "Stone")
						{
							p.playerScore++;
							(*it)->health = 0;
						}
					}
				}
				if (damage)
					p.healthP -= 15;
			}
		}
		lifeBarPlayer.update(p.healthP);//значение здоровья

		if (Keyboard::isKeyPressed(Keyboard::Tab)) { return true; }//если таб, то перезагружаем игру
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; }//если эскейп, то выходим из игры

		window.setView(view);
		lvl.Draw(window);
		for (it = entities.begin(); it != entities.end(); it++)
		{
			window.draw((*it)->sprite);
		}
		std::ostringstream playerScoreString;
		playerScoreString << p.playerScore;		//занесли в нее число очков, то есть формируем строку
		text.setString("Collected stones: " + playerScoreString.str() + "/3");//задаем строку тексту и вызываем сформированную выше строку методом .str() 
		text.setPosition(view.getCenter().x - 620, view.getCenter().y - 300);//задаем позицию текста, отступая от центра камеры
		window.draw(text);//рисую этот текст
		window.draw(p.sprite);
		if (p.playerScore >= 3)
		{
			p.sprite.setTextureRect(IntRect(40, 108, 100, 180));
			textWin.setString("You won");//задаем строку тексту и вызываем сформированную выше строку методом .str() 
			textWin.setPosition(view.getCenter().x - 200, view.getCenter().y - 50);//задаем позицию текста, отступая от центра камеры
			window.draw(textWin);//рисую этот текст
		}
		if (!p.life)
		{
			textLose.setString("Game Over");//задаем строку тексту и вызываем сформированную выше строку методом .str() 
			textLose.setPosition(view.getCenter().x - 200, view.getCenter().y - 50);//задаем позицию текста, отступая от центра камеры
			window.draw(textLose);//рисую этот текст
		}
		lifeBarPlayer.draw(window);//рисуем полоску здоровья
		window.display();
	}
}
void gameRunning()
{
	if (game())
		gameRunning();
}
int main()
{
	gameRunning();
	return 0;
}

