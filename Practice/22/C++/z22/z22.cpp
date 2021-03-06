#include<iostream>
#include<vector>
#include<string>

using namespace std;
string maze[25] = {
   "####B######################",
   "# #       #   #      #    #",
   "# # # ###### #### ####### #",
   "# # # #       #   #       #",
   "#   # # ######### # ##### #",
   "# # # #   #       #     # #",
   "### ### ### ############# #",
   "# #   #     # #           #",
   "# # #   ####### ###########",
   "# # # #       # #         C",
   "# # ##### ### # # ####### #",
   "# # #     ### # #       # #",
   "#   ##### ### # ######### #",
   "######### ### #           #",
   "# ####### ### #############",
   "A           #   ###   #   #",
   "# ############# ### # # # #",
   "# ###       # # ### # # # #",
   "# ######### # # ### # # # F",
   "#       ### # #     # # # #",
   "# ######### # ##### # # # #",
   "# #######   #       #   # #",
   "# ####### ######### #######",
   "#         #########       #",
   "#######E############D######" };
int m = 0;
void cont(int x1, int y1, int q) {
    if (!(x1 > 27 || y1 > 24 || x1 < 0 || y1 < 0)) {
        if ((maze[y1][x1] >= 'A') && (maze[y1][x1] <= 'Z')) {
            cout << maze[y1][x1] << " ";
            m = 1;
            return;
        }
        else {
            if (!(x1 >= 27 || y1 >= 24 || x1 <= 0 || y1 <= 0)) {
                if (maze[y1][x1] == '#') { return; }
                else {
                    if (maze[y1 + 1][x1] != '#' && q != 2) {
                        cont(x1, y1 + 1, 1);

                    }
                    if (maze[y1 - 1][x1] != '#' && q != 1) {
                        cont(x1, y1 - 1, 2);

                    }
                    if (maze[y1][x1 + 1] != '#' && q != 4) {
                        cont(x1 + 1, y1, 3);

                    }
                    if (maze[y1][x1 - 1] != '#' && q != 3) {
                        cont(x1 - 1, y1, 4);

                    }
                }
            }
        }
    }
    else {
        return;
    }
}

int main() {
    int x, y;
    setlocale(0, "");
    cin >> x >> y;
    if (x > 27 || y > 24 || x < 0 || y < 0) {
        cout << "Не верные координаты";
        m = 1;
    }
    else {
        if (maze[y][x] == '#') {
            cout << "Не верные координаты";
            m = 1;
        }
        else cont(x, y, 0);
    }
    if (m == 0) cout << "Выхода нет";
}