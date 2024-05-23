#include <iostream>
#include <vector>
#include <algorithm>

//A funcao a seguir calcula o maior valor possivel que pode ser acumulado ate cada um dos elementos da matriz
void calcularCaminhoMaximo(long long int** dados, long long int** resultados, int numLin, int numCol) {

	for (int cnt = 0; cnt != numCol; cnt++) {
		resultados[0][cnt] = dados[0][cnt];
	}

	for (int i = 1; i != numLin; i++) {
		for (int j = 0; j != numCol; j++) {
			if (j == 0) {
				resultados[i][j] = dados[i][j] + std::max(resultados[i - 1][j], resultados[i - 1][j + 1]);
			}
			else if (j == numCol-1) {
				resultados[i][j] = dados[i][j] + std::max(resultados[i - 1][j - 1], resultados[i - 1][j]);
			}
			else {
				resultados[i][j] = dados[i][j] + std::max(std::max(resultados[i - 1][j - 1], resultados[i - 1][j]), resultados[i - 1][j + 1]);
			}
		}
	}
}

//Essa funcao recupera os indices do caminho que levam ao valor maximo
std::vector<int> recuperarCaminho(long long int** dados, long long int** resultados, int numLin, int numCol, int indiceMaximo) {

	std::vector<int> caminho;
	int indiceCaminho = indiceMaximo;
	long long int valorOrigem = 0;
	long long int valor = resultados[numLin - 1][indiceMaximo];
	caminho.insert(caminho.begin(), indiceCaminho);

	for (int linha = numLin - 2; linha >= 0; linha--) {
		valorOrigem = valor - dados[linha + 1][indiceCaminho];
		if (indiceCaminho > 0 && indiceCaminho < numCol - 1) {
			if (valorOrigem == resultados[linha][indiceCaminho - 1]) {
				valor = resultados[linha][indiceCaminho - 1];
				indiceCaminho -= 1;
			}
			else if (valorOrigem == resultados[linha][indiceCaminho]) {
				valor = resultados[linha][indiceCaminho];
			}
			else if (valorOrigem == resultados[linha][indiceCaminho + 1]) {
				valor = resultados[linha][indiceCaminho + 1];
				indiceCaminho += 1;
			}
		}
		else if (indiceCaminho == 0) {
			if (valorOrigem == resultados[linha][indiceCaminho]) {
				valor = resultados[linha][indiceCaminho];
			}
			else if (valorOrigem == resultados[linha][indiceCaminho + 1]) {
				valor = resultados[linha][indiceCaminho + 1];
				indiceCaminho += 1;
			}
		}
		else if (indiceCaminho == numCol - 1) {
			if (valorOrigem == resultados[linha][indiceCaminho - 1]) {
				valor = resultados[linha][indiceCaminho - 1];
				indiceCaminho -= 1;
			}
			else if (valorOrigem == resultados[linha][indiceCaminho]) {
				valor = resultados[linha][indiceCaminho];
			}
		}
		caminho.insert(caminho.begin(), indiceCaminho);
	}

	return caminho;
}

//A funcao a seguir libera a memoria alocada para a matriz
void liberarMemoria(long long int** matriz, int numLin) {

	for (int cnt = 0; cnt != numLin; cnt++) {
		delete matriz[cnt];
	}

	delete matriz;

}

int main() {

	//Declaracao das variaveis que serao utilizadas
	int numeroDeLinhas, numeroDeColunas;
	long long int numeroDeFrutas = 0;
	std::cin >> numeroDeLinhas >> numeroDeColunas;

	//Declaracao das matrizes
	long long int** mapaDeFrutas = new long long int* [numeroDeLinhas];
	long long int** resultado = new long long int* [numeroDeLinhas];


	//Inicializa-se uma matrizes com os dados e outra com zeros que serao 
	//substituidos pelos resultados obtidos ao longo do processo 
	for (int i = 0; i != numeroDeLinhas; i++) {
		mapaDeFrutas[i] = new long long int[numeroDeColunas];
		resultado[i] = new long long int[numeroDeColunas];

		for (int j = 0; j != numeroDeColunas; j++) {
			std::cin >> numeroDeFrutas;
			mapaDeFrutas[i][j] = numeroDeFrutas;
			resultado[i][j] = 0;
		}
	}

	//Chama-se a funcao que ira calcular os resultados
	calcularCaminhoMaximo(mapaDeFrutas, resultado, numeroDeLinhas, numeroDeColunas);

	//Variaveis que guardarao o valor Maximo e o indice em que ele se encontra
	int indiceDoMaximo = 0;
	long long int valorMaximo = resultado[numeroDeLinhas - 1][0];

	//O loop a seguir encontra esses valores
	for (int cnt = 1; cnt != numeroDeColunas; cnt++) {
		if (resultado[numeroDeLinhas - 1][cnt] > valorMaximo) {
			indiceDoMaximo = cnt;
			valorMaximo = resultado[numeroDeLinhas - 1][cnt];
		}
	}

	//Agora, recupera-se o caminho que levou ao valor maximo
	std::vector<int> caminhoMaximo;
	caminhoMaximo = recuperarCaminho(mapaDeFrutas, resultado, numeroDeLinhas, numeroDeColunas, indiceDoMaximo);

	//Exibe-se o resultado obtido
	std::cout << valorMaximo << "\n";
	for (int cnt = 0; cnt != caminhoMaximo.size() - 1; cnt++) {
		std::cout << caminhoMaximo[cnt] << " ";
	}
	std::cout << caminhoMaximo[caminhoMaximo.size() - 1];

	//Por fim, desaloca-se a memoria utilizada
	liberarMemoria(mapaDeFrutas, numeroDeLinhas);
	liberarMemoria(resultado, numeroDeLinhas);

	return 0;
}