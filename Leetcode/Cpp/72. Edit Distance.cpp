class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.length(), m = word2.length();
		int** A = new int* [m + 1];
		for (int i = 0; i < m + 1; i++)
			A[i] = new int[n + 1] {0};
		for (int i = 0; i < m + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				if (j == 0)
					A[i][j] = i - j;
				else if (i == 0)
					A[i][j] = j - i;
				else {
					if (word2[i - 1] == word1[j - 1])
						A[i][j] = A[i - 1][j - 1];
					else {
						int min = A[i - 1][j - 1];

						if (A[i][j - 1] < min)
							min = A[i][j - 1];
						if (A[i - 1][j] < min)
							min = A[i - 1][j];
						A[i][j] = min + 1;
					}
				}
			}
		}
		return A[m][n];
	}
};