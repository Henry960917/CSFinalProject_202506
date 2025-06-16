//#include <SFML/Graphics.hpp>
//#include <vector>
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//#define W 400
//#define H 300
//#define walkers 1
//
//using namespace sf;
//using namespace std;
//
//int cnt = 0;
//vector<vector<int>> grid(H, vector<int>(W, 0));
//bool iniOk = false;
//int sizeCell = 10; // pixel
//bool canGo = true;
//
//struct Walker {
//    int x;
//    int y;
//};
//
//Walker walker[walkers];
//
//void walkerIni() {
//    for (int i = 0; i < walkers; i++) {
//        walker[i].x = H / 2;
//        walker[i].y = W / 2;
//    }
//    grid[walker[0].x][walker[0].y] = 1; // 走過
//}
//
//int main() {
//    RenderWindow window(VideoMode(W * sizeCell, H * sizeCell), "Self Avoiding Walk");
//    window.setFramerateLimit(60);
//
//    srand(time(0));
//
//    RectangleShape blackCell(Vector2f(sizeCell, sizeCell));
//    blackCell.setFillColor(Color::Black);
//
//    RectangleShape redDot(Vector2f(sizeCell, sizeCell));
//    redDot.setFillColor(Color::Red);
//
//    int dx[] = { -1, 0, 1, 0 };
//    int dy[] = { 0, 1, 0, -1 };
//
//    while (window.isOpen()) {
//        Event ev;
//        while (window.pollEvent(ev)) {
//            if (ev.type == Event::Closed) {
//                window.close();
//            }
//        }
//
//        if (!iniOk) {
//            walkerIni();
//            iniOk = true;
//        }
//
//        if (canGo) {
//            cnt++;
//            if (cnt % 100 == 0) {
//                cout << "目前步數: " << cnt << endl;
//            }
//
//            for (int i = 0; i < walkers; i++) {
//                vector<int> possibleDir;
//
//                for (int d = 0; d < 4; d++) {
//                    int nx = walker[i].x + dx[d];
//                    int ny = walker[i].y + dy[d];
//
//                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] == 0) {
//                        possibleDir.push_back(d);
//                    }
//                }
//
//                if (!possibleDir.empty()) {
//                    int dir = possibleDir[rand() % possibleDir.size()];
//                    walker[i].x += dx[dir];
//                    walker[i].y += dy[dir];
//                    grid[walker[i].x][walker[i].y] = 1;
//                }
//                else {
//                    canGo = false; // 無路可走
//                    cout << "自避行走結束，共走了 " << cnt << " 步。" << endl;
//                }
//            }
//        }
//
//        window.clear(Color::White);
//
//        for (int i = 0; i < H; i++) {
//            for (int j = 0; j < W; j++) {
//                if (grid[i][j]) {
//                    blackCell.setPosition(j * sizeCell, i * sizeCell);
//                    window.draw(blackCell);
//                }
//            }
//        }
//
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