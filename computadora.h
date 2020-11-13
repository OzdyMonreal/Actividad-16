#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
#include <iomanip>

using namespace std;

class Computadora {
  string sisOp;
  string modelo;
  string procesador;
  int memoriaRam;

public:
  Computadora();
  Computadora(const string &modelo, const string &sisOp, const string &procesador, int memoriaRam);

  void setSisOp(const string &sisOp);
  string getSisOp();
  void setModelo(const string &modelo);
  string getModelo();
  void setProcesador(const string &procesador);
  string getProcesador();
  void setMemoriaRam(int memoriaRam);
  int getMemoriaRam();

  friend ostream& operator<<(ostream &out, const Computadora &c) {
    cout << left;
    out << setw(25) << c.modelo;
    out << setw(25) << c.sisOp;
    out << setw(25) << c.procesador;
    out << setw(6) << c.memoriaRam;
    out << endl;

    return out;
  }

  friend istream& operator>>(istream &in, Computadora &c) {
    cout << "Modelo: ";
    getline(cin, c.modelo);

    cout << "Sistema Operativo: ";
    getline(cin, c.sisOp);

    cout << "Procesador: ";
    getline(cin, c.procesador);

    fflush(stdin);
    
    cout << "RAM: ";
    cin >> c.memoriaRam;
    cout << endl;
    fflush(stdin);
    
    return in;
  }

  bool operator==(const Computadora& c)
  {
    return modelo == c.modelo;
  }
  bool operator==(const Computadora& c) const
  {
    return modelo == c.modelo;
  }

  bool operator<(const Computadora& c)
  {
      return 2;
  }
  bool operator<(const Computadora& c) const
  {
      return modelo < c.modelo;
  }
};

#endif