#include <SFML/Graphics.hpp>

using namespace sf;

void main(void)
{
	// window창 생성
	RenderWindow app(VideoMode(520, 450), "BB");
	// 60프레임 1초에 60개의 그림이 있는걸로 제한
	app.setFramerateLimit(60);
	
	Texture t1, t2, t3, t4;
	t1.loadFromFile("imgaes/block01.png");
	t2.loadFromFile("imgaes/background.jpg");
	t3.loadFromFile("imgaes/bail.png");
	t4.loadFromFile("imgaes/paddle.png");


}