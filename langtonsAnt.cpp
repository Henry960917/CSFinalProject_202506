#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#define W 400
#define H 300
#define ants 1000

using namespace sf;
using namespace std;

int cnt = 0;
vector<vector<int>> grid(H, vector<int>(W, 0));
bool iniOk = false;
int sizeCell = 4; // pixel

struct antPosi {
    int x;
    int y;
    int dir = 0; // 初始方向上
};

antPosi ant[ants];

void antIni() {
    for (int i = 0; i < ants; i++) {
        ant[i].x = rand() % H;
        ant[i].y = rand() % W;
        ant[i].dir = rand() % 4;
    }
}

int main() {
    RenderWindow window(VideoMode(W * sizeCell, H * sizeCell), "Langton's Ant");
    window.setFramerateLimit(60);

    Texture antTexture;
    antTexture.loadFromFile("greenAnt.jpg");
    Sprite Ant(antTexture);

    RectangleShape blackCell(Vector2f(sizeCell, sizeCell));
    blackCell.setFillColor(Color::Black);

    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    while (window.isOpen()) {
        Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == Event::Closed) {
                window.close();
            }
        }

        if (!iniOk) {
            antIni();
            iniOk = true;
        }

        cnt++;
        if (cnt % 100 == 0) {
            cout << "目前步數: " << cnt << endl;
        }

        for (int i = 0; i < ants; i++) {
            int &x = ant[i].x;
            int &y = ant[i].y;
            int &d = ant[i].dir;

            if (grid[x][y] == 0) { //白
                d = (d + 1) % 4;
                grid[x][y] = 1;
            }
            else {
                d = (d + 3) % 4;
                grid[x][y] = 0;
            }

            x = (x + dx[d] + H) % H;
            y = (y + dy[d] + W) % W;
        }

        window.clear(Color::White);

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == 1) {
                    blackCell.setPosition(j * sizeCell, i * sizeCell);
                    window.draw(blackCell);
                }
            }
        }

        // 畫出所有螞蟻
        for (int i = 0; i < ants; i++) {
            Ant.setPosition(ant[i].y * sizeCell, ant[i].x * sizeCell);
            window.draw(Ant);
        }

        window.display();
    }

    return 0;
}