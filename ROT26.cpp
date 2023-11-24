#include <iostream>
#include <ctype.h>

using namespace std;

void encriptar();
void desemcriptar();

int main(){

    int eleccion;

    cout << "Dime si quieres encriptar o desencriptar una palabra. 1 - Encriptar 2 - Desemcriptar" << endl;
    cin >> eleccion;

    if(eleccion == 1){
        encriptar();
    }else if(eleccion == 2){
        desemcriptar();
    }

    return 0;
}

void encriptar(){

    string palabra;

    cout << "Dime una palabra que quieres encriptar" << endl;
    cin.ignore();
    getline(cin,palabra);

    
    int n;

    do{

        cout << "Dime cuantas veces quieres que rote la palabra" << endl;
        cin >> n;

    } while (n < 0 || n > 25);

    string original = palabra;

    for(int i = 0; i < palabra.length(); i++){

        if(palabra[i] != 32){

            if(palabra[i] + n < 91){

                palabra[i] += + n;

            }else if(palabra[i] + n > 90 && palabra[i] < 91){

                int m;
                m = (palabra[i] + n) - 90;
                palabra[i] = 65 + (m - 1);

            }else if(palabra[i] + n > 96 && palabra[i] + n < 123){

                palabra[i] += + n;

            }else if(palabra[i] + n > 122){

                int m;
                m = (palabra[i] + n) - 122;
                palabra[i] = 97 + (m - 1);

            }
        }    
    }

    cout << "Palabra desencriptada: " << original << endl;
    cout << "Palabra encriptada: " << palabra << endl;



}

void desemcriptar(){

    string palabra;

    cout << "Dime la palabra que quieres desencriptar" << endl;
    cin.ignore();
    getline(cin,palabra);

    int n;

    do{

        cout << "Dime el valor de cambio de posiciones (ROTN): " << endl;
        cin >> n;

    } while (n < 0 || n > 25);

    string original = palabra;

    for(int i = 0; i < palabra.length(); i++){

        if(palabra[i] != 32){
            
            if(palabra[i] - n < 65){

                int m;
                m = 65 - (palabra[i] - n);
                palabra[i] = 90 - (m - 1); 

            }else if(palabra[i] - n > 64 && palabra[i] - n < 91 && palabra[i] < 91){

                palabra[i] += - n;

            }else if(palabra[i] - n < 97 && palabra[i] > 96){

                int m;
                m = 97 - (palabra[i] - n);
                palabra[i] = 122 - (m - 1);

            }else if(palabra[i] - n > 96 && palabra[i] - n < 123){

                palabra[i] += - n;

            }
        }
    }


    cout << "Palabra sencriptada: " << original << endl;
    cout << "Palabra desencriptada: " << palabra << endl;



}
