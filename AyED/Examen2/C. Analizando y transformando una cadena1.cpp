#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main(){

    string texto;
    getline(cin, texto);

    int longitud = texto.length();
    int espacios = 0;

    for (char &c : texto){
        if (c == ' '){
            espacios++;
        }else if (isupper(c)){
            c = tolower(c);
        }else if (islower(c)){
            c = toupper(c);
        }else if (isdigit(c)){
            if (c != '9'){
                c = ((c - '0' + 1) % 10) + '0';
            }
        }
    }


    cout << longitud << " " << espacios << endl;
    cout << texto << endl;

    return 0;
}