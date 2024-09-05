#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cantidad_vectores;
    cout << "Ingrese la cantidad de vectores a crear: ";
    cin >> cantidad_vectores;

    vector<vector<int> > vectores;

    for (int i = 0; i < cantidad_vectores; i++) {
        int tamano_vector;
        cout << "Ingrese la cantidad de elementos para el vector " << i + 1 << ": ";
        cin >> tamano_vector;

        vector<int> nuevo_vector(tamano_vector);

        cout << "Ingrese los elementos para el vector " << i + 1 << ":" << endl;
        for (int j = 0; j < tamano_vector; j++) {
            cout << "Elemento " << j + 1 << ": ";
            cin >> nuevo_vector[j];
        }

        vectores.push_back(nuevo_vector);
    }

    // Mostrar los vectores ingresados
    cout << "\nLos vectores ingresados son:\n";
    for (int i = 0; i < vectores.size(); i++) {
        cout << "Vector " << i + 1 << ": ";
        for (int j = 0; j < vectores[i].size(); j++) {
            cout << vectores[i][j] << " ";
        }
        cout << endl;
    }
	system("pause");
    return 0;
}


