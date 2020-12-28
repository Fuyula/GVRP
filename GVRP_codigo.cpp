#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Nodo {
    public:
    string Id;
    char Type;
    double Longitude;
    double Latitude;
    Nodo(string id, char tipo, double longitud, double latitud){
      Id = id;
      Type = tipo;
      Longitude = longitud;
      Latitude = latitud;
    }
};

int main() {
    ifstream archivo;
    string line;
    char id[1024];
    char tipo;
    double longitud, latitud;
    bool p_linea = true;
    
    vector<Nodo> nodos;

    archivo.open("Instancias_GVRP/S1_2i6s.txt");

    if (archivo.is_open()){
    while ( getline (archivo,line) ){
      if (p_linea)
      {
        p_linea = false;
        continue;
      }
      sscanf(line.c_str(), "%s %c %lf %lf", id, &tipo, &longitud, &latitud);
      nodos.emplace_back(id, tipo, longitud, latitud);
      cout << line << '\n';
    archivo.close();
  }
    return 0;
}