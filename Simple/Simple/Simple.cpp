
#include <iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
struct S_Point
{
    float x, y;
    S_Point(float x, float y) : x(x), y(y){}
};
int main()
{
    RenderWindow window(VideoMode(1000, 500), "Game");
    S_Point player_1_pos(1, 1);
    S_Point player_2_pos(975, 200);
    S_Point ball_pos(400, 200);

    while (window.isOpen())
    {
        Event event;
        window.clear(Color(0, 0, 0, 250));
        RectangleShape player_1(Vector2f(20.f, 60.f));
        RectangleShape player_2(Vector2f(20.f, 60.f));
        RectangleShape ball(Vector2f(20.f, 20.f));
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::W) {
                    player_1_pos.x--;
                }
                if (event.key.code == Keyboard::S) {
                    player_1_pos.y++;
                }
            }
        }
        player_1.setFillColor(Color(255, 255, 255, 250));
        player_2.setFillColor(Color(255, 255, 255, 250));
        
        player_1.move(player_1_pos.x, player_1_pos.y);
        player_2.move(player_2_pos.x, player_2_pos.y);
        ball.move(ball_pos.x, ball_pos.y);
        window.draw(player_1);
        window.draw(player_2);
        window.draw(ball);
        window.display();
    }
}

