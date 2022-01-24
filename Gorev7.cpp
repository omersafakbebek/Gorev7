#include <iostream>
#include <stdlib.h>
#include <valarray>
using namespace std;

int main(int argc, char* argv[]){
	int coefficient = atoi(argv[1]);
	int numberOfRows= atoi(argv[2]);
	int numberOfColumns= (argc-3)/numberOfRows;	
	valarray<int> matrix (argc-3);
	for (int i = 3; i<argc;i++){
		matrix[i-3]=atoi(argv[i]);		
	}
	for (int i = 0;i<numberOfRows;i++){
		valarray<int> row = matrix[slice(i*numberOfColumns,numberOfColumns,1)];		
		if (i==0){
			valarray<int> coefvector (numberOfColumns);
			for (int j = 0; j<numberOfColumns;j++){
				coefvector[j]=coefficient;
			}
			row = row*coefvector;
		}		
		for (int j = 0; j<numberOfColumns;j++){			
			cout << row[j] << " ";			
		}
		cout << "\n";
	}	
}
