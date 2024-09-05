#include <iostream>
#include <conio.h>
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
    short cdProfesor; // Añadimos un campo para el código del profesor
} TpCurso;

struct Nota {
    short cdAlumno;
    short cdCurso;
    float notaParcial;
    float notaFinal;
    float notaPromedio;
    char estado;
} TpNota;

struct Profesor {
    short cdProfesor;
    string nombreProfesor;
} TpProfesor;

//******** zona de funciones *********

//**************************************
// ADICIONAR REGISTROS ALUMNOS
//**************************************
void f_AdicionaAlumno(ofstream &GrabAlum) {
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
    cout << "\nCodigo Curso----> ";
    cin >> TpCurso.cdCurso;
    fflush(stdin);
    cout << "\nNombre Curso----> ";
    getline(cin, TpCurso.nombreCurso);

    GrabaCurso << TpCurso.cdCurso << endl;
    GrabaCurso << TpCurso.nombreCurso << endl;
    GrabaCurso << TpCurso.cdProfesor << endl; // Guardamos el código del profesor
}

//**************************************
// LEE REGISTROS CURSOS
//**************************************
void f_LeeCurso(ifstream &leeCurso) {
    string xCdCurso;
    cout << "\nRegistro de Cursos" << endl;
    cout << "\n********************" << endl;
    getline(leeCurso, xCdCurso);
    istringstream(xCdCurso) >> TpCurso.cdCurso;
    while (!leeCurso.eof()) {
        getline(leeCurso, TpCurso.nombreCurso);
        getline(leeCurso, xCdCurso);
        istringstream(xCdCurso) >> TpCurso.cdProfesor;

        cout << "\nCodigo Curso-------> " << TpCurso.cdCurso << endl;
        cout << "\nNombre Curso-------> " << TpCurso.nombreCurso << endl;
        cout << "\nCodigo Profesor----> " << TpCurso.cdProfesor << endl;

        cout << "**************************************" << endl;
        getline(leeCurso, xCdCurso);
        istringstream(xCdCurso) >> TpCurso.cdCurso;
    }
    system("pause");
}

//**************************************
// ADICIONAR REGISTROS PROFESORES
//**************************************
void f_AdicionaProfesor(ofstream &GrabaProf) {
    cout << "\nCodigo Profesor----> ";
    cin >> TpProfesor.cdProfesor;
    fflush(stdin);
    cout << "\nNombre Profesor----> ";
    getline(cin, TpProfesor.nombreProfesor);

    GrabaProf << TpProfesor.cdProfesor << endl;
    GrabaProf << TpProfesor.nombreProfesor << endl;
}

//**************************************
// LEE REGISTROS PROFESORES
//**************************************
void f_LeeProfesor(ifstream &leeProf) {
    string xCdProfesor;
    cout << "\nRegistro de Profesores" << endl;
    cout << "\n**********************" << endl;
    getline(leeProf, xCdProfesor);
    istringstream(xCdProfesor) >> TpProfesor.cdProfesor;
    while (!leeProf.eof()) {
        getline(leeProf, TpProfesor.nombreProfesor);

        cout << "\nCodigo Profesor-----> " << TpProfesor.cdProfesor << endl;
        cout << "\nNombre Profesor-----> " << TpProfesor.nombreProfesor << endl;

        cout << "**************************************" << endl;
        getline(leeProf, xCdProfesor);
        istringstream(xCdProfesor) >> TpProfesor.cdProfesor;
    }
    system("pause");
}

//**************************************
// ACTUALIZAR CURSO CON PROFESOR
//**************************************
void f_ActualizarCursoProfesor(ifstream &leeCurso, ofstream &cursoFile) {
    short claveCurso, claveProfesor;
    bool find = false;

    // Buscar Curso por Codigo
    fflush(stdin);
    cout << "Ingresar Codigo del Curso---> ";
    cin >> claveCurso;
    getline(leeCurso, TpCurso.cdCurso);

    string tempFilename = "D:\\Pruebas\\temp_curso.txt";
    ofstream tempFile(tempFilename.c_str(), ios::out);
    cursoFile.seekg(0);
    getline(cursoFile, xCdCurso);
    istringstream(xCdCurso) >> TpCurso.cdCurso;
    while (!cursoFile.eof()) {
        getline(cursoFile, TpCurso.nombreCurso);
        getline(cursoFile, xCdCurso);
        istringstream(xCdCurso) >> TpCurso.cdProfesor;

        if (TpCurso.cdCurso == claveCurso) {
            find = true;
            cout << "\nIngresar Codigo del Profesor ---> ";
            cin >> claveProfesor;
            TpCurso.cdProfesor = claveProfesor;
        }
        tempFile << TpCurso.cdCurso << endl;
        tempFile << TpCurso.nombreCurso << endl;
        tempFile << TpCurso.cdProfesor << endl;

        getline(cursoFile, xCdCurso);
        istringstream(xCdCurso) >> TpCurso.cdCurso;
    }
    tempFile.close();
    cursoFile.close();
    remove("D:\\Pruebas\\curso.txt");
    rename(tempFilename.c_str(), "D:\\Pruebas\\curso.txt");

    if (find) {
        cout << "Curso actualizado correctamente." << endl;
    } else {
        cout << "Codigo de curso no existe, Ingrese un codigo valido...." << endl;
    }
}

//******************************************************
// opc6.  LISTA DE NOTAS DE ASIGNATURAS POR ALUMNO
//******************************************************
void f_Notas(ifstream &leeAlumno, ifstream &leeNota, ifstream &leeCurso, ifstream &leeProf) {
    string xCdAlumno, xCdCurso, xnotaParcial, xnotaFinal, xnotaPromedio, xCdProfesor;
    short claveAlum, claveCurso, claveProfesor;
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

    if (find == false) {
        cout << "Codigo de alumno no existe, Ingrese un codigo valido...." << endl;
        Sleep(2000);
        return;
    }

    // claveAlum tiene el codigo de alumno buscado
    cout << "Alumno buscado es " << claveAlum;

    // Busqueda de Notas del Alumno
    getline(leeNota, xCdAlumno);
    istringstream(xCdAlumno) >> TpNota.cdAlumno;
    while (!leeNota.eof()) {
        getline(leeNota, xCdCurso);
        istringstream(xCdCurso) >> TpNota.cdCurso;
        getline(leeNota, xnotaParcial);
        istringstream(xnotaParcial) >> TpNota.notaParcial;
        getline(leeNota, xnotaFinal);
        istringstream(xnotaFinal) >> TpNota.notaFinal;
        getline(leeNota, xnotaPromedio);
        istringstream(xnotaPromedio) >> TpNota.notaPromedio;
        leeNota >> TpNota.estado;
        leeNota.ignore(); // ignore newline character after estado

        if (TpNota.cdAlumno == claveAlum) {
            find = false;
            getline(leeCurso, xCdCurso);
            istringstream(xCdCurso) >> TpCurso.cdCurso;
            while (!leeCurso.eof() && !find) {
                getline(leeCurso, TpCurso.nombreCurso);
                getline(leeCurso, xCdProfesor);
                istringstream(xCdProfesor) >> TpCurso.cdProfesor;

                if (TpNota.cdCurso == TpCurso.cdCurso) {
                    cout << "\nCurso " << TpCurso.cdCurso << " es " << TpCurso.nombreCurso << endl;
                    find = true;
                    break;
                }
                getline(leeCurso, xCdCurso);
                istringstream(xCdCurso) >> TpCurso.cdCurso;
            }

            find = false;
            getline(leeProf, xCdProfesor);
            istringstream(xCdProfesor) >> TpProfesor.cdProfesor;
            while (!leeProf.eof() && !find) {
                getline(leeProf, TpProfesor.nombreProfesor);
                if (TpCurso.cdProfesor == TpProfesor.cdProfesor) {
                    cout << "Profesor del Curso " << TpCurso.cdCurso << " es " << TpProfesor.nombreProfesor << endl;
                    find = true;
                    break;
                }
                getline(leeProf, xCdProfesor);
                istringstream(xCdProfesor) >> TpProfesor.cdProfesor;
            }

            cout << "\nNota Parcial-------> " << TpNota.notaParcial;
            cout << "\nNota Final---------> " << TpNota.notaFinal;
            cout << "\nNota Promedio------> " << TpNota.notaPromedio;
            cout << "\nEstado-------------> " << TpNota.estado;
            cout << "\n**************************************" << endl;
        }
        getline(leeNota, xCdAlumno);
        istringstream(xCdAlumno) >> TpNota.cdAlumno;
    }

    if (find == false) {
        cout << "\nNo existen Notas de Alumno...." << endl;
    }
    system("pause");
}

int main() {
    ofstream GrabAlum, GrabaCurso, GrabaProf;
    ifstream leeAlum, leeCurso, leeNota, leeProf;
    fstream cursoFile;
    short op, op2;

    do {
        system("cls");
        cout << "\n\n\t\t\tSISTEMA DE NOTAS";
        cout << "\n\t\t\t****************\n";
        cout << "\n\t\t1. Alumnos";
        cout << "\n\t\t2. Cursos";
        cout << "\n\t\t3. Profesores";
        cout << "\n\t\t4. Notas";
        cout << "\n\t\t5. Consulta de Notas de Alumnos";
        cout << "\n\t\t6. Salir";
        cout << "\n\t\tIngrese opcion---->";
        cin >> op;

        switch (op) {
            case 1:
                system("cls");
                cout << "\n\n\t\t\tREGISTRO DE ALUMNOS";
                cout << "\n\t\t\t*******************";
                cout << "\n\t\t1. Adicion";
                cout << "\n\t\t2. Lectura";
                cout << "\n\t\tIngrese opcion---->";
                cin >> op2;

                switch (op2) {
                    case 1:
                        GrabAlum.open("D:\\Pruebas\\alumnos.txt", ios::app);
                        f_AdicionaAlumno(GrabAlum);
                        GrabAlum.close();
                        break;
                    case 2:
                        leeAlum.open("D:\\Pruebas\\alumnos.txt", ios::in);
                        f_LeeAlumno(leeAlum);
                        leeAlum.close();
                        break;
                }
                break;

            case 2:
                system("cls");
                cout << "\n\n\t\t\tREGISTRO DE CURSOS";
                cout << "\n\t\t\t******************";
                cout << "\n\t\t1. Adicion";
                cout << "\n\t\t2. Lectura";
                cout << "\n\t\t3. Actualizar Curso con Profesor";
                cout << "\n\t\tIngrese opcion---->";
                cin >> op2;

                switch (op2) {
                    case 1:
                        GrabaCurso.open("D:\\Pruebas\\curso.txt", ios::app);
                        f_AdicionaCurso(GrabaCurso);
                        GrabaCurso.close();
                        break;
                    case 2:
                        leeCurso.open("D:\\Pruebas\\curso.txt", ios::in);
                        f_LeeCurso(leeCurso);
                        leeCurso.close();
                        break;
                    case 3:
                        cursoFile.open("D:\\Pruebas\\curso.txt", ios::in | ios::out);
                        f_ActualizarCursoProfesor(leeCurso, cursoFile);
                        cursoFile.close();
                        break;
                }
                break;

            case 3:
                system("cls");
                cout << "\n\n\t\t\tREGISTRO DE PROFESORES";
                cout << "\n\t\t\t***********************";
                cout << "\n\t\t1. Adicion";
                cout << "\n\t\t2. Lectura";
                cout << "\n\t\tIngrese opcion---->";
                cin >> op2;

                switch (op2) {
                    case 1:
                        GrabaProf.open("D:\\Pruebas\\profesores.txt", ios::app);
                        f_AdicionaProfesor(GrabaProf);
                        GrabaProf.close();
                        break;
                    case 2:
                        leeProf.open("D:\\Pruebas\\profesores.txt", ios::in);
                        f_LeeProfesor(leeProf);
                        leeProf.close();
                        break;
                }
                break;

            case 4:
                // Aquí se implementaría la función para gestionar las notas
                break;

            case 5:
                leeAlum.open("D:\\Pruebas\\alumnos.txt", ios::in);
                leeNota.open("D:\\Pruebas\\notas.txt", ios::in);
                leeCurso.open("D:\\Pruebas\\curso.txt", ios::in);
                leeProf.open("D:\\Pruebas\\profesores.txt", ios::in);
                f_Notas(leeAlum, leeNota, leeCurso, leeProf);
                leeAlum.close();
                leeNota.close();
                leeCurso.close();
                leeProf.close();
                break;
        }
    } while (op != 6);

    return 0;
}

