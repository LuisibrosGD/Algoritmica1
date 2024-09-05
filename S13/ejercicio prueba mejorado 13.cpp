#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

struct Alumno{
    short cdAlumno;
    string nombreAlumno;
}TpAlumno;

struct Curso{
    short cdCurso;
    string nombreCurso;
    
}TpCurso;

struct Nota{
    short cdAlumno;
    short cdCurso;
    float notaParcial;
    float notaFinal;
    float notaPromedio;
    char estado;
}TpNota;

//SEGUNDA PARTE 
/*
struct profesor{
	string cdProfesor;
	string nombre;
}profesores;
*/

//******** zona de funciones *********

//**************************************
// ADICIONAR REGISTROS ALUMNOS
//**************************************
void f_AdicionaAlumno(ofstream &GrabAlum){
    cout<<"\nRegistro de Alumnos"<<endl;
    cout<<"\n********************"<<endl;

    cout<<"\nCodigo Alumno----> ";
    cin>>TpAlumno.cdAlumno;
    fflush(stdin);
    cout<<"\nNombre Alumno----> ";
    getline(cin, TpAlumno.nombreAlumno);

    GrabAlum<<TpAlumno.cdAlumno<<endl;
    GrabAlum<<TpAlumno.nombreAlumno<<endl;
}

//**************************************
// LEE REGISTROS ALUMNOS
//**************************************
void f_LeeAlumno(ifstream &leeAlum){
    string xCdAlumno;
    system("cls");
    getline(leeAlum, xCdAlumno);
    istringstream(xCdAlumno)>>TpAlumno.cdAlumno;
    while (!leeAlum.eof()){
        getline(leeAlum, TpAlumno.nombreAlumno);

        cout<<"\nCodigo Alumno-------> "<<TpAlumno.cdAlumno<<endl;
        cout<<"\nNombre Alumno-------> "<<TpAlumno.nombreAlumno<<endl;

        cout<<"**************************************"<<endl;
        getline(leeAlum, xCdAlumno);
        istringstream(xCdAlumno)>>TpAlumno.cdAlumno;
    }
    system("pause");
}

//**************************************
// ADICIONAR REGISTROS CURSOS
//**************************************
void f_AdicionaCurso(ofstream &GrabaCurso){
    cout<<"\nCodigo Curso----> ";
    cin>>TpCurso.cdCurso;
    fflush(stdin);
    cout<<"\nNombre Curso----> ";
    getline(cin, TpCurso.nombreCurso);

    GrabaCurso<<TpCurso.cdCurso << endl;
    GrabaCurso<<TpCurso.nombreCurso << endl;
}

//**************************************
// LEE REGISTROS CURSOS
//**************************************
void f_LeeCurso(ifstream &leeCurso) {
    string xCdCurso;
    cout<<"\nRegistro de Cursos"<<endl;
    cout<<"\n********************"<<endl;
    getline(leeCurso, xCdCurso);
    istringstream(xCdCurso)>> TpCurso.cdCurso;
    while (!leeCurso.eof()) {
        getline(leeCurso, TpCurso.nombreCurso);
        cout<<"\nCodigo Curso-------> "<<TpCurso.cdCurso<<endl;
        cout<<"\nNombre Curso-------> "<<TpCurso.nombreCurso<<endl;
        cout<<"**************************************"<<endl;
        getline(leeCurso, xCdCurso);
        istringstream(xCdCurso)>>TpCurso.cdCurso;
    }
    system("pause");
}

//*********************************************************************
//***Opcion 5:  GRABACION DE NOTAS ************************************
//*********************************************************************
void f_GrabaNota(ifstream &leeAlumno, ifstream &leeCurso, ofstream &grabaNota){
    string xCdAlumno, xCdCurso;
    short claveAlum, claveCurso;
    bool find = false;

    // Busqueda del Datos del Alumno
    do{
        fflush(stdin);
        cout<<"Ingresar Codigo de Alumno---> ";
        cin>>claveAlum;
        getline(leeAlumno, xCdAlumno);
        istringstream(xCdAlumno)>>TpAlumno.cdAlumno;

        while (!leeAlumno.eof() && !find){
            getline(leeAlumno, TpAlumno.nombreAlumno);
            if(TpAlumno.cdAlumno == claveAlum){
                cout<<"\nCodigo Alumno-------> "<<TpAlumno.cdAlumno<<endl;
                cout<<"\nNombre Alumno-------> "<<TpAlumno.nombreAlumno<<endl;
                cout<<"**************************************"<<endl;
                find = true;
            }
            getline(leeAlumno, xCdAlumno);
            istringstream(xCdAlumno)>>TpAlumno.cdAlumno;
        }

        if (find == false){
            cout<<"Codigo de alumno no existe, Ingrese un codigo valido...."<<endl;
            Sleep(2000);
        }
    } while (find == false);

    find = false;

    // Busqueda del Datos del Curso
    do{
        fflush(stdin);
        cout<<"Ingresar Codigo del Curso---> ";
        cin>>claveCurso;
        getline(leeCurso, xCdCurso);
        istringstream(xCdCurso)>>TpCurso.cdCurso;

        while (!leeCurso.eof() && !find){
            getline(leeCurso, TpCurso.nombreCurso);
            if (TpCurso.cdCurso == claveCurso){
                cout<<"\nCodigo Curso-------> "<<TpCurso.cdCurso<<endl;
                cout<<"\nNombre Curso-------> "<<TpCurso.nombreCurso<<endl;
                cout<<"**************************************"<<endl;
                find = true;
            }
            getline(leeCurso, xCdCurso);
            istringstream(xCdCurso)>>TpCurso.cdCurso;
        }

        if (!find){
            cout<<"Codigo de Curso no existe, vuelva a ingresar...." <<endl;
            Sleep(1000);
        }
    } while (find == false);

    // Ingreso de Notas del Alumno
    cout<<"\nIngresar Nota Parcial ---> ";
    cin>>TpNota.notaParcial;
    cout<<"\nIngresar Nota Final ---> ";
    cin>>TpNota.notaFinal;
    TpNota.notaPromedio = (TpNota.notaParcial + TpNota.notaFinal)/2;

    if (TpNota.notaPromedio <= 10.5)
        TpNota.estado = 'D';
    else
        TpNota.estado = 'A';

    // Grabacion en archivo NOTAS.txt
    grabaNota<<claveAlum <<endl;
    grabaNota<<claveCurso<< endl;
    grabaNota<<TpNota.notaParcial<< endl;
    grabaNota<<TpNota.notaFinal<< endl;
    grabaNota<<TpNota.notaPromedio<< endl;
    grabaNota<< TpNota.estado <<endl;
}

//******************
// opc6.  LISTA DE NOTAS DE ASIGNATURAS POR ALUMNO
//******************
void f_Notas(ifstream &leeAlumno, ifstream &leeNota, ifstream &leeCurso) {
    string xCdAlumno, xCdCurso, xnotaParcial, xnotaFinal, xnotaPromedio;
    short claveAlum, claveCurso;
    bool find = false;

    // Buscar Alumno por Codigo
    fflush(stdin);
    cout<<"Ingresar Codigo de Alumno---> ";
    cin>>claveAlum;
    getline(leeAlumno, xCdAlumno);
    istringstream(xCdAlumno)>>TpAlumno.cdAlumno;

    while (!leeAlumno.eof() && !find) {
        getline(leeAlumno, TpAlumno.nombreAlumno);
        if (TpAlumno.cdAlumno == claveAlum) {
            cout<<"\n";
            cout<<"\nCodigo Alumno-------> "<<TpAlumno.cdAlumno;
            cout<<"\nNombre Alumno-------> "<<TpAlumno.nombreAlumno;
            cout<<"\n**************************************"<<endl;
            find = true;
        }
        getline(leeAlumno, xCdAlumno);
        istringstream(xCdAlumno)>>TpAlumno.cdAlumno;
    }

    if (find == false){
        cout<<"Codigo de alumno no existe, Ingrese un codigo valido...."<< endl;
        Sleep(2000);
        return;
    }
    // claveAlum tiene el codigo de alumno buscado
    cout <<"Alumno buscado es "<< claveAlum;

    // Busqueda de Notas del Alumno
    getline(leeNota, xCdAlumno);
    istringstream(xCdAlumno)>>TpNota.cdAlumno;
    while (!leeNota.eof()){
        getline(leeNota, xCdCurso);
        istringstream(xCdCurso)>>TpNota.cdCurso;
        getline(leeNota, xnotaParcial);
        istringstream(xnotaParcial)>>TpNota.notaParcial;
        getline(leeNota, xnotaFinal);
        istringstream(xnotaFinal)>>TpNota.notaFinal;
        getline(leeNota, xnotaPromedio);
        istringstream(xnotaPromedio)>>TpNota.notaPromedio;
        leeNota>>TpNota.estado;
        leeNota.ignore(); // ignore newline character after estado

        if (TpNota.cdAlumno == claveAlum){
            find = false;
            getline(leeCurso, xCdCurso);
            istringstream(xCdCurso)>>TpCurso.cdCurso;

            while (!leeCurso.eof() && find == false){
                getline(leeCurso, TpCurso.nombreCurso);
                if (TpNota.cdCurso == TpCurso.cdCurso){
                    cout<<"\n";
                    cout<<"\nAsignatura-----> "<<TpCurso.nombreCurso;
                    cout<<"\nNota Parcial---> "<<TpNota.notaParcial;
                    cout<<"\nNota Final-----> "<<TpNota.notaFinal;
                    cout<<"\nNota Promedio--> "<<TpNota.notaPromedio;
                    cout<<"\nEstado---------> "<<TpNota.estado;
                }
                getline(leeCurso, xCdCurso);
                istringstream(xCdCurso)>>TpCurso.cdCurso;
            }
            find = true;
        }
        getline(leeNota, xCdAlumno);
        istringstream(xCdAlumno) >> TpNota.cdAlumno;
    }
}

//**************************************
// MODIFICAR REGISTROS NOTAS OPCION 7
//**************************************
void f_ModificarNota(ifstream &leeAlumno, ifstream &leeCurso, fstream &notaFile) {
    string xCdAlumno, xCdCurso, xnotaParcial, xnotaFinal, xnotaPromedio;
    short claveAlum, claveCurso;
    bool find = false;
    long pos = 0;

    // Buscar Alumno por Codigo
    fflush(stdin);
    cout<<"Ingresar Codigo de Alumno---> ";
    cin>>claveAlum;
    getline(leeAlumno, xCdAlumno);
    istringstream(xCdAlumno)>>TpAlumno.cdAlumno;

    while (!leeAlumno.eof() && !find) {
        getline(leeAlumno, TpAlumno.nombreAlumno);
        if (TpAlumno.cdAlumno == claveAlum) {
            cout<<"\n- - - - - - - - - - - - - ";
            cout<<"\nCodigo Alumno-------> "<<TpAlumno.cdAlumno;
            cout<<"\nNombre Alumno-------> "<<TpAlumno.nombreAlumno;
            cout<<"\n - - - - - - - - - -"<<endl;
            find = true;
        }
        getline(leeAlumno, xCdAlumno);
        istringstream(xCdAlumno) >> TpAlumno.cdAlumno;
    }

    if (find == false) {
        cout<<"Codigo de alumno no existe, Ingrese un codigo valido...."<<endl;
        Sleep(2000);
        return;
    }
    find = false;

    // Busqueda de Notas del Alumno
    string tempFilename="D:\\Pruebas\\temp_nota.txt";
    ofstream tempFile(tempFilename.c_str(), ios::out);
    notaFile.seekg(0);
    getline(notaFile, xCdAlumno);
    istringstream(xCdAlumno)>>TpNota.cdAlumno;
    while (!notaFile.eof()){
        getline(notaFile, xCdCurso);
        istringstream(xCdCurso)>>TpNota.cdCurso;
        getline(notaFile, xnotaParcial);
        istringstream(xnotaParcial)>>TpNota.notaParcial;
        getline(notaFile, xnotaFinal);
        istringstream(xnotaFinal)>>TpNota.notaFinal;
        getline(notaFile, xnotaPromedio);
        istringstream(xnotaPromedio)>>TpNota.notaPromedio;
        notaFile>>TpNota.estado;
        notaFile.ignore(); // ignore newline character after estado

        if (TpNota.cdAlumno == claveAlum) {
            find = true;
            cout<<"\nIngresar nueva Nota Parcial ---> ";
            cin>>TpNota.notaParcial;
            cout<<"\nIngresar nueva Nota Final ---> ";
            cin>>TpNota.notaFinal;
            TpNota.notaPromedio=(TpNota.notaParcial + TpNota.notaFinal) / 2;

            if (TpNota.notaPromedio <= 10.5)
                TpNota.estado = 'D';
            else
                TpNota.estado = 'A';
        }
        tempFile<<TpNota.cdAlumno << endl;
        tempFile<<TpNota.cdCurso << endl;
        tempFile<<TpNota.notaParcial << endl;
        tempFile<<TpNota.notaFinal << endl;
        tempFile<<TpNota.notaPromedio << endl;
        tempFile<<TpNota.estado << endl;

        getline(notaFile, xCdAlumno);
        istringstream(xCdAlumno)>>TpNota.cdAlumno;
    }
    tempFile.close();
    notaFile.close();
    remove("D:\\Pruebas\\nota.txt");
    rename(tempFilename.c_str(), "D:\\Pruebas\\nota.txt");

    cout<<"Notas modificadas correctamente."<<endl;
}






void menu() {
    system("CLS");
    cout<<"\tMENU DE OPCIONES"<<endl<<endl;
    cout<<"1.- Registro de Alumnos "<<endl;
    cout<<"2.- Lista de Alumnos "<<endl;
    cout<<"3.- Registro de Cursos "<<endl;
    cout<<"4.- Lista de Cursos "<<endl;
    cout<<"5.- Registro de Notas por alumno"<<endl;
    cout<<"6.- Mostrar Notas de Alumno" <<endl;
    cout<<"7.- Modificar Notas por Alumno "<<endl;
    cout<<"0.- SALIR PROGRAMA" << endl<<endl;
    cout<<"Ingrese Opcion ---> ";
}


int main() {
    char opc = ' ';
    do {
        menu();
        cin>>opc;
        system("CLS");
        switch(opc){
            case '1':{
                ofstream GrabaAlumno("D:\\Pruebas\\alumno.txt", ios::app);
                f_AdicionaAlumno(GrabaAlumno);
                GrabaAlumno.close();
                break;
            }
            case '2': {
                ifstream LeerAlumno("D:\\Pruebas\\alumno.txt", ios::in);
                if (LeerAlumno.fail()) {
                    cout << "Error en el archivo..." << endl;
                    Sleep(2000);
                    exit(1);
                }
                f_LeeAlumno(LeerAlumno);
                LeerAlumno.close();
                break;
            }
            case '3': {
                ofstream GrabaCurso("D:\\Pruebas\\curso.txt", ios::app);
                f_AdicionaCurso(GrabaCurso);
                GrabaCurso.close();
                break;
            }
            case '4': {
                ifstream LeerCurso("D:\\Pruebas\\curso.txt", ios::in);
                if (LeerCurso.fail()) {
                    cout<<"Error en el archivo..." << endl;
                    Sleep(2000);
                    exit(1);
                }
                f_LeeCurso(LeerCurso);
                LeerCurso.close();
                break;
            }
            case '5': {
                ifstream LeerAlumno("D:\\Pruebas\\alumno.txt", ios::in);
                ifstream LeerCurso("D:\\Pruebas\\curso.txt", ios::in);
                ofstream GrabaNota("D:\\Pruebas\\nota.txt", ios::app);
                f_GrabaNota(LeerAlumno, LeerCurso, GrabaNota);
                LeerAlumno.close();
                LeerCurso.close();
                GrabaNota.close();
                break;
            }
            case '6': {
                ifstream LeerAlumno("D:\\Pruebas\\alumno.txt", ios::in);
                ifstream LeerNota("D:\\Pruebas\\nota.txt", ios::in);
                ifstream LeerCurso("D:\\Pruebas\\curso.txt", ios::in);
                f_Notas(LeerAlumno, LeerNota, LeerCurso);
                LeerAlumno.close();
                LeerNota.close();
                LeerCurso.close();
                break;
            }
            case '7': {
                ifstream LeerAlumno("D:\\Pruebas\\alumno.txt", ios::in);
                ifstream LeerCurso("D:\\Pruebas\\curso.txt", ios::in);
                fstream NotaFile("D:\\Pruebas\\nota.txt", ios::in | ios::out);
                f_ModificarNota(LeerAlumno, LeerCurso, NotaFile);
                LeerAlumno.close();
                LeerCurso.close();
                NotaFile.close();
                break;
            }
        }
        cout << "\n\nPresione una tecla para continuar....";
        getch();
    } while (opc != '0');

    return 0;
}


