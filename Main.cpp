#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void print_arr(T* pa, const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << *(pa + i) << ", ";
	std::cout << "\b\b]\n";
}

template <typename T>
void power(T* n, int m) {
	if (m == 0) {
		*n = 1;
		return;
	}
	else 
		if (m > 1) {
			T result = *n;
			for (int i = 1; i < m; i++)
				*n *= result;
		}
}

int main() {
	
	// 22.1 Change even and odd array elements
	std::cout << "\t22.1 Change even and odd array elements\n";
	const int size = 10;
	int arr[size];
	int* pa = &arr[0];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		*(pa + i) = rand() % (11);	// [0..10]
	std::cout << "Initial array:\n";
	print_arr(pa, size);
	for (int i = 0; i < size; i += 2)
		std::swap(*(pa + i), *(pa + i + 1));
	std::cout << "Result array:\n";
	print_arr(pa, size);

	// 22.2 Exponentiation
	std::cout << "\n\t22.2 Exponentiation\n";
	int n, m;
	std::cout << "Enter number -> ";
	std::cin >> n;
	std::cout << "Enter number exponent (non-negative integer) -> ";
	std::cin >> m;
	if (m < 0)
		std::cout << "Input error!\n";
	else {
		std::cout << n << '^' << m << " = ";
		power(&n, m);
		std::cout << n << '\n';
	}

	return 0;
}