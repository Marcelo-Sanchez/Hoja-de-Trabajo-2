#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
struct productos{
	int code;
	int nivelm;
	int nivela;
	string proveedor;
	int precio;
	
};

void insertar_datos_archivo();
void read_file();
void nivelmi(productos & ingreso);
void mp();//menu principal


int main(){
	///producto datos;	
	mp();
//	nivel minimo (datos);
	//read_file();
	
	
}

void nivelmi(productos & ingreso){
	ofstream archivo;
	string nombreArchivo;
	fflush(stdin); //borrar el buffer existente
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombreArchivo);
	
	/*Comprobar archivo*/
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	system("CLS");
	int nivelm,nivela,precio,code;	
	string proveedor;

	/*Ingreso de datos*/
	cout<<"Ingrese Codigo del producto: "<<endl;
	cin>>code; //ingreso.code;
	fflush(stdin);
	cout<<"Ingrese Nivel Minimo: "<<endl;
	cin>>nivelm;
	cout<<"Ingrese Nivel Actual: "<<endl;
	cin>>nivela;
	cout<<"Ingrese el proveedor : "<<endl;
	cin>>proveedor;
	cout<<"Ingrese El precio del producto: "<<endl;
	cin>>precio;
	/*Calculos*/
	if (nivela==nivelm);
	
	/*Abrir, Grabar datos al archivo y cerrarlo*/
	archivo.open(nombreArchivo.c_str(),ios::app);
	archivo<<code<<"\t"<<nivelm<<"\t"<<nivela<<"\t"<<proveedor<<"\t"<<precio<<endl;
	archivo.close();
}

void mp(){
	int i;
	productos datos;
	
	do {
		system("CLS");
		cout<<"-------------------"<<"\n";
		cout<<"Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<"1 - Agregar productos "<<"\n";
		cout<<"2 - Leer archivo"<<"\n";
		cout<<"3 - Salir"<<"\n";
		cout<<"-------------------\n";
		cout<<"Seleccione su opcion: ";
		cin>>i;
		if (i==1)
			nivelmi(datos);
		else if (i==2)
			read_file();			
		else if (i==3) 	
			break;
		else 
			break;
		
	} while(i!=4);	
}


void read_file(){
	ifstream archivo; //leer archivo
	string nombreArchivo;
	int lineas,i=0;
	string s,linea;


	float sumatotal=0;
	fflush(stdin);
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}
	

	while (getline(archivo, s))
        lineas++;
        
    archivo.close();
    system("CLS");
	//cout<<"Lineas: "<<lineas<<endl;
	productos recordset_r[lineas];
		
	archivo.open(nombreArchivo.c_str(),ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	/*Leer datos del archivo*/
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        //cout<<"i: "<<i;
        //int codigo de articulo;
	//int nivel minimo;
	//int nivel actual;
	//float proveedor;
	//int precio;

        archivo>>recordset_r[i].code>>recordset_r[i].nivelm>>recordset_r[i].nivela>> recordset_r[i].proveedor >> recordset_r[i].precio;

    }
    archivo.close();    
    
    
    for (int i = 0; i < lineas; i++)
    {
    	cout<<"Registro: "<<i<<endl; 
    	cout<<"Codigo"<<setw(10)<<"nivelminimo "<<setw(10)<<"nivelactual"<<setw(10)<<"proveedor"<<setw(10)<<"precio"<<endl;
    	cout<<recordset_r[i].code<<setw(10)<<recordset_r[i].nivelm<<setw(10)<<recordset_r[i].nivela<<setw(10)<<recordset_r[i].proveedor<<setw(10)<<recordset_r[i].precio<<endl;
		
	}
	
	system("Pause");
	
}

void insertar_datos_archivo(){
	cout<<"Insertando datos\n\n";
	system("PAUSE");
	system("CLS");
}
