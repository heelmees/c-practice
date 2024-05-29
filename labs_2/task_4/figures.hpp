#pragma once
#include "figures.hpp"

namespace sd
{
    class Shape {
    public:
        virtual void draw(sf::RenderWindow& window) = 0;
        virtual ~Shape() {}
    };

    class Line : public Shape {
    public:
        Line(float x1, float y1, float x2, float y2) {
            m_line = sf::VertexArray(sf::Lines, 2);
            m_line[0].position = sf::Vector2f(x1, y1);
            m_line[1].position = sf::Vector2f(x2, y2);
            m_line[0].color = sf::Color::Cyan;
            m_line[1].color = sf::Color::Cyan;
        }

        void draw(sf::RenderWindow& window) override {
            window.draw(m_line);
        }

    private:
        sf::VertexArray m_line;
    };

    class Triangle : public Shape {
    public:
        Triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
            m_triangle.setPointCount(3);
            m_triangle.setPoint(0, sf::Vector2f(x1, y1));
            m_triangle.setPoint(1, sf::Vector2f(x2, y2));
            m_triangle.setPoint(2, sf::Vector2f(x3, y3));
            m_triangle.setFillColor(sf::Color::Yellow);
        }

        void draw(sf::RenderWindow& window) override {
            window.draw(m_triangle);
        }

    private:
        sf::ConvexShape m_triangle;
    };

    class Circle : public Shape {
    public:
        Circle(float x, float y, float radius) {
            m_circle.setPosition(x, y);
            m_circle.setRadius(radius);
            m_circle.setFillColor(sf::Color::Green);
        }

        void draw(sf::RenderWindow& window) override {
            window.draw(m_circle);
        }

    private:
        sf::CircleShape m_circle;
    };

    class Rectangle : public Shape {
    public:
        Rectangle(float x, float y, float width, float height) {
            m_rectangle.setPosition(x, y);
            m_rectangle.setSize(sf::Vector2f(width, height));
            m_rectangle.setFillColor(sf::Color::Red);
        }

        void draw(sf::RenderWindow& window) override {
            window.draw(m_rectangle);
        }

    private:
        sf::RectangleShape m_rectangle;
    };
}