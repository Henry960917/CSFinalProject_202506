#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define W 400
#define H 300
#define walkers 1

using namespace sf;
using namespace std;

int cnt = 0;
vector<vector<int>> grid(H, vector<int>(W, 0));
bool iniOk = false;
int sizeCell = 4; // pixel

struct Walker {
   int x;
   int y;
};

Walker walker[walkers];

void walkerIni() {
   for (int i = 0; i < walkers; i++) {
       walker[i].x = H / 2;
       walker[i].y = W / 2;
   }
   grid[walker[0].x][walker[0].y] = 1; // ¨«¹L
}

int main() {
   RenderWindow window(VideoMode(W * sizeCell, H * sizeCell), "Random Walk");
   window.setFramerateLimit(60);

   srand(time(0));

   RectangleShape blackCell(Vector2f(sizeCell, sizeCell));
   blackCell.setFillColor(Color::Black);

   RectangleShape redDot(Vector2f(sizeCell, sizeCell));
   redDot.setFillColor(Color::Red);

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
           walkerIni();
           iniOk = true;
       }

       cnt++;
       if (cnt % 100 == 0) {
           cout << "¥Ø«e¨B¼Æ: " << cnt << endl;
       }

       for (int i = 0; i < walkers; i++) {
           int dir = rand() % 4;

           walker[i].x = (walker[i].x + dx[dir] + H) % H;
           walker[i].y = (walker[i].y + dy[dir] + W) % W;

           grid[walker[i].x][walker[i].y] = 1;
       }

       window.clear(Color::White);

       for (int i = 0; i < H; i++) {
           for (int j = 0; j < W; j++) {
               if (grid[i][j]) {
                   blackCell.setPosition(j * sizeCell, i * sizeCell);
                   window.draw(blackCell);
               }
           }
       }

//        for (int i = 0; i < walkers; i++) {
//            redDot.setPosition(walker[i].y * sizeCell, walker[i].x * sizeCell);
//            window.draw(redDot);
//        }
//
//        window.display();
//    }
//
//    return 0;
//}
