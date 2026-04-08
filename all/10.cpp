/*恐怖份子在一條巷子中放入了好幾顆炸彈，炸彈有分小炸彈與大炸彈，請計算這條巷子
在所有炸彈引爆後，還有那些地方是安全的。這裡假設巷子以一連串的0來表示，小x
表示小炸彈，爆炸範圍是1(會炸到左右各一個0)，大X是大炸彈，爆炸範圍是2(會炸
到左右各2個0)，請從d.txt中讀入一串由0, x, X組成的字串(最長80個字元)，
接著輸出炸彈爆炸後還剩下幾個0。 
範例輸入一： 
00x00000X0xX0000x*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream f("d.txt");
    string s;
    if (!(f >> s)) return 0;
    int n = s.length();
    vector<int> safe(n, 1);
    for (int i = 0; i < n; i++) {
        int dist = (s[i] == 'x' ? 1 : (s[i] == 'X' ? 2 : 0));
        if (dist > 0) {
            for (int j = i - dist; j <= i + dist; j++)
                if (j >= 0 && j < n) safe[j] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0' && safe[i]) ans++;

    cout << s << "\nAns=" << ans << endl;
    return 0;
}
