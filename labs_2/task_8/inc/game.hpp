#pragma once
#include <string>
#include <thread>
#include <iostream>
#include <Ship.hpp>
#include <Bullet.hpp>
#include <Object.hpp>
#include <Comet.hpp>
#include <Asteroid.hpp>
#include <cmath>

namespace mt
{

	const float pi = acos(-1);

	class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Circle* m_c;
		int m_n;
		sf::RenderWindow m_window;
		sf::Texture m_textureBackground;
		sf::Sprite m_spriteBackground;
		sf::Font m_font;
		sf::Text m_fpsText;
		Ship m_ship;
		bool isVisible = true;
		bool isTouchBorder = true;

		Asteroid asteroid;
		Comet comet;


		bool m_pressedR = false;

		std::vector<Object*> m_spaceObjects;

	public:
		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		~Game()
		{
			for (int i = 0; i < m_spaceObjects.size(); i++)
				delete m_spaceObjects[i];

			delete[] m_c;
		}

		bool Setup(int n)
		{
			m_n = n;
			// Ñîçäàíèå îêíà
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);


			// Çàãðóçêà òåêñòóðû ôîíà
			if (!m_textureBackground.loadFromFile("C:\\Users\\richa\\dev\\c-practice\\labs_2\\task_8\\assets\\plants1.jpg"))
			{
				std::cout << "Error while loading background.jpg" << std::endl;
				return false;
			}
			m_spriteBackground.setTexture(m_textureBackground);

			

			// Ñîçäàíèå êîðàáëÿ èãðîêà
			if (!m_ship.Setup(100, 100))
				return false;

			srand(time(0));

			m_c = new mt::Circle[m_n];
			for (int i = 0; i < m_n; i++)
			{
				int r = rand() % 100 + 10;
				int x = rand() % (1000 - 2 * r) + r;
				int y = rand() % (600 - 2 * r) + r;
				int v = rand() % 50 + 100;
				float alfa = rand() % 7;
				m_c[i].Setup(x, y, r, v, alfa);
			}

			m_spaceObjects.push_back(new Comet);
			m_spaceObjects[0]->Setup(400, 400, 1, 0, "assets\\comet.png", 1.0f);

			m_spaceObjects.push_back(new Asteroid);
			m_spaceObjects[1]->Setup(600, 600, 0, 1, "assets\\asteroid.png", 0.3f);

			m_spaceObjects.push_back(new Asteroid);
			m_spaceObjects[2]->Setup(700, 800, 0, 1, "assets\\asteroid.png", 0.3f);
		}

		void TouchBorder(Circle& obj)
		{
			float x = obj.X();
			float y = obj.Y();
			float r = obj.R();

			//std::cout << x << " " << y << std::endl;

			if (isTouchBorder)
			{
				isTouchBorder = false;

				if (x + r >= m_width || x - r <= 0)
				{
					obj.Alfa(pi - obj.Alfa());
				}

				if (y + r >= m_height || y - r <= 0)
				{
					obj.Alfa(2 * pi - obj.Alfa());
				}

			}
			else
			{
				if (x + r + 20 <= m_width || x - r - 20 >= 0)
				{
					isTouchBorder = true;
				}

				if (y + r + 20 <= m_height || y - r - 20 >= 0)
				{
					isTouchBorder = true;
				}
			}

		}

		void Collision(int i)
		{
			Circle& c = m_c[i];
			float dist = sqrt(pow(m_ship.X() - c.X(), 2) + pow(m_ship.Y() - c.Y(), 2));
			if (m_ship.R() + c.R() >= dist)
			{
				std::cout << "Collision " << m_ship.V() << std::endl;
				isVisible = false;
			}
		}

		void LifeCycle()
		{
			sf::Clock clock;


			while (m_window.isOpen())
			{
				// Îáðàáîòêà ñîáûòèé
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();				
				}

				// Îáðàáîòêà êëàâèàòóðû TODO
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					m_ship.setVelocity(0.1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					m_ship.setVelocity(-0.1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					m_ship.Rotate(-0.05);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					m_ship.Rotate(0.05);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (!m_ship.BulletAvailable())
						m_ship.Attack();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					if (!m_pressedR)
					{
						m_pressedR = true;
						comet.Attack();
					}
				}
				else
					m_pressedR = false;

				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();
	

				for (int i = 0; i < m_n; i++)
				{
					float x = m_c[i].X();
					float y = m_c[i].Y();
					float r = m_c[i].R();
					float v = m_c[i].V();
					float alfa = m_c[i].Alfa();

					float x_s = x + v * cos(alfa) * dt;
					float y_s = y + v * sin(alfa) * dt;


					bool collision = false;
					if (x_s + r >= m_width)
					{
						m_c[i].Alfa(pi - m_c[i].Alfa());
						m_c[i].X(m_width - r);
						collision = true;
					}

					if (x_s - r <= 0)
					{
						m_c[i].Alfa(pi - m_c[i].Alfa());
						m_c[i].X(r);
						collision = true;
					}

					if (y_s + r >= m_height)
					{
						m_c[i].Alfa(2 * pi - m_c[i].Alfa());
						m_c[i].Y(m_height - r);
						collision = true;
					}

					if (y_s - r <= 0)
					{
						m_c[i].Alfa(2 * pi - m_c[i].Alfa());
						m_c[i].Y(r);
						collision = true;
					}

					if (!collision)
					{
						m_c[i].X(x_s);
						m_c[i].Y(y_s);
					}
				}

				//for (int i = 0; i < m_n; i++)
				//	m_c[i].Move(dt);

				//for (int i = 0; i < m_n; i++)
				//	Collision(i);

				// Ïåðåìåùåíèå êîðàáëÿ
				m_ship.Move(dt);


				for (int i = 0; i < m_spaceObjects.size(); i++)
				{
					m_spaceObjects[i]->Move(dt);
				}

				m_fpsText.setString(std::to_string(1 / dt));

				// Îòîáðàæåíèå
				m_window.clear();
				m_window.draw(m_spriteBackground);
				m_window.draw(m_fpsText);
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_c[i].Get());

				//std::cout << m_ship.BulletAvailable() << std::endl;

				for (int i = 0; i < m_spaceObjects.size(); i++)
				{
					m_window.draw(m_spaceObjects[i]->Get());
				}

				if (m_ship.BulletAvailable())
					m_window.draw(m_ship.GetBullet());
				if (isVisible)
					m_window.draw(m_ship.Get());
				m_window.display();
			}
		}
	};

}