#include <iostream>
#include <map>
using namespace std;

//В аудитории стоят M компьютеров, на жестком диске каждого из которых имеется
//некоторое известное количество свободной памяти. Можно ли установить на них
//заданное число N программных систем, если каждая система требует для размещения не
//менее S[j](j = 1, …, N) памяти.

const int M = 5;//компьютеры
const int N = 23;//система(windows,linux)

static int k = 1;

void is_Goog(map<int, int> :: iterator j, map<int, int> :: iterator itend) {
    if (j != itend) {
        cout << j->first << " " << j->second;
        if (j->second > N) cout << " good" << endl;
        else cout << " bed" << endl;
        return is_Goog(++j, itend);
    }
    else return;
}

bool is_Shut(string s, string p, int len) {
    if (p[0] == '*') {
        if (p.length() == 1) k = 0;
        else {
            s.erase(0, 1);
            p.erase(0, 1);
            len--;
            return is_Shut(s, p, len);
        }
    }
    else if (p[0] == '?') {
        if (len == 1) k = 0;
        else {
            s.erase(0, 1);
            p.erase(0, 1);
            len--;
            return is_Shut(s, p, len);
        }
    }
    else if ((s[0] == p[0]) && (len != 1)) {
        k = 0;
        s.erase(0, 1);
        p.erase(0, 1);
        len--;
        return is_Shut(s, p, len);
    }


    if (k == 1) return false;
    else return true;
}

void zad_1() {
    map<int, int> PC = { {1, 40}, {2, 20}, {3, 45}, {4, 27}, {5, 12} };
    map<int, int> ::iterator it0 = PC.begin();
    map<int, int> ::iterator it1 = PC.end();
    is_Goog(it0, it1);
}

void zad_2() {
    string s, p;
    s = "aaasdxzc";
    p = "*???";
    int slen = s.length();
    cout << boolalpha << is_Shut(s, p, slen) << endl;
}

int main(){
    int n;
    while (true)
    {
        cout << "zad_1 (1) or zad_2 (2) ";
        cin >> n;
        if (n == 1) zad_1();
        else if (n == 2) zad_2();
        else exit(0);
    }

}