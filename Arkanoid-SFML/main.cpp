#include <SFML/Graphics.hpp>
#define WIDTH  520
#define HEIGHT  450

using namespace sf;

bool isCollide(Sprite s1, Sprite s2);

void main(void)
{
	// windowâ ����
	RenderWindow app(VideoMode(WIDTH, HEIGHT), "BB");
	app.setFramerateLimit(60);

	Texture t1, t2, t3, t4;
	t1.loadFromFile("images/block01.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/ball.png");
	t4.loadFromFile("images/paddle.png");

	Sprite sBackground(t2), sBall(t3), sPaddle(t4);
	sPaddle.setPosition(300, 400);
	sBall.setPosition(300, 300);

	Sprite block[200];
	int n = 0;
	for (int x = 1; x <= 10; x++)
	{
		for (int y = 0; y <= 10; y++)
		{
			block[n].setTexture(t1);
			block[n].setPosition(x * 43, y * 20);
			n++;
		}
	}

	// ���� -> �̵��ϴ� �ӵ����� + ��������
	float dx = 5.0f, dy = 6.0f;

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}
		// �� �����̱�
		sBall.move(dx, 0);
		for (int i = 0; i < n; i++)
		{
			if (isCollide(sBall, block[i])) // ���̶� ���̶� �浹�Ѵٸ�
			{
				dx = -dx;
				// ������ �þ߿��� ������� ��
				block[i].setPosition(-300, 0);
			}
		}

		sBall.move(0, dy);
		for (int i = 0; i < n; i++)
		{
			if (isCollide(sBall, block[i])) // ���̶� ���̶� �浹�Ѵٸ�
			{
				dy = -dy;
				// ������ �þ߿��� ������� ��
				block[i].setPosition(-300, 0);
			}
		}

		// ���� ��ġ(��ǥ)
		Vector2f b = sBall.getPosition();

		// ȭ�� �ٱ��� �׵θ��� �浹�ϴ� ���
		if (b.x < 0 || b.x> WIDTH)
			dx = -dx;
		if (b.y < 0 || b.y > HEIGHT)
			dy = -dy;

		// Ű���忡 ���� paddle�� ������
		if (Keyboard::isKeyPressed(Keyboard::Right)) //������ Ű ������ �����̱�
			sPaddle.move(5.0f, 0.0f);

		if (Keyboard::isKeyPressed(Keyboard::Left)) //������ Ű ������ �����̱�
			sPaddle.move(-5.0f, 0.0f);

		if (isCollide(sPaddle, sBall))
		{
			dy = -dy;
		}

		app.clear();
		app.draw(sBackground);
		app.draw(sBall);
		app.draw(sPaddle);
		for (int i = 0; i < n; i++)
			app.draw(block[i]);

		app.display();
	}

}

bool isCollide(Sprite s1, Sprite s2)
{
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
	// �׸��� �Ϲ������� �� �簢��(���� �簢��) intersect(�������� �ǹ�) 
	// �� ���̿� �������� �����Ѵ��� ����� �ڵ�
}