#include <iostream>
#include <conio.h> // getch()
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

struct Alumno {
    short cdAlumno;
    string nombreAlumno;
} TpAlumno;

struct Curso {
    short cdCurso;
    string nombreCurso;
} TpCurso;

struct Nota {
    short cdAlumno;
    short cdCurso;
    float notaParcial;
    float notaFinal;
    float notaPromedio;
    char estado;
} TpNota;

//******** zona de funciones *********

//**************************************
// ADICIONAR REGISTROS ALUMNOS
//**************************************
void f_AdicionaAlumno(ofstream &GrabAlum) {
	fflush(stdin);
    cout << "\nRegistro de Alumnos" << endl;
    cout << "\n********************" << endl;

    cout << "\nCodigo Alumno----> ";
    cin >> TpAlumno.cdAlumno;
    fflush(stdin);
    cout << "\nNombre Alumno----> ";
    getline(cin, TpAlumno.nombreAlumno);

    GrabAlum << TpAlumno.cdAlumno << endl;
    GrabAlum << TpAlumno.nombreAlumno << endl;
}

//**************************************
// LEE REGISTROS ALUMNOS
//**************************************
void f_LeeAlumno(ifstream &leeAlum) {
	fflush(stdin);
    string xCdAlumno;
    system("cls");
    getline(leeAlum, xCdAlumno);
    istringstream(xCdAlumno) >> TpAlumno.cdAlumno;
    while (!leeAlum.eof()) {
        getline(leeAlum, TpAlumno.nombreAlumno);

        cout << "\nCodigo Alumno-------> " << TpAlumno.cdAlumno << endl;
        cout << "\nNombre Alumno-------> " << TpAlumno.nombreAlumno << endl;

        cout << "**************************************" << endl;
        getline(leeAlum, xCdAlumno);
        istringstream(xCdAlumno) >> TpAlumno.cdAlumno;
    }

    system("pause");
}

//**************************************
// ADICIONAR REGISTROS CURSOS
//**************************************
void f_AdicionaCurso(ofstream &GrabaCurso) {
	fflush(stdin);
    cout << "\nCodigo Curso----> ";
    cin >> TpCurso.cdCurso;
    fflush(stdin);
    cout << "\nNombre Curso----> ";
    getline(cin, TpCurso.nombreCurso);

    GrabaCurso << TpCurso.cdCurso << endl;
    GrabaCurso << TpCurso.nombreCurso << endl;
}

//**************************************
// LEE REGISTROS CURSOS
//**************************************
void f_LeeCurso(ifstream &leeCurso) {
	fflush(stdin);
    string xCdCurso;
    cout << "\nRegistro de Cursos" << endl;
    cout << "\n********************" << endl;
    getline(leeCurso, xCdCurso);
    istringstream(xCdCurso) >> TpCurso.cdCurso;
    while (!leeCurso.eof()) {
        getline(leeCurso, TpCurso.nombreCurso);

        cout << "\nCodigo Curso-------> " << TpCurso.cdCurso << endl;
        cout << "\nNombre Curso-------> " << TpCurso.nombreCurso << endl;

        cout << "**************************************" << endl;
        getline(leeCurso, xCdCurso);
        istringstream(xCdCurso) >> TpCurso.cdCurso;
    }

    system("pause");
}

//*********************************************************************
//***Opcion 5:  GRABACION DE NOTAS ************************************
//*********************************************************************
void f_GrabaNota(ifstream &leeAlumno, ifstream &leeCurso, ofstream &grabaNota) {
	fflush(stdin);
    string xCdAlumno, xCdCurso;
    short claveAlum, claveCurso;
    bool find = false;

    // Busqueda del Datos del Alumno
    do {
        fflush(stdin);
        cout << "Ingresar Codigo de Alumno---> ";
        cin >> claveAlum;
        getline(leeAlumno, xCdAlumno);
        istringstream(xCdAlumno) >> TpAlumno.cdAlumno;

        while (!leeAlumno.eof() && !find) {
            getline(leeAlumno, TpAlumno.nombreAlumno);
            if (TpAlumno.cdAlumno == claveAlum) {
                cout << "\nCodigo Alumno-------> " << TpAlumno.cdAlumno << endl;
                cout << "\nNombre Alumno-------> " << TpAlumno.nombreAlumno << endl;
                cout << "**************************************" << endl;
                find = true;
            }

            getline(leeAlumno, xCdAlumno);
            istringstream(xCdAlumno) >> TpAlumno.cdAlumno;
        }

        if (!find) {
            cout << "Codigo de alumno no existe, Ingrese un codigo valido...." << endl;
            Sleep(2000);
        }
    } while (!find);

    find = false; // reinicializa el flag

    // Busqueda del Datos del Curso
    do {
        fflush(stdin);
        cout << "Ingresar Codigo del Curso---> ";
        cin >> claveCurso;
        getline(leeCurso, xCdCurso);
        istringstream(xCdCurso) >> TpCurso.cdCurso;

        while (!leeCurso.eof() && !find) {
            getline(leeCurso, TpCurso.nombreCurso);
            if (TpCurso.cdCurso == claveCurso) {
                cout << "\nCodigo Curso-------> " << TpCurso.cdCurso << endl;
                cout << "\nNombre Curso-------> " << TpCurso.nombreCurso << endl;
                cout << "**************************************" << endl;
                find = true;
            }

            getline(leeCurso, xCdCurso);
            istringstream(xCdCurso) >> TpCurso.cdCurso;
        }

        if (!find) {
            cout << "Codigo de Curso no existe, vuelva a ingresar...." << endl;
            Sleep(1000);
        }
    } while (!find);

    // Ingreso de Notas del Alumno
    cout << "\nIngresar Nota Parcial ---> ";
    cin >> TpNota.notaParcial;
    cout << "\nIngresar Nota Final ---> ";
    cin >> TpNota.notaFinal;
    TpNota.notaPromedio = (TpNota.notaParcial + TpNota.notaFinal) / 2;

    if (TpNota.notaPromedio <= 10.5)
        TpNota.estado = 'D';
    else
        TpNota.estado = 'A';

    // Grabacion en archivo NOTAS.txt
    grabaNota << claveAlum << endl;
    grabaNota << claveCurso << endl;
    grabaNota << TpNota.notaParcial << endl;
    grabaNota << TpNota.notaFinal << endl;
    grabaNota << TpNota.notaPromedio << endl;
    grabaNota << TpNota.estado << endl;
}

//******************************************************
// opc6.  LISTA DE NOTAS DE ASIGNATURAS POR ALUMNO
//******************************************************
void f_Notas(ifstream &leeAlumno, ifstream &leeNota, ifstream &leeCurso) {
	fflush(stdin);
    string xCdAlumno, xCdCurso, xnotaParcial, xnotaFinal, xnotaPromedio, xestado;
    short claveAlum;
    bool find = false;

    // Buscar Alumno por Codigo
    fflush(stdin);
    cout << "Ingresar Codigo de Alumno---> ";
    cin >> claveAlum;
    getline(leeAlumno, xCdAlumno);
    istringstream(xCdAlumno) >> TpAlumno.cdAlumno;

    while (!leeAlumno.eof() && !find) {
        getline(leeAlumno, TpAlumno.nombreAlumno);
        if (TpAlumno.cdAlumno == claveAlum) {
            cout << "\n**************************************";
            cout << "\nCodigo Alumno-------> " << TpAlumno.cdAlumno;
            cout << "\nNombre Alumno-------> " << TpAlumno.nombreAlumno;
            cout << "\n**************************************" << endl;
            find = true;
        }

        getline(leeAlumno, xCdAlumno);
        istringstream(xCdAlumno) >> TpAlumno.cdAlumno;
    }

    if (!find) {
        cout << "Codigo de alumno no existe, Ingrese un codigo valido...." << endl;
        Sleep(2000);
        return;
    }

    // Busqueda de Notas del Alumno
    while (getline(leeNota, xCdAlumno)) {
        istringstream(xCdAlumno) >> TpNota.cdAlumno;

        if (TpNota.cdAlumno == claveAlum) {
            getline(leeNota, xCdCurso);
            istringstream(xCdCurso) >> TpNota.cdCurso;
            getline(leeNota, xnotaParcial);
            istringstream(xnotaParcial) >> TpNota.notaParcial;
            getline(leeNota, xnotaFinal);
            istringstream(xnotaFinal) >> TpNota.notaFinal;
            getline(leeNota, xnotaPromedio);
            istringstream(xnotaPromedio) >> TpNota.notaPromedio;
            getline(leeNota, xestado);
            TpNota.estado = xestado[0];

            // Buscar nombre del curso
            ifstream tempCurso("D:\\Pruebas\\curso.txt", ios::in);
            if (tempCurso.fail()) {
                cout << "Error en el archivo de cursos..." << endl;
                Sleep(2000);
                return;
            }

            bool cursoEncontrado = false;
            while (getline(tempCurso, xCdCurso)) {
                istringstream(xCdCurso) >> TpCurso.cdCurso;
                if (TpCurso.cdCurso == TpNota.cdCurso) {
                    getline(tempCurso, TpCurso.nombreCurso);
                    cursoEncontrado = true;
                    break;
                }

                getline(tempCurso, xCdCurso); // read the next course
            }
            tempCurso.close();

            if (cursoEncontrado) {
                cout << "Curso: " << TpCurso.nombreCurso << endl;
                cout << "Nota Parcial: " << TpNota.notaParcial << endl;
                cout << "Nota Final: " << TpNota.notaFinal << endl;
                cout << "Nota Promedio: " << TpNota.notaPromedio << endl;
                cout << "Estado: " << TpNota.estado << endl;
                cout << "**************************************" << endl;
            } else {
                cout << "Curso no encontrado para el codigo " << TpNota.cdCurso << endl;
            }
        }
    }
    system("pause");
}

//******************************************
// OPCION 7: MODIFICAR NOTAS DEL ALUMNO
//******************************************
void f_ModificarNotas(ifstream &leeAlumno, ifstream &leeNota, ifstream &leeCurso) {
	fflush(stdin);
    ofstream tempNota("D:\\Pruebas\\tempNota.txt", ios::app);
    if (!tempNota) {
        cout << "Error en la apertura del archivo temporal." << endl;
        return;
    }

    string xCdAlumno, xCdCurso, xnotaParcial, xnotaFinal, xnotaPromedio, xestado;
    short claveAlum;
    bool find = false;

    // Buscar Alumno por Codigo
    fflush(stdin);
    cout << "Ingresar Codigo de Alumno---> ";
    cin >> claveAlum;
    getline(leeAlumno, xCdAlumno);
    istringstream(xCdAlumno) >> TpAlumno.cdAlumno;

    while (!leeAlumno.eof() && !find) {
        getline(leeAlumno, TpAlumno.nombreAlumno);
        if (TpAlumno.cdAlumno == claveAlum) {
            cout << "\n**************************************";
            cout << "\nCodigo Alumno-------> " << TpAlumno.cdAlumno;
            cout << "\nNombre Alumno-------> " << TpAlumno.nombreAlumno;
            cout << "\n**************************************" << endl;
            find = true;
        }

        getline(leeAlumno, xCdAlumno);
        istringstream(xCdAlumno) >> TpAlumno.cdAlumno;
    }

    if (!find) {
        cout << "Codigo de alumno no existe, Ingrese un codigo valido...." << endl;
        Sleep(2000);
        return;
    }

    // Busqueda y modificación de Notas del Alumno
    while (getline(leeNota, xCdAlumno)) {
    	fflush(stdin);
        istringstream(xCdAlumno) >> TpNota.cdAlumno;

        if (TpNota.cdAlumno == claveAlum) {
            getline(leeNota, xCdCurso);
            istringstream(xCdCurso) >> TpNota.cdCurso;
            getline(leeNota, xnotaParcial);
            istringstream(xnotaParcial) >> TpNota.notaParcial;
            getline(leeNota, xnotaFinal);
            istringstream(xnotaFinal) >> TpNota.notaFinal;
            getline(leeNota, xnotaPromedio);
            istringstream(xnotaPromedio) >> TpNota.notaPromedio;
            getline(leeNota, xestado);
            TpNota.estado = xestado[0];

            // Buscar nombre del curso
            ifstream tempCurso("D:\\Pruebas\\curso.txt", ios::in);
            if (tempCurso.fail()) {
                cout << "Error en el archivo de cursos..." << endl;
                Sleep(2000);
                return;
            }

            bool cursoEncontrado = false;
            while (getline(tempCurso, xCdCurso)) {
                istringstream(xCdCurso) >> TpCurso.cdCurso;
                if (TpCurso.cdCurso == TpNota.cdCurso) {
                    getline(tempCurso, TpCurso.nombreCurso);
                    cursoEncontrado = true;
                    break;
                }

                getline(tempCurso, xCdCurso); // read the next course
            }
            tempCurso.close();

            if (cursoEncontrado) {
                cout << "Curso: " << TpCurso.nombreCurso << endl;
                cout << "Nota Parcial Actual: " << TpNota.notaParcial << endl;
                cout << "Nota Final Actual: " << TpNota.notaFinal << endl;
                cout << "Nota Promedio Actual: " << TpNota.notaPromedio << endl;
                cout << "Estado Actual: " << TpNota.estado << endl;
                cout << "**************************************" << endl;

                // Modificación de las notas
                cout << "Ingresar Nueva Nota Parcial ---> ";
                cin >> TpNota.notaParcial;
                cout << "Ingresar Nueva Nota Final ---> ";
                cin >> TpNota.notaFinal;
                TpNota.notaPromedio = (TpNota.notaParcial + TpNota.notaFinal) / 2;

                if (TpNota.notaPromedio <= 10.5)
                    TpNota.estado = 'D';
                else
                    TpNota.estado = 'A';
            } else {
                cout << "Curso no encontrado para codigo: " << TpNota.cdCurso << endl;
            }
        }

        tempNota << TpNota.cdAlumno << endl;
        tempNota << TpNota.cdCurso << endl;
        tempNota << TpNota.notaParcial << endl;
        tempNota << TpNota.notaFinal << endl;
        tempNota << TpNota.notaPromedio << endl;
        tempNota << TpNota.estado << endl;
    }
    leeNota.close();
    tempNota.close();

    // Eliminar el archivo original y renombrar el temporal
    remove("D:\\Pruebas\\nota.txt");
    rename("D:\\Pruebas\\tempNota.txt", "D:\\Pruebas\\nota.txt");

    cout << "Notas modificadas con exito." << endl;
    system("pause");
}

//******************************************
//************   PROGRAMA PRINCIPAL    *****
//******************************************

int main() {
    ofstream GrabaAlumno, GrabaCurso, grabaNota;
    ifstream LeeAlumno, LeeCurso, leeNota;

    short op, claveAlum, claveCurso;

    do {
        system("cls");
        cout << "*********************************************" << endl;
        cout << "          UNIVERSIDAD XYZ" << endl;
        cout << "*********************************************" << endl;
        cout << "[1]. Adicion de Alumnos " << endl;
        cout << "[2]. Listado de Alumnos " << endl;
        cout << "[3]. Adicion de Cursos " << endl;
        cout << "[4]. Listado de Cursos " << endl;
        cout << "[5]. Ingreso de Notas del Alumno " << endl;
        cout << "[6]. Reporte de Notas del Alumno" << endl;
        cout << "[7]. Modificar Notas del Alumno" << endl;
        cout << "[0]. Salir" << endl;
        cout << "*********************************************" << endl;
        cout << "Ingresar opcion --->";
        cin >> op;

        switch (op) {
            case 1:
                GrabaAlumno.open("D:\\Pruebas\\alumno.txt", ios::app);
                if (GrabaAlumno.fail()) {
                    cout << "Error en la apertura del archivo alumno.txt" << endl;
                    Sleep(2000);
                    break;
                }
                f_AdicionaAlumno(GrabaAlumno);
                GrabaAlumno.close();
                break;

            case 2:
                LeeAlumno.open("D:\\Pruebas\\alumno.txt", ios::in);
                if (LeeAlumno.fail()) {
                    cout << "Error en la apertura del archivo alumno.txt" << endl;
                    Sleep(2000);
                    break;
                }
                f_LeeAlumno(LeeAlumno);
                LeeAlumno.close();
                break;

            case 3:
                GrabaCurso.open("D:\\Pruebas\\curso.txt", ios::app);
                if (GrabaCurso.fail()) {
                    cout << "Error en la apertura del archivo curso.txt" << endl;
                    Sleep(2000);
                    break;
                }
                f_AdicionaCurso(GrabaCurso);
                GrabaCurso.close();
                break;

            case 4:
                LeeCurso.open("D:\\Pruebas\\curso.txt", ios::in);
                if (LeeCurso.fail()) {
                    cout << "Error en la apertura del archivo curso.txt" << endl;
                    Sleep(2000);
                    break;
                }
                f_LeeCurso(LeeCurso);
                LeeCurso.close();
                break;

            case 5:
                LeeAlumno.open("D:\\Pruebas\\alumno.txt", ios::in);
                if (LeeAlumno.fail()) {
                    cout << "Error en la apertura del archivo alumno.txt" << endl;
                    Sleep(2000);
                    break;
                }

                LeeCurso.open("D:\\Pruebas\\curso.txt", ios::in);
                if (LeeCurso.fail()) {
                    cout << "Error en la apertura del archivo curso.txt" << endl;
                    Sleep(2000);
                    break;
                }

                grabaNota.open("D:\\Pruebas\\nota.txt", ios::app);
                if (grabaNota.fail()) {
                    cout << "Error en la apertura del archivo nota.txt" << endl;
                    Sleep(2000);
                    break;
                }

                f_GrabaNota(LeeAlumno, LeeCurso, grabaNota);

                LeeAlumno.close();
                LeeCurso.close();
                grabaNota.close();
                break;

            case 6:
                LeeAlumno.open("D:\\Pruebas\\alumno.txt", ios::in);
                if (LeeAlumno.fail()) {
                    cout << "Error en la apertura del archivo alumno.txt" << endl;
                    Sleep(2000);
                    break;
                }

                leeNota.open("D:\\Pruebas\\nota.txt", ios::in);
                if (leeNota.fail()) {
                    cout << "Error en la apertura del archivo nota.txt" << endl;
                    Sleep(2000);
                    break;
                }

                LeeCurso.open("D:\\Pruebas\\curso.txt", ios::in);
                if (LeeCurso.fail()) {
                    cout << "Error en la apertura del archivo curso.txt" << endl;
                    Sleep(2000);
                    break;
                }

                f_Notas(LeeAlumno, leeNota, LeeCurso);

                LeeAlumno.close();
                leeNota.close();
                LeeCurso.close();
                break;

            case 7:
                LeeAlumno.open("D:\\Pruebas\\alumno.txt", ios::in);
                if (LeeAlumno.fail()) {
                    cout << "Error en la apertura del archivo alumno.txt" << endl;
                    Sleep(2000);
                    break;
                }

                leeNota.open("D:\\Pruebas\\nota.txt", ios::in);
                if (leeNota.fail()) {
                    cout << "Error en la apertura del archivo nota.txt" << endl;
                    Sleep(2000);
                    break;
                }

                LeeCurso.open("D:\\Pruebas\\curso.txt", ios::in);
                if (LeeCurso.fail()) {
                    cout << "Error en la apertura del archivo curso.txt" << endl;
                    Sleep(2000);
                    break;
                }

                f_ModificarNotas(LeeAlumno, leeNota, LeeCurso);

                LeeAlumno.close();
                leeNota.close();
                LeeCurso.close();
                
                break;

            case 0:
                cout << "Saliendo del programa..." << endl;
                Sleep(2000);
                break;

            default:
                cout << "Opcion no valida, intente nuevamente..." << endl;
                Sleep(2000);
                break;
        }

    } while (op != 0);

    return 0;
}

