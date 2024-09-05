#include <iostream>
#include <windows.h>
#include <mmsystem.h>  // Incluir este encabezado para PlaySound

using namespace std;

int main() {
    system("color 4F");
    
    char soundfile[] = "D:\\pruebas\\musica1.wav";
    if (PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC)) {
        cout << "Reproduciendo sonido..." << endl;
    } else {
        cout << "Error al reproducir el sonido." << endl;
    }
    
    system("pause");
    return 0;
}


