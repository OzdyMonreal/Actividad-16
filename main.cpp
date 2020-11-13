#include <iostream>
#include "laboratorio.h"

using namespace std;

int main() {
  Laboratorio lab;
  string op;

  while (true)
  {
    fflush(stdin);
    cout << "1) Agregar Computadora" << endl;
    cout << "2) Mostrar" << endl;
    cout << "3) Respaldar" << endl;
    cout << "4) Recuperar" << endl;
    cout << "5) Insertar" << endl;
    cout << "6) Inicializar" << endl;
    cout << "7) Eliminar" << endl;
    cout << "8) Ordenar" << endl;
    cout << "9) Buscar" << endl;
    cout << "10) Ordenar Sistema Operativo" << endl;
    cout << "11) Ordenar Procesador" << endl;
    cout << "12) Ordenar Memoria RAM" << endl;
    cout << "0) Salir" << endl;
    getline(cin, op);

    if (op == "1") {
      Computadora c;

      cin >> c;

      lab.agregarFinal(c); 
fflush(stdin);

    } 
    else if (op == "2") {
      lab.mostrar();
    }
    else if (op == "3") {
        lab.respaldar();
    }
    else if (op == "4") {
        lab.recuperar();
    }
    else if (op == "5") {
      Computadora c;
      cin >> c;

      size_t pos;
      cout << "Posición: ";
      fflush(stdin);
      cin >> pos; 

      if (pos >= lab.size()) {
        cout << "Posición no valida" << endl;
      }
      else {
          lab.insertar(c, pos);
      }
    }
    else if (op == "6") {
      Computadora c;
      cin >> c;

      size_t n;
      cout << "n: ";
      fflush(stdin);
      cin >> n; 

      lab.inicializar(c, n);
    }
    else if (op == "7") {
      size_t pos;
      cout << "Posición: ";
      fflush(stdin);
      cin >> pos; 

      if (pos >= lab.size()) {
          cout << "Posición no valida" << endl;
      }
      else {
          lab.eliminar(pos);
      }
      fflush(stdin);
    }
    else if (op == "8") {
        lab.ordenar();
    }
    else if (op == "9") {
      Computadora c;
      fflush(stdin);
      cin >> c; 
      fflush(stdin);

      Computadora *ptr = lab.buscar(c);

      if (ptr == nullptr) {
        cout << "No encontrado" << endl;
      }
      else {
        cout << *ptr << endl;
      }
    }
    else if (op == "10") {
      lab.ordenarSistemaOP();
      fflush(stdin);
    }
    else if (op == "11") {
      lab.ordenarProcesador();
      fflush(stdin);
    }
    else if (op == "12") {
      lab.ordenarMemoriaRam();
      fflush(stdin);
    }
    else if (op == "0") {
      break;
    }
  }

    return 0;
}