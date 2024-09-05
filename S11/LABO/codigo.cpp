#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Mascota {
    int codigo;
    string tipoAnimal;
    string nombre;
    double peso;
    int edad;
    string tipoAtencion;
    double precioAtencion;
    string fechaAtencion;
    int diasRecuperacion;
    double costoTotal;
};

void generarFecha(string &fecha) {
    time_t t = time(0);
    struct tm * now = localtime(&t);
    fecha = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
}

void registrarMascota(vector<Mascota> &mascotas) {
    Mascota mascota;
    mascota.codigo = rand() % 500 + 1;
    
    cout << "Seleccione el tipo de animal (1. Perro, 2. Gato, 3. Especial): ";
    int opcionAnimal;
    cin >> opcionAnimal;
    switch (opcionAnimal) {
        case 1: mascota.tipoAnimal = "Perro"; break;
        case 2: mascota.tipoAnimal = "Gato"; break;
        case 3: mascota.tipoAnimal = "Especial"; break;
        default: mascota.tipoAnimal = "Desconocido"; break;
    }

    cout << "Ingrese el nombre de la mascota: ";
    cin >> mascota.nombre;

    mascota.peso = rand() % 5 + 1; // Random peso entre 1 y 5 kg
    mascota.edad = rand() % 120 + 1; // Random edad entre 1 y 120 meses

    cout << "Seleccione el tipo de atención (1. Diagnostico, 2. Operacion, 3. Tratamiento): ";
    int opcionAtencion;
    cin >> opcionAtencion;
    switch (opcionAtencion) {
        case 1: 
            mascota.tipoAtencion = "Diagnostico";
            mascota.precioAtencion = 100.0;
            mascota.diasRecuperacion = 0;
            break;
        case 2: 
            mascota.tipoAtencion = "Operacion";
            mascota.precioAtencion = 600.0;
            mascota.diasRecuperacion = rand() % 10 + 1;
            break;
        case 3: 
            mascota.tipoAtencion = "Tratamiento";
            mascota.precioAtencion = 300.0;
            mascota.diasRecuperacion = rand() % 10 + 1;
            break;
        default:
            cout << "Opcion no valida." << endl;
            return;
    }

    generarFecha(mascota.fechaAtencion);
    mascota.costoTotal = mascota.precioAtencion + (mascota.diasRecuperacion * 150.0);
    if (mascota.tipoAtencion == "Operacion") {
        mascota.costoTotal *= 0.8; // Descuento del 20% si es operacion
    }
    mascota.costoTotal *= 1.18; // Añadir IGV 18%

    mascotas.push_back(mascota);
    
    // Ruta del archivo de registro
    string rutaArchivo = "C:\\ALGORITMICA!\\CacyaTorocahua\\mascotas.txt";
    
    ofstream file(rutaArchivo, ios::app);
    if (file.is_open()) {
        file << mascota.codigo << " " << mascota.tipoAnimal << " " << mascota.nombre << " " << fixed << setprecision(1) << mascota.peso << " " << mascota.edad << " " << mascota.tipoAtencion << " " << fixed << setprecision(2) << mascota.precioAtencion << " " << mascota.fechaAtencion << " " << mascota.diasRecuperacion << " " << fixed << setprecision(2) << mascota.costoTotal << endl;
        file.close();
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
}

void mostrarMascotas(const vector<Mascota> &mascotas) {
    for (const auto &mascota : mascotas) {
        cout << "Codigo: " << mascota.codigo << ", Tipo de Animal: " << mascota.tipoAnimal << ", Nombre: " << mascota.nombre << ", Peso: " << mascota.peso << " kg, Edad: " << mascota.edad << " meses, Tipo de Atencion: " << mascota.tipoAtencion << ", Precio Atencion: S/" << mascota.precioAtencion << ", Fecha Atencion: " << mascota.fechaAtencion << ", Dias Recuperacion: " << mascota.diasRecuperacion << ", Costo Total: S/" << mascota.costoTotal << endl;
    }
}

void modificarMascota(vector<Mascota> &mascotas, int codigo) {
    for (auto &mascota : mascotas) {
        if (mascota.codigo == codigo) {
            cout << "Modificar el tipo de atención y días de recuperación de la mascota con codigo " << codigo << ":" << endl;

            cout << "Seleccione el nuevo tipo de atención (1. Diagnostico, 2. Operacion, 3. Tratamiento): ";
            int opcionAtencion;
            cin >> opcionAtencion;
            switch (opcionAtencion) {
                case 1: 
                    mascota.tipoAtencion = "Diagnostico";
                    mascota.precioAtencion = 100.0;
                    mascota.diasRecuperacion = 0;
                    break;
                case 2: 
                    mascota.tipoAtencion = "Operacion";
                    mascota.precioAtencion = 600.0;
                    mascota.diasRecuperacion = rand() % 10 + 1;
                    break;
                case 3: 
                    mascota.tipoAtencion = "Tratamiento";
                    mascota.precioAtencion = 300.0;
                    mascota.diasRecuperacion = rand() % 10 + 1;
                    break;
                default:
                    cout << "Opcion no valida." << endl;
                    return;
            }

            mascota.costoTotal = mascota.precioAtencion + (mascota.diasRecuperacion * 150.0);
            if (mascota.tipoAtencion == "Operacion") {
                mascota.costoTotal *= 0.8; // Descuento del 20% si es operacion
            }
            mascota.costoTotal *= 1.18; // Añadir IGV 18%
            cout << "El tipo de atención y días de recuperación de la mascota han sido modificados." << endl;
            return;
        }
    }
    cout << "No se encontró ninguna mascota con el código especificado." << endl;
}

int main() {
    vector<Mascota> mascotas;
    srand(time(0));
    int opcion;

    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Registrar los datos de las mascotas" << endl;
        cout << "2. Mostrar la lista de las mascotas registradas" << endl;
        cout << "3. Modificar tipo de atención y días de recuperación de una mascota por su código" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarMascota(mascotas);
                break;
            case 2:
                mostrarMascotas(mascotas);
                break;
            case 3:
                int codigo;
                cout << "Ingrese el codigo de la mascota a modificar: ";
                cin >> codigo;
                modificarMascota(mascotas, codigo);
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
