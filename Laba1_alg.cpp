#include <iostream>
#include <clocale>
#include <ctime>

#define N 18

using namespace std;

int alg_S(int* K, int k);
int alg_Q(int* K, int k);
int alg_T(int* K, int k);
int alg_BIN(int* K, int k);
int _count=0;

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	int K[N + 1], k, ks, temp;
	double timeS=0;

	for (int i = 0; i < N; i++)
	{
		K[i] = i+1 /*rand() % 1000*/;
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", K[i]);
	}
	printf("\n");
	printf("Введите ключ: ");
	cin >> k;
	printf("\n");
	ks = alg_S(K, k);
	if (ks != -1) printf("Результат алгоритма S: Ключ найден на %d индексе; количество сравнений: %d\n", ks, _count+1);
	else printf("Результат алгоритма S: Ключ не найден; количество сравнений: %d\n", _count);
	
	_count = 0;
	ks = alg_Q(K, k);
	if (ks != -1) printf("Результат алгоритма Q: Ключ найден на %d индексе; количество сравнений: %d\n", ks, _count+1);
	else printf("Результат алгоритма Q: Ключ не найден; количество сравнений: %d\n", _count);

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (K[j] > K[j + 1]) {
				temp = K[j];
				K[j] = K[j + 1];
				K[j + 1] = temp;
			}
		}
	}
	printf("\n");

	for (int i = 0; i < N; i++)
	{
		printf("%d ", K[i]);
	}
	printf("\n\n");
	
	_count = 0;
	ks = alg_T(K, k);
	if(ks != -1) printf("Результат алгоритма T: Ключ найден на %d индексе; количество сравнений: %d\n", ks, _count+1);
	else printf("Результат алгоритма T: Ключ не найден; количество сравнений: %d\n", _count+1);

	_count = 0;
	ks = alg_BIN(K, k);
	if (ks != -1) printf("Результат алгоритма BIN: Ключ найден на %d индексе; количество сравнений: %d\n", ks, _count+1);
	else printf("Результат алгоритма BIN: Ключ не найден; количество сравнений: %d\n", _count+1);

	system("pause");
	return 0;
}

int alg_S(int* K, int k)
{
	int i = 0;
	while (i < N)
	{
		_count++;
		if (K[i] != k) i++;
		else return i + 1;
	}
	return -1;
}

int alg_Q(int* K, int k)
{
	int i = 0;
	K[N] = k;
	for (i; i <= N; i++)
	{
		if (K[i] == k)
			break;
		_count++;
	}
	if (i < N)
		return i + 1;
	else
		return -1;
}

int alg_T(int* K, int k)
{
	int i = 0;

	K[N] = k;

	while (k > K[i])
	{
		i++;
		_count++;
	}
	if (k == K[i])
		return i + 1;
	else
		return -1;
}

int alg_BIN(int* K, int k)
{
	int iN = 0, iK = N, i;
	while (iN < iK)
	{
		i = (iN + iK) / 2;
		if (k < K[i]) 
		{
			iK=i;
			_count+=2;
		}
		else
			if (k == K[i])
			{
				_count+=3;
				return i + 1;
			}
			else
			{
				_count+=3;
				iN=i;
			}
	}
	return -1;
}
