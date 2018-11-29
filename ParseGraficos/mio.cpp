#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include <stack>
using namespace std; 
///COMPILAR ASI ---->   g++ -std=c++0x mio.cpp -o a

vector<string> guardados;
void metodoArchivo() {//Lee caracter por caracter del Archivo .txt
    //int linea = 0;
    ifstream fichero; //variable fichero para leer los datos
    fichero.open(("training_log_1543511205096.txt"));
    //fichero.get(caracter);
    string frase,token;

    if (fichero.fail()) {// si fichero no falla coge un letra dle fichero
        cout << "Error al abrir el training_log_1543511205096.txt" << endl;

    } 
    else {
        while (!fichero.eof()) {//mientras fichero no llegue al final
        	//listarecorrido.push_back(caracter);

            //fichero.get(caracter);
            getline(fichero,frase);
            
            
            ///Tokens
            istringstream iss(frase);
			while(getline(iss,token,' '))
			{
			    if (token=="accuracy")
			    	guardados.push_back(frase);
			}

        }
    }
    fichero.close();
}
void tokeniza()
{	string token;
	ofstream ficheroSalida;
	ficheroSalida.open ("data.csv");

	for(int i=0;i<guardados.size();i++)
	{
		istringstream iss(guardados[i]);
		int id=0;
		while(getline(iss,token,' '))
		{
		    if(id==0 or id==3 or id==4)
		    {
		    	ficheroSalida<<token<<"\t";
		    }	
		    id++;
		}
		ficheroSalida<<endl;
	}
	ficheroSalida.close(); 

}

int main()
{
  metodoArchivo();
  tokeniza();
  return 0;
}