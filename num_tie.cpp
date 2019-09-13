#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>Num;
	int number;
	int count = 0;
	int result = 0;
	int save = 0;

	for (int i{ 0 }; i < N; i++) {
		cin >> number;
		Num.push_back(number);
	}

	sort(Num.begin(), Num.end());

	for (int i{ N-1 }; i >= 0; i--) {
		if (Num[i] <= 0) {
			result += save;
			count = 0;
			save = 0;
			break;
		}

		else if (Num[i] == 1) {
			result += save;
			result += Num[i];
			count = 0;
			save = 0;
		}

		else {
			if (count == 0) {
				save = Num[i];
				count++;
				if (i == 0) {
					result += save;
					count = 0;
					save = 0;
				}
			}
			else if (count == 1) {
				result += (save * Num[i]);
				count = 0;
				save = 0;
			}
		}
	}

	for (int i{ 0}; i < N; i++) {
		if (Num[i] > 0) {
			result += save;
			count = 0;
			save = 0;
			break;
		}

		else {
			if (count == 0) {
				save = Num[i];
				count++;

				if (i == N - 1) {
					result += save;
					count = 0;
					save = 0;
				}
			}
			else if (count == 1) {
				result += (save * Num[i]);
				count = 0;
				save = 0;
			}
		}
	}
	
	cout << result;
}