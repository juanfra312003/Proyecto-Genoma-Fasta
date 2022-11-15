#include "Genoma.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

// Funciones de Estetica
void genetica();
void caballo();

int main() {
  // Variables
  string comando;
  Genoma genoma;
  genetica();
  
  //cargar test_genome.fa
  //codificar test_genome.fabin
  
  //cargar AligSeq85678-lin.fa
  //codificar AligSeq85678-lin.fabin  

  while (true) {
    cout << "$";
    getline(cin, comando);

    if (comando == "");

    else if (comando == "listar_secuencias") {
      list<string> lista = genoma.listarSecuencias();
      list<string>::iterator it = lista.begin();
      for (; it != lista.end(); it++)
        cout << "\t" << *it << endl;
      cout << endl;
    }

    else if (comando == "conteo") {
      string cnt = genoma.conteo();
      cout << "\t" << cnt << endl << endl;
    }

    else if (comando == "cls") {
      system("clear");
      genetica();
    }

    else if (comando == "salir") {
      system("clear");
      cout << "Saliendo... HIIIII" << endl;
      caballo();
      return 0;
    }

    else {
      string buffer = comando, arg;
      istringstream i(buffer);
      i >> comando;
      i >> arg;

      if (comando == "cargar") {
        cout << "\t";
        arg = "ArchivosFasta/" + arg;
        int retorno = genoma.cargarInfoArchivo(arg);
        if (retorno == -1)
          cout << arg << " no se encuentra o no puede leerse." << endl << endl;
        else if (retorno == 0)
          cout << arg << " no contiene ninguna secuencia." << endl << endl;
        else if (retorno == 1)
          cout << "1 secuencia cargada correctamente desde " << arg << "." << endl << endl;
        else
          cout << retorno << " secuencias cargadas correctamente desde " << arg << "." << endl << endl;
      }

      else if (comando == "histograma") {
        list<string> lista = genoma.listarhistograma(arg);
        list<string>::iterator it = lista.begin();
        for (; it != lista.end(); it++)
          cout << "\t" << *it << endl;
        cout << endl;
      }

      else if (comando == "codificar") {
        cout << "\t";
        if(arg != ""){
          arg = "ArchivosFasta/"+arg;
          if(!genoma.codificar(arg))
            cout << "No se pueden guardar las secuencias cargadas en " << arg << endl << endl;
          else 
            cout << "Secuencias codificadas y almacenadas en " << arg << endl << endl;
        }
      }

      else if (comando == "decodificar") {
        cout << "\t";
        if(arg != ""){
          arg = "ArchivosFasta/"+arg;
          if(!genoma.decodificar(arg))
            cout << "No se pueden cargar las secuencias en " << arg << endl << endl;
          else 
            cout << "Secuencias decodificadas desde " << arg << " y cargadas en memoria." << endl << endl;
        }
      }
        
      else
        cout << "\tComando invalido " << endl << endl;
    }
  }
}

void genetica() {
  cout << "  -----------------------------------------------------------------" << endl;
  cout << "|   _____  ______  _   _  ______  _______  _____  _____             |" << endl;
  cout << "|  / ____||  ____|| \\ | ||  ____||__   __||_   _|/ ____|    /\\      |" << endl;
  cout << "| | |  __ | |__   |  \\| || |__      | |     | | | |        /  \\     |" << endl;
  cout << "| | | |_ ||  __|  | . ` ||  __|     | |     | | | |       / /\\ \\    |" << endl;
  cout << "| | |__| || |____ | |\\  || |____    | |    _| |_| |____  / ____ \\   |" << endl;
  cout << "|  \\_____||______||_| \\_||______|   |_|   |_____|\\_____|/_/    \\_\\  |" << endl;
  cout << "  -----------------------------------------------------------------" << endl << endl;
}

void caballo() {
  cout << "                    ▒" << endl;
  cout << "                  ▒▒▒" << endl;
  cout << "                 ▒▒░▒" << endl;
  cout << "                ▒▒░░▒" << endl;
  cout << "           ████▒▒▒░░▒" << endl;
  cout << "         ███████▒▒░░▒█" << endl;
  cout << "        █████████▒▒████" << endl;
  cout << "       ████████▒█▒▒█████" << endl;
  cout << "       ████████▒▒▒▒██████" << endl;
  cout << "      ████████▒▒▒▒▒███████" << endl;
  cout << "      ██████▒█▒▒▒▒▒████████" << endl;
  cout << "     ████▒█▒▒▒▒▒▒▒██████████" << endl;
  cout << "      ░▒▒▒░▒▒▒▒▒▒▒███████████" << endl;
  cout << "     ░▒▒▒▒██░▒▒▒▒▒▒███████████" << endl;
  cout << "     ░▒▒▒▒██░▒▒▒▒▒▒███████████" << endl;
  cout << "    ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█████████" << endl;
  cout << "    ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█████████" << endl;
  cout << "   ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒██████" << endl;
  cout << "  ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒██████" << endl;
  cout << "  ░▒█▒▒▒▒▒▒▒▒▒▒▒░ ░▒▒█▒▒██████" << endl;
  cout << "  ░▒██▒▒▒▒▒▒▒▒░░   ░▒▒▒▒██████" << endl;
  cout << "  ░▒▒▒▒▒▒█▒░░       ░▒▒▒██▒███" << endl;
  cout << "  ░▒▒▒▒▒█▒▒░        ░▒▒▒██▒███" << endl;
  cout << "   ░▒▒▒██▒░          ░▒▒██▒███" << endl;
  cout << "     ▒█▒░             ░▒▒█▒███" << endl;
  cout << "                      ░▒▒█▒███" << endl;
  cout << "                       ░▒▒▒███" << endl;
  cout << "                        ░▒░█░█" << endl;
}