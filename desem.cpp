#include <iostream>

using namespace std;


//Inicializador de memoria.
void initMemory(int * memoria){
	for(int i = 0; i < (sizeof(memoria)/sizeof(int)); i++){
		memoria[i] = 0;
	}
}

//Imprimir memoria.
void printMemory(int * memoria, int from, int to){
	cout << "\n";
	for(int i = from; i < to; i++){
		cout << memoria[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char ** argv){
	//Instrucciones del programa a realizar.
	//int program[] = {2,7, 4, 100, 3, 20, 5, 10, 15, 14, 16, 14, 1, 8, 5, 102, 0};
	int program[] = {1,32,2,12,3,12,4,12,5,12,6,12,7,12,8,9,10,12,11,12,12,13,1,16,1,0,14,15,16,14,17,18,0,17,16};
	//Memoria disponible.
	int memoria[1024];
	
	//Se inicializa la memoria.
	initMemory(memoria);
	
	//Registros X y Y
	int xReg = 0, yReg = 0;
	
	for(int i=0; i< (sizeof(program)/sizeof(program[0]));){
		switch(program[i]){
		
			case 1:
				// JMP #
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				cout << i << ":" << memoria[i] << " " << memoria[i+1] << "\t\tJMP " << program[i+1] << "\n";
				i+=2;
			break;

			case 2:
				// MOV X, #
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				xReg = memoria[i+1];
				cout << i <<":" << memoria[i] << " " << memoria[i+1] << "\t\tMOV x, " << program[i+1] << "\n";
				i+=2;
			break;	
			
			case 4:
				//MOV M, x
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				memoria[memoria[i+1]] = xReg;
				cout << i << ":" << memoria[i] << " " << memoria[i+1] << "\t\tMOV " << program[i+1] << ", "<< program[i]  << "\n";
				i+=2;	
			break;

			case 3:
				//MOV Y, #
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				yReg = memoria[i+1];
				cout << i << ":" << memoria[i] << " " << memoria[i+1] <<"\t\tMOV y, " << program[i+1] << "\n";
				i+=2;
			break;
			
			case 5:
				//MOV M, Y
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				memoria[memoria[i+1]] = yReg;
				cout << i << ":" << memoria[i] << " " << memoria[i+1] << "\t\tMOV "<< program[i+1] << ", " << program[i] << "\n";
				i+= 2;
			break;
			
			case 6:
				//MOV X, M
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				xReg = memoria[memoria[i+1]];
				cout << i << ":" << memoria[i] << " " << memoria[i+1] << "\t\tMOV x, " << program[i+1] << "\n";
				i+=2;
			break;	
			
			case 7:
				//MOV Y, M
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				yReg = memoria[memoria[i+1]];
				cout << i << ":" << memoria[i] << " " << memoria[i+1] << "\t\tMOV y, " << program[i+1] << "\n";
				i+=2;

			break;
					
			case 8:
				//ADD X, Y
				memoria[i] = program[i];
				xReg += yReg;
				cout << i << ":" << memoria[i] <<"\t\tADD x, y" << "\n";
				i+= 1;
			break;

			case 9:
				//ADD Y, X
				memoria[i] = program[i];
				yReg += xReg;
				cout << i << ":" << memoria[i] <<"\t\tADD x, y" << "\n";
				i+= 1;
			break;
			
			case 10:
				//ADD X, #
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				xReg += memoria[i+1];
				cout << i << ":" <<  memoria[i] << " " << memoria[i+1] <<"\t\tADD x, " << memoria[i+1] << "\n";
				i+= 2;
			break;

			case 11:
				//ADD Y, #
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				yReg += memoria[i+1];
				cout << i << ":" <<  memoria[i] << " " << memoria[i+1] <<"\t\tADD x, " << memoria[i+1] << "\n";
				i+= 2;
			break;
			
			case 12:
				//INC X
				memoria[i] = program[i];
				xReg += 1;
				cout << i << ":" << memoria[i] << " " << "\t\tINC x\n";
				i+=1;
			break;

			case 13:
				//INC Y
				memoria[i] = program[i];
				yReg += 1;
				cout << i << ":" << memoria[i] << " " << "\t\tINC y\n";
				i+=1;
			break;
			
			case 14:
				//DEC X
				memoria[i] = program[i];
				xReg -= 1;
				cout << i << ":" << memoria[i] << " " << "\t\tDEC x\n";
				i+=1;
			break;
			
			case 15:
				//DEC Y
				memoria[i] = program[i];
				yReg -= 1;
				cout << i << ":" << memoria[i] << " " << "\t\tDEC y\n";
				i+=1;
			break;
			
			case 16:
				//JZ X, #
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				cout << i << ":" << memoria[i] << " " << memoria[i+1] << "\t\tJZ x, " << program[i+1] << "\n"; 
				i+= 2;
			break;
			
			case 17:
				//JZ Y, #
				memoria[i] = program[i];
				memoria[i+1] = program[i+1];
				cout << i << ":" << memoria[i] << " " << memoria[i+1] << "\t\tJZ y, " << program[i+1] << "\n"; 
				i+= 2;
			break;			

			case 0:
				//END
				memoria[i] = program[i];
				cout << i << ":"  << memoria[i]  <<"\t\tEND\n";
				return 0;
			break;

			defualt:
				i++;
			}
			//printMemory(memoria, 100, 105);
			//cout << "xReg: " << xReg << "\n";
			//cout << "yReg: " << yReg << "\n";	
		}
	return 0;
}

