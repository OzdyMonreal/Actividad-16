#include "laboratorio.h"
#include <fstream>
#include <algorithm>

Laboratorio::Laboratorio() {
}

void Laboratorio::agregarFinal(const Computadora &c) {
  computadoras.push_back(c);
}

void Laboratorio::mostrar() {
  cout << left;
  cout << setw(25) << "Modelo";
  cout << setw(25) << "Sistema Operativo";
  cout << setw(25) << "Procesador";
  cout << setw(15) << "RAM";
  cout << endl;
  for (size_t i = 0; i < computadoras.size(); i++) {
    Computadora c = computadoras[i];

    cout << c;
  }
}

void Laboratorio::respaldar_tabla()
{
  ofstream archivo ("computadoras.txt");
  if (archivo.is_open()) {
      archivo << left;
      archivo << setw(25) << "Modelo";
      archivo << setw(25) << "Sistema Operativo";
      archivo << setw(25) << "Procesador";
      archivo << setw(15) << "RAM";
      archivo << endl;
      for (size_t i = 0; i < computadoras.size(); i++) {
          Computadora &c = computadoras[i];
          archivo << c;
      }
  }
  archivo.close();
}

void Laboratorio::respaldar()
{
  ofstream archivo("computadoras.txt");
  if (archivo.is_open()) {
      for (size_t i = 0; i < computadoras.size(); i++) {
          Computadora &c = computadoras[i];
          archivo << c.getModelo() << endl;
          archivo << c.getSisOp() << endl;
          archivo << c.getProcesador() << endl;
          archivo << c.getMemoriaRam() << endl;
      }
  }
  archivo.close();
}

void Laboratorio::recuperar() {
  ifstream archivo("computadoras.txt");
  if (archivo.is_open()) {
    string temp;
    int memoriaRam;
    Computadora c;

    while (true)
    {

      getline(archivo, temp); // Modelo
      c.setModelo(temp);

      getline(archivo, temp); // Sistema Operativo
      if (archivo.eof()) break;
      c.setSisOp(temp);

      getline(archivo, temp); // Procesador
      c.setProcesador(temp);

      getline(archivo, temp); // RAM
      memoriaRam = stoi(temp);
      c.setMemoriaRam(memoriaRam);

      agregarFinal(c);
    }
  }
  archivo.close();
}

void Laboratorio::insertar(const Computadora &c, size_t pos)
{
    computadoras.insert(computadoras.begin() + pos, c);
}

size_t Laboratorio::size()
{
    return computadoras.size();
}

void Laboratorio::inicializar(const Computadora &c, size_t n)
{
    computadoras = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t pos)
{
    computadoras.erase(computadoras.begin() + pos);
}

void Laboratorio::ordenar()
{
    sort(computadoras.begin(), computadoras.end());
}
void Laboratorio::ordenarSistemaOP()
{
    sort(computadoras.begin(), computadoras.end(), 
    [](Computadora c1, Computadora c2){return c1.getSisOp() < c2.getSisOp();});
}
void Laboratorio::ordenarProcesador()
{
    sort(computadoras.begin(), computadoras.end(),
    [](Computadora c1, Computadora c2){return c1.getProcesador() > c2.getProcesador();});
}
void Laboratorio::ordenarMemoriaRam()
{
    sort(computadoras.begin(), computadoras.end(),
    [](Computadora c1, Computadora c2){return c1.getMemoriaRam() < c2.getMemoriaRam();});
}

Computadora* Laboratorio::buscar(const Computadora &c)
{
    // vector<Computadora>::iterator
    auto it = find(computadoras.begin(), computadoras.end(), c);

    if (it == computadoras.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}