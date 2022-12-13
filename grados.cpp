#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "grado.dat";

struct Grado{
	int codigo;
	char nombre[50];
	
};
void ingresar();
void abrir();


int main (){
	abrir();
 ingresar();
	
	return 0;	
}


void abrir(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Grado grado;
	int registro=0;
	fread ( &grado, sizeof(Grado), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< grado.codigo <<" | "<< grado.nombre<<" "<<endl;
        
        
		fread ( &grado, sizeof(Grado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
	Grado grado;
		 string nombre;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>grado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(grado.nombre, nombre.c_str()); 
			
		
		
		fwrite( &grado, sizeof(Grado), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir();
	
	
}

