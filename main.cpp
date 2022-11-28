#include "Bingo.h";
#include "Card.h";
#include "Slider.h";
#include <iostream>
using namespace std;

int main() {
    int choose, bingo_input, slide_input, card_input;
    while(true) {
        system("cls");
        cout << "------미니게임-----" << endl;
        cout << "1 : 빙고게임" << endl;
        cout << "2 : 퍼즐게임" << endl;
        cout << "3 : 카드게임" << endl;
        cout << "0 : 종료" << endl;
        cout << "2103 박다은" << endl;
        cin >> choose;
        if(cin.fail() || choose > 4) {
            cout << "번호를 잘못 입력하셨습니다!" << endl;
            choose = 0;
            cin.clear();
            cin.ignore(999, '\n');
        }
        system("cls");
        if(choose == 0) {
            cout << "플레이해줘서 감사합니다." << endl;
            cout << "2103 박다은" << endl;
            exit(0);
        }
        else if(choose == 1) {
            Bingo bingo;
            bingo.Render();
            while(true) {
                COORD pos = {0,0};
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                cout << "빙고 3개를 맞추세요" << endl;
                cout << endl;
                bingo.Print();
                cin >> bingo_input;
                bingo.Update(bingo_input);
                int check = bingo.Check();
                if(check == 3) {
                    break;
                }
            }
        }
        else if(choose==2) {
            Slide slide;
            slide.Render();
            while(true) {
                COORD pos = {0,0};
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                cout << "숫자를 정렬하세요" << endl;
                slide.Print();
                slide_input = _getch();
                int check = slide.Check();
                if (check == 24) {
                    break;
                }
            }
        }
        else if(choose == 3) {
            Card card;
            card.Render();
            while(true) {
                system("cls");

                cout << "카드 짝 맞추기 게임" << endl;
                cout << endl;
                card.Print();
                card_input = _getch();
                card.Update(card_input);
                int check = card.Check();
                if(check == 16) {
                    break;
                }
            }
        }
    }
    return 0;
};
