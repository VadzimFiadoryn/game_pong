#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <stdio.h>  
#include <math.h> 
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
using namespace std;

bool IsKeyDown(int virtualKeyCode)
{
	short keyState = GetAsyncKeyState(virtualKeyCode);
	return ((keyState & 0x8000) > 0);
}
int bol_sped_x = 0;
int bol_sped_y = 10;
class Star
{
	sf::CircleShape *p1 = new sf::CircleShape;
	sf::CircleShape *p2 = new sf::CircleShape;
public:
	Star(const int x = 25, const int y = 3)
	{
		sf::CircleShape star1(x, y);
		sf::CircleShape star2(x, y);
		star2.move((50), (50));
		star2.rotate(180);
		star2.setFillColor(sf::Color::Red);
		star1.setFillColor(sf::Color::Red);
		*p1 = star1;
		*p2 = star2;
	}
	sf::CircleShape  get_Star1()
	{
		return *p1;
	}
	sf::CircleShape  get_Star2()
	{
		return *p2;
	}
	void move_Star(int moveX, int moveY)
	{
		p1->move((moveX), (moveY));
		p2->move((moveX), (moveY));
	}
	void set_Star_color_blak()
	{
		p1->setFillColor(sf::Color::Black);
		p2->setFillColor(sf::Color::Black);
	}
};
/////////////////////////////
int main()
{
	int windowCol = 800; int windowRow = 600;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test STAR");
	sf::CircleShape shape(15);
	shape.setFillColor(sf::Color::Blue);
	shape.move((400), (400));
	sf::RectangleShape rectangle(sf::Vector2f(100, 25));
	rectangle.setFillColor(sf::Color::Green);
	rectangle.move((400), (560));
	//////////////////////////// 
	const int star_shtuk = 30;
	Star *ptr_Star = new Star[star_shtuk];
	Star mass[star_shtuk];
	for (int i = 0; i < 10; i++)
	{			
		mass[i].move_Star((i + 1) * 60, 50);
	}
	for (int i = 0; i < 10; i++)
	{
		mass[i + 10].move_Star((i + 1) * 60, 100);
	}
	for (int i = 0; i < 10; i++)
	{
		mass[i + 20].move_Star((i + 1) * 60, 150);
	}
	////////////////////////// 
	sf::CircleShape star1(25, 3);
	sf::CircleShape star2(25, 3);
	star2.move((50), (50));
	star2.rotate(180);
	star2.setFillColor(sf::Color::Black);
	star1.setFillColor(sf::Color::Black);
	star1.move((150), (150));
	star2.move((150), (150));
	sf::CircleShape star3(25, 3);
	sf::CircleShape star4(25, 3);
	star4.move((50), (50));
	star4.rotate(180);
	star3.setFillColor(sf::Color::Red);
	star4.setFillColor(sf::Color::Red);
	star3.move((300), (150));
	star4.move((300), (150));
	///////////////////////////////
	sf::RectangleShape line1(sf::Vector2f(800, 5));
	line1.move((0), (0));
	sf::RectangleShape line2(sf::Vector2f(800, 5));
	line2.move((0), (595));
	sf::RectangleShape line3(sf::Vector2f(600, 5));
	line3.rotate(90);
	line3.move((5), (5));
	sf::RectangleShape line4(sf::Vector2f(600, 5));
	line4.rotate(90);
	line4.move((800), (5));
	while (window.isOpen())
	{
		sf::Event event;
		while (rand() % 7 == 3)
		{
			shape.move((bol_sped_x), (bol_sped_y));
			if (shape.getPosition().y > 530 && rectangle.getPosition().x   < shape.getPosition().x + 25 && rectangle.getPosition().x + 100 > shape.getPosition().x)
			{
				cout << shape.getPosition().x << endl;
				cout << shape.getPosition().y << endl;
				bol_sped_y = -2;
				bol_sped_x = rand() % 3 - 3;
				if (IsKeyDown(VK_LEFT))
				{
					bol_sped_x += -2;					
				}
				if (IsKeyDown(VK_RIGHT))
				{
					bol_sped_x += 2;					
				}
			}
			if (shape.getPosition().x + 25 > 795 || shape.getPosition().x < 5)
			{
				bol_sped_x = -bol_sped_x;
			}
			if (shape.getPosition().y > 550)
			{
				shape.setPosition(sf::Vector2f((400), (10)));
				bol_sped_x = 0;
				bol_sped_y = 2;
			}
			if (shape.getPosition().y < 5)
			{
				bol_sped_y = 2;
			}
			if (IsKeyDown(VK_LEFT) && rectangle.getPosition().x > 5)
			{
				rectangle.move((-10), (-0));
			}
			if (IsKeyDown(VK_RIGHT) && rectangle.getPosition().x + 100 < 795)
			{
				rectangle.move(10, (0));
			}
			/////////////////////////////////////////////// 
			if (abs(star1.getPosition().x - shape.getPosition().x) < 25 && abs(star2.getPosition().y - shape.getPosition().y) < 25)
			{
				star1.setFillColor(sf::Color::Black);
				star2.setFillColor(sf::Color::Black);
				cout << "star1.getPosition().x ==" << star1.getPosition().x << endl << "hape.getPosition().x)" << shape.getPosition().x << endl
					<< "abs(star2.getPosition().y ==" << star2.getPosition().y << endl << "shape.getPosition().y" << shape.getPosition().y << endl;
			}
			if (abs(star3.getPosition().x - shape.getPosition().x) < 25 && abs(star4.getPosition().y - shape.getPosition().y) < 25)
			{
				star3.setFillColor(sf::Color::Black);
				star4.setFillColor(sf::Color::Black);
				cout << "star1.getPosition().x ==" << star3.getPosition().x << endl << "hape.getPosition().x)" << shape.getPosition().x << endl
					<< "abs(star2.getPosition().y ==" << star4.getPosition().y << endl << "shape.getPosition().y" << shape.getPosition().y << endl;
			}
			/////////////////////////////////////////////// 
			for (int i = 0; i < star_shtuk; i++)
			{
				if ((abs(mass[i].get_Star1().getPosition().x - shape.getPosition().x) < 30 && abs(mass[i].get_Star2().getPosition().y - shape.getPosition().y) < 30))
				{
					mass[i].get_Star1().setFillColor(sf::Color::Black);
					mass[i].get_Star2().setFillColor(sf::Color::Black);
					mass[i].set_Star_color_blak();
					cout << "wow" << endl;
				}
			}
		}
		window.clear();
		window.draw(rectangle);
		window.draw(line1);
		window.draw(line2);
		window.draw(line3);
		window.draw(line4);
		for (int i = 0; i < star_shtuk; i++)
		{			
			window.draw(mass[i].get_Star1());			
			window.draw(mass[i].get_Star2());
		}
		window.draw(shape);
		window.display();
		shape.getPosition();
	}
	return 0;
}

