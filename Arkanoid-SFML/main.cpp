#include <SFML/Graphics.hpp>

using namespace sf;

void main(void)
{
	// windowâ ����
	RenderWindow app(VideoMode(520, 450), "BB");
	// 60������ 1�ʿ� 60���� �׸��� �ִ°ɷ� ����
	app.setFramerateLimit(60);
	
	Texture t1, t2, t3, t4;
	t1.loadFromFile("imgaes/block01.png");
	t2.loadFromFile("imgaes/background.jpg");
	t3.loadFromFile("imgaes/bail.png");
	t4.loadFromFile("imgaes/paddle.png");


}