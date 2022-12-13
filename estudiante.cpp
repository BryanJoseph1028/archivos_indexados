#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "estudiante.dat";
const char *nombe_archivo_g = "grado.dat";
struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	int grado;
};
struct Grado{
	int codigo;
	char nombre[50];
	
};
void ingresar_estudiante();
void abrir_estudiante();
void mostrar_grado();
bool validar_grado(int);
string buscar_grado_nombre(int);


int main (){
	abrir_estudiante();
 ingresar_estudiante();


	return 0;	
}



void abrir_estudiante(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" | "<<"GRADO"<<" "<<endl;	
		do{
			
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre<<" "<<estudiante.apellido<<" | "<<buscar_grado_nombre(estudiante.grado)<<endl;    
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Estudiante estudiante;
		string nombre,apellido;
		int e=0;
		do{
			
			fflush(stdin);
				
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		mostrar_grado();
		int g=0;
		cout<<"Ingrese el Codigo del Grado:";
		cin>>g;
		cin.ignore();
		if (validar_grado(g)==1){
			estudiante.grado = g;
		}else{
			system("cls");
			e=1;
			cout<<"Mensaje de Error:"<<endl;
			cout<<"El codigo de Grado #"<<g<<" No existe:"<<endl;
			system("PAUSE");
			break;
		}
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	
	abrir_estudiante();
	if (e==1){
	ingresar_estudiante();
	}
	
	
}
void mostrar_grado(){
	
	FILE* archivo = fopen(nombe_archivo_g, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo_g, "w+b");
	}
	Grado grado;
	int registro=0;
	fread ( &grado, sizeof(Grado), 1, archivo );
	
	
		do{
			
			
		cout<< grado.codigo <<"="<< grado.nombre<<". ";
		 
		fread ( &grado, sizeof(Grado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
    	cout<<endl;
		fclose(archivo);
	}
	
bool validar_grado(int c){
	bool r=false;
	FILE* archivo = fopen(nombe_archivo_g, "rb");
	int indice=0,pos=0,cod=0;
	Grado grado;
	fread ( &grado, sizeof(Grado), 1, archivo );
		do{
			if (grado.codigo == c){
			pos = indice;
			r=true;
			}
		fread ( &grado, sizeof(Grado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );
    fread ( &grado, sizeof( Grado ), 1, archivo );
	fclose(archivo);
	
	return r;
}

string buscar_grado_nombre(int c){
	string nombre="";
	FILE* archivo = fopen(nombe_archivo_g, "rb");
	int indice=0,pos=0,cod=0;
	Grado grado;
	fread ( &grado, sizeof(Grado), 1, archivo );
		do{
			if (grado.codigo == c){
			pos = indice;
			}
		fread ( &grado, sizeof(Grado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
	fseek ( archivo,pos * sizeof(Grado), SEEK_SET );
    fread ( &grado, sizeof( Grado ), 1, archivo );
    
     nombre = grado.nombre;
	fclose(archivo);
	
	return nombre;
}



