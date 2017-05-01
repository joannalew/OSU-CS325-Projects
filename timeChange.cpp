/********************************
* Joanna Lew, Daniel Olivas, Nathan Stauffer
* CS325 project 2 algorithm run time comparison
*********************************/
#include "functions.hpp"

using namespace std;

void runSlow(vector<int> V, ofstream &fout);
void runGreedy(vector<int> V, ofstream &fout);
void runDP(vector<int> V, ofstream &fout);
void timeSlow( vector<vector<int>> Vectors, ofstream &fout);
void timeGreedy( vector<vector<int>> Vectors, ofstream &fout);
void timeDP( vector<vector<int>> Vectors, ofstream &fout);

int main() {

	vector<int> V1 {1, 2, 12, 24, 48, 60};
	vector<int> V2 {1, 5, 10, 25, 50};
	vector<int> V3 {1, 6, 13, 37, 150};
	vector<vector<int>> Vectors {V1, V2, V3};
	vector<int> A;
	ofstream fout;
	fout.open("changeSlowAmount.txt");
	//ALGORITHM #1: changeslow
	fout << "changeslow\n" << "A, Coins\n";
	for (int i = 0; i < Vectors.size(); i++) {
		runSlow(Vectors.at(i), fout);
		fout << "\n";
	}
	fout.close();
	fout.open("changegreedyAmount.txt");
	//ALGORITHM #2: changegreedy
	fout << "changegreedy\n" << "A, Coins\n";
	for (int i = 0; i < Vectors.size(); i++) {
		runGreedy(Vectors.at(i), fout);
		fout << "\n";
	}
	fout.close();
	fout.open("chagedpAmount.txt");
	//ALGORITHM #3: changedp
	fout << "changedp\n" << "A, Coins\n";
	for (int i = 0; i < Vectors.size(); i++) {
		runDP(Vectors.at(i), fout);
		fout << "\n";
	}
	fout.close();

	fout.open("changeSlowTime.txt");
	//ALGORITHM #1: changeslow timing
	fout << "changeslow\n" << "A, Coins\n";
	timeSlow(Vectors, fout);
	fout << "\n";
	fout.close();

	fout.open("changegreedyTime.txt");
	//ALGORITHM #2: changegreedy timing
	fout << "changegreedy\n" << "A, Coins\n";
	timeGreedy(Vectors, fout);
	fout << "\n";
	fout.close();

	fout.open("chagedpTime.txt");
	//ALGORITHM #3: changedp timing
	fout << "changedp\n" << "A, Coins\n";
	timeDP(Vectors, fout);
	fout << "\n";
	fout.close();

	return 0;
}

void runSlow(vector<int> V, ofstream &fout)
{
	int size = 45;
	vector<int> A {};
	vector<int> change(V.size(), 0);
	for (int i = 1; i <= size; i++)
	{
		A.push_back(i);
	}
	fout << "[";
	for (int i = 0; i < V.size(); i++)
	{
		fout << V.at(i);
		if(i == V.size() -1 )
			break;
		else fout << ", ";
	}
	fout << "]\n";
	for (int i = 0; i < A.size(); i++)
	{
		int sum = 0;
		change = changeslow(V, A.at(i));

		for(int j = 0; j < change.size(); j++)
			sum += change.at(j);

		fout << A.at(i) << " , " << sum << " \n";
	}
}

void runGreedy(vector<int> V, ofstream &fout)
{
	int start = 2000;
	int size = 2200;
	vector<int> A {};
	vector<int> change(V.size(), 0);
	for (int i = 1; i <= size; i++)
	{
		A.push_back(i);
	}
	fout << "[";
	for (int i = 0; i < A.size(); i++)
	{
		fout << V.at(i);
		if(i == V.size() -1 )
			break;
		else fout << ", ";
	}
	fout << "]\n";
	for (int i = start; i < A.size(); i++)
	{
		int sum = 0;
		change = changegreedy(V, A.at(i));
		for(int j = 0; j < change.size(); j++)
			sum += change.at(j);

		fout << A.at(i) << " , " << sum << " \n";
	}
}

void runDP(vector<int> V, ofstream &fout)
{
	int start = 2000;
	int size = 2200;
	vector<int> A {};
	vector<int> change(V.size(), 0);
	for (int i = 1; i <= size; i++)
	{
		A.push_back(i);
	}
	fout << "[";
	for (int i = 0; i < A.size(); i++)
	{
		fout << V.at(i);
		if(i == V.size() -1 )
			break;
		else fout << ", ";
	}
	fout << "]\n";
	for (int i = start; i < A.size(); i++)
	{
		int sum = 0;
		change = changedp(V, A.at(i));

		for(int j = 0; j < change.size(); j++)
			sum += change.at(j);

		fout << A.at(i) << " , " << sum << " \n";
	}
}

void timeSlow( vector<vector<int>> Vectors, ofstream &fout)
{
	int size = 0;
	double time = 0;
	double avgTime = 0;
	for(int k = 0; k < 10; k++) {
		fout << "round " << k+1 << "\n";
		for (int i = 0; i < Vectors.size(); i++) {
			vector<int> change(Vectors.at(i).size(), 0);
			clock_t t1, t2;
			t1 = clock();
			change = changeslow(Vectors.at(i), size);
			t2 = clock();
			double diff = ((double) t2 - (double) t1);
			time += diff / CLOCKS_PER_SEC;
			change.clear();
		}
		avgTime = time / 3.0;
		fout << size << ", " << avgTime << "\n";
		time = 0;
		size += 5;
	}
}

void timeGreedy( vector<vector<int>> Vectors, ofstream &fout)
{
	int size = 0;
	double time = 0;
	double avgTime = 0;
	for(int k = 0; k < 10; k++) {
		fout << "round " << k+1 << "\n";
		for (int i = 0; i < Vectors.size(); i++) {
			vector<int> change(Vectors.at(i).size(), 0);
			clock_t t1, t2;
			t1 = clock();
			change = changegreedy(Vectors.at(i), size);
			t2 = clock();
			double diff = ((double) t2 - (double) t1);
			time += diff / CLOCKS_PER_SEC;
			change.clear();
		}
		avgTime = time / 3.0;
		fout << size << ", " << avgTime << "\n";
		time = 0;
		size += 20000000;
	}
}

void timeDP( vector<vector<int>> Vectors, ofstream &fout) {
	int size = 0;
	double time = 0;
	double avgTime = 0;
	for (int k = 0; k < 10; k++) {
		fout << "round " << k + 1 << "\n";
		for (int i = 0; i < Vectors.size(); i++) {
			vector<int> change(Vectors.at(i).size(), 0);
			clock_t t1, t2;
			t1 = clock();
			change = changedp(Vectors.at(i), size);
			t2 = clock();
			double diff = ((double) t2 - (double) t1);
			time += diff / CLOCKS_PER_SEC;
			change.clear();
		}
		avgTime = time / 3.0;
		fout << size << ", " << avgTime << "\n";
		time = 0;
		size += 100000;
	}
}

