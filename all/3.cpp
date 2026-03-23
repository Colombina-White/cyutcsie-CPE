#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("b.txt");
    string s;
    if (!getline(file, s)) return 0;
    file.close();

    cout << s << endl;

    size_t a_pos;
    while ((a_pos = s.find_last_of("Aa")) != string::npos) {
        size_t l_pos = s.find_first_of("Ll", a_pos);
        
        if (l_pos != string::npos) {
            s.erase(a_pos, l_pos - a_pos + 1);
        } else {
            break; 
        }
    }

    cout << "Ans=" << s << endl;
    return 0;
}
